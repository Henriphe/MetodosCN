#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define max 200 // VARIÁVEL QUE DEFINE LIMITE DE ITERAÇÕES (PARA NÃO FICA EM UM LOOP INFINITO E TRAVAR O COMPUTADOR)

// FUNÇÃO QUE DESEJA CALCULAA A RAIZ
// XLOGX - 1
float f(float x)
{
    //return 4 * sin(x) - pow(2.718281828459045235360287, x);
    //return pow(x, 3) -  x - 1;
    return x * log10(x) - 1;
}

// MÉTODO DA POSIÇÃO FALSA
float posicaoFalsa(float a, float b, float e)
{
    float fa, fb, fx, x;

    fa = f(a);
    fb = f(b);

    x = (a * fb - b * fa) / (fb - fa);

    // SE b - a OU f(a) OU f(b) FOR MENOR QUE A PRECISÃO, RETORNA A MÉDIA PONDERADA ENTRE A E B COM PESOS |f(b)| E |f(a)|
    // PASSO 2 DO ALGORITMO
    if (fabs((b - a) < e || fabs(fa) < e || fabs(fb) < e))
    {
        return x;
    }

    for (int i = 1; fabs(f(x)) > e && i <= max; i++)
    {
        x = (a * fb - b * fa) / (fb - fa);
        fx = f(x);


        

        printf("\niteracao %d\n", i);
        printf("a = %.8f\nb = %.8f\na * f(b) = %.8f\nb * f(a) = %.8f\na*f(b)-b*f(a)= %.8f\nf(b) - f(a) = %.8f\n", a, b, a * fb, b * fa, a*f(b)-b*f(a), fb - fa);
        printf("x = %.8f\nf(a) = %.8f\nf(b) = %.8f\nf(x) = %.8f\na - b = %.8f\n", x, fa, fb, fx, a - b);

        // SE Mf(x) > 0, ENTÃO A RAIZ ESTÁ NO INTERVALO [x, b]
        // PASSO 7 DO ALGORITMO
        if (fa * fx > 0)
        {
            printf("------ f(a) * f(x) = %.8f-----\n", fa * fx);
            a = x;
            fa = fx;
        }
        else
        {
            b = x;
            fb = fx;
        }

        // SE b - a OU f(a) OU f(b) FOR MENOR QUE A PRECISÃO, RETORNA A MÉDIA PONDERADA ENTRE A E B COM PESOS |f(b)| E |f(a)|
        if (fabs((b - a) < e || fabs(fa) < e || fabs(fb) < e))
        {
            return x;
        }
    }

    return x;
}

int main()
{
    // DADOS INICIAIS
    float a=2, b=3, e=pow(10,-7), x;
/*
    printf("Digite o valor de a e b no intervalo [a, b]: ");
    scanf("%f %f", &a, &b);
    printf("Digite o valor da precisao: ");
    scanf("%f", &e);
*/
    // CHAMADA DA FUNÇÃO
    x = posicaoFalsa(a, b, e);

    // RESULTADO
    printf("\nRaiz aproximada da funcao: %.8f\n\n", x);
    return 0;
}