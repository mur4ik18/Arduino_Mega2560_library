CC = avr-gcc
# Processor name
MCU = atmega2560

# Processor frequency
F_CPU = 16000000UL

CFLAGS += -Wall -mmcu=$(MCU) -DF_CPU=$(F_CPU)

lib_source = ./lib
lib_output = ./out


SRCS = $(wildcard $(lib_source)/*.c)
OBJS = $(patsubst $(lib_source)/%.c, $(lib_output)/%.o, $(SRCS))

# default:
# 	$(CC) -Os $(CFLAGS) -o main.bin main.c $(OBJS)
# 	avr-objcopy -j .text -j .data -O ihex main.bin main.hex
# 	sudo avrdude -p atmega2560 -c stk500v2 -D -U flash:w:main.hex:i -F -P /dev/ttyACM0
# 
# 	sudo putty /dev/ttyACM0 -serial -sercfg 9600



# all: $(lib_output)
# 
# $(OBJS)/%.o: $(SRCS)/%.c
# 	$(CC) $(CFLAGS) -c $< -o $@ 
# 
# $(lib_output):
# 	mkdir -p $@

clean:
	# suprimer la merde 
	rm *.o
