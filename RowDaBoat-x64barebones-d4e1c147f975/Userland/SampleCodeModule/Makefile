include ../Makefile.inc

MODULE=0000-sampleCodeModule.bin
SOURCES=$(wildcard *.c)
SOURCES_INTERRUPTS=$(wildcard ../../Kernel/Interrupts/*.c)
SOURCE_KDRIVER=$(wildcard ../../Kernel/keyboardDriver.c)
SOURCE_VDRIVER=$(wildcard ../../Kernel/video_driver.c)
SOURCES_INTERRUPTS_ASM=$(wildcard ../../Kernel/Interrupts/*.asm)
SOURCES_ASM=$(wildcard *.asm)
OBJECTS_INTERRUPTS=$(SOURCES_INTERRUPTS:.c=.o)
OBJECTS_KDRIVER=$(SOURCES_KDRIVER:.c=.o)
OBJECTS_VDRIVER=$(SOURCES_VDRIVER:.c=.o)
OBJECTS_INTERRUPTS_ASM=$(SOURCES_INTERRUPTS_ASM:.asm=.o)
OBJECTS_ASM=$(SOURCES_ASM:.asm=.o)
OBJECTS=$(SOURCES:.c=.o)


all: $(MODULE)

$(MODULE): $(OBJECTS) $(OBJECTS_ASM) $(OBJECTS_INTERRUPTS_ASM) $(OBJECTS_KDRIVER) $(OBJECTS_VDRIVER) $(OBJECTS_INTERRUPTS) 
	$(LD) $(LDFLAGS) -T sampleCodeModule.ld -o $(MODULE) $^

%.o: %.c
	$(GCC) $(GCCFLAGS)  -I./Include -I./../../Kernel/Interrupts -I./../../Kernel/include -c $< -o $@

%.o : %.asm
	$(ASM) $(ASMFLAGS) $< -o $@


clean:
	rm -rf *.o

.PHONY: all clean print
