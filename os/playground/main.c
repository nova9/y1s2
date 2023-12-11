#include <unistd.h>
#include <stdio.h>

int main()
{
    int id = fork();

    if (id)
    {
        sleep(1);
        printf("%d\n", id);
    }
    else
    {

        printf("child\n");
    }
}