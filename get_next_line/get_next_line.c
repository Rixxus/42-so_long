/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:25:58 by rmount            #+#    #+#             */
/*   Updated: 2023/03/12 10:27:30 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* This function takes a char pointer and a char and searches for the first
	occurrence of the char in the string. If an occurrence is found, the
	pointer to it is returned. If the character is not found, NULL is returned.
*/
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (!c)
	{
		return ((char *)s);
	}
	return (0);
}

/* This function is called from get_next_line takes the line pointer which
contains everything that was read from the buffer. It traverses line until
finding a null or new line character, then uses ft_substring to write the
leftovers of the line (everything after the newline character) to the 
leftovers variable, appends a null-terminator and returns leftovers to 
	1. first while will increment i until we reach either a null-terminator
	or a new line character. 
	2. while loop has two conditions: 
	if the i index of line is null, it means we have reached the end of 
	the file. if i index is a new line character, we have reached the 
	end of the line and need to check what is following the new line character.
	3. if has two conditions:
	the first is true if line at index i is null, which means we
	have reached the end of the file and we return NULL.
	the second condition is only true if line at index i is a new
	line character, and the following index is null - which should
	only occur on the last null terminator in the file.
	4. leftovers is assigned the return value of calling ft_substr 
	passing line, i + 1, and the length of line - 1.
*/
static char	*get_leftovers(char *line)
{
	char	*leftovers;
	size_t	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		i++;
	}
	if (!line[i] || !line[1])
	{
		return (NULL);
	}
	leftovers = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!*leftovers)
	{
		free(leftovers);
		leftovers = NULL;
	}
	line[i + 1] = '\0';
	return (leftovers);
}

/* This function ...
   bytes_read is a counter for the number of bytes we read
   floor_tile is temp storage - like a sim. or me.
	1. bytes_read is initialised to 1 to ensure the following while loop
	is entered.
	2. while loop remains true as long as bytes_read does not equal zero.
	if bytes_read becomes equal to zero, it means we have reached the end of
	the file.
	3. bytes_read is intialised with the return of the read function passing
	fd, buffer and BUFFER_SIZE which returns an integer of the number of bytes
	it was able to read. 
	
	4. The read function takes the file descriptor, the buffer 
	pointer and BUFFER_SIZE and writes BUFFER_SIZE number of bytes from the 
	file matching the fd to the the buffer pointer.  
	5. if bytes_read equals -1 it means that there was an error calling the
	read function and read_up_to_buffer will return NULL to get_next_line.
	6. if bytes_read equals zero, it means we have reached the end of the
	file we are reading, in which case we break out of the loop and pick up
	at the next line of code outside the else if.
   7. buffer at index bytes_read is set to null as we need to assign 
   it a null terminating character to show where the line ends.
   8. backlog is null to begin with, so we set it to the return value of
   ft_strdup passing an empty string. ft_strdup will then "duplicate" 
   the empty string and append a null-terminator to it. backlog now
   has only a "\0" in it.
   9. floor_tile is assigned the value of backlog and will hold it
   while we join it to the buffer.
   10. backlog is set with the return value of a call to ft_strjoin
   passing floor_tile and buffer, which joins whatever is in the buffer
   to the end of what is in floor_tile. 
   11. floor_tile is freed as its content has been added to the 
   backlog and its value set to NULL in preparation for the next
   call to read_up_to_buffer.
   12. if loop calls ft_strchr passing buffer and the newline
   character, which checks if the newline character is anywhere in
   the buffer. If it is found, we break out of the while loop.
   13. backlog is returned to where read_up_to_buffer was called in 
   get_next_line.
*/

static char	*read_up_to_buffer(int fd, char *buffer, char *backlog)
{
	int		bytes_read;
	char	*floor_tile;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		if (!backlog)
			backlog = ft_strdup("");
		floor_tile = backlog;
		backlog = ft_strjoin(floor_tile, buffer);
		free(floor_tile);
		floor_tile = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (backlog);
}

/* This function takes in the file descriptor of a file to read from.
   Three variables are created inside the function - a character pointer 'line',
   a character pointer 'buffer' and a static character pointer 'backlog'.
   
   *line will 
   *buffer will be initialised to the size required to hold the BUFFER_SIZE
   *backlog is a static variable - this means that it remembers its value 
   throughout the entire lifetime of the program and not just in its 
   particular scope.
   BUFFER_SIZE is passed in when the program is compiled.
   1. if statement checks whether the value of fd is less than zero - not a valid
   file - or the BUFFER_SIZE passed in is less than or equal to zero - not a 
   valid length. If either of these conditions are true, get_next_line returns
   NULL and ends.
   2. buffer is initialised with memory allocated the size of the
   BUFFER_SIZE +1 for the null-terminating character.
   3. if !buffer is true, it means the malloc has failed, so get_next_line 
   returns null and ends.
   4. line is initialised with a call to the function 'read_up_to_buffer' - 
   which is passed the file descripter, buffer and backlog variables.
   NOTE: while it looks like the line, buffer and backlog variables are
   being passed by value rather than reference
   5. free(buffer) is called to free the memory that was malloced to the 
   buffer variable.
   6. buffer is set to null for the next time get_next_line is called.
   7. if !line is true, read_up_to_buffer has either failed or the end
   of the file has been reached, in which case get_next_line returns 
   NULL and ends.
   8. backlog is a static pointer and is used to remember where in the
   file we are up to. It is initialised with the return from the function 
   get_leftovers, which is passed the line variable when called.
*/

char	*get_next_line(int fd)
{
	char		*line;
	char		*buffer;
	static char	*backlog;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
	{
		return (NULL);
	}
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
	{
		return (NULL);
	}
	line = read_up_to_buffer(fd, buffer, backlog);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		return (NULL);
	}
	backlog = get_leftovers(line);
	return (line);
}