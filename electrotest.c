#include <stdlib.h>
#include <stdio.h>



int main(int argc, const char *argv[])
{
    float   volt = 0.0f;
    float   current = 0.0f;
    char    connectionType = 0;
    int     resistorCount = 0;
    float*  resistorArray = 0;

    printf("Ange spänning i Volt: ");
    scanf("%f", &volt);

    printf("Ange koppling [S | P]: ");
    scanf("%s", &connectionType);

    printf("Antal komponenter: ");
    scanf("%d", &resistorCount);

    resistorArray = malloc(3 * sizeof(float));

    for (int i = 0; i < resistorCount; ++i)
    {
        printf("Komponent %d i ohm: ", i + 1);
        scanf("%f", &resistorArray[i]);
    }
    return 0;
}
