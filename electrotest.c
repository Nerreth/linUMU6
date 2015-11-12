#include <stdlib.h>
#include <stdio.h>

float calc_power_r (float volt, float resistance);
float calc_power_i (float volt, float current);


int main(int argc, const char *argv[])
{
    float   volt = 0.0f;
    float   current = 0.0f;
	float 	watt = 0.0;
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
	
	//resistance ska ändras till det vi kallar ersättningsmotståndet.
	watt = calc_power_i(volt, resistance); 
	printf("Effekt: %f", watt);
	
    return 0;
}
