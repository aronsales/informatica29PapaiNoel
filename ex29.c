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
#include <string.h>

#define MAXCASAS 9

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

#define PRINTGRAF_ON ;
#define PRINTGRAF_OFF ;

int tabuleiro0=0,tabuleiro1=0,tabuleiro2=0,tabuleiro3=0,tabuleiro4=0,tabuleiro5=0,tabuleiro6=0,tabuleiro7=0,tabuleiro8=0;
int mododejogo,dificuldade;
int turnojogador=1;
int turnomaquina=-1;
int vencedor=0;

void inicializacao ()
{
    printf("\nBem-vindo(a) ao programa informatica29PapaiNoel!!");
    printf("\nPrograma criado por: \n Aron Sales de Melo de Medeiros Monteiro, e \n Guido de Lyra Ferrario.");
    printf("\nO programa traz o tradicional Jogo da Velha!\n");
}

void menu ()
{
    printf("\nHa tres modalidades disponiveis: \n");
    printf("Pressione:");
    printf("\n'1' se voce deseja um jogo para dois humanos.");
    printf("\n'2' se voce deseja ver uma partida simulada.");
    printf("\n'3' se voce deseja jogar contra a maquina.\n");
    scanf("%d", &mododejogo);
    if(mododejogo==2 || mododejogo==3)
    {
        printf("\n Voce escolheu jogar contra a maquina, por favor, informe em qual dificuldade voce deseja o desafio:");
        printf("\n '4' - Nivel facil");
        printf("\n '5' - Nivel medio");
        printf("\n '6' - Nivel dificil\n");
        scanf("%d", &dificuldade);
    }
    if(mododejogo==1 || mododejogo==3)
    {
        printf("\n\nO usuario devera escolher em qual 'casa' ele jogara!");
        printf("\n Exemplo de tabuleiro:\n");
        printf("\n  0 | 1 | 2");
        printf("\n -----------");
        printf("\n  3 | 4 | 5");
        printf("\n -----------");
        printf("\n  6 | 7 | 8\n");
        printf("\n Os numeros representam as opcoes de 'casa' para a execucao da jogada!\n\n");
        printf("\n SE O JOGADOR PRESSIONAR UM NUMERO DE UMA CASA JA OCULPADA, PERDERA' A VEZ!!\n");
    }
}

void humanojoga() //jogada do humano
{
    int jogada;

    printf("\nEscolha a casa que voce quer jogar:\n");
    scanf("%d", &jogada);

    if(jogada==0 && tabuleiro0==0)
        if(turnojogador==1)
            tabuleiro0=tabuleiro0+1;
        else
            tabuleiro0=tabuleiro0-1;

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

    if(mododejogo==1)
        if(turnojogador==1)
            turnojogador=turnojogador-2;
        else
            turnojogador=turnojogador+2;

}

void nivelfacil () //nivel facil, jogada da maquina
{
    int marquei=0;
    int jogadafacil;

    while(marquei==0)
    {
        srand(time(NULL));
        jogadafacil=rand()%MAXCASAS;

        if(jogadafacil==0 && tabuleiro0==0)
        {
            if(turnomaquina==1)
                tabuleiro0=tabuleiro0+1;
            else
                tabuleiro0=tabuleiro0-1;
            marquei=marquei+1;
        }
        if(jogadafacil==1 && tabuleiro1==0)
        {
            if(turnomaquina==1)
                tabuleiro1=tabuleiro1+1;
            else
                tabuleiro1=tabuleiro1-1;
            marquei=marquei+1;
        }
        if(jogadafacil==2 && tabuleiro2==0)
        {
            if(turnomaquina==1)
                tabuleiro2=tabuleiro2+1;
            else
                tabuleiro2=tabuleiro2-1;
            marquei=marquei+1;
        }
        if(jogadafacil==3 && tabuleiro3==0)
        {
            if(turnomaquina==1)
                tabuleiro3=tabuleiro3+1;
            else
                tabuleiro3=tabuleiro3-1;
            marquei=marquei+1;
        }

        if(jogadafacil==4 && tabuleiro4==0)
        {
            if(turnomaquina==1)
                tabuleiro4=tabuleiro4+1;
            else
                tabuleiro4=tabuleiro4-1;
            marquei=marquei+1;
        }

        if(jogadafacil==5 && tabuleiro5==0)
        {
            if(turnomaquina==1)
                tabuleiro5=tabuleiro5+1;
            else
                tabuleiro5=tabuleiro5-1;
            marquei=marquei+1;
        }

        if(jogadafacil==6 && tabuleiro6==0)
        {
            if(turnomaquina==1)
                tabuleiro6=tabuleiro6+1;
            else
                tabuleiro6=tabuleiro6-1;
            marquei=marquei+1;
        }

        if(jogadafacil==7 && tabuleiro7==0)
        {
            if(turnomaquina==1)
                tabuleiro7=tabuleiro7+1;
            else
                tabuleiro7=tabuleiro7-1;
            marquei=marquei+1;
        }


        if(jogadafacil==8 && tabuleiro8==0)
        {
            if(turnomaquina==1)
                tabuleiro8=tabuleiro8+1;
            else
                tabuleiro8=tabuleiro8-1;
            marquei=marquei+1;
        }
    }
    if(mododejogo==2)
        if(turnomaquina==1)
            turnomaquina=-1;
        else
            turnomaquina=1;

}

