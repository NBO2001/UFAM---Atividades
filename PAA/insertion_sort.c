#include <stdio.h>

int insertionSort(int* A, int n){

  int pivo;
  int i;
  for(i=1; i < n; i++){

    pivo = A[i];

    int j = 0;
    while (j < i && A[i-1-j] > pivo)
    {
        A[i-j] = A[i-1-j];   
        j++;
    }

    A[i-j] = pivo;


  }

}

void printVector(int* A, int n){

    printf("{ ");
    for(int i=0; i < n; i++){
      printf("%d, ", A[i]);
    }
    printf(" }\n");
}

int main(){
  int arr[] = {6, 3, 0, 5};

  printVector(arr,4);
  insertionSort(arr,4);
  printVector(arr,4);

}

