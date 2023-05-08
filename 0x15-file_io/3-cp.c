/*Libraries*/

/*open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*read and write*/
#include <unistd.h>

/*malloc, free*/
#include <stdlib.h>

/*dprintf*/
#include <stdio.h>

/*prototypes*/
void create_fail(char *file);
void write_fail(char *file);
void close_fail(int file);

/**
 *main - copies a file
 *@argc: number of arguments
 *@argv: arguments
 *Return: 0 on success
 */

int main(int argc, char *argv[])
{
	int fileDesc, numBytes, newFiledesc, endFile, endNewfile;
	char *filename, *buffer, *newFilename;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	buffer = malloc(1024 * sizeof(char));
	if (buffer == NULL)
		return (-1);
	newFilename = *(argv + 2);
	filename = *(argv + 1);
	fileDesc = open(filename, O_RDONLY);
	if (fileDesc == -1)
	{
		free(buffer);
		create_fail(filename);
	}
	newFiledesc = open(newFilename, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	if (newFiledesc == -1)
	{
		free(buffer);
		write_fail(newFilename);
	}
	do {
		numBytes = read(fileDesc, buffer, sizeof(char) * 1024);
		if (numBytes == -1)
		{
			free(buffer);
			create_fail(filename);
		}
		numBytes = write(newFiledesc, buffer, numBytes);
		if (numBytes == -1)
		{
			free(buffer);
			write_fail(newFilename);
		}
	} while (numBytes == 1024);
	free(buffer);
	endNewfile = close(newFiledesc);
	endNewfile == -1 ? close_fail(newFiledesc) : (void)0;
	endFile = close(fileDesc);
	endFile == -1 ? close_fail(fileDesc) : (void)0;
	return (0);
}

/**
 *close_fail - cant close a file
 *@file: file descriptor that couldnt be closed
 *Return: none
 */

void close_fail(int file)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %i\n", file);
	exit(100);
}

/**
 *create_fail - cant create a file
 *@file: file name
 *Return: none
 */

void create_fail(char *file)
{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		exit(98);
}

/**
 *write_fail - cant create a file
 *@file: file name
 *Return: none
 */

void write_fail(char *file)
{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		exit(99);
}
