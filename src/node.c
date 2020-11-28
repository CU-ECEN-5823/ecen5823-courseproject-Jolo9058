/***************************************************************************
 * @file  node.c was switch.c from Silabs soc-btmest-switch example code
 * @brief node module implementation
 *
 * @editor    Awesome Student, Awesome.Student@Colorado.edu
 * @date      Sep 15, 2020
 *
 * @institution University of Colorado Boulder (UCB)
 * @course      ECEN 5823-001: IoT Embedded Firmware (Fall 2020)
 * @instructor  David Sluiter
 *
 * @assignment ecen5823-assignment10-AwesomeStudent
 * @due        Sep 18, 2020
 *
 * @resources  Utilized Silicon Labs' BT mesh v1.7 library
 *
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/* C Standard Library headers */
#include <src/node.h>
#include <stdlib.h>
#include <stdio.h>

#include "node.h"

/* Bluetooth stack headers */
#include "native_gecko.h"
#include "mesh_generic_model_capi_types.h"
#include "mesh_lighting_model_capi_types.h"
#include "mesh_lib.h"
#include "board_features.h"

#include "ble_mesh_device_type.h"
/* Timer definitions */
#include "app_timer.h"
#include "app.h"
#include "alarm.h"
//// Flag for use on the friend node, indicating that an alarm state is in progress
//extern uint16 alarm_state;
//// Flag for use on friend node, indicating that alarms are deactivated
//extern uint16 alarm_deactivate;


#ifdef ENABLE_LOGGING
#define log(...) printf(__VA_ARGS__)
#else
#define log(...)
#endif


#define PRIMARY_ELEMENT    0 ///< Client models located in primary element
#define IMMEDIATE          0 ///< Immediate transition time is 0 seconds
#define PUBLISH_ADDRESS    0 ///< The unused 0 address is used for publishing
#define IGNORED            0 ///< Parameter ignored for publishing
#define NO_FLAGS           0 ///< No flags used for message



/// current position of the switch (button PB0)
static uint8_t switch_pos = 0;
/// number of on/off requests to be sent
static uint8_t onoff_request_count;
/// on/off transaction identifier
static uint8_t onoff_trid = 0;

char buf[30]; // for sprintf, see below





static void onoff_request(uint16_t model_id,
                          uint16_t element_index,
                          uint16_t client_addr,
                          uint16_t server_addr,
                          uint16_t appkey_index,
                          const struct mesh_generic_request *request,
                          uint32_t transition_ms,
                          uint16_t delay_ms,
                          uint8_t request_flags)
{
  log("ON/OFF request: requested state=<%s>, transition=%lu, delay=%u\r\n",
      request->on_off ? "ON" : "OFF", transition_ms, delay_ms);

  if (switch_pos == request->on_off) {
    log("Request for current state received; no op\r\n");
  } else {
    log("Turning alarm <%s>\r\n", request->on_off ? "ON" : "OFF");

      switch_pos = request->on_off;
      if(switch_pos && !get_alarm_deactivate()){
    	  set_alarm_state(1);
    	  DI_Print("Alarm Active!", DI_ROW_LIGHTNESS);

    	  struct gecko_msg_flash_ps_load_rsp_t * load_result = gecko_cmd_flash_ps_load(STORAGE_KEY);
    	  storage_val[0] = load_result->value.data[0] + 1;
    	  if(load_result->result){
    		  log("Persistent storage load failed. Error code: %x\n\r", load_result->result);
    	  }
    	  else{
    		  log("Total alarms: %d\n\r", storage_val[0]);
    		  sprintf(buf, "Total Alarms: %d", storage_val[0]);
    		  DI_Print(buf, 8);
    	  }


    	  struct gecko_msg_flash_ps_save_rsp_t * store_result = gecko_cmd_flash_ps_save(STORAGE_KEY, 1, storage_val);
    	  if(store_result->result){
    		  log("Persistent storage store failed. Error code: %x\n\r", store_result->result);
    	  }

      }
      else{
    	  set_alarm_state(0);
    	  if(!get_alarm_deactivate()) DI_Print("Alarm Not Active", DI_ROW_LIGHTNESS);
      }
    }
}




/*******************************************************************************
 * node initialization.
 * This is called at each boot if provisioning is already done.
 * Otherwise this function is called after provisioning is completed.
 ******************************************************************************/
void node_init(void)
{



  if(DeviceIsOnOffPublisher()){
	  // Initialize mesh lib, up to 8 models
	  mesh_lib_init(malloc, free, 8);
  }
  if(DeviceIsOnOffSubscriber()){

	  uint16_t res;

	  mesh_lib_init(malloc,free,10);

	  //Initialize Friend functionality
	  log("Friend mode initialization\r\n");
	  res = gecko_cmd_mesh_friend_init()->result;
	  if (res) {
	    log("Friend init failed 0x%x\r\n", res);
	  }

	  mesh_lib_generic_server_register_handler(MESH_GENERIC_ON_OFF_SERVER_MODEL_ID,
			                                           0,
			                                           onoff_request,
			                                           NULL,
			                                           NULL);
//	  mesh_lib_generic_server_update();
//	  mesh_lib_generic_server_publish();
  }


}

