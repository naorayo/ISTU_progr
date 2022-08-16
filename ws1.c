#include <stdio.h>  // директивы препроцессора
#include <conio.h>
#include <math.h>
int main()
{
  const float a=1.5e-3;  // задание констант
  const float b=0.314159265e-5;
  float x, r, s, y, z;  // описание переменных
  printf("\nLaboratornaya rabota nomer 1");
  printf("\nVariant 3");
  printf("\nMR-14-1");
  printf("\nBakanov Maxim\n");
  printf("\nx=");  // ввод исходных данных
  scanf("%f", &x);
  y=cbrt(a*tan(0.25e-3+abs(b*sin(x))));
  z=(pow(a, 2*cos(x))+pow(b, -a)*cos(sin(x)+pow(a, -b)))/(pow(x, y));
  printf("\ny=%5.3f", y);  // вывод результата
  printf("\nz=%5.3f", z);
  return 0;
}