void fim() //funcao para calcular o vencedor da partida
{
    if(tabuleiro0==1 && tabuleiro1==1 && tabuleiro2==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(tabuleiro3==1 && tabuleiro4==1 && tabuleiro5==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(tabuleiro6==1 && tabuleiro7==1 && tabuleiro8==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(tabuleiro0==1 && tabuleiro3==1 && tabuleiro6==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(tabuleiro1==1 && tabuleiro4==1 && tabuleiro7==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(tabuleiro2==1 && tabuleiro5==1 && tabuleiro8==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(tabuleiro0==1 && tabuleiro4==1 && tabuleiro8==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(tabuleiro2==1 && tabuleiro4==1 && tabuleiro6==1)
    {
        vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }

    if(tabuleiro0==-1 && tabuleiro1==-1 && tabuleiro2==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro3==-1 && tabuleiro4==-1 && tabuleiro5==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro6==-1 && tabuleiro7==-1 && tabuleiro8==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro0==-1 && tabuleiro3==-1 && tabuleiro6==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro1==-1 && tabuleiro4==-1 && tabuleiro7==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro2==-1 && tabuleiro5==-1 && tabuleiro8==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro0==-1 && tabuleiro4==-1 && tabuleiro8==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro2==-1 && tabuleiro4==-1 && tabuleiro6==-1)
    {
        vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(tabuleiro0!=0 && tabuleiro1!=0 && tabuleiro2!=0 && tabuleiro3!=0 && tabuleiro4!=0 && tabuleiro5!=0 && tabuleiro6!=0 && tabuleiro7!=0 && tabuleiro8!=0 && vencedor==0)
        printf("\nDeu Velha! ! ! Jogo empatou\n");

}

void tabuleiro() //funcao para imprimir as jogadas no tabuleiro
{
 
    PRINTGRAF_ON ;
    printf("\n\n\n");

    if(tabuleiro0!=0)
    {
        if(tabuleiro0==1)
            printf("X");
        if(tabuleiro0==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(tabuleiro1!=0)
    {
        if(tabuleiro1==1)
            printf("X");
        if(tabuleiro1==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc", WVV);

    if(tabuleiro2!=0)
    {
        if(tabuleiro2==1)
            printf("X");
        if(tabuleiro2==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("\n");
    printf("%lc",WHH);
    printf("%lc",WVH);
    printf("%lc",WHH);
    printf("%lc",WVH);
    printf("%lc",WHH);
    printf("\n");

    if(tabuleiro3!=0)
    {
        if(tabuleiro3==1)
            printf("X");
        if(tabuleiro3==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(tabuleiro4!=0)
    {
        if(tabuleiro4==1)
            printf("X");
        if(tabuleiro4==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(tabuleiro5!=0)
    {
        if(tabuleiro5==1)
            printf("X");
        if(tabuleiro5==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("\n");
    printf("%lc",WHH);
    printf("%lc",WVH);
    printf("%lc",WHH);
    printf("%lc",WVH);
    printf("%lc",WHH);
    printf("\n");

    if(tabuleiro6!=0)
    {
        if(tabuleiro6==1)
            printf("X");
        if(tabuleiro6==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(tabuleiro7!=0)
    {
        if(tabuleiro7==1)
            printf("X");
        if(tabuleiro7==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(tabuleiro8!=0)
    {
        if(tabuleiro8==1)
            printf("X");
        if(tabuleiro8==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("\n");

    PRINTGRAF_OFF;
}

int main (void)
{
    setlocale(LC_ALL, "");
    inicializacao();
    menu();
    if(mododejogo==1)
        while(vencedor==0)
        {
            tabuleiro();
            fim();
            humanojoga();
        }
    if(mododejogo==2)
        while(vencedor==0)
        {
            tabuleiro();
            fim();
            nivelfacil();
        }
    if(mododejogo==3)
        while(vencedor==0)
        {
            tabuleiro();
            fim();
            humanojoga();
            tabuleiro();
            fim();
            nivelfacil();
        }
}

