# === Tools ===
CC     := clang
ASM    := nasm
LD     := ld
GRUBMK := grub-mkrescue

# === Directories ===
SRC_DIR     := files/source
LINKER_SCRIPT := $(SRC_DIR)/linker.ld
ISO_DIR     := files/isofiles
BOOT_DIR    := $(ISO_DIR)/boot

# === Target ===
ISO := yauc.iso
KERNEL := kernel.bin

# === Compiler Flags (Clang i386 freestanding) ===
CFLAGS := --target=i686-elf \
          -m32 \
          -ffreestanding -nostdlib -nostdlibinc \
          -fno-pic -fno-pie \
          -fno-stack-protector \
          -mno-red-zone \
          -Wall -Wextra -O0 -g \
          -Ifiles/source/include \
          -Ifiles/source/arch


# === NASM Flags ===
ASMFLAGS := -f elf32

# === Linker Flags ===
LDFLAGS := -m elf_i386 -T $(SRC_DIR)/linker.ld

# === Find all sources ===
C_SOURCES   := $(shell find $(SRC_DIR) -type f -name '*.c')
ASM_SOURCES := $(shell find $(SRC_DIR) -type f -name '*.s')

OBJ_C   := $(C_SOURCES:.c=.o)
OBJ_ASM := $(ASM_SOURCES:.s=.o)
OBJ_ALL := $(OBJ_C) $(OBJ_ASM)

# === Default ===
all: $(KERNEL) iso

# === Compile C ===
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# === Assemble ASM ===
%.o: %.s
	$(ASM) $(ASMFLAGS) $< -o $@

# === Link kernel ===
$(KERNEL): $(OBJ_ALL)
	$(LD) $(LDFLAGS) -o $(KERNEL) $(OBJ_ALL)

# === Build ISO ===
iso: $(KERNEL)
	mkdir -p $(BOOT_DIR)
	mv $(KERNEL) $(BOOT_DIR)/
	$(GRUBMK) -o $(ISO) $(ISO_DIR)
	find $(SRC_DIR) -type f -name '*.o' -delete
	find $(SRC_DIR) -type f -name '*.d' -delete

# === Run in QEMU (optional) ===
run:
	qemu-system-i386 -cdrom $(ISO)

# === Clean ===
clean:
	rm -f $(KERNEL)
	find $(SRC_DIR) -type f -name '*.o' -delete
	find $(SRC_DIR) -type f -name '*.d' -delete
	rm -f $(ISO)
