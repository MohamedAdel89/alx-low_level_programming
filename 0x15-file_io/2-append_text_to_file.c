/*Libraries*/

/*open*/
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*read and write*/
#include <unistd.h>

/**
 *append_text_to_file - appends text at the end of a file
 *@filename: pointer to the string of the name of the file
 *@text_content: a NULL terminated string to write to the file
 *Return: 1 on success, -1 on failure
 */

int append_text_to_file(const char *filename, char *text_content)
{
	int fileDesc, numBytes, len = 0;

	if (filename == NULL)
		return (-1);
	if (text_content == NULL)
	{
		if (open(filename, O_WRONLY | O_APPEND) == -1)
			return (-1);
		else
			return (1);
	}

	while (*(text_content + len) != '\0')
		len++;

	/*Open*/
	fileDesc = open(filename, O_WRONLY | O_APPEND);
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
