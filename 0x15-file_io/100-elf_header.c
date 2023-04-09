#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>


#define BUFFER_SIZE 128


void print_elf_header(Elf64_Ehdr *header)
{
	printf("ELF Header:\n");
	printf(" magic: ");
	for (int i = 0; i < EI_NIDENT; i++)
		print("%02 ", header->e_ident[i]);

	printf("\n class:	%s\n",
		header->e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" :
		header->e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" : "none");
	printf(" Data:	%s\n",
		header->e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement,little endian" :
		header->e_ident[EI_DATA] == ELFDATA2MSB ? "2'S complement, big endian" : "none");
	printf(" version:	%d (current)\n", header->e_version);
	printf(" OS/ABI:	");
	switch (header->e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV: printf("UNIX - system V\n");

					break;
		case ELFOSABI_HPUX: printf("UNIX - HP-UX\n");
					break;
		case ELFOSABI_NETBSD: printf("UNIX - NetBSD\n");
					break;
		case ELFOBASI_LINUX: printf("UNIX - linux\n");
					break;
		default: printf("UNIX - none\n");
					break;
	}

	printf("ABI Version:	%d\n", header->e_ident[EI_ABIVERSION]);
	printf("Type:	");
	switch (header->e_type)
	{
		case ET_NONE: printf("none (Unknown type\n");
				break;
		case ET_REL: printf("REL (Relocatable file)\n");
				break;
		case ET_EXEC: printf("EXEC (Executable file)\n");
				break;
		case ET_DYN: printf("DYN (shared object file)\n");
				break;
		default: printf("%#\n", header->e_type);
				break;
	}
	printf("Enry point address:	%#lx\n", header->e_entry);
}

int main(int argc, char **argv)
{
	int fd;
	char buffer[BUFFER_SIZE];
	Elf64_Edhr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage:%s elf_filename\n", argv[0]);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);

	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: cannot open file %s\n", argv[1]);
		exit(98);
	}

	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: cannot read ELF header from file %s\n", argv[1]);
		exit(98);
	}

	if (header.e_ident[EI_MAGO] != ELFMAGO ||
			header.e_ident[EI_MAG1] != ELFMAG1 ||
			header.e_ident[EI_MAG2] != ELFMAG2 ||
			header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: file %s is not an ELF file\n", argv[1]);
		exit(98);
	}
}

