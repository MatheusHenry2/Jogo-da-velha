#include <iostream>
#include <iomanip>
using namespace std;

//autor matheus henry barbosa

bool vitoria1 = 0, vitoria2 = 0;

void startGame(char tabuleiro[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            tabuleiro[i][j] = '__';
    }
}

void printGame(char tabuleiro[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        cout << endl;
        for (int j = 0; j < 3; j++)
            cout << setw(4) << tabuleiro[i][j];
    }
}

bool isValidPosicao(unsigned int linha, unsigned int coluna, char tabuleiro[3][3])
{
    if (linha < 0 || linha >= 3)
        return false;

    if (coluna < 0 || coluna >= 3)
        return false;

    if (tabuleiro[linha][coluna] == 'X' || tabuleiro[linha][coluna] == 'O')
        return false;

    return true;
}

unsigned int verificaJogador(unsigned int player)
{
    if (player == 2)
        return 1;
    return 2;
}

void insertGame(unsigned int linha, unsigned int coluna, char tabuleiro[3][3], unsigned int player)
{
    if (player == 1)
        tabuleiro[linha][coluna] = 'O';
    else
        tabuleiro[linha][coluna] = 'X';
}

void isVictoryPlayerLine(char tabuleiro[3][3])
{
    unsigned int wlinha = 0, wlinha2 = 0;

    for (int i = 0; i < 3; i++)
    {
        wlinha = 0;
        for (int j = 0; j < 3; j++)
        {
            if (tabuleiro[i][j] == 'O')
                wlinha++;

            if (tabuleiro[i][j] == 'X')
                wlinha2++;
        }
        if (wlinha == 3)
            vitoria1 = 1;

        if (wlinha2 == 3)
            vitoria2 = 1;
    }
}

void isVictoryPlayerDiagonal(char tabuleiro[3][3])
{
    unsigned int wdiagonal = 0, wdiagonal2 = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (i == j)
            {
                if (tabuleiro[i][j] == 'O')
                    wdiagonal++;

                if (tabuleiro[i][j] == 'X')
                    wdiagonal2++;
            }
        }
    }

    if (wdiagonal == 3)
        vitoria1 = 1;

    if (wdiagonal2 == 3)
        vitoria2 = 1;
}

void isVictorySecundaryDiagonal(char tabuleiro[3][3])
{
    unsigned int sdiagonal = 0, sdiagonal2 = 0;

    if (tabuleiro[0][2] == 'O')
        sdiagonal++;

    if (tabuleiro[1][1] == 'O')
        sdiagonal++;

    if (tabuleiro[2][0] == 'O')
        sdiagonal++;

    if (tabuleiro[0][2] == 'X')
        sdiagonal++;

    if (tabuleiro[1][1] == 'X')
        sdiagonal2++;

    if (tabuleiro[2][0] == 'X')
        sdiagonal2++;

    if (sdiagonal == 3)
        vitoria1 = 1;

    if (sdiagonal2 == 3)
        vitoria2 = 1;
}

void isVictoryColum(char tabuleiro[3][3])
{
    unsigned int scolum = 0, scolum2 = 0;

    if (tabuleiro[0][0] == 'O' && tabuleiro[1][0] == 'O' && tabuleiro[2][0] == 'O')
        vitoria1 = 1;

    if (tabuleiro[0][1] == 'O' && tabuleiro[1][1] == 'O' && tabuleiro[2][1] == 'O')
        vitoria1 = 1;

    if (tabuleiro[0][2] == 'O' && tabuleiro[1][2] == 'O' && tabuleiro[2][2] == 'O')
        vitoria1 = 1;

    if (tabuleiro[0][0] == 'X' && tabuleiro[1][0] == 'X' && tabuleiro[2][0] == 'X')
        vitoria2 = 1;

    if (tabuleiro[0][1] == 'X' && tabuleiro[1][1] == 'X' && tabuleiro[2][1] == 'X')
        vitoria2 = 1;

    if (tabuleiro[0][2] == 'X' && tabuleiro[1][2] == 'X' && tabuleiro[2][2] == 'X')
        vitoria2 = 1;
}

int main()
{
    char tabuleiro[3][3];
    unsigned int linha, coluna, player = 2;

    startGame(tabuleiro);
    printGame(tabuleiro);

    do
    {
        player = verificaJogador(player);
        do
        {
            cout << "\n\nJogador " << player << " Informe a linha da sua jogada:";
            cin >> linha;
            cout << "\nJogador " << player << " Informe a coluna da sua jogada:";
            cin >> coluna;
        } while (!isValidPosicao(linha, coluna, tabuleiro));
        insertGame(linha, coluna, tabuleiro, player);
        printGame(tabuleiro);
        isVictoryPlayerLine(tabuleiro);
        isVictoryPlayerDiagonal(tabuleiro);
        isVictorySecundaryDiagonal(tabuleiro);
        isVictoryColum(tabuleiro);
    } while (vitoria1 == 0 && vitoria2 == 0);

    cout << "\n\n (-- PARABENS TEMOS UM VENCEDOR --)" << endl;

    if (vitoria1 == 1)
        cout << "\nJogador 1 venceu parabens carai!" << endl;
    else
        cout << "\nJogador 2 venceu parabens carai";
}