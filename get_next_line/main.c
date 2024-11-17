#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>


int main(void)
{
    int     fd;
    char    *line;

	umask(0);
	
    fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);

    write(fd, "merhaba\n", 8);
	write(fd, "omer\n", 5);
	write(fd, "kuzu\n", 6);

    fd = open("example.txt", O_RDONLY);

    while (line = get_next_line(fd))
        printf("%s", line);
}