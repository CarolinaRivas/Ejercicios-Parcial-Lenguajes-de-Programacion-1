#define N 20
#include <stdio.h>

void leer_matriz(int A[N][N], int filas, int columnas)
{
    int i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("Ingresa la entrada [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    return;
}
// Funcion para ver mas bonita la matriz
void escribir_matriz(int A[N][N], int filas, int columnas)
{
    int i, j;
    for (i = 0; i < filas; i++)
    {
        for (j = 0; j < columnas; j++)
        {
            printf("\t%d", A[i][j]);
        }
        printf("\n");
    }
    return;
}
// m numero de filas A y B
// n numero de columnas de A
// p numero de columnas de B

void multiplicar(int A[N][N], int B[N][N], int C[N][N], int m, int n, int p)
{
    int i, j, k;
    // limpiar o inicializar matriz C
    for (i = 0; i < m; i++)
        for (k = 0; k < p; k++)
            C[i][k] = 0;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            for (k = 0; k < p; k++)
                C[i][k] = C[i][k] + A[i][j] * B[j][k];
}

int main()
{
    int m, n, p;
    int A[N][N], B[N][N], C[N][N];
    printf("------------------------------------------------\n");
    printf("Bienvenido a tu Programa Calcular Multiplicacion de Matrices :D \n");
    printf("------------------------------------------------\n");

    printf("\n Datos de la matriz A: \n");
    printf("ingrese la cantidad de filas\n");
    scanf("%d", &m);
    printf("------------------------------------------------\n");
    printf("ingrese la cantidad de columnas\n");
    scanf("%d", &n);
    printf("------------------------------------------------\n");
    leer_matriz(A, m, n);
    printf("------------------------------------------------\n");

    printf("\n Datos de la matriz B: \n");
    printf("ingrese la cantidad de columnas\n");
    scanf("%d", &p);
    printf("------------------------------------------------\n");
    leer_matriz(B, n, p);
    printf("------------------------------------------------\n");

    printf("\n matriz A: \n");
    escribir_matriz(A, m, n);
    printf("------------------------------------------------\n");

    printf("\n matriz B: \n");
    escribir_matriz(B, n, p);
    printf("------------------------------------------------\n");
    printf("\n matriz C: \n");
    multiplicar(A, B, C, m, n, p);
    escribir_matriz(C, m, p);
}
