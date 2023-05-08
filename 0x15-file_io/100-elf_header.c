#include "main.h"
void print_elf_header(const char* elf_filename) {
    int fd = open(elf_filename, O_RDONLY);
    if (fd == -1) {
        fprintf(stderr, "Failed to open file: %s (%s)\n", elf_filename, strerror(errno));
        exit(98);
    }
    
    Elf64_Ehdr elf_header;
    if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header)) {
        fprintf(stderr, "Failed to read ELF header: %s (%s)\n", elf_filename, strerror(errno));
        close(fd);
        exit(98);
    }
    
    if (memcmp(elf_header.e_ident, "\177ELF", 4) != 0) {
        fprintf(stderr, "Not an ELF file: %s\n", elf_filename);
        close(fd);
        exit(98);
    }
    
    printf("Magic:   ");
    for (int i = 0; i < EI_NIDENT; i++) {
        printf("%02x ", elf_header.e_ident[i]);
    }
    printf("\n");
    
    printf("Class:                             ");
    switch (elf_header.e_ident[EI_CLASS]) {
        case ELFCLASS32:
            printf("ELF32\n");
            break;
        case ELFCLASS64:
            printf("ELF64\n");
            break;
        default:
            printf("Invalid class\n");
            break;
    }
    
    printf("Data:                              ");
    switch (elf_header.e_ident[EI_DATA]) {
        case ELFDATA2LSB:
            printf("2's complement, little endian\n");
            break;
        case ELFDATA2MSB:
            printf("2's complement, big endian\n");
            break;
        default:
            printf("Invalid data encoding\n");
            break;
    }
    
    printf("Version:                           %d\n", elf_header.e_ident[EI_VERSION]);
    
    printf("OS/ABI:                            ");
    switch (elf_header.e_ident[EI_OSABI]) {
        case ELFOSABI_SYSV:
            printf("UNIX - System V\n");
            break;
        case ELFOSABI_HPUX:
            printf("HP-UX\n");
            break;
        case ELFOSABI_NETBSD:
            printf("NetBSD\n");
            break;
        case ELFOSABI_LINUX:
            printf("Linux\n");
            break;
        case ELFOSABI_SOLARIS:
            printf("Solaris\n");
            break;
        case ELFOSABI_IRIX:
            printf("IRIX\n");
            break;
        case ELFOSABI_FREEBSD:
            printf("FreeBSD\n");
            break;
        case ELFOSABI_OPENBSD:
            printf("OpenBSD\n");
            break;
        default:
            printf("Unknown\n");
            break;
    }
