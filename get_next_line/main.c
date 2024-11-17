#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include "get_next_line.h"

int main(void)
{
    int fd;
    char *s;

    umask(0);
    fd = open("example.txt", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    write(fd, "omer\nfaruk\nkuzu\n\n", 18);

    fd = open("example.txt", O_RDONLY);
    while ((s = get_next_line(fd)) != NULL)
        printf("%s", s);
}