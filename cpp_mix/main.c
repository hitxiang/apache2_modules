#include "animal.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   // if (argc < 2) exit(EXIT_FAILURE);
    Animal *a = animal_create_init(25, 1.83); // 6'0" 25yo (perhaps a human? :P)
    animal_setage(a, 26); // birthday
    printf("Age: %d\nHeight: %f\n", animal_getage(a), animal_getheight(a));
    exit(EXIT_SUCCESS);
}
