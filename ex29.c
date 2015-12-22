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
int inicilizacao(void);
int tabuleiro(void);
int menu(void);
int humanos;
int humanoxpc;
int nivelfacil(int tab[MAXTAB][MAXTAB], int vez);
int nivelmedio(int tab[MAXTAB][MAXTAB], int vez);
int niveldificil(int tab[MAXTAB][MAXTAB], int vez);

