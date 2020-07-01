#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"

#define MAXDIM 1000000
#define DEBUG 0

void iniZahlen(int** zahlen){
	*zahlen = (int*)calloc(MAXDIM,sizeof(int));

	if(zahlen == NULL)
	{
		printf("Allokationsfehler fuer zahlen!\n");
		exit(1);
	}
}

void print(int* zahlen, int anzahl){

	unsigned int i;

	for(i=0;i<anzahl;i++)
	{
		printf("%d ",zahlen[i]);
	}

	printf("\n");

}

int main(int argc, char *argv[])
{
	int* zahlenBubbleSort;
	int* zahlenInsertSort;
	int* zahlenMyInsertSort;
	int* zahlenShellSort;
	int* zahlenQuickSort;
    int i;
    double start;
    double ende;
    int anzahl;

	iniZahlen(&zahlenBubbleSort);
	iniZahlen(&zahlenInsertSort);
	iniZahlen(&zahlenMyInsertSort);
	iniZahlen(&zahlenShellSort);
	iniZahlen(&zahlenQuickSort);

    srand(1);

	printf("\nanzahl\tbubbleSort\tInsertsort\tmyInsertSort\tshellSort\tquickSort");
	printf("\n---------------------------------------------------------------------------");

    for(anzahl = 100; anzahl < MAXDIM; anzahl *= 2)
    {
        printf("\n%d",anzahl);

        for(i=0;i<anzahl;i++)
        {
			zahlenBubbleSort[i] = rand();
			zahlenInsertSort[i] = zahlenQuickSort[i] = zahlenMyInsertSort[i] = zahlenShellSort[i] = zahlenBubbleSort[i];
        }

        if(DEBUG)
        {
			printf("unsortiert:\n");
			print(zahlenBubbleSort, anzahl);
        }

        start = (double)clock()/(double)CLOCKS_PER_SEC;
		bubbleSort(zahlenBubbleSort,anzahl);
        ende = (double)clock()/(double)CLOCKS_PER_SEC;

		printf("\t%09.4lf s",ende-start);

        start = (double)clock()/(double)CLOCKS_PER_SEC;
		insertSort(zahlenInsertSort,anzahl);
        ende = (double)clock()/(double)CLOCKS_PER_SEC;

		printf("\t%09.4lf s",ende-start);

		start = (double)clock()/(double)CLOCKS_PER_SEC;
		myInsertSort(zahlenMyInsertSort,anzahl);
		ende = (double)clock()/(double)CLOCKS_PER_SEC;

		printf("\t%09.4lf s",ende-start);

		start = (double)clock()/(double)CLOCKS_PER_SEC;
		shellSort(zahlenShellSort,anzahl);
		ende = (double)clock()/(double)CLOCKS_PER_SEC;

		printf("\t%09.4lf s",ende-start);

		start = (double)clock()/(double)CLOCKS_PER_SEC;
		quickSort(zahlenQuickSort,anzahl);
		ende = (double)clock()/(double)CLOCKS_PER_SEC;

		printf("\t%09.4lf s",ende-start);

        if(DEBUG)
        {
			printf("sortiert myInsert:\n");
			print(zahlenBubbleSort, anzahl);

            printf("sortiert Insertsort:\n");
			print(zahlenInsertSort, anzahl);
        }
    }

	free(zahlenBubbleSort);
	free(zahlenInsertSort);
	free(zahlenQuickSort);
	free(zahlenShellSort);
	free(zahlenMyInsertSort);

    return 0;
}
