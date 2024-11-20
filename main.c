#include "get_next_line_bonus.h"
#include "get_next_line.h"
#include <stdio.h>

int main()
{
    int fd = 1;
    char *line;

    while ((line = get_next_line(fd)))
        printf("%s", line);
}
