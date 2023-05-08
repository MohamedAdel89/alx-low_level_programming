#ifndef _MAIN_H
#define _MAIN_H

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <errno.h>
#include <string.h>
#include <elf.h>
int append_text_to_file(const char *filename, char *text_content);
int create_file(const char *filename, char *text_content);
ssize_t read_textfile(const char *filename, size_t letters);
#endif


#define EI_NIDENT 16
typedef struct {
                unsigned char e_ident[EI_NIDENT];
         	uint16_t e_type;
 		uint16_t e_machine;
	        uint32_t e_version;
	        uint64_t e_entry;
	        uint64_t e_phoff;
	        uint64_t e_shoff;
		uint32_t e_flags;
	        uint16_t e_ehsize;
	        uint16_t e_phentsize;
	        uint16_t e_phnum;
	        uint16_t e_shentsize;
	        uint16_t e_shnum;
	        uint16_t e_shstrndx;
	      } Elf64_Ehdr;
#endif
