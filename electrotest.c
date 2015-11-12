#include <stdlib.h>
#include <stdio.h>

// Prototyper
float calc_power_r (float volt, float resistance);
float calc_power_i (float volt, float current);
int e_resistance(float orig_resistance, float *res_array);


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
	
//Fix me: resistance ska ändras till det vi kallar ersättningsmotståndet.
	watt = calc_power_i(volt, resistance);
	printf("Effekt: %f", watt);
	

	// Skriv ut ersättningsresistanser i E12serien
	printf("Ersättningsresistanser i E12­serien kopplade i serie:");
	// Vi återanvänder resistorArray, så vi nollar alla värden för säkerhets skull
	int indx = 0; // index variabel att använda vid loopar
	for (indx = 0; indx < (int)(sizeof(resistorArray)/sizeof(resistorArray[0])); indx++)
	{
		resistorArray[indx] = 0.0; // Nolla
	}
//Fix me: ändra variabel 'resistance' till det variabelnamn som motsvarar "Ersättningsresistans"
	// Anropa e_resistance med ersättningsresistansen och pekningen till resistorArray
	// och få tillbaka antalet ersättningsresistanser i E12serien samt att dess värden lagras i resistorArray
	int count = e_resistance(resistance, resistorArray);
	// Gå genom hela resistorArray och skriv ut dess innehåll
	for (indx = 0; indx < count; indx++)
	{
		printf(" %g", resistorArray[indx]);
		// Undersök om vi kommer skriva ut mer genom att undersöka om loopen är klar efter denna vända eller inte
		if (indx + 1 < count)
		{
			// Det kommer mera text, skriv ut separator
			printf(",");
		}
		else // Det kommer inte mera text, avsluta med en ny rad
		{
			printf("\n");
		}
	}

	// Frigör minnet som resistorArray har allokerat
	free(resistorArray);
    return 0;
}
