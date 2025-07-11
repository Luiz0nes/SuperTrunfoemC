#include <stdio.h>
#include <string.h>

// Definindo a estrutura de uma carta
struct Carta {
    char estado[3];            // Ex: "SP"
    char codigo[10];           // Código da carta (identificador)
    char nomeCidade[50];       // Nome da cidade
    int populacao;             // População total
    float area;                // Área em km²
    float pib;                 // Produto Interno Bruto em bilhões
    int pontosTuristicos;      // Número de pontos turísticos
    float densidadePopulacional; // População / Área
    float pibPerCapita;          // PIB / População
};

int main() {
    // --- Cadastro das Cartas (Pré-definido) ---

    struct Carta carta1 = {
        "SP",
        "C1",
        "São Paulo",
        12300000,
        1521.11,
        7012089000.0,
        25
    };

    struct Carta carta2 = {
        "RJ",
        "C2",
        "Rio de Janeiro",
        6710000,
        1182.3,
        4034308000.0,
        18
    };

    // --- Cálculo da Densidade Populacional e PIB per capita ---

    carta1.densidadePopulacional = carta1.populacao / carta1.area;
    carta2.densidadePopulacional = carta2.populacao / carta2.area;

    carta1.pibPerCapita = carta1.pib / carta1.populacao;
    carta2.pibPerCapita = carta2.pib / carta2.populacao;

    // --- Comparação: escolher o atributo desejado aqui ---
    // Atributos disponíveis: populacao, area, pib, densidadePopulacional, pibPerCapita

    printf("Comparação de cartas (Atributo: PIB per capita):\n\n");

    printf("Carta 1 - %s (%s): R$ %.2f\n", carta1.nomeCidade, carta1.estado, carta1.pibPerCapita);
    printf("Carta 2 - %s (%s): R$ %.2f\n", carta2.nomeCidade, carta2.estado, carta2.pibPerCapita);

    // --- Lógica para determinar o vencedor ---
    // Lembrando: para PIB per capita, o maior valor vence

    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("\nResultado: Carta 1 (%s) venceu!\n", carta1.nomeCidade);
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("\nResultado: Carta 2 (%s) venceu!\n", carta2.nomeCidade);
    } else {
        printf("\nResultado: Empate!\n");
    }

    return 0;
}
