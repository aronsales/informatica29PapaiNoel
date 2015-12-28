/* ex29.c - "Jogo da velha"
 * Autores:
 * -Aron Sales de Melo de Medeiros Monteiro
 * -Guido de Lyra Ferrario
 *
 *Codigo protegido pela Licensa GNU2.0, para mais informacoes acessar o arquivo LICENSE no repositorio do github
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

#define WVH L'\u253c' /* ^VU253c ┼ */
#define WHH L'\u2500' /* ^VU2500 ─ */  
#define WVV L'\u2502' /* ^VU2502 │ */

#define PRINTGRAF_ON ;
#define PRINTGRAF_OFF ;


void inicializacao () //mensagens de inicio
{
    printf("\nBem-vindo(a) ao programa informatica29PapaiNoel!!");
    printf("\nPrograma criado por: \n-Aron Sales de Melo de Medeiros Monteiro, e \n-Guido de Lyra Ferrario.");
    printf("\nO programa traz o tradicional Jogo da Velha!\n");
}

void menu (int *mododejogo,int *dificuldade,int *quemcomeca) //menu
{
    printf("\n-Ha tres modalidades disponiveis: \n");
    printf("Pressione:");
    printf("\n'1' se voce deseja um jogo para dois humanos.");
    printf("\n'2' se voce deseja ver uma partida simulada.");
    printf("\n'3' se voce deseja jogar contra a maquina.\n");
    scanf("%d", &*mododejogo);
    if(*mododejogo==2 || *mododejogo==3)
    {
        printf("\n-Por favor, informe em qual dificuldade voce deseja o desafio:");
        printf("\n'4' - Nivel facil");
        printf("\n'5' - Nivel medio");
        printf("\n'6' - Nivel dificil\n");
        scanf("%d", &*dificuldade);
    }
    if(*mododejogo==1 || *mododejogo==3)
    {
        printf("\n\nO usuario devera escolher em qual 'casa' ele jogara!");
        printf("\n-Exemplo de tabuleiro:\n");
        printf("\n 0 | 1 | 2");
        printf("\n---+---+---");
        printf("\n 3 | 4 | 5");
        printf("\n ---+---+---");
        printf("\n 6 | 7 | 8\n");
        printf("\nOs numeros representam as opcoes de 'casas' para a execucao da jogada!\n\n");
        printf("\nSE O JOGADOR PRESSIONAR UM NUMERO DE UMA CASA JA OCUPADA, PERDERA A VEZ!!\n");
    }
    if(*mododejogo==3)
    {
        printf("\n-Quem fara o primeiro movimento?\n");
        printf("\nPressione\n'1' para humano ou\n");
        printf("'2' para computador:\n");
        scanf("%d", &*quemcomeca);
    }
}

void humanojoga(int *tabuleiro0,int *tabuleiro1,int *tabuleiro2,int *tabuleiro3,int *tabuleiro4,int *tabuleiro5,int *tabuleiro6,int *tabuleiro7,int *tabuleiro8,int *turnojogador,int *mododejogo)
    //Funcao da jogada do humano
{
    int jogada;

    printf("\nEscolha a casa que voce quer jogar:\n");
    scanf("%d", &jogada);
    //Recolherá a jogada do humano, e se a casa for válida, jogará
    if(jogada==0 && *tabuleiro0==0)
    {
        if(*turnojogador==1)
            *tabuleiro0=*tabuleiro0+1;
        else
            *tabuleiro0=*tabuleiro0-1;
    }

    if(jogada==1 && *tabuleiro1==0)
    {
        if(*turnojogador==1)
            *tabuleiro1=*tabuleiro1+1;
        else
            *tabuleiro1=*tabuleiro1-1;
    }

    if(jogada==2 && *tabuleiro2==0)
    {
        if(*turnojogador==1)
            *tabuleiro2=*tabuleiro2+1;
        else
            *tabuleiro2=*tabuleiro2-1;
    }

    if(jogada==3 && *tabuleiro3==0)
    {
        if(*turnojogador==1)
            *tabuleiro3=*tabuleiro3+1;
        else
            *tabuleiro3=*tabuleiro3-1;
    }

    if(jogada==4 && *tabuleiro4==0)
    {
        if(*turnojogador==1)
            *tabuleiro4=*tabuleiro4+1;
        else
            *tabuleiro4=*tabuleiro4-1;
    }

    if(jogada==5 && *tabuleiro5==0)
    {
        if(*turnojogador==1)
            *tabuleiro5=*tabuleiro5+1;
        else
            *tabuleiro5=*tabuleiro5-1;
    }

    if(jogada==6 && *tabuleiro6==0)
    {
        if(*turnojogador==1)
            *tabuleiro6=*tabuleiro6+1;
        else
            *tabuleiro6=*tabuleiro6-1;
    }

    if(jogada==7 && *tabuleiro7==0)
    {
        if(*turnojogador==1)
            *tabuleiro7=*tabuleiro7+1;
        else
            *tabuleiro7=*tabuleiro7-1;
    }

    if(jogada==8 && *tabuleiro8==0)
    {
        if(*turnojogador==1)
            *tabuleiro8=*tabuleiro8+1;
        else
            *tabuleiro8=*tabuleiro8-1;
    }

    if(*mododejogo==1)
    {
        if(*turnojogador==1)
            *turnojogador=*turnojogador-2;
        else
            *turnojogador=*turnojogador+2;
    }

}

