#include <stdio.h>
#include <string.h>

// Estrutura para representar uma carta de país
struct Carta {
    char nome[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadeDemografica; // populacao / area
};

// Função para mostrar o menu de atributos
void mostrarMenu(int excluir) {
    printf("Escolha um atributo:\n");
    if (excluir != 1) printf("1 - População\n");
    if (excluir != 2) printf("2 - Área\n");
    if (excluir != 3) printf("3 - PIB\n");
    if (excluir != 4) printf("4 - Pontos Turísticos\n");
    if (excluir != 5) printf("5 - Densidade Demográfica\n");
}

int main() {
    // --- Cadastro das cartas ---
    struct Carta carta1 = {"Brasil", 213000000, 8515767.0, 2200000.0, 50, 0};
    struct Carta carta2 = {"Canadá", 38000000, 9984670.0, 2100000.0, 30, 0};

    // Calcula densidade demográfica
    carta1.densidadeDemografica = carta1.populacao / carta1.area;
    carta2.densidadeDemografica = carta2.populacao / carta2.area;

    int atributo1 = 0, atributo2 = 0;

    printf("\n===== SUPER TRUNFO - COMPARAÇÃO DUPLA =====\n\n");

    // --- Escolha do primeiro atributo ---
    do {
        mostrarMenu(0);
        printf("Escolha o PRIMEIRO atributo: ");
        scanf("%d", &atributo1);
        if (atributo1 < 1 || atributo1 > 5)
            printf("Opção inválida. Tente novamente.\n");
    } while (atributo1 < 1 || atributo1 > 5);

    // --- Escolha do segundo atributo (diferente do primeiro) ---
    do {
        mostrarMenu(atributo1);
        printf("Escolha o SEGUNDO atributo (diferente do primeiro): ");
        scanf("%d", &atributo2);
        if (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1)
            printf("Opção inválida ou repetida. Tente novamente.\n");
    } while (atributo2 < 1 || atributo2 > 5 || atributo2 == atributo1);

    float valor1_c1 = 0, valor1_c2 = 0;
    float valor2_c1 = 0, valor2_c2 = 0;

    // --- Atribuição dos valores para comparação ---
    switch (atributo1) {
        case 1: valor1_c1 = carta1.populacao; valor1_c2 = carta2.populacao; break;
        case 2: valor1_c1 = carta1.area; valor1_c2 = carta2.area; break;
        case 3: valor1_c1 = carta1.pib; valor1_c2 = carta2.pib; break;
        case 4: valor1_c1 = carta1.pontosTuristicos; valor1_c2 = carta2.pontosTuristicos; break;
        case 5: valor1_c1 = carta1.densidadeDemografica; valor1_c2 = carta2.densidadeDemografica; break;
    }

    switch (atributo2) {
        case 1: valor2_c1 = carta1.populacao; valor2_c2 = carta2.populacao; break;
        case 2: valor2_c1 = carta1.area; valor2_c2 = carta2.area; break;
        case 3: valor2_c1 = carta1.pib; valor2_c2 = carta2.pib; break;
        case 4: valor2_c1 = carta1.pontosTuristicos; valor2_c2 = carta2.pontosTuristicos; break;
        case 5: valor2_c1 = carta1.densidadeDemografica; valor2_c2 = carta2.densidadeDemografica; break;
    }

    // --- Impressão clara dos dados comparados ---
    printf("\n--- Comparando: %s vs %s ---\n", carta1.nome, carta2.nome);

    printf("\nAtributo 1 (%d): %.2f x %.2f\n", atributo1, valor1_c1, valor1_c2);
    printf("Atributo 2 (%d): %.2f x %.2f\n", atributo2, valor2_c1, valor2_c2);

    // --- Comparações usando regras e operador ternário ---
    float resultado1 = (atributo1 == 5) ? ((valor1_c1 < valor1_c2) ? 1 : 0) : ((valor1_c1 > valor1_c2) ? 1 : 0);
    float resultado2 = (atributo2 == 5) ? ((valor2_c1 < valor2_c2) ? 1 : 0) : ((valor2_c1 > valor2_c2) ? 1 : 0);

    // Soma dos dois valores para cada carta
    float soma1 = valor1_c1 + valor2_c1;
    float soma2 = valor1_c2 + valor2_c2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", carta1.nome, soma1);
    printf("%s: %.2f\n", carta2.nome, soma2);

    // --- Resultado Final ---
    if (soma1 > soma2) {
        printf("\n***Vencedor*** %s\n", carta1.nome);
    } else if (soma2 > soma1) {
        printf("\n***Vencedor*** %s\n", carta2.nome);
    } else {
        printf("\n***Empate!***\n");
    }

    return 0;
}
