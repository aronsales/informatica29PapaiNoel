/* ex29.c - "Jogo da velha"
 * Autores:
 * -Aron Sales de Melo de Medeiros Monteiro
 * -Guido de Lyra Ferrario
 **/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <locale.h>

//codigos para usar caracteres especiais da tabela ASCII
#ifdef __linux__
#define UL L'\u2518' /* ┘ */
#define UR L'\u2514' /* └ */
#define UH L'\u2534' /* ┴ */
#define DR L'\u250c' /* ┌ */
#define DL L'\u2510' /* ┐ */
#define DH L'\u252c' /* ┬ */
#define VR L'\u251c' /* ├ */
#define VL L'\u2524' /* ┤ */
#define VH L'\u253c' /* ┼ */
#define HH L'\u2500' /* ─ */
#define VV L'\u2502' /* │ */
#elif _WIN32 || _WIN64
#define UL 0xd9 /* ┘ */
#define UR 0xc0 /* └ */
#define UH 0xc1 /* ┴ */
#define DR 0xda /* ┌ */
#define DL 0xbf /* ┐ */
#define DH 0xc2 /* ┬ */
#define VR 0xc3 /* ├ */
#define VL 0xb4 /* ┤ */
#define VH 0xc5 /* ┼ */
#define HH 0xc4 /* ─ */
#define VV 0xb3 /* │ */

#else
#error "este programa nao eh compativel com o sistema"
#endif

typedef struct
{
    int tab[MAXTAB][MAXTAB];
    int modo;
    int nivel;
}Velha;

//prototipo de funcoes
int inicializacao(void);
int tabuleiro(void);
int menu(void);
int humanos;
int humanoxpc;
int nivelfacil(int tab[MAXTAB][MAXTAB], int vez);
int nivelmedio(int tab[MAXTAB][MAXTAB], int vez);
int niveldificil(int tab[MAXTAB][MAXTAB], int vez);

Velha velha;

void inicializacao ()
{
    printf("\nBem-vindo(a) ao programa informatica29PapaiNoel!!");
    printf("\nPrograma criado por: \n Aron Sales de Melo de Medeiros Monteiro, e \n Guido de Lyra Ferrario.");
    printf("\nO programa traz o tradicional Jogo da Velha!\n");
}

void menu ()
{
    printf("\nHa tres modalidades disponiveis: \n Pressione '1' se voce deseja um jogo com dois humanos; \n '2' se voce deseja ver uma partida simulada; \n '3' se voce deseja jogar contra a maquina!\n");
    scanf("%d",velha.modo);
    //se tiver escolhido a opcao 3
    printf("\n Voce escolheu jogar contra a maquina, por favor, informe em qual dificuldade voce deseja o desafio:");
    printf("\n '4' - Nivel facil");
    printf("\n '5' - Nivel medio");
    printf("\n '6' - Nivel dificil");
    scanf("%d",velha.nivel);
    printf("\nO usuario devera escolher em qual 'casa' ele jogara!");
    printf("\n Exemplo de tabuleiro:");
    printf("\n 1 | 2 | 3");
    printf("\n ----------");
    printf("\n 4 | 5 | 6");
    printf("\n ----------");
    printf("\n 7 | 8 | 9");
}

void jogada()
{
    printf("Escolha a casa que voce quer jogar");
    scanf("%d", jogada);

    if(jogada==1 && tabuleiro1==0)
        if(turnojogador==1)
            tabuleiro1=tabuleiro1+1;
        else
            tabuleiro1=tabuleiro1-1;

    if(jogada==2 && tabuleiro2==0)
        if(turnojogador==1)
            tabuleiro2=tabuleiro2+1;
        else
            tabuleiro2=tabuleiro2-1;

    if(jogada==3 && tabuleiro3==0)
        if(turnojogador==1)
            tabuleiro3=tabuleiro3+1;
        else
            tabuleiro3=tabuleiro3-1;

    if(jogada==4 && tabuleiro4==0)
        if(turnojogador==1)
            tabuleiro4=tabuleiro4+1;
        else
            tabuleiro4=tabuleiro4-1;

    if(jogada==5 && tabuleiro5==0)
        if(turnojogador==1)
            tabuleiro5=tabuleiro5+1;
        else
            tabuleiro5=tabuleiro5-1;

    if(jogada==6 && tabuleiro6==0)
        if(turnojogador==1)
            tabuleiro6=tabuleiro6+1;
        else
            tabuleiro6=tabuleiro6-1;

    if(jogada==7 && tabuleiro7==0)
        if(turnojogador==1)
            tabuleiro7=tabuleiro7+1;
        else
            tabuleiro7=tabuleiro7-1;

    if(jogada==8 && tabuleiro8==0)
        if(turnojogador==1)
            tabuleiro8=tabuleiro8+1;
        else
            tabuleiro8=tabuleiro8-1;

    if(jogada==9 && tabuleiro9==0)
        if(turnojogador==1)
            tabuleiro9=tabuleiro9+1;
        else
            tabuleiro9=tabuleiro9-1;
}
