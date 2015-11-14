#include <stdlib.h>
#include <stdio.h>

// Prototyper
float calc_power_r (float volt, float resistance);
float calc_power_i (float volt, float current);
int e_resistance(float orig_resistance, float *res_array);
float calc_resistance(int count, char conn, float* array);

/*
 * - beräkna resistans(ohm) från ett antal resistorer i serie eller parallell
 * - beräkna effekten(watt) från resistansen ovan samt spänningen(volt)
 * - beräkna vilka, upp till, tre E12 resistorer man kan använda för att
 *   ersätta den förstnämnda resistansen
 */
int main()
{
	// Deklarera och initiera
    float   volt = 0.0f; // Antalet volt
    float   current = 0.0f; // Antalet ampere
    float   watt = 0.0f; // Antalet watt
    char    connectionType = 0; // Kopplingstyp, (0)serie och (1)parallell
    int     resistorCount = 0; // Antalet resistorer
    float*  resistorArray = 0; // Pekare för resistansen för varje resistor
    float*  replacementArray = 0; // Pekare för resistansen för varje E12 resistor
    int		i = 0; // Index, används av loopar

    // Be användaren ange antalet volt
    printf("Ange spänning i Volt: ");
    scanf("%f", &volt);

    // Be användaren ange kopplingstyp
    printf("Ange koppling [S | P]: ");
    scanf("%s", &connectionType);

    // Be användare ange antalet resistorer
    printf("Antal komponenter: ");
    scanf("%d", &resistorCount);

    // Allokera minne för resistorernas resistans, mängden är dynamisk och baseras på antalet resistorer
    resistorArray = malloc(resistorCount * sizeof(float));

    // Be användaren ange resistansen för varje resistor och spara varje värde som ett array-element
    for (i = 0; i < resistorCount; ++i)
    {
        printf("Komponent %d i ohm: ", i + 1); // Läsvänlig omvandling, för array börjar räkning från 0
        scanf("%f", &resistorArray[i]);
    }

    // Anropa beräkning av den totala resistansen baserat på vad användaren har angivit
    // Spara resultatet i substitutResistance
    float substitutResistance = calc_resistance(resistorCount, connectionType
                                                , resistorArray);
    // Validera resultatet från resistansberäkning, vi vill aldrig ha negativ resistans
    if (substitutResistance < 0)
    {
        printf("En eller flera argument är icke gilltiga. Programmet avslutas.\n");
        free(resistorArray); // Frigör allokerat minne
        return 0;
    }
    else // Valideringen lyckades, vi kan fortsätta
    {
    	// Presentera den totala resistansen för användaren, begränsa till två decimaler
        printf("Ersättningsresistans: %.2f ohm\n", substitutResistance);
    }

    // Anropa beräkning av watt baserat på vad användaren angivit
    watt = calc_power_r(volt, substitutResistance);
    // Presentera watten för användaren, begränsa till två decimaler
    printf("Effekt: %.2f W\n", watt);

	// Skriv ut ersättningsresistanser i E12serien
	printf("Ersättningsresistanser i E12­serien kopplade i serie:");
	// Allokera minne för replacementArray så den kan spara 3 element
    replacementArray = malloc(3 * sizeof(float));
	// Anropa e_resistance med ersättningsresistansen och pekningen till repacementArray
	// och få tillbaka antalet ersättningsresistanser i E12serien samt att dess värden lagras i replacementArray
	int count = e_resistance(substitutResistance, replacementArray);
	// Gå genom hela replacementArray och skriv ut dess innehåll
	for (i = 0; i < count; i++)
	{
		printf(" %g", replacementArray[i]);
		// Undersök om vi kommer skriva ut mer genom att undersöka om loopen är klar efter denna vända eller inte
		if (i + 1 < count)
		{
			// Det kommer mera text, skriv ut separator
			printf(",");
		}
		else // Det kommer inte mera text, avsluta med en ny rad
		{
			printf("\n");
		}
	}

	// Frigör minnet som resistorArray och replacementArray har allokerat
	free(resistorArray);
	free(replacementArray);
    return 0;
}
