import java.util.Scanner;
public class Lab_5_2_main
{
public static void main(String[] args) // Начало программы
{
     Scanner sc;
     sc = new Scanner(System.in);
String strok, st;
    int i, j;  // Описание переменных
    System.out.println("Лабораторная работа номер 5");
    System.out.println("Задание номер 2");
    System.out.println("Варант номер 3");
    System.out.println("МР-14-1");
    System.out.println("Баканов Максим");
    System.out.println("---------------------------");
    System.out.println("Введите строку");
        strok = sc.nextLine(); // Описание строки
        char[] strokArray; // Преобразование строки в массив
        strokArray = strok.toCharArray();
        int n=strok.length()-1;
        for  (i=1; i>=1; i++) // Вычисляем место первого слова
            {
            if (strokArray[i]== (' '))
                {
                    break;
                }
             }
        for (j=n; j>=1; j--) // Вычисляем место первого слова
        {
         if (strokArray[j]== (' '))
         {
             break;
         }
        }
    System.out.println((strok.substring(j+1, n+1))+(strok.substring(i, j+1))+(strok.substring(0, i)));
}
}
