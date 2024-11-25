#include <stdio.h>
#include <stdlib.h>

// Desafio Super Trunfo - Países
// Tema 2 - Comparação das Cartas
// Este código inicial serve como base para o desenvolvimento do sistema de comparação de cartas de cidades. 
// Siga os comentários para implementar cada parte do desafio.

// Definindo novos tipos de variaveis
typedef unsigned int    uint;
typedef unsigned char   uchar;

// strutura da carta
typedef struct CartasSuperTrunfo {
        uchar    
            estado,
            codigo[4],
            nome[50];
        uint
            populacao,
            nPontosTuristicos;
        float
            area,
            dencidade,
            pib,
            pibPCapita;

} CartasSuperTrunfo;


float calcularDiv(float, float);                            // faz divisão de dois valores...
int compara(float*, float*);                                // compara 2 valores retornado -1, 0 e 1 
CartasSuperTrunfo *cadastro(void);                          // faz o cadastro da carta
void exibir(CartasSuperTrunfo*, CartasSuperTrunfo*);          
void menucompara(CartasSuperTrunfo*, CartasSuperTrunfo*);
int menu(void);


int main() {
    // Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    CartasSuperTrunfo
        *cartaJogador1 = NULL,
        *cartaJogador2 = NULL;

    int 
        opcao = 0;

    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    do
    {

        opcao = menu();

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)
    switch (opcao)
    {
    case 0:
        printf("\n\n\nTenha um bom dia....\n\nPrecione qualquer tecla para continuar....\n\n\n");
        getchar();
        break;
        // Comparação de Cartas:
        // Desenvolva a lógica de comparação entre duas cartas.
        // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

        // Exemplo:
        // if (populacaoA > populacaoB) {
        //     printf("Cidade 1 tem maior população.\n");
        // } else {
        //     printf("Cidade 2 tem maior população.\n");
        // }
    case 1:
        cartaJogador1 = cadastro();
        break;
    case 2:
        cartaJogador2 = cadastro();
        break;
    case 3:
        if (cartaJogador1 && cartaJogador2)
            menucompara(cartaJogador1, cartaJogador2);
        else if (!cartaJogador1)
            printf("\n\n\n\t Falta cadastra carta para Jogador 1... \n\tPrecione qualquer tecla para continuar...\n\n\n");
        else if (!cartaJogador2)
            printf("\n\n\n\t Falta cadastra carta para Jogador 2... \n\tPrecione qualquer tecla para continuar...\n\n\n");
        getchar();
        break;
    case 4:
        if(cartaJogador1 && cartaJogador2)
            exibir(cartaJogador1, cartaJogador2);
        else
            printf("\n\n\n\tPara exibie é preciso cadastrar Jogador 1 e 2... \n\tPrecione qualquer tecla para continuar...\n\n\n");
        break;
    default:
        printf("\n\n\n\t\t    Opção invalida... \n\tPrecione qualquer tecla para continuar...\n\n\n");
        getchar();
        break;
    }


    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);


    } while (opcao);
    
    free(cartaJogador1);
    free(cartaJogador2);
    
    return 0;
}

// faz divisao dos numeros
float calcularDiv(float dividendo, float divisor) {

    return dividendo / divisor;
}

/* compara qual numero float e maior 
** se for o positivo retorna 1
** se for o negativo retorna -1 
** se for igual retorna 0 */
int compara(float* positivo, float* negativo) {
    
    if (positivo != negativo)
        if (positivo > negativo)
            return 1;
        else
            return -1;
    
    return 0;
}

// Cadastro de cartas
CartasSuperTrunfo *cadastro(void) {
    
    CartasSuperTrunfo
        *carta = (CartasSuperTrunfo*) malloc(sizeof(CartasSuperTrunfo));

        printf("\n\n\n"); // Pula linhas para iniciar o cadastro
        printf("Digite letra do Estado da cidade:\t");
        scanf(" %c", &carta->estado);
        getchar();
        printf("Digite o codigo da cidade:\t\t");
        getchar();
        scanf("%4[^\n]c", &carta->codigo);
        getchar();
        printf("Digite o neme da cidade:\t\t");
        scanf("%50[^\n]s", &carta->nome);
        printf("Digite a População da cidade:\t\t");
        scanf("%i", &carta->populacao);
        printf("Digite a are da cidade:\t\t\t");
        scanf("%f", &carta->area);
        printf("Digite o PIB da cidade:\t\t\t");
        scanf("%f", &carta->pib);
        printf("Digite o Pontos Turisticos da cidade:\t");
        scanf("%i", &carta->nPontosTuristicos);

        carta->dencidade = calcularDiv(carta->populacao, carta->area);
        carta->pibPCapita = calcularDiv(carta->pib * 1000000000, (float)carta->populacao);
        getchar();
    return carta;
}