/***************************************************************************//**
 * This function publishes one generic on/off request to change the state
 * of PB0 in the group. Global variable switch_pos holds the latest
 * PB0 state, possible values are:
 * switch_pos = 1 -> PB0 was pressed
 * switch_pos = 0 -> PB0 was released
 *
 * param[in] retrans  Indicates if this is the first request or a retransmission,
 *                    possible values are 0 = first request, 1 = retransmission.
 *
 * @note This application sends multiple generic on/off requests for each
 *       button press and release to improve reliability.
 *       The transaction ID is not incremented in case of a retransmission.
 ******************************************************************************/
static void send_onoff_request(uint8_t retrans)
{
	log("IN send on off request\n\r");
  struct mesh_generic_request req;
  const uint32_t transtime = 0; // using zero transition time by default

  req.kind = mesh_generic_request_on_off;
  req.on_off = switch_pos ? MESH_GENERIC_ON_OFF_STATE_ON : MESH_GENERIC_ON_OFF_STATE_OFF;

  // Increment transaction ID for each request, unless it's a retransmission
  if (retrans == 0) {
    onoff_trid++;
  }

  // Delay for the request is calculated so that the last request will have
  // a zero delay and each of the previous request have delay that increases
  // in 50 ms steps. For example, when using three on/off requests
  // per button press the delays are set as 100, 50, 0 ms
  uint16_t delay = (onoff_request_count - 1) * 50;

  uint16_t resp = mesh_lib_generic_client_publish(MESH_GENERIC_ON_OFF_CLIENT_MODEL_ID,
                                                  PRIMARY_ELEMENT,
                                                  onoff_trid,
                                                  &req,
                                                  transtime, // transition time in ms
                                                  delay,
                                                  NO_FLAGS   // flags
                                                  );




  if (resp) {
    log("gecko_cmd_mesh_generic_client_publish failed, code 0x%x\r\n", resp);
  } else {
	  if (switch_pos) {
		  log("on request sent, trid = %u, delay = %u\r\n", onoff_trid, delay);
	  } else {
		  log("off request sent, trid = %u, delay = %u\r\n", onoff_trid, delay);
	  }
  }

  // Keep track of how many requests has been sent
  if (onoff_request_count > 0) {
    onoff_request_count--;
  }

} // send_onoff_request()




/*******************************************************************************
 * This function change the switch position and send it to the server.
 *
 * @param[in] position  Defines PB0 position change, possible values are
 *                      0 = OFF (released), 1 = ON (pressed)
 *
 ******************************************************************************/
void change_switch_position(uint8_t position)
{
#if PIR_SENSOR
  switch_pos = position;

  // Turns light ON or OFF, using Generic OnOff model
  log("PIR sensor ");
  if (switch_pos) {
    log("Human Presence Detected\r\n");
  }

  onoff_request_count = 3; // Request is sent 3 times to improve reliability

  send_onoff_request(0);  // Send the first request

  // If there are more requests to send, start a repeating soft timer
  // to trigger retransmission of the request after 50 ms delay
  if (onoff_request_count > 0) {
    gecko_cmd_hardware_set_soft_timer(TIMER_MS_2_TIMERTICK(50),
                                      RETRANS_ONOFF_TIMER,
                                      REPEATING);
  }

#elif NOISE_SENSOR == 1
  switch_pos = position;

  // Turns light ON or OFF, using Generic OnOff model
  //log("Noise sensor \n\r");
  if (switch_pos) {
    log("SOUND Detected\r\n");
  }

  onoff_request_count = 3; // Request is sent 3 times to improve reliability

  send_onoff_request(0);  // Send the first request

  // If there are more requests to send, start a repeating soft timer
  // to trigger retransmission of the request after 50 ms delay
  if (onoff_request_count > 0) {
    gecko_cmd_hardware_set_soft_timer(TIMER_MS_2_TIMERTICK(50),
                                      RETRANS_ONOFF_TIMER,
                                      REPEATING);
  }

#endif
} // change_switch_position()

/*******************************************************************************
 *  Handling of message retransmission timer events.
 *
 *  @param[in] pEvt  Pointer to incoming event.
 ******************************************************************************/
void handle_retrans_timer_evt(struct gecko_cmd_packet *pEvt)
{

  switch (pEvt->data.evt_hardware_soft_timer.handle) {

    case RETRANS_ONOFF_TIMER:
      send_onoff_request(1);   // param 1 indicates that this is a retransmission
      // stop retransmission timer if it was the last attempt
      if (onoff_request_count == 0) {
        gecko_cmd_hardware_set_soft_timer(TIMER_STOP,
                                          RETRANS_ONOFF_TIMER,
                                          REPEATING);
      }
      break;

    default:
      break;
  }

} // handle_retrans_timer_evt()


