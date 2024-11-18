#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/*int main(void)
{
    int fd1, fd2, fd3;
    char *line;

    fd1 = open("file1.txt", O_RDONLY);
    fd2 = open("file2.txt", O_RDONLY);
    fd3 = open("file3.txt", O_RDONLY);

    while ((line = get_next_line(fd1)) != NULL)
        printf("%s", line);
    while ((line = get_next_line(fd2)) != NULL)
        printf("%s", line);
    while ((line = get_next_line(fd3)) != NULL)
        printf("%s", line);
}
*/

int main()
{
    int fd = 1;
    char *line;

    while ((line = get_next_line(fd)) != NULL)
        printf("%s", line);
}