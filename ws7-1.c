#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float function(int n, int *vector);
int main() {

  int i, n, m, vector_max, vector_min, l;
 tme_t t; // Текущее время для инициализации генератора случайных     чисел(рандомайзера)
  srand((unsigned) time(&t)); // Инициализация рандомайзера
  printf("\nLaboratornaya rabota nomer 7");
  printf("\nZadanie nomer 1");
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
l=function(n, vector);
printf("Srednee arifmeticheskoe znachenie majdu vtorim max i vtorim min= %d",l);
}

float function(int n, int *vector)
{
int max, min, max_2, min_2, i, n_max_2=0, n_min_2=0, temp, k=0, summ=0;
max=min=*vector;
for(i=0;i<n;i++) //находим первые мин. и макс. эл-ты
{
if (*(vector+i)>max)
   max=*(vector+i);
if (*(vector+i)<min)
   min=*(vector+i);
}
min_2=max;
max_2=min;

for(i=0;i<n;i++) //находим вторые по знач. мax и min
{
if ((*(vector+i)<min_2) && (*(vector+i)!=min))
    {
	min_2=*(vector+i);
	n_min_2=i;
	}
if ((*(vector+i)>max_2) && (*(vector+i)!=max))
    {
	max_2=*(vector+i);
	n_max_2=i;
	}
}
if (n_min_2>n_max_2)
  {
   temp=n_min_2;
   n_min_2=n_max_2;
   n_max_2=temp;
  }
if(max_2==min_2)
    {
	printf("\nMAX i MIN odno i to zhe chislo\n");
	}
else
    {
    	  printf("\nmax_2=%d n_max_2=%d", max_2, n_max_2);
          printf("\nmin_2=%d n_min_2=%d\n", min_2, n_min_2);
          for(i=((n_min_2)+1); i<n_max_2; i++)
		  {
           summ+=*(vector+i);
           k++; //считаем кол-во элементов которые мы суммируем для получения ср. арифметич. знач.
          }
          printf("\nk=%d\n", k);
    }
if (k==0) return 0;
else return summ/k;
}