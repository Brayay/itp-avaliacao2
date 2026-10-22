/*
 * ITP - Segunda avaliacao
 * Opcao 1: Boletim de uma pequena turma
 * Compilar: gcc -std=c11 -Wall -Wextra main.c -o programa
 * Executar: ./programa
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUNOS 10
#define NUM_NOTAS  3
#define TAM_NOME   50

void ler_dados(float notas[][NUM_NOTAS], char nomes[][TAM_NOME], int qtd)
{
    for (int i = 0; i < qtd; i++) {
        do {
            printf("Nome do estudante %d: ", i + 1);
            scanf("%49s", nomes[i]);
        } while (strlen(nomes[i]) == 0);

        for (int j = 0; j < NUM_NOTAS; j++) {
            printf("  Nota %d de %s (0 a 10): ", j + 1, nomes[i]);
            scanf("%f", &notas[i][j]);
            while (notas[i][j] < 0 || notas[i][j] > 10) {
                printf("  Nota invalida! Digite de novo: ");
                scanf("%f", &notas[i][j]);
            }
        }
    }
}

void calcular_medias(float notas[][NUM_NOTAS], int qtd, float *medias)
{
    for (int i = 0; i < qtd; i++) {
        float soma = 0;
        for (int j = 0; j < NUM_NOTAS; j++) {
            soma = soma + notas[i][j];
        }
        medias[i] = soma / NUM_NOTAS;
    }
}

void exibir_tabela(float notas[][NUM_NOTAS], char nomes[][TAM_NOME],
                   float *medias, int qtd)
{
    printf("\n%-15s %6s %6s %6s %7s  %s\n",
           "Nome", "Nota1", "Nota2", "Nota3", "Media", "Situacao");

    for (int i = 0; i < qtd; i++) {
        printf("%-15s", nomes[i]);
        for (int j = 0; j < NUM_NOTAS; j++) {
            printf(" %6.2f", notas[i][j]);
        }
        printf(" %7.2f  ", medias[i]);

        if (medias[i] >= 6) {
            printf("atingiu a meta\n");
        } else {
            printf("abaixo da meta\n");
        }
    }
}

void exibir_resumo(char nomes[][TAM_NOME], float *medias, int qtd)
{
    float soma = 0;
    float maior = medias[0];

    for (int i = 0; i < qtd; i++) {
        soma = soma + medias[i];
        if (medias[i] > maior) {
            maior = medias[i];
        }
    }

    printf("\nMedia geral da turma: %.2f\n", soma / qtd);
    printf("Maior media: %.2f - ", maior);

    for (int i = 0; i < qtd; i++) {
        if (medias[i] == maior) {
            printf("%s ", nomes[i]);
        }
    }
    printf("\n");
}

int main(void)
{
    float notas[MAX_ALUNOS][NUM_NOTAS];
    char nomes[MAX_ALUNOS][TAM_NOME];
    int qtd;

    printf("Quantidade de estudantes (1 a %d): ", MAX_ALUNOS);
    scanf("%d", &qtd);
    while (qtd < 1 || qtd > MAX_ALUNOS) {
        printf("Quantidade invalida! Digite de novo: ");
        scanf("%d", &qtd);
    }

    float *medias = calloc(qtd, sizeof(float));
    if (medias == NULL) {
        printf("Erro: nao foi possivel alocar memoria.\n");
        return 1;
    }

    ler_dados(notas, nomes, qtd);
    calcular_medias(notas, qtd, medias);
    exibir_tabela(notas, nomes, medias, qtd);
    exibir_resumo(nomes, medias, qtd);

    free(medias);
    return 0;
}