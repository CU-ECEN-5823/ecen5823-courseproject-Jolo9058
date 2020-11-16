Bluetooth Mesh Models
For Home Security Project
Author: Joe Lopez

This document is intended to define a common interface for bluetooth mesh behavior in the project to facilitate independent development of nodes. This should allow each interface to be opaque to the other nodes, so that they have no need to understand what is going on inside another node in order to interface with it. 
If anything is unclear, ambiguous or needs to be changed, please notify the team so this document can be updated and everyone can stay up-to-date with changes. 
Note: It is strongly recommended that any 'magic numbers' mentioned in this document be implemented with #defines in code so that if, for any reason, they need to be changed that can be done so easily

Reference for models: https://www.bluetooth.com/wp-content/uploads/2019/04/1903_Mesh-Models-Overview_FINAL.pdf

Generic On/Off Model
This model will be used to send alert notifications from low power (sensor) nodes to the friend node. 
Sensor Nodes/Low Power Nodes implement the server model. The Friend Node implements the client model.
This state contains only the On/Off state. On (1) indicates that the alarm of that node is going off. Off (0) indicates that the node's alarm is not going off.
Off (0) should be the default value for all sensor nodes.
The client shall not set the value on the server at any time. The client can ignore an alarm state if appropriate, but should not set the value on the server to do so (and the server should ignore any attempt to change its value). 
The value should stay at On (1) as long as the event causing an alarm is ongoing. It should reset to Off (0) as soon as that event is no longer ongoing. 


Generic Power Level Model
This model will be used to determine the sleep level of the Low Power nodes.
Sensor Nodes/Low Power Nodes implement the server model. The Friend Node implements the client model. The Friend node is to use Generic Level Set messages to control power levels on Sensor Nodes.
Values in the model are Generic Power Actual, Generic Power Last, Generic Power Default, and Generic Power Range.

State
Description from Spec
Interpretation in Project
Generic Power Actual
Sets element’s power level as a linear percentage of the maximum available. Note that with this state set to zero, the device is permitted to continue to be sufficiently powered for wireless communication to remain available. It is like putting the device into standby mode. 
Sets which sleep mode the node will enter. Enumerations are:
100: Do not sleep
75: EM1
50: EM2
25: EM3
0: EM4
All other values should be considered illegal.
Generic Power Last
 Records the last known value of generic power actual, so the last power level can be restored when the device is switched on. This behavior is governed by a state binding with the generic onoff state and whether or not the generic power default state is zero. 
As the spec. 
Generic Power Default
If this state has a non-zero value when the device is switched on and the generic onoff state changes to 0x01, the power level is restored to the value of this state.
As the spec. This should probably be the lowest power level the node can sleep in and still operate properly unless there's a compelling reason otherwise.
Generic Power Range
Contains the minimum and maximum power levels the device can be set to as a percentage of the maximum level the device is capable of outputting.
As the spec. Minimum should be the lowest power level the node can sleep in and still operate properly. Maximum can be 100/EM0 or something else if appropriate.

The server nodes are allowed to change the value stored in this model if necessary. When doing so, they should provide an indication to the Client. 
The Client should  check the range before issuing a set value command and not issue any set value commands that would violate the range specified.
If the server's power level value somehow gets set to a value that would make it stop operating properly, it is not required to actually go to that sleep depth. If the power level is in the allowed range, the server is required to go to the indicated sleep depth. 
