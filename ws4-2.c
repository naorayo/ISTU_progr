#include <stdio.h>	//Директивы препроцессора
#include <conio.h>
#include <math.h>
int main()
{
	int k, n;	//Описание переменных
	float a, a1, a2, s;
	printf("\nLaboratornaya rabota nomer 4");
	printf("\nZadanie nomer 2");
	printf("\nVariant nomer 3");
	printf("\nMR-14-1");
	printf("\nBakanov Maxim\n");;
    printf("\nVvod ishodnih dannih:\n"); //Ввод  исходных данных
	printf("\n a1=");
	scanf("%f", &a1); //Первый член последовательности
	printf("\n a2=");
	scanf("%f", &a2);	//Второй член последовательности
	printf("\n n=");
	scanf("%d", &n);	 //Количество членов последовательности
	printf("\n-----------------");
	printf("\n  k     a     s ");
	printf("\n-----------------");
	s=a1+a2;	//Начальное значение суммы
for (k=3; k<=n; k++)   // k – номер очередного члена последовательности
		{
			a=sqrt(a2)/cbrt(a1);	//Очередное слагаемое
			s+=a;	//Очередное значение суммы
			a1=a2;
			a2=a;
			printf("\n%3d   %1.5f   %1.5f", k, a, s		}
	printf("\n-----------------\n");
	return 0;
}