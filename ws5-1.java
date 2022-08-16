import java.util.Scanner;
public class main {
    public static void main(String[] args)  //Начало программы    {
        Scanner sc;
        sc = new Scanner(System.in);
    String eval;   // Описание переменных
    int num;
    System.out.println("Лабораторная работа номер 5");
    System.out.println("Задание номер 1");
    System.out.println("Варант номер 3");
    System.out.println("МР-14-1");
    System.out.println("Баканов Максим");
    System.out.println("---------------------------");
        System.out.println("Введите выражение");
        eval = sc.nextLine();
        char[] chArray;  // Преобразование строки в массив
        chArray = eval.toCharArray();
        String[] nums = eval.split("[-+*/]"); // Массив чисел
        String[] op = eval.split("\\d+"); // Массив операций
        double res = Integer.parseInt(nums[0]); // Начальное значение
        for (int i = 1; i < op.length; i++)
        {
            int b = Integer.parseInt(nums[i]); // Парсим
следующее число
/* Анализирует строковый параметр как десятичное целое число со знаком. Символы в строке должны все быть десятичными цифрами, за исключением того, что первый символ может представлять собой ASCII-знак минус'-' ('\u002D') указать на отрицательную величину или текстовый знак плюс '+' ('\u002B'), чтобы указать положительное значение. */
            switch (op[i].charAt(0)) // Выполняем действие
            {
            case '+':
                res += b;
                break;
            case '-':
                res -= b;
                break;
            case '*':
                res *= b;
                break;
            case '/':
                res /= b;
                break;
            default:
            }
        }
        System.out.println(res);
    }
    }