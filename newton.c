#include <stdio.h>
#include <math.h>

/* Função que define a função cuja raiz se deseja encontrar */
double f(double x) {
    return x*x*x - 3*x*x + 2*x - 5;
}

/* Função que define a derivada da função */
double f_linha(double x) {
    return 3*x*x - 6*x + 2;
}

int main() {
    double valor_inicial, valor_atual, valor_anterior, precisao;
    int numero_iteracoes = 0;

    /* Recebe do usuário o valor inicial e a precisão desejada */
    printf("Digite o valor inicial: ");
    scanf("%lf", &valor_inicial);

    printf("Digite a precisão desejada para a raiz: ");
    scanf("%lf", &precisao);

    /* Define o valor atual como sendo o valor inicial */
    valor_atual = valor_inicial;

    /* Realiza o método de Newton enquanto a diferença entre o valor atual e o valor anterior for maior do que a precisão */
    do {
        /* Define o valor anterior como sendo o valor atual */
        valor_anterior = valor_atual;

        /* Calcula o valor atual usando o método de Newton */
        valor_atual = valor_anterior - f(valor_anterior) / f_linha(valor_anterior);

        /* Incrementa o número de iterações */
        numero_iteracoes++;
    } while (fabs(valor_atual - valor_anterior) > precisao);

    /* Imprime a raiz encontrada e o número de iterações realizadas */
    printf("A raiz encontrada é: %.15lf\n", valor_atual);
    printf("Número de iterações: %d\n", numero_iteracoes);

    return 0;
}
