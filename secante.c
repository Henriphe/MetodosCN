#include <stdio.h>
#include <math.h>

/* Função que define a função cuja raiz se deseja encontrar */
double f(double x) {
    return x*x*x - 3*x*x + 2*x - 5;
}

int main() {
    double valor_anterior, valor_atual, valor_anterior_anterior, precisao;
    int numero_iteracoes = 0;

    /* Recebe do usuário os dois valores iniciais e a precisão desejada */
    printf("Digite o primeiro valor inicial: ");
    scanf("%lf", &valor_anterior_anterior);

    printf("Digite o segundo valor inicial: ");
    scanf("%lf", &valor_anterior);

    printf("Digite a precisão desejada para a raiz: ");
    scanf("%lf", &precisao);

    /* Realiza o método da secante enquanto a diferença entre o valor atual e o valor anterior for maior do que a precisão */
    do {
        /* Calcula o valor atual usando o método da secante */
        valor_atual = valor_anterior - f(valor_anterior) * (valor_anterior - valor_anterior_anterior) / (f(valor_anterior) - f(valor_anterior_anterior));

        /* Define o valor anterior anterior como sendo o valor anterior */
        valor_anterior_anterior = valor_anterior;

        /* Define o valor anterior como sendo o valor atual */
        valor_anterior = valor_atual;

        /* Incrementa o número de iterações */
        numero_iteracoes++;
    } while (fabs(valor_atual - valor_anterior) > precisao);

    /* Imprime a raiz encontrada e o número de iterações realizadas */
    printf("A raiz encontrada é: %.15lf\n", valor_atual);
    printf("Número de iterações: %d\n", numero_iteracoes);

    return 0;
}
