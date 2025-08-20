#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

void cadastroCarta(
    int numCarta, 
    char *c_uf, 
    char c_nome[], 
    int *c_id, 
    unsigned long int *c_pop, 
    float *c_km, 
    float *c_pib, 
    int *c_pt, 
    float *c_dp, 
    float *c_pibC, 
    float *c_super
) {
    printf("\n ----- Cadastro de Carta %i ----- \n", numCarta);
    printf("\n 1.1 - De qual estado ela é?              [ A - H ]: ");
    scanf(" %c", c_uf);

    printf("\n 1.2 - Qual o nome dela? [ nomes compostos usar \"-\" ]: ");
    scanf("%s", c_nome);

    printf("\n 1.3 - Escolha um código:       [ 1 - 4 ]: ");
    scanf("%d", c_id);

    printf("\n 1.4 - Qual a população estimada?         [ Ex.: xxxxx s/ \".\" ]: ");
    scanf("%lu", c_pop);

    printf("\n 1.5 - Qual a area (km²) total estimada?        [ Ex.: xxxxx ]: ");
    scanf("%f", c_km);

    printf("\n 1.6 - Qual o PIB estimado?               [ Ex.: xxxxx ]: ");
    scanf("%f", c_pib);

    printf("\n 1.7 - Quantos pontos turisticos possui? ");
    scanf("%d", c_pt);

    *c_dp   = (float)(*c_pop) / (*c_km);
    *c_pibC = (float)(*c_pib) / (*c_pop);
    *c_super = (float)(*c_pop + *c_km + *c_pib + *c_pt + *c_pibC + (1 / *c_dp));
}


void exibirCarta(int numCarta, char c_uf, char c_nome[], int c_id, unsigned long int c_pop, float c_km, float c_pib, int c_pt, float c_dp, float c_pibC, float c_super)
{
    printf("\n ----- Exibindo Carta %i ----- \n"
           "-> Código: %c%d \n"
           "-> Estado: %c\n"
           "-> Nome: %s \n"
           "-> Populacao: %lu \n"
           "-> Area: %.2fkm² \n"
           "-> PIB: %.2f  \n"
           "-> Qtd Pontos Turisticos: %d  \n"
           "-> Densidade Populacional: %.2f hab/km² \n"
           "-> PIB per Capita: %f  \n"
           "-> Super Poder: %.2f  \n",
           numCarta,
           c_uf, c_id,
           c_uf,
           c_nome,
           c_pop,
           c_km,
           c_pib,
           c_pt,
           c_dp,
           c_pibC,
           c_super);
}

int main()
{
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio
    char c1_uf, c2_uf;
    char c1_nome[30], c2_nome[30];
    int c1_id, c2_id;
    unsigned long int c1_pop, c2_pop;
    float c1_km, c2_km;
    float c1_pib, c2_pib;
    int c1_pt, c2_pt;
    float c1_dp, c2_dp;
    float c1_pibC, c2_pibC; // Necessário uma validação, se PIB é milhões ou bilhões.
    float c1_super, c2_super;

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio
    cadastroCarta(
        1,
        &c1_uf,
        c1_nome,
        &c1_id,
        &c1_pop,
        &c1_km,
        &c1_pib,
        &c1_pt,
        &c1_dp,
        &c1_pibC,
        &c1_super);

    cadastroCarta(
        2,
        &c2_uf,
        c2_nome,
        &c2_id,
        &c2_pop,
        &c2_km,
        &c2_pib,
        &c2_pt,
        &c2_dp,
        &c2_pibC,
        &c2_super);

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.
    printf("\n -> Vamos comparar com base na população! \n");
    printf("1 - %s: %lu \n", c1_nome, c1_pop);
    printf("2 - %s: %lu \n", c2_nome, c2_pop);

    if (c1_pop > c2_pop)
    {
        printf("--> Cidade 1 - %s tem maior população.\n", c1_nome);
    }
    else
    {
        printf("--> Cidade 2 - %s tem maior população.\n", c2_nome);
    }

    return 0;
}
