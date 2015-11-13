#include <stdlib.h>
#include <stdio.h>

// Prototyper
float calc_power_r (float volt, float resistance);
float calc_power_i (float volt, float current);
int e_resistance(float orig_resistance, float *res_array);
float calc_resistance(int count, char conn, float* array);


int main(int argc, const char *argv[])
{
    float   volt = 0.0f;
    float   current = 0.0f;
    float   watt = 0.0;
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

    int i;
    for (i = 0; i < resistorCount; ++i)
    {
        printf("Komponent %d i ohm: ", i + 1);
        scanf("%f", &resistorArray[i]);
    }

    float substitutResistance = calc_resistance(resistorCount, connectionType
                                                , resistorArray);

    if (substitutResistance < 0)
    {
        printf("En eller flera argument är icke gilltiga. Programmet avslutas.\n");
        free(resistorArray);
        return 0;
    }
    else
    {
        printf("Ersättningsresistans: %f\n", substitutResistance);
    }


    watt = calc_power_r(volt, substitutResistance);
    printf("Effekt: %f\n", watt);

	// Skriv ut ersättningsresistanser i E12serien
	printf("Ersättningsresistanser i E12­serien kopplade i serie:");

    float replacementArray[3] = {};
	// Anropa e_resistance med ersättningsresistansen och pekningen till
    // repacementArray
	// och få tillbaka antalet ersättningsresistanser i E12serien samt att dess värden lagras i replacementArray
	int count = e_resistance(substitutResistance, replacementArray);
	// Gå genom hela replacementArray och skriv ut dess innehåll
	int indx = 0; // index variabel att använda vid loopar
	for (indx = 0; indx < count; indx++)
	{
		printf(" %g", replacementArray[indx]);
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
