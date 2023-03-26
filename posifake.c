#include <stdio.h>
#include <math.h>

/* Função que define a função cuja raiz se deseja encontrar */
double f(double x) {
    return x*x*x - 3*x*x + 2*x - 5;
}

int main() {
    double limite_inferior, limite_superior, ponto_medio, valor_funcao_limite_inferior, valor_funcao_limite_superior, valor_funcao_ponto_medio, precisao;
    int numero_iteracoes = 0;

    /* Recebe do usuário o intervalo inicial e a precisão desejada */
    printf("Digite o limite inferior e o limite superior do intervalo inicial: ");
    scanf("%lf %lf", &limite_inferior, &limite_superior);

    printf("Digite a precisão desejada para a raiz: ");
    scanf("%lf", &precisao);

    /* Calcula o valor da função nos limites do intervalo inicial */
    valor_funcao_limite_inferior = f(limite_inferior);
    valor_funcao_limite_superior = f(limite_superior);

    /* Realiza o método da posição falsa enquanto o intervalo não for menor do que a precisão */
    while (fabs(limite_superior - limite_inferior) > precisao) {
        /* Calcula o ponto médio ponderado do intervalo */
        ponto_medio = (limite_inferior*valor_funcao_limite_superior - limite_superior*valor_funcao_limite_inferior) / (valor_funcao_limite_superior - valor_funcao_limite_inferior);

        /* Calcula o valor da função no ponto médio */
        valor_funcao_ponto_medio = f(ponto_medio);

        /* Incrementa o número de iterações */
        numero_iteracoes++;

        /* Verifica se a raiz está no subintervalo [a,c] ou [c,b] */
        if (valor_funcao_limite_inferior * valor_funcao_ponto_medio < 0.0) {
            limite_superior = ponto_medio;
            valor_funcao_limite_superior = valor_funcao_ponto_medio;
        } else {
            limite_inferior = ponto_medio;
            valor_funcao_limite_inferior = valor_funcao_ponto_medio;
        }
    }

    /* Imprime a raiz encontrada e o número de iterações realizadas */
    printf("A raiz encontrada é: %.15lf\n", ponto_medio);
    printf("Número de iterações: %d\n", numero_iteracoes);

    return 0;
}
