#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * check_elf - a function that checks if a file is an ELF file
 * @ident: input pointer
 * Desc: if file is not ELF file - exit 98
 */

void check_elf(unsigned char *ident)
{
	int i;

	for (i = 0; i < 4; i++)
	{
		if (ident[i] != 127 && ident[i] != 'E' && ident[i] != 'L' && ident[i] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - a function that prints magic numbers of an ELF
 * @ident: input pointer
 * Desc: the magic numbers separated by spaces
 */

void print_magic(unsigned char *ident)
{
	int i;

	printf("Magic: ");

	for (i = 0; i < EI_NIDENT; i++)
	{
		printf("%02x", ident[i]);

		if (i == EI_NIDENT - 1)
		{
			printf("\n");
		}
		else
			printf(" ");
	}
}

/**
 * print_class - a function that prints class of an ELF
 * @ident: input pointer
 */

void print_class(unsigned char *ident)
{
	printf(" Class: ");

	switch (ident[EI_CLASS])
	{
		case ELFCLASSNONE:
			printf("none\n");
			break;
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * print_data - a function that prints data of an ELF
 * @ident: input pointer
 */

void print_data(unsigned char *ident)
{
	printf(" Data: ");

	switch (ident[EI_DATA])
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
			printf("<unknown: %x>\n", ident[EI_CLASS]);
	}
}

/**
 * print_version - a function that prints a version of an ELF
 * @ident: input pointer
 */

void print_version(unsigned char *ident)
{
	printf(" Version: %d", ident[EI_VERSION]);

	switch (ident[EI_VERSION])
	{
		case EV_CURRENT:
			printf(" (current)\n");
			break;
		default:
			printf("\n");
			break;
	}
}

/**
 * print_osabi - a function that prints OS/ABI of an ELF
 * @ident: input pointer
 */

void print_osabi(unsigned char *ident)
{
	printf(" OS/ABI: ");

	switch (ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - system v\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
			break;
		case ELFOSABI_NETBSD:
			printf("UNIX - NETBSD\n");
			break;
		case ELFOSABI_LINUX:
			printf("UNIX - LINUX\n");
			break;
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_SOLARIS:
			printf("UNIX - SOLARIS\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FREEBSD\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf(" STANDALONE APP\n");
			break;
		default:
			printf("<unknown: %x>\n", ident[EI_OSABI]);
	}
}

/**
 * print_abi_and_type - function that prints abi version
 * and type of ELF
 * @type: ELF type
 * @ident: pointer to an array
 */

void print_abi_and_type(unsigned int type, unsigned char *ident)
{
	printf(" ABI Version: %d\n", ident[EI_ABIVERSION]);

	if (ident[EI_DATA] == ELFDATA2MSB)
		type >>= 8;
	printf("Type: ");

	switch (type)
	{
		case T_NONE:
			printf("NONE (None)\n");
			break;
		case T_REL:
			printf("REL (Relocatable file)\n");
			break;
		case T_EXEC:
			printf("EXEC (Executable file)\n");
			break;
		case T_CORE:
			printf("CORE (Core file)\n");
			break;
		case T_DYN:
			printf("DYN (Shared object file)\n")
				break;
		default:
			printf("<unknown: %x>\n", type);
	}
}

/**
 * print_entry - function that print entry point
 * @e_entry: input address
 * @e_ident: input pointer
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & OxFFOOFFOO) | ((e_entry >> 8) & OxFFOOFF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#Ix\n", e_entry);
}

/**
 * close_elf_and_main -function that close an elf and
 * of the program displaying information
 * @argv: array of pointers to arguments
 * @argc: number of arguments
 * Return: 0
 */

int close_elf_and_main(int argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
		exit(98);
	}
	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: %s : No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("Elf Header:\n");
	print_magic(header->ident);
	print_class(header->ident);
	print_data(header->ident);
	print_version(header->ident);
	print_osabi(header->ident);
	print_abi(header->ident);
	print_type(heaer->type, header->ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
