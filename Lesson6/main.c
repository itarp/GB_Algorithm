#include <stdio.h>
#include <math.h>

void sort();
void tpk();

void bubleSort(int array[][5]);
void show(int array[][5]);
void iSwap(int *a, int *b);
void dSwap(double *a, double *b);

int main() {
  printf("\nTask 1 - bubble sort\n");
  sort();
  printf("\nTask 3 - Trabb Pardo-Knuth algorithm\n");  
  tpk();
}

void sort(){
  int A[4][5] = {
    10, 12, 3, 4, 47,
    6, 63, 8, 15, 44,
    11, 41, 13, 14, 1,
    16, 17, 22, 19, 31
  };

  printf("Original array:\n");
  show(A); // Отображение исходного массива

  bubleSort(A); // Сортировка массива

  printf("\nSorted array:\n");
  show(A);  //Отображение массива после сортировки
}

void tpk(){
  double array[11] = {0};
  double num = 0;

  printf("Enter 11 numbers: \n");
  for(int i = 0; i < 11; i++)
    scanf("%lf", &array[i]);
  
  // Реверс массива
  for(int i = 0; i < 11 / 2; i++) 
    dSwap(&array[11 - i - 1], &array[i]);

  for(int i = 0; i < 11; i++){
    num = sqrt(fabs(array[i])) + 5 * pow(array[i], 3);
    if (num > 400)
      printf("%d The number is over 400\n", i +1);
    else
      printf("%d %.16g\n", i + 1, num);
      }
}

void bubleSort(int array[][5]) {
  for(int i = 1; i < 20; i++) 
    for(int ii = 20 - 1; ii >= i; ii--)
      if(*(*array + ii-1) > *(*array + ii))
	iSwap(*array + ii - 1, *array + ii);
}

void show(int array[][5]) {
  for(int i=0; i < 4; i++){ 
    for (int ii=0; ii < 5; ii++)
      printf("%d\t", array[i][ii]);
    printf("\n");
  }
}

inline void iSwap(int *a, int *b) {
  int t = 0;
  t = *a;
  *a = *b;
  *b = t;
}

inline void dSwap(double *a, double *b) {
  double t = 0;
  t = *a;
  *a = *b;
  *b = t;
}
