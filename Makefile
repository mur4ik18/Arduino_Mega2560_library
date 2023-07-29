CC = avr-gcc
AVRDUDE = avrdude
OBJCOPY = avr-objcopy

TTY = /dev/ttyACM0

PROCESSOR_NAME = atmega2560
CPU_FREQUENCY = 16000000UL

CFLAGS += -Wall -Wextra -mmcu=$(PROCESSOR_NAME) -DF_CPU=$(CPU_FREQUENCY) -std=c99 -pedantic -Os

MKDIR_P = mkdir -p

SRCPATH = ./lib
OUTPATH = ./out
EXAMPLS = ./examples


# --------------------------------------------------------------------------------------------------------------------
# Here u can use different examples which you can find in examples folder
# Names what you can use:
# 	- blink
#	- shift_register
#	- 1dig_7seg_display
# --------------------------------------------------------------------------------------------------------------------
OUTNAME = 1dig_7seg_display

OUTBIN = $(OUTPATH)/$(OUTNAME).bin
OUTHEX = $(OUTPATH)/$(OUTNAME).hex

EXSRCS = $(wildcard $(EXAMPLS)/*.c)

SRCS = $(wildcard $(SRCPATH)/*.c)
OBJS = $(patsubst $(SRCPATH)/%.c, $(OUTPATH)/%.o, $(SRCS))

all: $(OUTPATH) $(OUTHEX)

$(OUTPATH):
	$(MKDIR_P) $@

$(OUTPATH)/%.o: $(SRCPATH)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

$(OUTBIN): $(OBJS)
	$(CC) $(CFLAGS) -c $(EXAMPLS)/$(OUTNAME).c -o $(OUTPATH)/$(OUTNAME).o
	$(CC) $(CFLAGS) -o $@ $(OUTPATH)/$(OUTNAME).o $^

$(OUTHEX): $(OUTBIN)
	$(OBJCOPY) -j .text -j .data -O ihex $^ $@

flash: $(OUTHEX)
	sudo $(AVRDUDE) -p  $(PROCESSOR_NAME) -c stk500v2 -D -U flash:w:$<:i -F -P $(TTY)

.PHONY: connect
connect:
	sudo putty $(TTY) -serial -sercfg 9600

clean: $(OUTPATH)
	rm -rf $^
