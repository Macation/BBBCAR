################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.c 

OBJS += \
./Libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.o 

COMPILED_SRCS += \
./Libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.src 

C_DEPS += \
./Libraries/iLLD/TC26B/Tricore/Src/Std/IfxSrc.d 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC26B/Tricore/Src/Std/%.src: ../Libraries/iLLD/TC26B/Tricore/Src/Std/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING C/C++ Compiler'
	cctc -D__CPU__=tc26xb -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gpt12" -I"D:/1Project/shabi/BBBCAR-V3/src/AppSw/Tricore/Driver" -I"D:/1Project/shabi/BBBCAR-V3/src/AppSw/Tricore/Main" -I"D:/1Project/shabi/BBBCAR-V3/src/AppSw/Tricore/User" -I"D:/1Project/shabi/BBBCAR-V3/src/AppSw/Tricore/APP" -I"D:/1Project/shabi/BBBCAR-V3/src/AppSw" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Infra/Platform/Tricore/Compilers" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Multican/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Infra/Platform" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cif/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Hssl/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cpu/Trap" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/If/Ccu6If" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dsadc/Dsadc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Port" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Stm/Timer" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dts/Dts" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Eth" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Flash" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Vadc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Msc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Qspi/SpiMaster" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Scu/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/SysSe/Comm" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/SysSe/Math" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Infra/Platform/Tricore" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Trig" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Tim" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6/TimerWithTrigger" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Emem" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Mtu" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Infra" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Fft" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/I2c/I2c" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Asclin/Asc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/SysSe" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Flash/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/If" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Psi5" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cpu" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Fce/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Stm/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Msc/Msc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Vadc/Adc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Asclin" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/Pwm" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Atom" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Port/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Psi5/Psi5" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Eray" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Qspi/SpiSlave" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6/Icu" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cpu/CStart" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Hssl" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cif" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Eth/Phy_Pef7071" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Hssl/Hssl" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Iom/Driver" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Multican/Can" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Psi5s/Psi5s" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Fft/Fft" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6/PwmHl" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Iom/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/_Lib" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/Timer" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Sent" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Eray/Eray" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gpt12/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dma" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Fce/Crc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Qspi" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Infra/Sfr" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Infra/Sfr/TC26B" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/SysSe/Bsp" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/SysSe/General" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cpu/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dts" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Src" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dma/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cif/Cam" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Src/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Asclin/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/I2c/Std" -I"D:/1Project/shabi/BBBCAR-V3/Configurations" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/_Lib/DataHandling" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Sent/Sent" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6/Timer" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Psi5/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Psi5s" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Emem/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6/PwmBc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Iom" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6/TPwm" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Multican" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Mtu/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Infra/Sfr/TC26B/_Reg" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Tom/PwmHl" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dma/Dma" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/Timer" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/SysSe/Time" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dsadc/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Cpu/Irq" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Ccu6" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gpt12/IncrEnc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Psi5s/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Scu" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/_Lib/InternalMux" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Stm" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dsadc/Rdc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Vadc/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dts/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Eth/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Smu" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/_PinMap" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Asclin/Lin" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/StdIf" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Dsadc" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Fce" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/PwmHl" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Qspi/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Tom" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Tim/In" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Msc/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Fft/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Atom/Pwm" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/Service/CpuGeneric/_Utilities" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Gtm/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Smu/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/I2c" -I"D:/1Project/shabi/BBBCAR-V3/Libraries" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Asclin/Spi" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Eray/Std" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Port/Io" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/_Impl" -I"D:/1Project/shabi/BBBCAR-V3/Libraries/iLLD/TC26B/Tricore/Sent/Std" --iso=99 --c++14 --language=+volatile --anachronisms --fp-model=3 --fp-model=c --fp-model=f --fp-model=l --fp-model=n --fp-model=r --fp-model=z -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc26xb -o "$@"  "$<"  -cs --dep-file=$(@:.src=.d) --misrac-version=2012 -N0 -Z0 -Y0 2>&1; sed -i -e '/ctc\\include/d' -e '/Libraries\\iLLD/d' -e '/Libraries\\Infra/d' -e 's/\(.*\)".*\\BBBCAR-V3\(\\.*\)"/\1\.\.\2/g' -e 's/\\/\//g' $(@:.src=.d) && \
	echo $(@:.src=.d) generated
	@echo 'Finished building: $<'
	@echo ' '

Libraries/iLLD/TC26B/Tricore/Src/Std/%.o: ./Libraries/iLLD/TC26B/Tricore/Src/Std/%.src
	@echo 'Building file: $<'
	@echo 'Invoking: TASKING Assembler'
	astc -o  "$@" "$<" --list-format=L1 --optimize=gs
	@echo 'Finished building: $<'
	@echo ' '


