/*Libraries*/

/*open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*read and write*/
#include <unistd.h>

/**
 *create_file - reads a text file and prints it to the POSIX standard output.
 *@filename: pointer to the string of the name of the file
 *@text_content: a NULL terminated string to write to the file
 *Return: 1 on success, -1 on failure
 */

int create_file(const char *filename, char *text_content)
{
	int fileDesc, numBytes, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
	{
		text_content = "";
	}
	while (*(text_content + len) != '\0')
		len++;

	/*Open*/
	fileDesc = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fileDesc == -1)
	{
		return (-1);
	}

	/*Write*/
	numBytes = write(fileDesc, text_content, len);
	if (numBytes == -1)
	{
		close(fileDesc);
		return (-1);
	}
	close(fileDesc);
	return (1);
}
