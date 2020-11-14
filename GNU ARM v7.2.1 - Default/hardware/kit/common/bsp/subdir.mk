################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hardware/kit/common/bsp/bsp_stk.c 

OBJS += \
./hardware/kit/common/bsp/bsp_stk.o 

C_DEPS += \
./hardware/kit/common/bsp/bsp_stk.d 


# Each subdirectory must supply rules for building sources it contributes
hardware/kit/common/bsp/bsp_stk.o: ../hardware/kit/common/bsp/bsp_stk.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DMESH_LIB_NATIVE=1' '-DNVM3_DEFAULT_NVM_SIZE=24576' '-D__HEAP_SIZE=0x1500' '-DENABLE_LOGGING=1' '-DNVM3_DEFAULT_MAX_OBJECT_SIZE=512' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0xD00' '-DEFR32BG13P632F512GM48=1' -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/Device/SiliconLabs/EFR32BG13P/Include" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/middleware/glib/glib" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/protocol/bluetooth/bt_mesh/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/nvm3/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/CMSIS/Include" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/hardware/kit/common/drivers" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/radio/rail_lib/plugin/coexistence/hal/efr32" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/hardware/kit/common/bsp" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emlib/src" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emlib/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/protocol/bluetooth/bt_mesh/src" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/Device/SiliconLabs/EFR32BG13P/Source/GCC" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/middleware/glib" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/radio/rail_lib/plugin/coexistence/common" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/protocol/bluetooth/bt_mesh/inc/common" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/sleep/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/radio/rail_lib/common" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/nvm3/src" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/radio/rail_lib/chip/efr32/efr32xg1x" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/sleep/src" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/common/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/service/sleeptimer/src" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/middleware/glib/dmd/ssd2119" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/hardware/kit/common/halconfig" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/radio/rail_lib/protocol/ble" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/hardware/kit/EFR32BG13_BRD4104A/config" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/service/sleeptimer/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/protocol/bluetooth/bt_mesh/inc/soc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/halconfig/inc/hal-config" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/uartdrv/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/protocol/bluetooth/ble_stack/src/soc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/bootloader/api" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/middleware/glib/dmd" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/common/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/protocol/bluetooth/ble_stack/inc/soc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/Device/SiliconLabs/EFR32BG13P/Source" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/gpiointerrupt/inc" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/middleware/glib/dmd/display" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/radio/rail_lib/protocol/ieee802154" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/emdrv/gpiointerrupt/src" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/service/sleeptimer/config" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub/platform/radio/rail_lib/plugin" -I"/Users/dsluiter/SimplicityStudio/v4_workspace/starter_code/soc-btmesh-pubsub" -O0 -fno-builtin -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"hardware/kit/common/bsp/bsp_stk.d" -MT"hardware/kit/common/bsp/bsp_stk.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


