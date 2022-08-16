#include <string.h> // Директивы препроцессора
#include <stdio.h>
#include <stack>
#include <math.h>

using namespace std;
const int SIZE = 1e3+2;
char a[SIZE], b[SIZE];
int matr[SIZE][SIZE];

void out_ans(int n, int m) // Эта функция достает LCS из матрицы
{
    int pos = 0;
    int i = n, j = m;
    stack<int> lcsPos; // Создаём СТЕК
    while (matr[i][j]) // Просматриваем матрицу и записываем LCS в СТЕК
        {
            if (a[i-1] == b[j-1])
            {
                 lcsPos.push(i-1); // PUSH – кладём элемент на вершину стека
                 i--; j--;
            }
            else
                {
                    if (matr[i-1][j] >= matr[i][j-1])
                    i--;
                    else
                    j--;
                }
        }
        while (!lcsPos.empty())
            {
                 printf("%c", a[lcsPos.top()]);
                 lcsPos.pop();
            }
}
void output_lcs_Need_Vunsh(char *a, int n, char *b, int m) // Эта функция заполняет матрицу двумя циклами
{
    for (int i=1;i<=n;i++)
        {
            memset(matr[i],0,(m+1)*sizeof(int));
            for (int j=1;j<=m;j++)
            {
                if (a[i-1] == b[j-1])
                matr[i][j] = matr[i-1][j-1] + 1;
                else
                {
                    matr[i][j] = max(matr[i][j-1],matr[i-1][j]);
                }
            }
        }
    printf("\nstring a   = %s", a);
    printf("\nstring b   = %s\n", b);
    printf("\nDlina LCS(a,b) = %d", matr[n][m]);
    printf("\nLCS(a,b) = ");
    out_ans(n,m);
}
int main(void)
{
        printf("\nVvedite stroku a: ");
    scanf("%s", &a);
    printf("\nVvedite stroku b: ");
    scanf("%s", &b);
    output_lcs_Need_Vunsh(a,strlen(a),b,strlen(b));
    return 0;
}