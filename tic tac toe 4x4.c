#include <stdio.h>

#define Tam 4

void inicializarTabuleiro(char tabuleiro[Tam][Tam]) 
{
	int i, j;
    for (i = 0; i < Tam; i++) 
    {
        for (j = 0; j < Tam; j++) 
        {
            tabuleiro[i][j] = ' ';
        }
    }
}

void imprimirTabuleiro(char tabuleiro[Tam][Tam]) 
{
	int i, j, k;
    printf("\n");
    for (i = 0; i < Tam; i++) 
    {
        for (j = 0; j < Tam; j++) 
        {
            printf(" %c ", tabuleiro[i][j]);
            if (j < Tam - 1) printf("|");
        }
        printf("\n");
        if (i < Tam - 1) 
        {
            for (k = 0; k < Tam; k++) 
            {
                printf("--- ");
            }
            printf("\n");
        }
    }
    printf("\n");
}

int VerificarVitoria(char tabuleiro[Tam][Tam], char jogador) 
{
	int i, j, contador;
    // Verificar as linhas
    for (i = 0; i < Tam; i++) 
    {
        contador = 0;
        for (j = 0; j < Tam; j++) 
        {
            if (tabuleiro[i][j] == jogador) 
            contador++;
        }
        if (contador == Tam) return 1;
    }
    // Verificar as colunas
    for (i = 0; i < Tam; i++) 
    {
        contador = 0;
        for (j = 0; j < Tam; j++) 
        {
            if (tabuleiro[j][i] == jogador) 
            contador++;
        }
        if (contador == Tam) return 1;
    }
    // Verificar diagonal principal
    contador = 0;
    for (i = 0; i < Tam; i++) 
    {
        if(tabuleiro[i][i] == jogador) 
        contador++;
    }
    if (contador == Tam) 
    return 1;
    // Verificar diagonal secundária
    contador = 0;
    for (i = 0; i < Tam; i++) 
    {
        if (tabuleiro[i][Tam - 1 - i] == jogador) 
        contador++;
    }
    if (contador == Tam) 
    return 1;

    return 0;
}

int VerificarEmpate(char tabuleiro[Tam][Tam]) 
{
	int i, j;
    for (i = 0; i < Tam; i++) 
    {
        for (j = 0; j < Tam; j++) 
        {
            if (tabuleiro[i][j] == ' ') 
            return 0;
        }
    }
    return 1;
}

int main() 
{

    char tabuleiro[Tam][Tam];
	int linha, coluna, jogadas;
	char jogadorA;
	int SIZE;

    inicializarTabuleiro(tabuleiro);

    jogadorA = 'X';
    jogadas = 0;
	SIZE = 4;

    while(1) 
    {
        imprimirTabuleiro(tabuleiro);

        printf("Jogador %c, escolha uma linha e coluna (1 a 4): ", jogadorA);
        scanf("%d %d", &linha, &coluna);
		linha --;
		coluna --;
        if (linha >= 0 && linha < SIZE && coluna >= 0 && coluna < SIZE && tabuleiro[linha][coluna] == ' ') 
        {
            tabuleiro[linha][coluna] = jogadorA;
            jogadas++;

            if (VerificarVitoria(tabuleiro, jogadorA)) 
            {
                imprimirTabuleiro(tabuleiro);
                printf("Jogador %c venceu!\n", jogadorA);
                break;
            }

            if (VerificarEmpate(tabuleiro)) 
            {
                imprimirTabuleiro(tabuleiro);
                printf("Empate!\n");
                break;
            }

            jogadorA = (jogadorA == 'X') ? 'O' : 'X';
        } 
        else 
        {
            printf("Erro, Tente Novamente!\n");
        }
    }
    return 0;
}