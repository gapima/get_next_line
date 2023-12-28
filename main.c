#include <stdio.h>
#include <fcntl.h>
//#include "get_next_line_bonus.h"
#include "get_next_line.h"
int main()
{

    int teste = open("teste.txt", O_RDONLY);
    printf("%d\n", teste);
    char *str = get_next_line(teste);
    printf("%s\n", str);
    free(str);

    str = get_next_line(teste);
    printf("%s\n", str);
    free(str);
    str = get_next_line(teste);
    printf("%s\n", str);
    free(str);
    str = get_next_line(teste);
    printf("%s\n", str);
    free(str);
    close(teste);
}