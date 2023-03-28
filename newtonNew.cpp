#include <iostream>
#include <math.h>

using namespace std;

// Limite de interações
#define max_i 50

// Função x^3-9x+3
float f(float x){
    return (pow(x, 3) - 9 * x + 3);
}

// derivada da função x^3-9x+3
float d(float x){
    return (3 * pow(x, 2) - 9);
}

// Função de iteração
float form_i(float x0){
    return (x0 - (f(x0) / d(x0)));
}

// Método de Newton Rhapson
float newtonRhapson(float x0, float e1, float e2){
    float x1, fx0, fx1;
    fx0 = f(x0);

    // Passo 2 do algoritmo
    if (fabs(fx0) < e1){
        return x0;
    }

    // Passo 3 e 7 do algoritmo
    for (int i = 1; i <= max_i; i++){
        // Passo 4 do algoritmo
        x1 = form_i(x0);
        fx1 = f(x1);

        printf("\nIteração %d\n",i);
        printf("x%d\t\t%f\n",i, x1);
        printf("f(x%d)\t%f\n",i, fx1);
        printf("(x%d-x%d)\t%f\n\n", i, i-1, (x1 - x0));
        
        // Passo 5 do algoritmo
        if (fabs(fx1) < e1 || fabs((x1 - x0)) < e2){
            return x1;
        }

        // Passo 6 do algoritmo
        x0 = x1;
        fx0 = fx1;
        x1 = form_i(x0);
    }
    return x1;
}

int main(){
    float a, b, x0, e1, e2, raiz;

    x0 = 0.5;
    e1 = e2 = 0.0005;
    
    /*printf("Digite o valor de x0: ");
    scanf("%f", &x0);

    printf("Digite o valor das precisoes e1 e2: ");
    scanf("%f %f", &e1, &e2);*/

    raiz = newtonRhapson(x0, e1, e2);
    printf("Raiz: %f", raiz);

    return 0;
}