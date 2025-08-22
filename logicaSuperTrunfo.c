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
int comparaCaracteristicas(int isDP, void *c1, void *c2, char tipo)
{
    if (isDP)
    {
        float a = *(float *)c1;
        float b = *(float *)c2;

        return (a == b)? 0 : (a < b)? 1 : 2;
    }

    switch (tipo)
    {
    case 'i':
        int ai = *(int *)c1;
        int bi = *(int *)c2;
        
        return (ai == bi)? 0 : (ai > bi)? 1 : 2;

    case 'f':
        float af = *(float *)c1;
        float bf = *(float *)c2;

        return (af == bf)? 0 : (af > bf)? 1 : 2;

    case 'd':
        double ad = *(double *)c1;
        double bd = *(double *)c2; 
        
        return (ad == bd)? 0 : (ad > bd)? 1 : 2;

    case 'u':
        unsigned long int au = *(unsigned long int *)c1;
        unsigned long int bu = *(unsigned long int *)c2; 

        return (au == bu)? 0 : (au > bu)? 1 : 2;

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

    int opMenu1, opMenu2;
    int result1, result2;
    int empates = 0, vitorias_c1 = 0, vitorias_c2 = 0;

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


    printf("\n---         Super Trunfo                     --- \n");
    printf("-- Qual o Primeiro Atributo a Ser Comparado?  -- \n");
    printf("- 1. População                                 - \n");
    printf("- 2. Area Total                                - \n");
    printf("- 3. PIB                                       - \n");
    printf("- 4. Pontos Turisticos                         - \n");
    printf("- 5. Densidade Populacional                    - \n");
    printf("- 6. PIB p/Capita                              - \n");
    printf("- 7. Super Poder                               - \n");
    printf("R: ");
    scanf("%i", &opMenu1);

    switch (opMenu1)
    {
    case 1:
        printf("-> Comparando Populacao: \n");
        result1 = comparaCaracteristicas(0, &c1_pop, &c2_pop, 'u');
        printf("Resultado: %s", (result1 == 0)? "Empate" : (result1 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 2:
        printf("-> Comparando Area Total: \n");
        result1 = comparaCaracteristicas(0, &c1_km, &c2_km, 'f');
        printf("Resultado: %s", (result1 == 0)? "Empate" : (result1 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 3:
        printf("-> Comparando PIB: \n");
        result1 = comparaCaracteristicas(0, &c1_pib, &c2_pib, 'f');
        printf("Resultado: %s", (result1 == 0)? "Empate" : (result1 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 4:
        printf("-> Comparando Pontos Turisticos: \n");
        result1 = comparaCaracteristicas(0, &c1_pt, &c2_pt, 'i');
        printf("Resultado: %s", (result1 == 0)? "Empate" : (result1 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 5:
        printf("-> Comparando Densidade Populacional: \n");
        result1 = comparaCaracteristicas(1, &c1_dp, &c2_dp, 'f');
        printf("Resultado: %s", (result1 == 0)? "Empate" : (result1 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 6:
        printf("-> Comparando PIB per/Capita: \n");
        result1 = comparaCaracteristicas(0, &c1_pibC, &c2_pibC, 'f');
        printf("Resultado: %s", (result1 == 0)? "Empate" : (result1 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 7:
        printf("-> Comparando Super Poder (Soma de todos atributos): \n");
        result1 = comparaCaracteristicas(0, &c1_super, &c2_super, 'f');
        printf("Resultado: %s", (result1 == 0)? "Empate" : (result1 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    default:
        printf("-> Ops... opcao invalida! \n");
        break;
    }

    printf("\n---         Super Trunfo                     --- \n");
    printf("-- Qual o Segundo Atributo a Ser Comparado?   -- \n");
    printf("- 1. População                                 - \n");
    printf("- 2. Area Total                                - \n");
    printf("- 3. PIB                                       - \n");
    printf("- 4. Pontos Turisticos                         - \n");
    printf("- 5. Densidade Populacional                    - \n");
    printf("- 6. PIB p/Capita                              - \n");
    printf("- 7. Super Poder                               - \n");
    printf("R: ");
    scanf("%i", &opMenu2);

    switch (opMenu2)
    {
    case 1:
        printf("-> Comparando Populacao: \n");
        result2 = comparaCaracteristicas(0, &c1_pop, &c2_pop, 'u');
        printf("Resultado: %s", (result2 == 0)? "Empate" : (result2 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 2:
        printf("-> Comparando Area Total: \n");
        result2 = comparaCaracteristicas(0, &c1_km, &c2_km, 'f');
        printf("Resultado: %s", (result2 == 0)? "Empate" : (result2 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 3:
        printf("-> Comparando PIB: \n");
        result2 = comparaCaracteristicas(0, &c1_pib, &c2_pib, 'f');
        printf("Resultado: %s", (result2 == 0)? "Empate" : (result2 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 4:
        printf("-> Comparando Pontos Turisticos: \n");
        result2 = comparaCaracteristicas(0, &c1_pt, &c2_pt, 'i');
        printf("Resultado: %s", (result2 == 0)? "Empate" : (result2 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 5:
        printf("-> Comparando Densidade Populacional: \n");
        result2 = comparaCaracteristicas(1, &c1_dp, &c2_dp, 'f');
        printf("Resultado: %s", (result2 == 0)? "Empate" : (result2 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 6:
        printf("-> Comparando PIB per/Capita: \n");
        result2 = comparaCaracteristicas(0, &c1_pibC, &c2_pibC, 'f');
        printf("Resultado: %s", (result2 == 0)? "Empate" : (result2 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    case 7:
        printf("-> Comparando Super Poder (Soma de todos atributos): \n");
        result2 = comparaCaracteristicas(0, &c1_super, &c2_super, 'f');
        printf("Resultado: %s", (result2 == 0)? "Empate" : (result2 == 1)? "Carta 1 Venceu" : "Carta 2 Venceu");
        break;

    default:
        printf("-> Ops... opcao invalida! \n");
        break;
    }

    

    // Após obter result1 do primeiro atributo
    if (result1 == 0) {
        empates++;
    } else if (result1 == 1) {
        vitorias_c1++;
    } else if (result1 == 2) {
        vitorias_c2++;
    }

    // Após obter result2 do segundo atributo
    if (result2 == 0) {
        empates++;
    } else if (result2 == 1) {
        vitorias_c1++;
    } else if (result2 == 2) {
        vitorias_c2++;
    }

    // Exibir o placar final
    printf("\n\n--- PLACAR FINAL ---\n");
    printf("Empates: %d\n", empates);
    printf("Vitórias Carta 1 (%s): %d\n", c1_nome, vitorias_c1);
    printf("Vitórias Carta 2 (%s): %d\n", c2_nome, vitorias_c2);
    
    return 0;
}
