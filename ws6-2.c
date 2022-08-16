#include <stdio.h> //Директивы препроцессора
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <math.h>

int main()
{
int i, j, n, m, massiv_min, massiv_max, temp;
time_t t; // Текущее время для инициализации рандомайзера
srand((unsigned) time (&t)); // Инициализация рандомазера

  printf("\nLaboratornaya rabota nomer 6");
  printf("\nZadanie nomer 2");
  printf("\nVariant 3");
  printf("\nMR-14-1");
  printf("\nBakanov Maxim\n");

  printf("\nVvedite niz. granitsu diapazona:"); // Ввод данных
  scanf("%d", &massiv_min);
  printf("\nVvedite verh granitsu diapazona:");
  scanf("%d", &massiv_max);
  printf("\nVvedite razmer massiva:");
  scanf("%d", &n);

  int massiv[n][n]; //Вывод исходного массива
  printf("\nIshodniy massiv:\n");
  m=massiv_max-massiv_min+1;

  for(i=0; i<n; i++) // Получение случайного числа в диапазоне от vector_min до vector_max
  {
  	for(j=0; j<n; j++)
  	{
  		massiv[i][j]=rand()%m+massiv_min;
  		printf("%5d", massiv[i][j]);
	  }
	  printf("\n");
	  }
	for(i=0; i<n/2; i++)
	{
		for(j=0; j<i; j++)
		{
			temp=massiv[i][j]; // Отразить верхние элементы (выше средней строки)
			massiv[i][j]=massiv[i][n-1-j];
			massiv[i][n-1-j]=temp;

			temp=massiv[n-1-i][j]; // Отразить нижние элементы (ниже средней строки)
			massiv[n-1-i][j]=massiv[n-1-i][n-1-j];
			massiv[n-1-i][n-1-j]=temp;
		}
	}
    if (n &1) // Отразить элементы в средней строке, если N нечетно
    {
        for (j = 0; j < n / 2; j++)
        {
            temp = massiv[n / 2][j];
            massiv[n / 2][j] = massiv[n / 2][n - 1 - j];
            massiv[n / 2][n - 1 - j] = temp;
        }
    }
  printf("\nVihodnoi massiv\n");
  for(i=0; i<n; i++)
  {
  	for(j=0; j<n; j++)
  	{
  		printf("%5d", massiv[i][j]);
	  }
	printf("\n");
  }
printf("\n");
return 0;
}