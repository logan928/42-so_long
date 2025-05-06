
#include <fcntl.h>      // open()
#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include "get_next_line.h"  // Your GNL header file

int main(int argc, char **argv)
{
    int fd;
    char *line;
   // int loopcount = 0;

    if (argc != 2) 
    {
        printf("Usage: %s test.txt\n", argv[0]);
        return (1);
    }

    fd = open(argv[1], O_RDONLY);
    if (fd == -1)  
    {
        perror("Error opening file");
        return (1);
    }

    printf("Reading file: %s (BUFFER_SIZE = %d) %d \n\n", argv[1], BUFFER_SIZE, fd);


    while ((line = get_next_line(fd)))  
    {
        printf("%s", line);  
        free(line);  
    }
    if (!line)
        printf("gnl returned NULL \n");
    close(fd);  
    return (0);
}

