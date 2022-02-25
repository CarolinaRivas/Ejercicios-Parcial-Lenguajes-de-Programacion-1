#include <stdio.h>

long calcularPotencia(long numero, long potencia)
{
    long resultado = numero;
    if (potencia <= 0)
    {
        return 1;
    }
    while (potencia > 1)
    {
        resultado = resultado * numero;
        potencia--;
    }
    return resultado;
}
int main()
{
    long numero;
    long potencia;
    printf("------------------------------------------------\n");
    printf("Bienvenido a tu Programa Calcular Potencias :D \n");
    printf("------------------------------------------------\n");

    printf("Ingresa la base \n");
    scanf("%ld", &numero);

    printf("Ingresa la potencia \n");
    scanf("%ld", &potencia);

    long calcular = calcularPotencia(numero, potencia);
    printf(" %ld elevado a %ld da como resultado %ld\n", numero, potencia, calcular);
}