#include <stdio.h>
#include <string.h>

// Estrutura representando uma carta de país
struct Carta {
    char nome[50];             // Nome do país
    int populacao;             // População total
    float area;                // Área em km²
    float pib;                 // Produto Interno Bruto
    int pontosTuristicos;      // Número de pontos turísticos
    float densidadeDemografica; // População / Área
};

int main() {
    // --- Cadastro pré-definido das cartas ---
    struct Carta carta1 = {
        "Brasil",
        213000000,
        8515767.0,
        2200000.0,
        50,
        0 // será calculado
    };

    struct Carta carta2 = {
        "Canadá",
        38000000,
        9984670.0,
        2100000.0,
        30,
        0 // será calculado
    };

    // --- Cálculo da densidade demográfica (população / área) ---
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int opcao;

    // --- Menu Interativo ---
    printf("==== SUPER TRUNFO - Comparação de Países ====\n\n");
    printf("Escolha o atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - PIB\n");
    printf("4 - Pontos Turísticos\n");
    printf("5 - Densidade Demográfica\n");
    printf("Digite sua opção: ");
    scanf("%d", &opcao);

    printf("\nComparando %s e %s\n\n", carta1.nome, carta2.nome);

    switch (opcao) {
        case 1:
            printf("Atributo: População\n");
            printf("%s: %d habitantes\n", carta1.nome, carta1.populacao);
            printf("%s: %d habitantes\n", carta2.nome, carta2.populacao);

            if (carta1.populacao > carta2.populacao) {
                printf("\nVencedor: %s\n", carta1.nome);
            } else if (carta2.populacao > carta1.populacao) {
                printf("\nVencedor: %s\n", carta2.nome);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 2:
            printf("Atributo: Área\n");
            printf("%s: %.2f km²\n", carta1.nome, carta1.area);
            printf("%s: %.2f km²\n", carta2.nome, carta2.area);

            if (carta1.area > carta2.area) {
                printf("\nVencedor: %s\n", carta1.nome);
            } else if (carta2.area > carta1.area) {
                printf("\nVencedor: %s\n", carta2.nome);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 3:
            printf("Atributo: PIB\n");
            printf("%s: R$ %.2f bilhões\n", carta1.nome, carta1.pib);
            printf("%s: R$ %.2f bilhões\n", carta2.nome, carta2.pib);

            if (carta1.pib > carta2.pib) {
                printf("\nVencedor: %s\n", carta1.nome);
            } else if (carta2.pib > carta1.pib) {
                printf("\nVencedor: %s\n", carta2.nome);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 4:
            printf("Atributo: Pontos Turísticos\n");
            printf("%s: %d locais\n", carta1.nome, carta1.pontosTuristicos);
            printf("%s: %d locais\n", carta2.nome, carta2.pontosTuristicos);

            if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
                printf("\nVencedor: %s\n", carta1.nome);
            } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
                printf("\nVencedor: %s\n", carta2.nome);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        case 5:
            printf("Atributo: Densidade Demográfica\n");
            printf("%s: %.2f hab/km²\n", carta1.nome, carta1.densidadeDemografica);
            printf("%s: %.2f hab/km²\n", carta2.nome, carta2.densidadeDemografica);

            // Regra especial: menor valor vence
            if (carta1.densidadeDemografica < carta2.densidadeDemografica) {
                printf("\nVencedor: %s (menor densidade)\n", carta1.nome);
            } else if (carta2.densidadeDemografica < carta1.densidadeDemografica) {
                printf("\nVencedor: %s (menor densidade)\n", carta2.nome);
            } else {
                printf("\nEmpate!\n");
            }
            break;

        default:
            printf("Opção inválida! Tente novamente.\n");
            break;
    }

    return 0;
}
