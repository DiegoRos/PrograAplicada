#include "defInsertion.h"

void insertionSort(int arr[], int n){
	int i, j, key;

	for(i = 1; i < n; ++i){
		key = arr[i];
		j = i - 1;
		
		while(j >= 0 && arr[j] > key){
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void printArray(int arr[], int n){
	int i;
	printf("\n[");
	for(i = 0; i < n; ++i){
		(i < n-1) ? printf(" %d,", arr[i]) : printf(" %d", arr[i]);
	}
	printf(" ]\n");
	
}
