/*Libraries*/

/*open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*read and write*/
#include <unistd.h>

/*malloc*/
#include <stdlib.h>

/**
 *read_textfile - reads a text file and prints it to the POSIX standard output.
 *@filename: pointer to the string of the name of the file
 *@letters: number of letters it should read and print
 *Return: actual number of letters it could read and print
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fileDesc;
	char *buffer = malloc((sizeof(char) * letters));
	int numBytes;

	if (buffer == NULL || filename == NULL)
		return (0);

	/*Open*/
	fileDesc = open(filename, O_RDONLY);
	if (fileDesc == -1)
	{
		free(buffer);
		return (0);
	}

	/*Read*/
	numBytes = read(fileDesc, buffer, sizeof(char) * letters);
	if (numBytes == -1)
	{
		free(buffer);
		close(fileDesc);
		return (0);
	}

	/*Write*/
	numBytes = write(STDOUT_FILENO, buffer, numBytes);
	if (numBytes == -1)
	{
		free(buffer);
		close(fileDesc);
		return (0);
	}
	free(buffer);
	close(fileDesc);
	return (numBytes);
}
