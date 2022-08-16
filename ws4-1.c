#include <stdio.h>		//директивы препроцессора
#include <conio.h>
#include <math.h>
int main()
{
	float s, f;	//описание переменных
	int i, n;
	printf("\nLaboratornaya rabota nomer 4");
	printf("\nZadanie nomer 1");
	printf("\nVariant nomer 3");
	printf("\nMR-14-1");
	printf("\nBakanov Maxim\n");
    printf("\nVvod ishodnih dannih:\n");   //ввод исходных данных
	printf("\n n=");
	scanf("%d", &n);	//количество слагаемых суммы
	printf("\n---------------");
	printf("\n  i       s  ");
	printf("\n---------------");
	s=1.0/15.0;			//начальное значение суммы
	f=(1.0/2.0)-((M_PI)/8);	//точное значение функции

for (i=1; i<=n; i++)
		{
		 s += 1/((4.0*i-1.0)*(4.0*i+1.0));	//очередная сумма
		printf("\n%3d   %0.6f", i, s);
         }

	printf("\n---------------\n");
	printf("\n    f=%0.6f\n", f);
		return 0;
}