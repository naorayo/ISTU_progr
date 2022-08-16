#include <stdio.h>   // Директивы препроцессора
#include <conio.h>
#include <math.h>
int main()
 {
 	float x, y;   // Описание переменных
 	printf("\nLaboratornaia rabota nomer 2");
 	printf("\nVariant nomer 3");
 	printf("\nMR-14-1");
 	printf("\nBakanov Maxim");
	printf("\n");
	printf("\nVvedite znachenie x:");   // Ввод исходных данных
 	scanf("%f", &x);
 	 do
        x=x+4;
	 while(x<0);
	 do
        x=x-4;
	 while(x>4);
	if(x<=1)
	y=sqrt(1-pow((x-1), 2));
	else
	     if(x<=3)
	     y=1-sqrt(1-pow((x-2), 2));
	     else y=sqrt(1-pow((x-1), 3));
	printf("\ny=%1.5f", y);   // Вывод результата


 	return 0;
}