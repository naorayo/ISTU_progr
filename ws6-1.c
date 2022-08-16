#include <stdio.h>  // Директивы препроцессора
#include <stdlib.h>
#include <conio.h>
#include <math.h>
#include <time.h>
int main()

{
  int i, m, n, vector_min, vector_max, max, min, max_2, min_2, n_min_2, n_max_2;  // описание переменных
  time_t t; // Текущее время для инициализации генератора случайных чисел(рандомайзера)
  srand((unsigned) time(&t)); // Инициализация рандомайзера
  printf("\nLaboratornaya rabota nomer 6");
  printf("\nVariant 3");
  printf("\nMR-14-1");
  printf("\nBakanov Maxim\n");

  printf("\nVvedite min znachenie diapazona:"); // Ввод данных
  scanf("%d", &vector_min);
  printf("\nVvedite max znachenie diapazona:");
  scanf("%d", &vector_max);
  printf("\nVvedite razmer vectora:");
  scanf("%d", &n);

  int vector[n];
  printf("\nIshodniy Vector:\n");
  m=vector_max-vector_min+1;
  for(i=0; i<n; i++)
  {
  	vector[i]=rand()%m+vector_min; // Получение случайного числа в диапазоне от vector_min до vector_max
  	printf("%5d", vector[i]);
  }
  printf("\n");
  max=vector[0];
  min=vector[0];


for(i=1; i<n; i++) // Ищем минимальный и максимальный элементы
  {
  	if (vector[i]>max)
  		max=vector[i];
  	if (vector[i]<min)
		min=vector[i];
	}
    for (i=0; i<n; i++) // Ищем вторые по значению минимальный и максимальный элементы
	{
				if (vector[i]<min_2 && vector[i]!=min)
		{
			min_2 = vector[i];
			n_min_2 = i;
		}
		if (vector[i]>max_2 && vector[i]!=max)
		{
			max_2 = vector[i];
			n_max_2 = i;
		}

	}
	if (max_2 == min_2) // Если таких элементов нет
	printf("\nMAX i MIN odno i to zhe chislo\n");
	else
	{
  printf("\nmax_2=%d n_max_2=%d", max_2, n_max_2);
  printf("\nmin_2=%d n_min_2=%d\n", min_2, n_min_2);

  vector[n_max_2]=min_2; //  Меняем местами минимальный и максимальный элементы вектора
  vector[n_min_2]=max_2;

  printf("\nVihodnoi vector:\n");
    for(i=0; i<n; i++)
  printf("%5d", vector[i]);
}
  printf("\n");
  return 0;
}