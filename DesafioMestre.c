#include <stdio.h>

// Estrutura para armazenar os dados da carta
struct Carta {
    char estado;
    char codigo[4];
    char nomeCidade[100];
    unsigned long int populacao;
    float area;
    float pib; // em bilhões de reais
    int pontosTuristicos;
    float densidadePopulacional;
    float pibPerCapita;
    float superPoder;
};

// Função para calcular os dados derivados
void calcularIndicadores(struct Carta *c) {
    c->densidadePopulacional = c->populacao / c->area;
    c->pibPerCapita = (c->pib * 1000000000) / c->populacao;
    float inversoDensidade = 1 / c->densidadePopulacional;
    c->superPoder = (float)c->populacao + c->area + c->pib + c->pontosTuristicos + c->pibPerCapita + inversoDensidade;
}

// Função para imprimir comparação
void compararEAvaliar(char *atributo, float valor1, float valor2, int menorVence) {
    int resultado;
    if (menorVence)
        resultado = valor1 < valor2;
    else
        resultado = valor1 > valor2;

    printf("%s: Carta 1 venceu (%d)\n", atributo, resultado);
}

int main() {
    struct Carta carta1, carta2;

    // Leitura da Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("Estado (A-H): "); scanf(" %c", &carta1.estado);
    printf("Código (ex: A01): "); scanf("%s", carta1.codigo);
    printf("Nome da cidade: "); scanf(" %[^\n]s", carta1.nomeCidade);
    printf("População: "); scanf("%lu", &carta1.populacao);
    printf("Área (km²): "); scanf("%f", &carta1.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta1.pib);
    printf("Nº de pontos turísticos: "); scanf("%d", &carta1.pontosTuristicos);

    // Leitura da Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("Estado (A-H): "); scanf(" %c", &carta2.estado);
    printf("Código (ex: B03): "); scanf("%s", carta2.codigo);
    printf("Nome da cidade: "); scanf(" %[^\n]s", carta2.nomeCidade);
    printf("População: "); scanf("%lu", &carta2.populacao);
    printf("Área (km²): "); scanf("%f", &carta2.area);
    printf("PIB (em bilhões): "); scanf("%f", &carta2.pib);
    printf("Nº de pontos turísticos: "); scanf("%d", &carta2.pontosTuristicos);

    // Cálculos
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Exibição dos dados
    printf("\n--- Informações das Cartas ---\n");

    printf("\nCarta 1:\n");
    printf("Estado: %c\n", carta1.estado);
    printf("Código: %s\n", carta1.codigo);
    printf("Cidade: %s\n", carta1.nomeCidade);
    printf("População: %lu\n", carta1.populacao);
    printf("Área: %.2f km²\n", carta1.area);
    printf("PIB: %.2f bilhões\n", carta1.pib);
    printf("Pontos Turísticos: %d\n", carta1.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta1.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta1.pibPerCapita);
    printf("Super Poder: %.2f\n", carta1.superPoder);

    printf("\nCarta 2:\n");
    printf("Estado: %c\n", carta2.estado);
    printf("Código: %s\n", carta2.codigo);
    printf("Cidade: %s\n", carta2.nomeCidade);
    printf("População: %lu\n", carta2.populacao);
    printf("Área: %.2f km²\n", carta2.area);
    printf("PIB: %.2f bilhões\n", carta2.pib);
    printf("Pontos Turísticos: %d\n", carta2.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta2.densidadePopulacional);
    printf("PIB per Capita: %.2f reais\n", carta2.pibPerCapita);
    printf("Super Poder: %.2f\n", carta2.superPoder);

    // Comparações
    printf("\nComparação de Cartas:\n");
    compararEAvaliar("População", (float)carta1.populacao, (float)carta2.populacao, 0);
    compararEAvaliar("Área", carta1.area, carta2.area, 0);
    compararEAvaliar("PIB", carta1.pib, carta2.pib, 0);
    compararEAvaliar("Pontos Turísticos", (float)carta1.pontosTuristicos, (float)carta2.pontosTuristicos, 0);
    compararEAvaliar("Densidade Populacional", carta1.densidadePopulacional, carta2.densidadePopulacional, 1); // menor vence
    compararEAvaliar("PIB per Capita", carta1.pibPerCapita, carta2.pibPerCapita, 0);
    compararEAvaliar("Super Poder", carta1.superPoder, carta2.superPoder, 0);

    return 0;
}
