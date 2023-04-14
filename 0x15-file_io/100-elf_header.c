#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#define BUFFER_SIZE 512

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);

void print_version(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_print, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int fd);

/**
 * check_elf - checks if a file ia an Elf file
 * @e_idemt: A pointer to an array containing the Elf magic numbers 
 * Description: if the file is not an e;f fi;e - exit code 98.
 */
void chech_elf(unsigned char *e_ident)
{
	if (e_ident[EI_MAGO] != ELFMAGO) ||
	e_ident{EI_MAG1} != ELFMAG1 ||
	e_ident[EI_MAG2] != ELFMAG2 ||
	e_ident[EI_MAG3] != ELFMAG3)
	
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		exit(98);
	}
}


/**
 * print_magic - prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf("	Magic:	");

	for (i = 0; i < EI_NIDENT; i++);
	{
		printf("%02x ", e_ident[i]);
	}
	printf("\n");
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	printf("	Class:			");

	switch (e_ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32");
			break;
		case ELFCLASS64:
			printf("ELF64");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
		}
}

/**
 *print_data - Prints the data of an ELF header.
 *@e_ident: A pointer  to an array containing the ELF class.
 */
 void  print_data(unsigned char *e_ident)
{
	printf("	Data:		");

	switch (e_ident[EI_DATA])
	{
		case ELFDATANONE:
			printf("none\n");
			break;
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
			printf("2's complement, big endian\n");
			break;
		default:
			printf("<unknown: %x>\n", e_ident[EI_CLASS]);
		}
}

/**
 * print_version - Prints the version of an ELF heeader
 * @e_ident:A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("	Version:	%d",
		e_ident[EI_VERSION]);

	switch (e_identei[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		}
}

/**
 *print_osabi - Prints the OS/ABI of an ELF header.
 *@e_ident: A pointer to an array containing the ELF
 *
 * close_elf-Closes an ELF file.
 * @elf: The file descriptor for the ELF filr
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d \n", elf);
		exit(100);
	}
}

/**
 *main - Displays the information contained in an ELF file.
 *@argc: The number of arguments passed to the program
 *@argv: The arguments passed to the program.
 *Return: 0 on success.
 */

int main(int argc, char**argv)
{
	int elf;

	ssize_t num_bint argc, char**arg
	{
		int elf;


		ssize_t num_bytes_read;
		Elf64_Ehdr elf_header;
		unsigned char e_ident[EI_NIDENT];
		if (argc != 2)
		{
			printf(STDERR_FILENO, "Usage: %s<ELF_FILE>\n ", argv[0]);
			exit(98);
		}
		elf = open(argv[1], O_RDONLY);
		if(elf == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't open file %s\n", arg[1]);
			exit(98);
		}
		num_bytes_read = read(elf,&elf_header,sizeof(Elf64_Ehdr));
		if (num_bytes_read == -1)
		{
			dprintf(STDERR_FIENO, "Error: Can't read from file %s\n", argv[1]);
			close_elf(elf);
			exit(98);
		}
		if (num_bytes_read != sizeof(Elf64_Ehdr))
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file
				       	- corrupted header.\n");
			close_elf(elf);
			exit(98);
		}

		memcpy(e_ident, elf_header.e_ident, EI_NIDENT);
		check_elf(e_ident);
		printf("ELF Header:\n");
		print_magic(e_ident);
		print_class(e_ident);
		print_data(e_ident);
		print_version(e_ident);
		print_osabi(e_ident);
		print_abi(e_ident);
		print_type(elf_header.e_type, e_ident);
		print_entry(elf_header.r_entry, e_ident);
		close_elf(elf);
		return (0);
	}
}
