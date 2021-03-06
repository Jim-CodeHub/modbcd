#-------------------------------------------------------------------------------------------------------
#																									   #
#								Makefile for modbcd TST source file 								   #
#																									   #
#-------------------------------------------------------------------------------------------------------

PROJECT		= AVR
MJR_VER		= ATmega128

TARGET 		= $(PROJECT)_$(MJR_VER)

CC 		    = avr-gcc
OBJCOPY 	= avr-objcopy
OBJDUMP 	= avr-objdump

PROGRAMMER 	= usbasp
L_FUSE_BIT 	= 0X2E
H_FUSE_BIT 	= 0XC9 #0XC1
E_FUSE_BIT 	= 0XFF #0XD4

MCU 		= atmega128
F_CPU 		= 16000000UL

OBJS		= main.o port_style2.o mbcrc.o
OBJS	   += ../modbcd/modbcd.o					\
			  ../modbcd/util/mbcd_box.o				
#../modbcd/util/mbcrc.o				

CFLAGS 		= -mmcu=$(MCU) -Werror -Wall -Os -std=c99 -D F_CPU=$(F_CPU)
CFLAGS     += -g
CFLAGS	   += -I.
CFLAGS	   += -I../modbcd							\
			  -I../modbcd/util						

LDFLAGS 	= -mmcu=$(MCU) -Wl,-Map=$(TARGET).map
 
export CC CFLAGS TARGET 


#-------------------------------------------------------------------------------------------------------
#																									   #
#									        Make rules 									   		   	   #
#																									   #
#-------------------------------------------------------------------------------------------------------

.PHONY: all clean fuse fuseset 

all:$(OBJS)
	$(CC) $(shell find ../ -name "*.o") $(LDFLAGS) -lm -o $(TARGET).elf 
	$(OBJCOPY) -O ihex -R .eeprom -R .fuse -R .lock -R .signature $(TARGET).elf $(TARGET).hex 
	$(OBJCOPY) -j .eeprom --set-section-flags=.eeprom="alloc,load" --change-section-lma .eeprom=0 --no-change-warnings -O ihex $(TARGET).hex $(TARGET).eep 
	$(OBJDUMP) -h -S $(TARGET).elf > $(TARGET).lss

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

fuse:
	make clean 
	make 
	sudo avrdude -c $(PROGRAMMER) -p $(MCU) -Ulfuse:w:$(L_FUSE_BIT):m -Uhfuse:w:$(H_FUSE_BIT):m -Uefuse:w:$(E_FUSE_BIT):m -Ulock:w:$(LOCK_BIT):m -Uflash:w:$(TARGET).hex

fuseset:
	sudo avrdude -P usb -p $(MCU) -c $(PROGRAMMER) -t

clean:
	@rm -rf $(shell find ../ -name "*.o")
	@rm -rf *.elf *.hex *.eep *.lss *.map


