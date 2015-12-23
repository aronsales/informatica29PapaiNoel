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
#include <wchar.h>

#define MAXTAB 3

//codigos para usar caracteres especiais da tabela ASCII
#define WUL L'\u2518' /* ^VU2518 ┘ */  
#define WDL L'\u2510' /* ^VU2510 ┐ */  
#define WDR L'\u250c' /* ^VU250c ┌ */  

#define WUR L'\u2514' /* ^VU2514 └ */  
#define WVH L'\u253c' /* ^VU253c ┼ */
#define WHH L'\u2500' /* ^VU2500 ─ */  
#define WVR L'\u251c' /* ^VU251c ├ */

#define WVL L'\u2524' /* ^VU2524 ┤ */

#define WUH L'\u2534' /* ^VU2534 ┴ */
#define WDF L'\u252c' /* ^VU252c ┬ */

#define WVV L'\u2502' /* ^VU2502 │ */

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

int tabuleiro1,tabuleiro2,tabuleiro3,tabuleiro4,tabuleiro5,tabuleiro6,tabuleiro7,tabuleiro8,tabuleiro9;
int jogada;
int turnojogador;

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

int jogada()
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

int nivelfacil ()
{
    int jogadafacil;
    if(jogadafacil==0)
    {
        srand(time(NULL));
        jogada=rand()%MAXCASAS;

        if(jogada==1 && tabuleiro1==0)
        {
            if(turnojogador=1)
                tabuleiro1=tabuleiro1+1;
            else
                tabuleiro1=tabuleiro1-1;
            jogadafacil=jogadafacil+1;
        }
        if(jogada==2 && tabuleiro2==0)
        {
            if(turnojogador=1)
                tabuleiro2=tabuleiro2+1;
            else
                tabuleiro2=tabuleiro2-1;
            jogadafacil=jogadafacil+1;
        }
        if(jogada==3 && tabuleiro3==0)
        {
            if(turnojogador=1)
                tabuleiro3=tabuleiro3+1;
            else
                tabuleiro3=tabuleiro3-1;
            jogadafacil=jogadafacil+1;
        }
        if(jogada==4 && tabuleiro4==0)
        {
            if(turnojogador=1)
                tabuleiro4=tabuleiro4+1;
            else
                tabuleiro4=tabuleiro4-1;
            jogadafacil=jogadafacil+1;
        }

        if(jogada==5 && tabuleiro5==0)
        {
            if(turnojogador=1)
                tabuleiro5=tabuleiro5+1;
            else
                tabuleiro5=tabuleiro5-1;
            jogadafacil=jogadafacil+1;
        }

        if(jogada==6 && tabuleiro6==0)
        {
            if(turnojogador=1)
                tabuleiro6=tabuleiro6+1;
            else
                tabuleiro6=tabuleiro6-1;
            jogadafacil=jogadafacil+1;
        }

        if(jogada==7 && tabuleiro7==0)
        {
            if(turnojogador=1)
                tabuleiro7=tabuleiro7+1;
            else
                tabuleiro7=tabuleiro7-1;
            jogadafacil=jogadafacil+1;
        }

        if(jogada==8 && tabuleiro8==0)
        {
            if(turnojogador=1)
                tabuleiro8=tabuleiro8+1;
            else
                tabuleiro8=tabuleiro8-1;
            jogadafacil=jogadafacil+1;
        }


        if(jogada==9 && tabuleiro9==0)
        {
            if(turnojogador=1)
                tabuleiro9=tabuleiro9+1;
            else
                tabuleiro9=tabuleiro9-1;
            jogadafacil=jogadafacil+1;
        }
    }
}

void tabuleiro (wchar_t tab[3][3])
{
    printf("%lc%lc%lc%lc%lc", tab[0][0], WVV, tab[0][1], WVV, tab[0][2]);
    printf("\n%lc%lc%lc%lc%lc", WHH, WVH, WHH, WVH, WHH);
    printf("\n%lc%lc%lc%lc%lc", tab[1][0], WVV, tab[1][1], WVV, tab[1][2]);
    printf("\n%lc%lc%lc%lc%lc", WHH, WVH, WHH, WVH, WHH);
    printf("\n%lc%lc%lc%lc%lc", tab[2][0], WVV, tav[2][1], WVV, tab[2][2]);
    printf("\n");
    return;
}

