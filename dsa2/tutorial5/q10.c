#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void *array;
    int elementSize;
    int capacity;
    int size;
} Array;

Array createArray(int elementSize, int capacity)
{
    Array array;
    array.array = malloc(elementSize * capacity);
    array.capacity = capacity;
    array.elementSize = elementSize;
    array.size = 0;
    return array;
}

int main()
{

}