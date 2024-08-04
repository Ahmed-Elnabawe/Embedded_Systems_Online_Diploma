# makefile with "Ahmed Elnabawe"

CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3  -mthumb -gdwarf-2
INCS=-I .
LIBS=
SCR=$(wildcard *.c)
OBJ=$(SCR:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name=learn_in_depth_cortex-m3
all: $(Project_name).bin
	@echo "========== done =========="

$(Project_name).bin:$(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker_script.ld   $(OBJ) $(ASOBJ) $(LIBS) -o $(Project_name).elf -Map=Map_file.map
%.o:%.c 
	$(CC)gcc.exe -c  $(CFLAGS) $(INCS) $< -o $@

#startup.o:startup.s 
#	$(CC)as.exe $(CFLAGS) $< -o $@	
clean_all:
	rm *.o *.bin *.map *.elf
clean:
	rm *.elf *.bin