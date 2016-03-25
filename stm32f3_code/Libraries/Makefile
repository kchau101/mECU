CC=arm-none-eabi-gcc
AR=arm-none-eabi-ar

###########################################

vpath %.c STM32F30x_StdPeriph_Driver/src STM32_USB-FS-Device_Driver/src

LIB_CFLAGS += -g -O2 -Wall
LIB_CFLAGS += -mlittle-endian -mthumb -mcpu=cortex-m4 -march=armv7e-m
LIB_CFLAGS += -mfpu=fpv4-sp-d16 -mfloat-abi=hard
LIB_CFLAGS += -ffreestanding -nostdlib
LIB_CFLAGS += -includestm32f30x_conf.h 
LIB_CFLAGS += -ICMSIS/Include 
LIB_CFLAGS += -ICMSIS/Device/ST/STM32F30x/Include 
LIB_CFLAGS += -ISTM32F30x_StdPeriph_Driver/inc
LIB_CFLAGS += -ISTM32_USB-FS-Device_Driver/inc
LIB_CFLAGS += -I../inc

LIB_SRCS = stm32f30x_adc.c stm32f30x_can.c stm32f30x_comp.c stm32f30x_crc.c \
       stm32f30x_dac.c stm32f30x_dbgmcu.c stm32f30x_dma.c \
       stm32f30x_exti.c stm32f30x_flash.c stm32f30x_gpio.c \
       stm32f30x_i2c.c stm32f30x_iwdg.c stm32f30x_misc.c stm32f30x_opamp.c \
       stm32f30x_pwr.c stm32f30x_rcc.c stm32f30x_rtc.c stm32f30x_spi.c \
       stm32f30x_syscfg.c stm32f30x_tim.c stm32f30x_usart.c \
       stm32f30x_wwdg.c 

LIB_OBJS = $(addprefix LIB_OBJS/,$(LIB_SRCS:.c=.o))
LIB_DEPS = $(addprefix LIB_DEPS/,$(LIB_SRCS:.c=.d))

.PHONY: all clean

all: libstm32f3.a

-include $(LIB_DEPS)

dirs:
	mkdir -p LIB_DEPS LIB_OBJS
	touch dirs

LIB_OBJS/%.o : %.c dirs
	$(CC) $(LIB_CFLAGS) -c -o $@ $< -MMD -MF LIB_DEPS/$(*F).d

libstm32f3.a: $(LIB_OBJS)
	$(AR) -r $@ $(LIB_OBJS)

clean:
	rm -f dirs $(LIB_OBJS) $(LIB_DEPS) libstm32f3.a

