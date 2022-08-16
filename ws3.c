#include <stdio.h>		// директивы препроцессора
#include <conio.h>
#include <math.h>
int main()
{
	float x, s, f, x_nach, x_kon, delta_x, eps, temp;   // описание переменных
	int n;
	printf("\nLaboratornaya rabota nomer 3");
	printf("\nVariant nomer 3");
	printf("\nMR-14-1");
	printf("\nBakanov Maxim");
	printf("\n");
	printf("\nVvod ishodnih dannih:");	// ввод исходных данных
	printf("\n");
	printf("\nx_nach=");
	scanf("%f", &x_nach);								// начальное значение аргумента
	printf("\nx_kon=");
	scanf("%f", &x_kon);								// конечное значение аргумента
	printf("\ndelta_x=");
	scanf("%f", &delta_x);								// шаг изменения аргумента
	printf("\neps=");
	scanf("%f", &eps);									// точность вычислений

	printf("\nDlya  x=%5.3f  do  %5.3f  s shagom  %5.3f  i tochnostiu  %5.3f\n", x_nach, x_kon, delta_x, eps);   // эхо-печать
    printf("\n");
	printf("\n   x      n         s            f");
	printf("\n--------------------------------------");
	x = x_nach;
	do
	{   // внешний цикл - изменение аргумента
	temp=x;   // первое слагаемое
	temp*=2;
	s=temp;   // начальное значение суммы
	n=1;   // количество итераций на каждом шаге
	f=log((1+x)/(1-x));   // точное значение функции
while(fabs(x-x_kon)<eps)
{
    temp*=(2.0*n-1.0)*(pow(x, (2.0*n+1.0)))/((2.0*n+1.0)*(pow(x, (2.0*n-1.0)))); //Очередное слагаемое
    s+=temp;
    n++;
}
	printf("\n%5.3f     %d     %0.6f     %1.6f", x, n, s, f);
	x += delta_x;	// увеличение аргумента на шаг  delta_x
}
while (x<x_kon+delta_x);
	printf("\n--------------------------------------");
	return(0);
}