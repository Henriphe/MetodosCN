#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float f(float x){
    return pow(x, 3) - 9 * x + 3;
    //return pow(x, 3) -  x - 1;
    //return x * log10(x) - 1;
}

float p(float x0, float x1){
    return ( (x0 * f(x1)) - (x1 * f(x0)) ) / (f(x1) - f(x0));
}

float metodoSecante(float x0, float x1, float e1, float e2){
    float x2, fx0, fx1, fx2;
    int i;
    fx0 = f(x0);
    fx1 = f(x1);

    // Passo 2 do algoritmo
    // Se f(x0) < e1 retorna x0
    if (fabs(fx0) < e1){
        return x0;
    } // Passo 3 do algoritmo
    // se |f(x1)| < e1 ou se |x1 - x0| < e2 retorna x1
    if (fabs(fx1) < e1 || fabs(x1 - x0) < e2){
        return x1;
    }
    // Passo 4 e 8 do algoritmo
    for (i = 1; i <= 50; i++){
        // Passo 5 do algoritmo
        // x2 recebe o valor de x1 e x0 aplicado na função p
        x2 = p(x0, x1);
        fx2 = f(x2);
        fx1 = f(x1);
        fx0 = f(x0);

        printf("\nIteracao %d\n", i);
        printf("x0\t%.8f\n", x0);
        printf("x1\t%.8f\n", x1);
        printf("x2\t%.8f\n", x2);

        printf("f(x0)\t%.8f\n", f(x0));
        printf("f(x1)\t%.8f\n", f(x1));

        printf("f(x2)\t%.8f\n", f(x2));
        printf("(x2-x1)\t%.8f\n\n", (x2 - x1));

        // Passo 6 do algoritmo
        // se o |f(x2)| < e1 ou |x2-x1| < e2 retorna x2
        if (fabs(f(x2)) < e1 || fabs(x2 - x1) < e2){
            return x2;
        }

        // Passo 7 do algoritmo
        // x0 recebe o valor de x1
        // x1 recebe o valor de x2
        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = fx2;
    }
    return x1;
}

int main(){
    float x0, x1, e1, e2, raiz;
    // Passo 1 do algoritmo
    // Dados iniciais
    x0 = 2.3;
    x1 = 2.7;
    e1 = e2 = pow(10, -7);

    raiz = metodoSecante(x0, x1, e1, e2);

    printf("%.8f", raiz);

    return 0;
}