void exibir(CartasSuperTrunfo* carta1, CartasSuperTrunfo* carta2){

        printf("\n\n");      
        printf("\nPropriedades\t\t\t\tJogador1\t\t\t\tJogador2\n");
        printf("\nEstado:\t\t\t%20c\t\t%20c\n", carta1->estado, carta2->estado);
        printf("Codigo:\t\t\t%20s\t\t%20s\n", carta1->codigo, carta2->codigo);
        printf("Cidade:\t\t\t%20s\t\t%20s\n", carta1->nome, carta2->nome);
        printf("População:\t\t%20d\t\t%20d\n", carta1->populacao, carta2->populacao);
        printf("Are em Km²:\t\t%20.2f\t\t%20.2f\n", carta1->area, carta2->area);
        printf("Dencidade Populacional:\t%20.2f\t\t%20.2f\n",carta1->dencidade, carta2->dencidade);
        printf("PIB em Bilhões R$:\t%20.2f\t\t%20.2f\n", carta1->pib, carta2->pib);
        printf("PIB per capita R$:\t%20.2f\t\t%20.2f\n", carta1->pibPCapita, carta2->pibPCapita);
        printf("Ponto Turistico:\t%20d\t\t%20d\n\n\n", carta1->nPontosTuristicos, carta2->nPontosTuristicos);

}
/****************************************
 *                                      *
 *  Carega o menu de poções principais  *
 *                                      *
 ****************************************/
int menu(void) {
    int opcao;
    printf("*************************************************\n*\n");
    printf("*\t1 - Digitar cartas Jogador 1\t\t*\n");
    printf("*\t2 - Digitar cartas Jogador 2\t\t*\n");
    printf("*\t3 - Comarar cartas\t\t\t*\n");
    printf("*\t4 - Exibir cartas\t\t\t*\n");
    printf("*\t0 - Sair do jogo\t\t\t*\n");
    printf("*\t\t\t\t\t\t*\n*\t\t\t\t\t\t*\n*\tOpção: ");
    scanf("%d", &opcao);
    getchar();
    printf("*\t\t\t\t\t\t*\n*************************************************\n");
    return opcao;
}

/****************************************
 *                                      *
 *  carrega menu com jagadas e faz as   *
 *  comparações das cartas e contagem   *
 *  de pontos e retorna o resultado     *
 *                                      *
 ****************************************/
void menucompara(CartasSuperTrunfo *j1, CartasSuperTrunfo *j2){

    int 
        opcao,
        pontos = 0;
    short
        populacao = 1,
        pontTuristicos = 1,
        are = 1,
        dencPopulacional = 1,
        pib = 1,
        pibpcapita =1;
    do {
        printf("************************************************\n*\n");
        printf("*\tEscolah o campo para compara!!\n");
        printf("************************************************\n*\n");
        printf("*\t1 - População\n");
        printf("*\t2 - Pontos turisticos\n");
        printf("*\t3 - area\n");
        printf("*\t4 - Decidade Populacional\n");
        printf("*\t5 - P.I.B.\n");
        printf("*\t6 - P.I.B. per capita\n");
        printf("*\t0 - Vencedor e sair\n");
        printf("*\n*\tOpção: ");
        scanf("%d", &opcao);
        printf("*\n************************************************\n*\n");

        switch (opcao)
        {
        case 0:
            if(pontos)
                if(pontos > 0)
                    printf("\tVitória Joagador 1.....\n\n");
                else
                    printf("\tVitória jogador 2.....\n\n");
            else
                printf("\tEmpate....\n\n");
            return;
        case 1:
            if (populacao) {
                pontos += compara((float*)j1->populacao, (float*)j2->populacao);
                populacao = 0;
            } else
                printf("Esta opção ja foi escolhida!!!");
        
            break;
    
        case 2:
            if (pontTuristicos){
                pontos += compara((float*)j1->nPontosTuristicos, (float*)j2->nPontosTuristicos);
                pontTuristicos = 0;
            } else
                printf("Esta opção ja foi escolhida!!!");
            break;
        case 3:
            if (are){
                pontos += compara(&j1->area, &j2->area);
                are = 0;
            } else
                ("Esta opção ja foi escolhida!!!");
    
            break;
        case 4:
            if (dencPopulacional) {
                pontos -= compara(&j1->dencidade, &j2->dencidade);
                dencPopulacional = 0;
            } else
                ("Esta opção ja foi escolhida!!!");
            break;
        case 5:
            if (pib){
                pontos += compara(&j1->pib,&j2->pib);
                pib = 0;
            } else
                ("Esta opção ja foi escolhida!!!");
            break;
        case 6:
            if (pibpcapita) {
                pontos += compara(&j1->pibPCapita, &j2->pibPCapita);
            } else
                ("Esta opção ja foi escolhida!!!");
            break;    
        default:
            break;
        }
    } while (1);
 
}