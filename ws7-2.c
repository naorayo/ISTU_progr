#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
void FillArray( int* array, const int size, int min, int max ); //функция заполняет одномерный целочисленный массив псевдослучайными данными в диапазоне [ min, max ]

void PrintLnArray( int* array, const int size ); //функция печатает одномерный целочисленный массив

double GetAverageArray( int* array, const int size ); // функция возвращает среднее арифметическое одномерного целочисленного массива

void FindIndexes( int* array, const int size, int* index1, int* index2 ); // функция находит и записывает в аргументы индексы двух элементов наиболее близких к среднему арифметическому одномерного целочисленного массива

void SortPartArray( int* array, int start, int finish ); // функция сортирует часть одномерного целочисленного массива между указанными индексами, первый индекс должен быть меньше второго

int main(void )
{
	srand( time( 0 ) ); // засеять генератор случайных чисел
	//**ВВОД ДАННЫХ**
	int size;
	printf("\nLaboratornaya rabota nomer 7");
          printf("\nZadanie nomer 2");
          printf("\nVariant 3");
          printf("\nMR-14-1");
          printf("\nBakanov Maxim\n");
	printf( "Vvedite razmer massiva " );
	printf( "Vvedite razmer massiva " );
	scanf( "%u", &size );
	int minRange, maxRange;
	printf( "vvedite cherez probel granitsi min i max " );
	scanf( "%d%d", &minRange, &maxRange );

	//**ЗАПОЛНЕНИЕ МАССИВА**
	int* vec = ( int* ) malloc( size * sizeof(int) ); // объявляем наш массив как указатель на int и выделяем необходимую память для него
	FillArray( vec, size, minRange, maxRange ); // заполняем массив случайными данными в диапазоне [min, max]

	puts( "\nIshodniy massiv:" );
	PrintLnArray( vec, size ); // выодим массив на экран

	//**РАСЧЁТЫ И ВЫВОД**
	double avg = GetAverageArray( vec, size );  // находим среднее арифметическое массива и выводим его на экран
	printf( "\nSrednee arifmeticheskoe = %.3f\n", avg );
	int index1, index2; // находим индексы элементов
	FindIndexes( vec, size, &index1, &index2 );
	printf( "\nNaidennie elementi %d [ %d ]\t%d [ %d ]\n", index1, vec[ index1 ], index2, vec[ index2 ] );;
	SortPartArray( vec, index1, index2 ); // сортируем элементы между найденными индексами
	puts( "\nRezultiruiushiy massiv" );
	PrintLnArray( vec, size );  // выводим результирующий массив на экран
	free( vec ); // освобождаем память занятую массивом
	return EXIT_SUCCESS; // выходим из программы
}



void FillArray( int* array, const int size, int min, int max )
{
	int i;
	++max; // если не увеличить max, то диапазон будет [min, max ), а нжно [min, max ]
		for ( i = 0; i < size; ++i )
		array[ i ] = min + rand() % ( max - min ); // каждый элемент массива заполняется значением
}

void PrintLnArray( int* array, const int size ) // в цикле выводим все значения массива по одному
{
	int i;
		for ( i = 0; i < size; ++i )
		printf( "%4d", array[ i ] );
	puts( "" ); // обрыв строки
}

double GetAverageArray( int* array, const int size )
     {
	int i;
	double sum = 0;
	for ( i = 0; i < size; ++i ) // в цикле считаем сумму всех элементов массива
		sum += array[ i ]; // находим среднее арифметическое значение
	return sum / size;
}
void FindIndexes( int* array, const int size, int* index1, int* index2 )
     {
	double avg = GetAverageArray( array, size );  // рассчитываем и запоминаем среднее арифметическое
	int i;
	*index1 = 0, *index2 = 1;
	for ( i = 1; i < size; ++i ) // в цикле находим индексы двух элементов значения которых наиболее близки к среднему арифметическому
              {  // поочерёдно сравниваем разницу элемента с индексом index1 и среднего арифметического с разницей очередного элемента и среднего арифметического
if ( fabs( avg - array[ i ] ) < fabs( avg - array[ *index1 ] ) )

 // если нашли разницу меньше, запоминаем это
			*index2 = *index1;
			*index1 = i;
			// аналогично здесь
		} else if ( fabs( avg - array[ i ] ) < fabs( avg - array[ *index2 ] ) )
			*index2 = i;
	}
	// Может быть ситуация, когда index2 будет меньше чем index1
	// Предусмотрим обмен значений индексов - чтобы index1 ВСЕГДА был НЕ БОЛЬШЕ чем index2
	int temp;
	if ( *index1 > *index2 ) {
		temp = *index1;
		*index1 = *index2;
		*index2 = temp;
	}
}

void SortPartArray( int* array, int start, int finish )
{
	int i, exit = 0;

	// цикл ПОКА не закончили сортировку
	while ( !exit )
{
		exit = 1; // предполагаем, что на данном шаге можем закончить сортировку
  		   for ( i = start + 1; i < finish - 1; ++i )
			if ( array[ i ] > array[ i + 1 ] ) // в цикле поочерёдно сравниваем каждый элемент с последующим элементом
{    // если текущий элемент больше чем следующий за ним, меняем их  местами
				int temp = array[ i ];
				array[ i ] = array[ i + 1 ];
				array[ i + 1 ] = temp;
				exit = 0; // если была перестановка, то ещё раз пробегаемся по массиву(пробуем найти ещё элементы для сортировки)
			}
	}

}