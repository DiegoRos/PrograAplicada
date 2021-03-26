#include "defInsertion.h"

void insertionSort(int arr[], int n);
void printArray(int arr[], int n);

int main (int argc, char *argv[]){
	int array[] = {6,4,7,8,9,1,2,3,5};

	int n = (int) (sizeof(array)/sizeof(int));


	printArray(array, n);
	insertionSort(array, n);
	printArray(array, n);
	
	return 0;
}
