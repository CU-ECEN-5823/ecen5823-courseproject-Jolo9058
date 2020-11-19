################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../platform/emdrv/nvm3/src/nvm3_default.c \
../platform/emdrv/nvm3/src/nvm3_hal_flash.c \
../platform/emdrv/nvm3/src/nvm3_lock.c 

OBJS += \
./platform/emdrv/nvm3/src/nvm3_default.o \
./platform/emdrv/nvm3/src/nvm3_hal_flash.o \
./platform/emdrv/nvm3/src/nvm3_lock.o 

C_DEPS += \
./platform/emdrv/nvm3/src/nvm3_default.d \
./platform/emdrv/nvm3/src/nvm3_hal_flash.d \
./platform/emdrv/nvm3/src/nvm3_lock.d 


# Each subdirectory must supply rules for building sources it contributes
platform/emdrv/nvm3/src/nvm3_default.o: ../platform/emdrv/nvm3/src/nvm3_default.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DMESH_LIB_NATIVE=1' '-DNVM3_DEFAULT_NVM_SIZE=24576' '-D__HEAP_SIZE=0x1500' '-DENABLE_LOGGING=1' '-DNVM3_DEFAULT_MAX_OBJECT_SIZE=512' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0xD00' '-DEFR32BG13P632F512GM48=1' -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Include" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\glib" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\nvm3\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\CMSIS\Include" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\drivers" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin\coexistence\hal\efr32" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\bsp" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emlib\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emlib\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Source\GCC" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin\coexistence\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\sleep\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\nvm3\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\chip\efr32\efr32xg1x" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\sleep\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\common\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd\ssd2119" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\halconfig" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\protocol\ble" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\EFR32BG13_BRD4104A\config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\halconfig\inc\hal-config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\uartdrv\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\ble_stack\src\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\bootloader\api" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\common\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\ble_stack\inc\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Source" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd\display" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\protocol\ieee802154" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\gpiointerrupt\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058" -O0 -fno-builtin -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"platform/emdrv/nvm3/src/nvm3_default.d" -MT"platform/emdrv/nvm3/src/nvm3_default.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/emdrv/nvm3/src/nvm3_hal_flash.o: ../platform/emdrv/nvm3/src/nvm3_hal_flash.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DMESH_LIB_NATIVE=1' '-DNVM3_DEFAULT_NVM_SIZE=24576' '-D__HEAP_SIZE=0x1500' '-DENABLE_LOGGING=1' '-DNVM3_DEFAULT_MAX_OBJECT_SIZE=512' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0xD00' '-DEFR32BG13P632F512GM48=1' -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Include" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\glib" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\nvm3\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\CMSIS\Include" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\drivers" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin\coexistence\hal\efr32" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\bsp" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emlib\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emlib\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Source\GCC" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin\coexistence\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\sleep\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\nvm3\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\chip\efr32\efr32xg1x" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\sleep\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\common\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd\ssd2119" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\halconfig" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\protocol\ble" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\EFR32BG13_BRD4104A\config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\halconfig\inc\hal-config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\uartdrv\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\ble_stack\src\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\bootloader\api" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\common\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\ble_stack\inc\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Source" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd\display" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\protocol\ieee802154" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\gpiointerrupt\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058" -O0 -fno-builtin -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"platform/emdrv/nvm3/src/nvm3_hal_flash.d" -MT"platform/emdrv/nvm3/src/nvm3_hal_flash.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

platform/emdrv/nvm3/src/nvm3_lock.o: ../platform/emdrv/nvm3/src/nvm3_lock.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM C Compiler'
	arm-none-eabi-gcc -g -gdwarf-2 -mcpu=cortex-m4 -mthumb -std=c99 '-DMESH_LIB_NATIVE=1' '-DNVM3_DEFAULT_NVM_SIZE=24576' '-D__HEAP_SIZE=0x1500' '-DENABLE_LOGGING=1' '-DNVM3_DEFAULT_MAX_OBJECT_SIZE=512' '-DHAL_CONFIG=1' '-D__STACK_SIZE=0xD00' '-DEFR32BG13P632F512GM48=1' -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Include" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\glib" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\nvm3\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\CMSIS\Include" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\drivers" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin\coexistence\hal\efr32" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\bsp" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emlib\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emlib\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Source\GCC" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin\coexistence\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\sleep\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\common" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\nvm3\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\chip\efr32\efr32xg1x" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\sleep\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\common\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd\ssd2119" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\common\halconfig" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\protocol\ble" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\hardware\kit\EFR32BG13_BRD4104A\config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\bt_mesh\inc\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\halconfig\inc\hal-config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\uartdrv\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\ble_stack\src\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\bootloader\api" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\common\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\protocol\bluetooth\ble_stack\inc\soc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\Device\SiliconLabs\EFR32BG13P\Source" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\gpiointerrupt\inc" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\middleware\glib\dmd\display" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\protocol\ieee802154" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\emdrv\gpiointerrupt\src" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\service\sleeptimer\config" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058\platform\radio\rail_lib\plugin" -I"C:\Users\School\SimplicityStudio\v4_workspace\ecen5823-courseproject-Jolo9058" -O0 -fno-builtin -Wall -c -fmessage-length=0 -ffunction-sections -fdata-sections -mfpu=fpv4-sp-d16 -mfloat-abi=softfp -MMD -MP -MF"platform/emdrv/nvm3/src/nvm3_lock.d" -MT"platform/emdrv/nvm3/src/nvm3_lock.o" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


