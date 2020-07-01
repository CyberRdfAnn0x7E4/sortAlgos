/* sort.c */

#include "sort.h"

void bubbleSort(int* zahlen, int len)
{
    int i,j;
    int tausch = 0;
    int tmp;

    for(j=0;j<len;j++)  // wird N durchlaufen
    {
        tausch = 0;

        for(i=0;i<len-1-j;i++)
        {
            if(zahlen[i]>zahlen[i+1])
            {
                tmp = zahlen[i];
                zahlen[i] = zahlen[i+1];
                zahlen[i+1] = tmp;

                tausch++;
            }
        }

        if(tausch == 0)
        {
            break;
        }
    }
}

void insertSort(int* zahlen, int len)
{
    int i,j;
    int wohin;
    int tmp;

    for(i=1;i<len;i++)
    {
        wohin = i;
        tmp = zahlen[i];

        for(j=0;j<i;j++)
        {
           if(zahlen[i]<zahlen[j])
           {
               wohin = j;
               break;
           }
        }

        for(j=i;j>wohin;j--)
        {
            zahlen[j]=zahlen[j-1];
        }

        zahlen[wohin] = tmp;
    }
}

void myInsertSort(int* zahlen, int len){

	unsigned int i, k;
	int tausch;

	for(i = k = 1; i < len; k = ++i){

		while(k>0 && zahlen[k] < zahlen[k-1]){
			tausch = zahlen[k];
			zahlen[k] = zahlen[k-1];
			zahlen[k-1] = tausch;
			k--;
		}
	}
}

void shellSort(int* zahlen, int len){

	int teiler = 4, tausch, k;
	unsigned int segment = 0;
	unsigned int i;

	while(teiler > 0){
		for(segment = 0; segment < teiler; segment++){

			for(i = k = segment; i < len; k = (i += teiler)){

				while(k - teiler > 0 && zahlen[k] < zahlen[k-teiler]){
					tausch = zahlen[k];
					zahlen[k] = zahlen[k-teiler];
					zahlen[k-teiler] = tausch;
					k -= teiler;
				}
			}
		}
		teiler--;
	}
}


int teile(int* zahlen, int left, int right){

	int i = left, j = right - 1;
	int pivot = zahlen[right], tausch;

	while(i < j){

		while(i < right && zahlen[i] < pivot){
			i++;
		}
		while(j > left && zahlen[j] >= pivot){
			j--;
		}
		if(i < j){
			tausch = zahlen[i];
			zahlen[i] = zahlen[j];
			zahlen[j] = tausch;
		}
	}

	if(zahlen[i] > pivot){
		tausch = zahlen[i];
		zahlen[i] = pivot;
		zahlen[right] = tausch;
	}

	return i;
}

void _quickSort(int* zahlen, int left, int right){

	int teiler;

	if(left < right){
		teiler = teile(zahlen, left, right);
		_quickSort(zahlen, left, teiler -1);
		_quickSort(zahlen, teiler+1, right);
	}
}

void quickSort(int* zahlen, int len){

	_quickSort(zahlen, 0, len-1);
}
