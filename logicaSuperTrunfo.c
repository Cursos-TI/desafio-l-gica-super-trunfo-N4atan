#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades.
// Siga os comentários para implementar cada parte do desafio.

void cadastroCarta(int numCarta, char *c_uf, char c_nome[], int *c_id, unsigned long int *c_pop, float *c_km, float *c_pib, int *c_pt, float *c_dp, float *c_pibC, float *c_super)
{
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

    *c_dp = (float)(*c_pop) / (*c_km);
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

// 'void *' é um ponteiro coringa
void comparaCaracteristicas(int isDP, void *c1, void *c2, char tipo)
{
    if (isDP)
    {
        float a = *(float *)c1;
        float b = *(float *)c2;

        if (a == b)
        {
            printf("Empate!");
        }
        else if (a < b)
        {
            printf("A Carta 1 Vence!");
        }
        else
        {
            printf("A Carta 2 Vence!");
        }

        return;
    }

    switch (tipo)
    {
    case 'i':
        int ai = *(int *)c1;
        int bi = *(int *)c2;
        
        if (ai == bi) 
        {
            printf("Empate!\n");
        } else if (ai > bi) {
            printf("Carta 1 vence!\n");
        } else {
            printf("Carta 2 vence!\n");
        }
        break;

    case 'f':
        float af = *(float *)c1;
        float bf = *(float *)c2;

        if (af == bf) 
        {
            printf("Empate!\n");
        } else if (af > bf) {
            printf("Carta 1 vence!\n");
        } else {
            printf("Carta 2 vence!\n");
        }
        break;

    case 'd':
        double ad = *(double *)c1;
        double bd = *(double *)c2; 
        
        if (ad == bd) 
        {
            printf("Empate!\n");
        } else if (ad > bd) {
            printf("Carta 1 vence!\n");
        } else {
            printf("Carta 2 vence!\n");
        }
        break;

    case 'u':
        unsigned long int au = *(unsigned long int *)c1;
        unsigned long int bu = *(unsigned long int *)c2; 
        
        if (au == bu) 
        {
            printf("Empate!\n");
        } else if (au > bu) {
            printf("Carta 1 vence!\n");
        } else {
            printf("Carta 2 vence!\n");
        }
        break;
    }
}

int main()
{
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

    int opMenu;

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


    printf("---         Super Trunfo         --- \n");
    printf("-- Qual Atributo Deseja Comparar? -- \n");
    printf("- 1. População                     - \n");
    printf("- 2. Area Total                    - \n");
    printf("- 3. PIB                           - \n");
    printf("- 4. Pontos Turisticos             - \n");
    printf("- 5. Densidade Populacional        - \n");
    printf("- 6. PIB p/Capita                  - \n");
    printf("- 7. Super Poder                   - \n");
    printf("R: ");
    scanf("%i", &opMenu);

    switch (opMenu)
    {
    case 1:
        printf("-> Comparando Populacao: \n");
        comparaCaracteristicas(0, &c1_pop, &c2_pop, 'u');
        break;

    case 2:
        printf("-> Comparando Area Total: \n");
        comparaCaracteristicas(0, &c1_km, &c2_km, 'f');
        break;

    case 3:
        printf("-> Comparando PIB: \n");
        comparaCaracteristicas(0, &c1_pib, &c2_pib, 'f');
        break;

    case 4:
        printf("-> Comparando Pontos Turisticos: \n");
        comparaCaracteristicas(0, &c1_pt, &c2_pt, 'i');
        break;

    case 5:
        printf("-> Comparando Densidade Populacional: \n");
        comparaCaracteristicas(1, &c1_dp, &c2_dp, 'f');
        break;

    case 6:
        printf("-> Comparando PIB per/Capita: \n");
        comparaCaracteristicas(0, &c1_pibC, &c2_pibC, 'f');
        break;

    case 7:
        printf("-> Comparando Super Poder (Soma de todos atributos): \n");
        comparaCaracteristicas(0, &c1_super, &c2_super, 'f');
        break;

    default:
        printf("-> Ops... opcao invalida! \n");
        break;
    }

    return 0;
}