void nivelfacil(int *tabuleiro0,int *tabuleiro1,int *tabuleiro2,int *tabuleiro3,int *tabuleiro4,int *tabuleiro5,int *tabuleiro6,int *tabuleiro7,int *tabuleiro8,int *turnomaquina,int *mododejogo)
    //Nivel facil, jogada da maquina aleatorio
{
    int marquei=0;
    int jogadafacil;

    while(marquei==0)
    {
        srand(time(NULL)); //Computador joga aleatoriamente,sorteando um valor para a variavel jogafacil, validando a jogada apenas se a casa estiver vazia
        jogadafacil=rand()%MAXCASAS;

        if(jogadafacil==0 && *tabuleiro0==0)
        {
            if(*turnomaquina==1)
                *tabuleiro0=*tabuleiro0+1;
            else
                *tabuleiro0=*tabuleiro0-1;
            marquei=marquei+1;
        }
        if(jogadafacil==1 && *tabuleiro1==0)
        {
            if(*turnomaquina==1)
                *tabuleiro1=*tabuleiro1+1;
            else
                *tabuleiro1=*tabuleiro1-1;
            marquei=marquei+1;
        }
        if(jogadafacil==2 && *tabuleiro2==0)
        {
            if(*turnomaquina==1)
                *tabuleiro2=*tabuleiro2+1;
            else
                *tabuleiro2=*tabuleiro2-1;
            marquei=marquei+1;
        }
        if(jogadafacil==3 && *tabuleiro3==0)
        {
            if(*turnomaquina==1)
                *tabuleiro3=*tabuleiro3+1;
            else
                *tabuleiro3=*tabuleiro3-1;
            marquei=marquei+1;
        }

        if(jogadafacil==4 && *tabuleiro4==0)
        {
            if(*turnomaquina==1)
                *tabuleiro4=*tabuleiro4+1;
            else
                *tabuleiro4=*tabuleiro4-1;
            marquei=marquei+1;
        }

        if(jogadafacil==5 && *tabuleiro5==0)
        {
            if(*turnomaquina==1)
                *tabuleiro5=*tabuleiro5+1;
            else
                *tabuleiro5=*tabuleiro5-1;
            marquei=marquei+1;
        }

        if(jogadafacil==6 && *tabuleiro6==0)
        {
            if(*turnomaquina==1)
                *tabuleiro6=*tabuleiro6+1;
            else
                *tabuleiro6=*tabuleiro6-1;
            marquei=marquei+1;
        }

        if(jogadafacil==7 && tabuleiro7==0)
        {
            if(*turnomaquina==1)
                *tabuleiro7=*tabuleiro7+1;
            else
                *tabuleiro7=*tabuleiro7-1;
            marquei=marquei+1;
        }


        if(jogadafacil==8 && *tabuleiro8==0)
        {
            if(*turnomaquina==1)
                *tabuleiro8=*tabuleiro8+1;
            else
                *tabuleiro8=*tabuleiro8-1;
            marquei=marquei+1;
        }
    }
    if(*mododejogo==2)
    {
        if(*turnomaquina==1)
            *turnomaquina=-1;
        else
            *turnomaquina=1;
    }

}
void nivelmedio(int *tabuleiro0,int *tabuleiro1,int *tabuleiro2,int *tabuleiro3,int *tabuleiro4,int *tabuleiro5,int *tabuleiro6,int *tabuleiro7,int *tabuleiro8,int *turnomaquina,int *mododejogo)
    //Funcao nivel medio, evita a derrota ou conquista a vitoria se duas casas do mesmo simbolo estiverem juntas
{
    int marquei=0;
    int jogadamedia;
    while(marquei==0)
    {
        //0 e 1
        //se as casa 0 e 1 estiverem preenchidas pelo adversario ou pelo proprio computador, e a 2 vazia,  ele deve jogar la, evitando a derrota ou conquistando a vitoria
        if((*tabuleiro0==1 && *tabuleiro1==1 && *tabuleiro2==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro1==-1 && *tabuleiro2==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro2=1;
            else
                *tabuleiro2=-1;
            marquei=marquei+1;
        }
        //0 e 2
        if((*tabuleiro0==1 && *tabuleiro2==1 && *tabuleiro1==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro2==-1 && *tabuleiro1==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro1=1;
            else
                *tabuleiro1=-1;
            marquei=marquei+1;
        }  
        //0 e 3
        if((*tabuleiro0==1 && *tabuleiro3==1 && *tabuleiro6==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro3==-1 && *tabuleiro6==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro6=1;
            else
                *tabuleiro6=-1;
            marquei=marquei+1;
        }
        //1 e 2
        if((*tabuleiro1==1 && *tabuleiro2==1 && *tabuleiro0==0 && marquei==0) || (*tabuleiro1==-1 && *tabuleiro2==-1 && *tabuleiro0==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro0=1;
            else
                *tabuleiro0=-1;
            marquei=marquei+1;
        }
        //0 e 4 (diagonal)
        //se as casa 0 e 4 estiverem preenchidas pelo adversario ou pelo computador, e a casa 8 vazia, o computador devera jogar nesta casa, evitando a derrota ou conquistando a vitoria.
        if((*tabuleiro0==1 && *tabuleiro4==1 && *tabuleiro8==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro4==-1 && *tabuleiro8==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro8=1;
            else
                *tabuleiro8=-1;
            marquei=marquei+1;
        }
        //3 e 4
        if((*tabuleiro3==1 && *tabuleiro4==1 && *tabuleiro5==0 && marquei==0) || (*tabuleiro3==-1 && *tabuleiro4==-1 && *tabuleiro5==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro5=1;
            else
                *tabuleiro5=-1;
            marquei=marquei+1;
        }
        //3 e 5
        if((*tabuleiro3==1 && *tabuleiro5==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro3==-1 && *tabuleiro5==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 5
        if((*tabuleiro4==1 && *tabuleiro5==1 && *tabuleiro3==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro5==-1 && *tabuleiro3==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro3=1;
            else
                *tabuleiro3=-1;
            marquei=marquei+1;
        }
        //6 e 7
        if((*tabuleiro6==1 && *tabuleiro7==1 && *tabuleiro8==0 && marquei==0) || (*tabuleiro6==-1 && *tabuleiro7==-1 && *tabuleiro8==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro8=1;
            else
                *tabuleiro8=-1;
            marquei=marquei+1;
        }
        //6 e 8
        if((*tabuleiro6==1 && *tabuleiro8==1 && *tabuleiro7==0 && marquei==0) || (*tabuleiro6==-1 && *tabuleiro8==-1 && *tabuleiro7==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro7=1;
            else
                *tabuleiro7=-1;
            marquei=marquei+1;
        }
        //7 e 8
        if((*tabuleiro7==1 && *tabuleiro8==1 && *tabuleiro6==0 && marquei==0) || (*tabuleiro7==-1 && *tabuleiro8==-1 && *tabuleiro6==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro6=1;
            else
                *tabuleiro6=-1;
            marquei=marquei+1;
        }
        //0 e 6
        if((*tabuleiro0==1 && *tabuleiro6==1 && *tabuleiro3==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro6==-1 && *tabuleiro3==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro3=1;
            else
                *tabuleiro3=-1;
            marquei=marquei+1;
        }
        //3 e 6
        if((*tabuleiro3==1 && *tabuleiro6==1 && *tabuleiro0==0 && marquei==0) || (*tabuleiro3==-1 && *tabuleiro6==-1 && *tabuleiro0==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro0=1;
            else
                *tabuleiro0=-1;
            marquei=marquei+1;
        }
        //1 e 4
        if((*tabuleiro1==1 && *tabuleiro4==1 && *tabuleiro7==0 && marquei==0) || (*tabuleiro1==-1 && *tabuleiro4==-1 && *tabuleiro7==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro7=1;
            else
                *tabuleiro7=-1;
            marquei=marquei+1;
        }
        //1 e 7
        if((*tabuleiro1==1 && *tabuleiro7==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro1==-1 && *tabuleiro7==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 7
        if((*tabuleiro4==1 && *tabuleiro7==1 && *tabuleiro1==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro7==-1 && *tabuleiro1==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro1=1;
            else
                *tabuleiro1=-1;
            marquei=marquei+1;
        }
        //2 e 5
        if((*tabuleiro2==1 && *tabuleiro5==1 && *tabuleiro8==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro5==-1 && *tabuleiro8==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro8=1;
            else
                *tabuleiro8=-1;
            marquei=marquei+1;
        }
        //2 e 8
        if((*tabuleiro2==1 && *tabuleiro8==1 && *tabuleiro5==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro8==-1 && *tabuleiro5==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro5=1;
            else
                *tabuleiro5=-1;
            marquei=marquei+1;
        }
        //5 e 8
        if((*tabuleiro5==1 && *tabuleiro8==1 && *tabuleiro2==0 && marquei==0) || (*tabuleiro5==-1 && *tabuleiro8==-1 && *tabuleiro2==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro2=1;
            else
                *tabuleiro2=-1;
            marquei=marquei+1;
        }
        //0 e 8(diagonal)
        if((*tabuleiro0==1 && *tabuleiro8==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro8==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 8(diagonal)
        if((*tabuleiro4==1 && *tabuleiro8==1 && *tabuleiro0==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro8==-1 && *tabuleiro0==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro0=1;
            else
                *tabuleiro0=-1;
            marquei=marquei+1;
        }
        //2 e 4(diagonal)
        if((*tabuleiro2==1 && *tabuleiro4==1 && *tabuleiro6==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro4==-1 && *tabuleiro6==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro6=1;
            else
                *tabuleiro6=-1;
            marquei=marquei+1;
        }
        //2 e 6(diagonal)
        if((*tabuleiro2==1 && *tabuleiro6==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro6==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 6(diagonal)
        if((*tabuleiro4==1 && *tabuleiro6==1 && *tabuleiro2==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro6==-1 && *tabuleiro2==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro2=1;
            else
                *tabuleiro2=-1;
            marquei=marquei+1;
        }
            srand(time(NULL)); 
            //Se nao houver risco de derrota ou possibilidade de derrota no turno, o computador ira jogar em uma casa aleatoria que esta disponivel para jogada
            jogadamedia=rand()%MAXCASAS;

        if(jogadamedia==0 && *tabuleiro0==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro0=*tabuleiro0+1;
            else
                *tabuleiro0=*tabuleiro0-1;
            marquei=marquei+1;
        }
        if(jogadamedia==1 && *tabuleiro1==0 && marquei==0) 
        {
            if(*turnomaquina==1)
                *tabuleiro1=*tabuleiro1+1;
            else
                *tabuleiro1=*tabuleiro1-1;
            marquei=marquei+1;
        }
        if(jogadamedia==2 && *tabuleiro2==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro2=*tabuleiro2+1;
            else
                *tabuleiro2=*tabuleiro2-1;
            marquei=marquei+1;
        }
        if(jogadamedia==3 && *tabuleiro3==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro3=*tabuleiro3+1;
            else
                *tabuleiro3=*tabuleiro3-1;
            marquei=marquei+1;
        }

        if(jogadamedia==4 && *tabuleiro4==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro4=*tabuleiro4+1;
            else
                *tabuleiro4=*tabuleiro4-1;
            marquei=marquei+1;
        }

        if(jogadamedia==5 && *tabuleiro5==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro5=*tabuleiro5+1;
            else
                *tabuleiro5=*tabuleiro5-1;
            marquei=marquei+1;
        }

        if(jogadamedia==6 && *tabuleiro6==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro6=*tabuleiro6+1;
            else
                *tabuleiro6=*tabuleiro6-1;
            marquei=marquei+1;
        }

        if(jogadamedia==7 && tabuleiro7==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro7=*tabuleiro7+1;
            else
                *tabuleiro7=*tabuleiro7-1;
            marquei=marquei+1;
        }
        if(jogadamedia==8 && *tabuleiro8==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro8=*tabuleiro8+1;
            else
                *tabuleiro8=*tabuleiro8-1;
            marquei=marquei+1;
        }
    }
    if(*mododejogo==2)
    {
        if(*turnomaquina==1)
            *turnomaquina=-1;
        else
            *turnomaquina=1;
    }
}


void niveldificil(int *tabuleiro0,int *tabuleiro1,int *tabuleiro2,int *tabuleiro3,int *tabuleiro4,int *tabuleiro5,int *tabuleiro6,int *tabuleiro7,int *tabuleiro8,int *turnomaquina,int *mododejogo)
    //Mesmas qualidades do nivel medio, alem disso tem prioridade para jogar no centro e pelas diagonais, dificultando o jogo para o humano
{
    int marquei=0;
    while(marquei==0)
    {
        //0 e 1
        if((*tabuleiro0==1 && *tabuleiro1==1 && *tabuleiro2==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro1==-1 && *tabuleiro2==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro2=1;
            else
                *tabuleiro2=-1;
            marquei=marquei+1;
        }
        //0 e 2
        if((*tabuleiro0==1 && *tabuleiro2==1 && *tabuleiro1==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro2==-1 && *tabuleiro1==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro1=1;
            else
                *tabuleiro1=-1;
            marquei=marquei+1;
        }  
        //0 e 3
        if((*tabuleiro0==1 && *tabuleiro3==1 && *tabuleiro6==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro3==-1 && *tabuleiro6==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro6=1;
            else
                *tabuleiro6=-1;
            marquei=marquei+1;
        }
        //1 e 2
        if((*tabuleiro1==1 && *tabuleiro2==1 && *tabuleiro0==0 && marquei==0) || (*tabuleiro1==-1 && *tabuleiro2==-1 && *tabuleiro0==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro0=1;
            else
                *tabuleiro0=-1;
            marquei=marquei+1;
        }
        //0 e 4 (diagonal)
        if((*tabuleiro0==1 && *tabuleiro4==1 && *tabuleiro8==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro4==-1 && *tabuleiro8==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro8=1;
            else
                *tabuleiro8=-1;
            marquei=marquei+1;
        }
        //3 e 4
        if((*tabuleiro3==1 && *tabuleiro4==1 && *tabuleiro5==0 && marquei==0) || (*tabuleiro3==-1 && *tabuleiro4==-1 && *tabuleiro5==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro5=1;
            else
                *tabuleiro5=-1;
            marquei=marquei+1;
        }
        //3 e 5
        if((*tabuleiro3==1 && *tabuleiro5==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro3==-1 && *tabuleiro5==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 5
        if((*tabuleiro4==1 && *tabuleiro5==1 && *tabuleiro3==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro5==-1 && *tabuleiro3==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro3=1;
            else
                *tabuleiro3=-1;
            marquei=marquei+1;
        }
        //6 e 7
        if((*tabuleiro6==1 && *tabuleiro7==1 && *tabuleiro8==0 && marquei==0) || (*tabuleiro6==-1 && *tabuleiro7==-1 && *tabuleiro8==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro8=1;
            else
                *tabuleiro8=-1;
            marquei=marquei+1;
        }
        //6 e 8
        if((*tabuleiro6==1 && *tabuleiro8==1 && *tabuleiro7==0 && marquei==0) || (*tabuleiro6==-1 && *tabuleiro8==-1 && *tabuleiro7==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro7=1;
            else
                *tabuleiro7=-1;
            marquei=marquei+1;
        }
        //7 e 8
        if((*tabuleiro7==1 && *tabuleiro8==1 && *tabuleiro6==0 && marquei==0) || (*tabuleiro7==-1 && *tabuleiro8==-1 && *tabuleiro6==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro6=1;
            else
                *tabuleiro6=-1;
            marquei=marquei+1;
        }
        //0 e 6
        if((*tabuleiro0==1 && *tabuleiro6==1 && *tabuleiro3==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro6==-1 && *tabuleiro3==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro3=1;
            else
                *tabuleiro3=-1;
            marquei=marquei+1;
        }
        //3 e 6
        if((*tabuleiro3==1 && *tabuleiro6==1 && *tabuleiro0==0 && marquei==0) || (*tabuleiro3==-1 && *tabuleiro6==-1 && *tabuleiro0==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro0=1;
            else
                *tabuleiro0=-1;
            marquei=marquei+1;
        }
        //1 e 4
        if((*tabuleiro1==1 && *tabuleiro4==1 && *tabuleiro7==0 && marquei==0) || (*tabuleiro1==-1 && *tabuleiro4==-1 && *tabuleiro7==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro7=1;
            else
                *tabuleiro7=-1;
            marquei=marquei+1;
        }
        //1 e 7
        if((*tabuleiro1==1 && *tabuleiro7==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro1==-1 && *tabuleiro7==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 7
        if((*tabuleiro4==1 && *tabuleiro7==1 && *tabuleiro1==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro7==-1 && *tabuleiro1==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro1=1;
            else
                *tabuleiro1=-1;
            marquei=marquei+1;
        }
        //2 e 5
        if((*tabuleiro2==1 && *tabuleiro5==1 && *tabuleiro8==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro5==-1 && *tabuleiro8==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro8=1;
            else
                *tabuleiro8=-1;
            marquei=marquei+1;
        }
        //2 e 8
        if((*tabuleiro2==1 && *tabuleiro8==1 && *tabuleiro5==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro8==-1 && *tabuleiro5==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro5=1;
            else
                *tabuleiro5=-1;
            marquei=marquei+1;
        }
        //5 e 8
        if((*tabuleiro5==1 && *tabuleiro8==1 && *tabuleiro2==0 && marquei==0) || (*tabuleiro5==-1 && *tabuleiro8==-1 && *tabuleiro2==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro2=1;
            else
                *tabuleiro2=-1;
            marquei=marquei+1;
        }
        //0 e 8(diagonal)
        if((*tabuleiro0==1 && *tabuleiro8==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro0==-1 && *tabuleiro8==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 8(diagonal)
        if((*tabuleiro4==1 && *tabuleiro8==1 && *tabuleiro0==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro8==-1 && *tabuleiro0==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro0=1;
            else
                *tabuleiro0=-1;
            marquei=marquei+1;
        }
        //2 e 4(diagonal)
        if((*tabuleiro2==1 && *tabuleiro4==1 && *tabuleiro6==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro4==-1 && *tabuleiro6==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro6=1;
            else
                *tabuleiro6=-1;
            marquei=marquei+1;
        }
        //2 e 6(diagonal)
        if((*tabuleiro2==1 && *tabuleiro6==1 && *tabuleiro4==0 && marquei==0) || (*tabuleiro2==-1 && *tabuleiro6==-1 && *tabuleiro4==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=marquei+1;
        }
        //4 e 6(diagonal)
        if((*tabuleiro4==1 && *tabuleiro6==1 && *tabuleiro2==0 && marquei==0) || (*tabuleiro4==-1 && *tabuleiro6==-1 && *tabuleiro2==0 && marquei==0))
        {
            if(*turnomaquina==1)
                *tabuleiro2=1;
            else
                *tabuleiro2=-1;
            marquei=marquei+1;
        }

        if(*tabuleiro4==0 && marquei==0) // computador da preferencia pela jogada na casa 4(do centro)
        {
            if(*turnomaquina==1)
                *tabuleiro4=1;
            else
                *tabuleiro4=-1;
            marquei=1;
        }

        if(*tabuleiro0==0 && marquei==0) 
            // Se nao houver risco de derrota ou possibilidade de vitoria, e a casa central estiver ocupada, o computador devera jogar em uma das casas nas 'quinas'(0,2,6 e 8) e se mesmo assim não tiver possibilidade de jogada, jogará na 1 e 7.
        {
            if(*turnomaquina==1)
                *tabuleiro0=1;
            else
                *tabuleiro0=-1;
            marquei=1;
        }

        if(*tabuleiro2==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro2=1;
            else
                *tabuleiro2=-1;
            marquei=1;
        }

        if(*tabuleiro6==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro6=1;
            else
                *tabuleiro6=-1;
            marquei=1;
        }

        if(*tabuleiro8==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro8=1;
            else
                *tabuleiro8=-1;
            marquei=1;
        }
        if(*tabuleiro1==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro1=1;
            else
                *tabuleiro1=-1;
            marquei=1;
        }

        if(*tabuleiro7==0 && marquei==0)
        {
            if(*turnomaquina==1)
                *tabuleiro7=1;
            else
                *tabuleiro7=-1;
            marquei=1;
        }
    if(*mododejogo==2)
        if(*turnomaquina==1)
            *turnomaquina=-1;
        else
            *turnomaquina=1;
    }
}


void fim(int *tabuleiro0,int *tabuleiro1,int *tabuleiro2,int *tabuleiro3,int *tabuleiro4,int *tabuleiro5,int *tabuleiro6,int *tabuleiro7,int *tabuleiro8,int *vencedor)
    //Funcao para calcular o vencedor da partida, de acordo com o valor das variaveis tabuleiro
{
    if(*tabuleiro0==1 && *tabuleiro1==1 && *tabuleiro2==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    //Se as casas 0, 1 e 2 estiverem oculpadas com +1, o jogador X ganhou
    if(*tabuleiro3==1 && *tabuleiro4==1 && *tabuleiro5==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(*tabuleiro6==1 && *tabuleiro7==1 && *tabuleiro8==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(*tabuleiro0==1 && *tabuleiro3==1 && *tabuleiro6==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(*tabuleiro1==1 && *tabuleiro4==1 && *tabuleiro7==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(*tabuleiro2==1 && *tabuleiro5==1 && *tabuleiro8==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(*tabuleiro0==1 && *tabuleiro4==1 && *tabuleiro8==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(*tabuleiro2==1 && *tabuleiro4==1 && *tabuleiro6==1)
    {
        *vencedor=1;
        printf("\nX ganhou ! ! ! \n");
    }
    if(*tabuleiro0==-1 && *tabuleiro1==-1 && *tabuleiro2==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    //Se 3 casas estiverem juntas, e com o valor de -1, decretará o 'O' como vencedor
    if(*tabuleiro3==-1 && *tabuleiro4==-1 && *tabuleiro5==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(*tabuleiro6==-1 && *tabuleiro7==-1 && *tabuleiro8==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(*tabuleiro0==-1 && *tabuleiro3==-1 && *tabuleiro6==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(*tabuleiro1==-1 && *tabuleiro4==-1 && *tabuleiro7==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(*tabuleiro2==-1 && *tabuleiro5==-1 && *tabuleiro8==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(*tabuleiro0==-1 && *tabuleiro4==-1 && *tabuleiro8==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(*tabuleiro2==-1 && *tabuleiro4==-1 && *tabuleiro6==-1)
    {
        *vencedor=-1;
        printf("\nO ganhou ! ! ! \n");
    }
    if(*tabuleiro0!=0 && *tabuleiro1!=0 && *tabuleiro2!=0 && *tabuleiro3!=0 && *tabuleiro4!=0 && *tabuleiro5!=0 && *tabuleiro6!=0 && *tabuleiro7!=0 && *tabuleiro8!=0 && *vencedor==0)
        printf("\nDeu Velha! ! ! Jogo empatou\n");

}

void tabuleiro(int *tabuleiro0,int *tabuleiro1,int *tabuleiro2,int *tabuleiro3,int *tabuleiro4,int *tabuleiro5,int *tabuleiro6,int *tabuleiro7,int *tabuleiro8) 
    //Funcao para imprimir as jogadas no tabuleiro, de acordo com as variavéis
{
    PRINTGRAF_ON ;
    printf("\n\n\n");
    //Se a casa não for neutra(0), entrará no laço, onde dependendo do valor(1 ou -1) imprimirá X ou O
    if(*tabuleiro0!=0)
    {
        if(*tabuleiro0==1)
            printf("X");
        if(*tabuleiro0==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);
    //Colocação da primeira | no tabuleiro

    if(*tabuleiro1!=0)
    {
        if(*tabuleiro1==1)
            printf("X");
        if(*tabuleiro1==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc", WVV);

    if(*tabuleiro2!=0)
    {
        if(*tabuleiro2==1)
            printf("X");
        if(*tabuleiro2==-1)
            printf("O");
    }
    else
        printf(" ");
    
    //Impressão da primeira linha na horizontal _+_+_
    printf("\n");
    printf("%lc",WHH);
    printf("%lc",WVH);
    printf("%lc",WHH);
    printf("%lc",WVH);
    printf("%lc",WHH);
    printf("\n");

    if(*tabuleiro3!=0)
    {
        if(*tabuleiro3==1)
            printf("X");
        if(*tabuleiro3==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(*tabuleiro4!=0)
    {
        if(*tabuleiro4==1)
            printf("X");
        if(*tabuleiro4==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(*tabuleiro5!=0)
    {
        if(*tabuleiro5==1)
            printf("X");
        if(*tabuleiro5==-1)
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

    if(*tabuleiro6!=0)
    {
        if(*tabuleiro6==1)
            printf("X");
        if(*tabuleiro6==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(*tabuleiro7!=0)
    {
        if(*tabuleiro7==1)
            printf("X");
        if(*tabuleiro7==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("%lc",WVV);

    if(*tabuleiro8!=0)
    {
        if(*tabuleiro8==1)
            printf("X");
        if(*tabuleiro8==-1)
            printf("O");
    }
    else
        printf(" ");

    printf("\n");

    PRINTGRAF_OFF;
}

void despedida() //Mensagem de despedida, aparece no fim do programa.
{
    printf("\n\nObrigado por executar o informatica29PapaiNoel!! Boas festas!\n\n");
}

int main (void)
{  
    //Variaveis locais na main, que serão passadas por parametro(referencia)
    int tabuleiro0=0,tabuleiro1=0,tabuleiro2=0,tabuleiro3=0,tabuleiro4=0,tabuleiro5=0,tabuleiro6=0,tabuleiro7=0,tabuleiro8=0;
    int vencedor=0;
    int turnojogador=1;
    int turnomaquina=-1;
    int mododejogo, dificuldade, quemcomeca;

    setlocale(LC_ALL, "");
    inicializacao();
    //Recebimento das variaveis do menu
    menu(&mododejogo, &dificuldade,&quemcomeca);
    //Se o modo de jogo for igual a '1'(2 humanos), entrará neste laço
    if(mododejogo==1)
        while(vencedor==0)
        {
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            humanojoga(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnojogador,&mododejogo);
        }
    //Se o modo de jogo for igual a '2'(2 computadores), estrará nestes laços de acordo com a dificuldade
    if(mododejogo==2 && dificuldade==4)
        while(vencedor==0)
        {
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            nivelfacil(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
        }
    if(mododejogo==2 && dificuldade==5)
        while(vencedor==0)
        {
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            nivelmedio(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
        }
    if(mododejogo==2 && dificuldade==6)
        while(vencedor==0)
        {
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            niveldificil(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
        }
    //Se o modo de jogo for '3'(Humano X Pc), estrará nestes laços de acordo com a dificuldade, e de quem começará
    if(mododejogo==3 && dificuldade==4 && quemcomeca==1)
        while(vencedor==0)
        {
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            humanojoga(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnojogador,&mododejogo);
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            nivelfacil(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
        }
    if(mododejogo==3 && dificuldade==4 && quemcomeca==2)
        while(vencedor==0)
        {
            turnomaquina=1;
            turnojogador=-1;
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            nivelfacil(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            humanojoga(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnojogador,&mododejogo);
        }
    if(mododejogo==3 && dificuldade==5 && quemcomeca==1)
        while(vencedor==0)
        {
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            humanojoga(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnojogador,&mododejogo);
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            nivelmedio(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
        }
    if(mododejogo==3 && dificuldade==5 && quemcomeca==2)
        while(vencedor==0)
        {
            turnomaquina=1;
            turnojogador=-1;
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            nivelmedio(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            humanojoga(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnojogador,&mododejogo);
        }
    if(mododejogo==3 && dificuldade==6 && quemcomeca==1)
        while(vencedor==0)
        {
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            humanojoga(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnojogador,&mododejogo);
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            niveldificil(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
        }
    if(mododejogo==3 && dificuldade==6 && quemcomeca==2)
        while(vencedor==0)
        {
            turnomaquina=1;
            turnojogador=-1;
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            niveldificil(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnomaquina,&mododejogo);
            tabuleiro(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8);
            fim(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&vencedor);
            humanojoga(&tabuleiro0,&tabuleiro1,&tabuleiro2,&tabuleiro3,&tabuleiro4,&tabuleiro5,&tabuleiro6,&tabuleiro7,&tabuleiro8,&turnojogador,&mododejogo);
        }
    //Mensagem de despedida
    despedida();
}

