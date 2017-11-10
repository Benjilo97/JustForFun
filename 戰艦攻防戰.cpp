#include <cstdlib>
#include <iostream>
#include <ctime>
using namespace std;

const int ROWS = 5;
const int COLS = 5;
void printBoard(char board[][COLS]);
void generateShip(char board[][COLS], int size);
void checkBoard(char board[][COLS], bool &victory);

int main(void)
{
    srand(time(NULL));
    char board[ROWS][COLS], playerBoard[ROWS][COLS];
    int sizeShip, nShips;

/*��l�Ƥ��*/
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            board[i][j] = '.';
            playerBoard[i][j] = '.';
        }
    }

/*�]�w�Ĥ��ĥ�ƶq*/
    cout << "\n�w��Ө��ĥ�𨾾ԹC��\n\n";
    do
    {
        cout << "��J�A�Q�n���Ĥ��ĥ�ƶq(���i�j��3): ";
        cin >> nShips;
    } while (nShips < 1 || nShips > 3);

/*�]�w�Ĥ��ĥ�j�p*/
    for (int i = 1; i <= nShips; i++)
    {
        do
        {
            cout << "�Ĥ�� " << i << " ����ĥ�j�p(��J1��3): ";
            cin >> sizeShip;
        } while (sizeShip < 1 || sizeShip > 3);
        generateShip(board, sizeShip);
    }

/*�C���i��*/
    int nBombs = 20, iGuess, jGuess;
    bool victory = false;

    if (nShips != 1)
        cout << "\n�� " << nShips << "����ĥ�æb�U�����줤\n";
    else
        cout << "\n�� " << nShips << "����ĥ�æb�U�����줤\n";
    cout << "��J���u��m��m����b���a�b\n"
    << "�Ҧp:�A�Q��@�����u�b�k�W���A�N�п�J1,5\n"
    << "\".\" ���i�Ťή���\n"
    << "\"*\" �����������u\n"
    << "\"o\" �O�����������u\n"
    << "\"S\" ����������ܨS��������ĥ��m"
    << "�A��20�����u\n"
    << "�C���}�l!\n\n";

/*�f�ֹC���������u*/
    for (int n = 1; n <= nBombs && !victory; n++)
        {
            printBoard(playerBoard);
            cout << "\n�� " << n << "�����u, ��J��m��m����b���a�b: ";
            cin >> iGuess;
            cin >> jGuess;

            if (board[iGuess - 1][jGuess - 1] == 'S')
            {
                cout << "�����F\n";
                board[iGuess - 1][jGuess - 1] = '*';
                playerBoard[iGuess - 1][jGuess - 1] = '*';
            }
            else if (board[iGuess - 1][jGuess - 1] == '.')
            {
                cout << "�����F\n";
                board[iGuess - 1][jGuess - 1] = 'o';
                playerBoard[iGuess - 1][jGuess - 1] = 'o';
            }
            victory = true;
        checkBoard(board, victory);
        }

/*���G�e�{*/
    cout << "\n�׽L:\n";
    printBoard(board);

    if (victory)
        cout << "\n����!�A���I�F�Ҧ���ĥ!\n\n";
    else
        cout << "\n�A�S�����I�Ҧ���ĥ!�A�դ@��!\n\n";
    return 0;
}

    void printBoard(char board[][COLS])
    {
        for (int i = 0; i < ROWS; i++)
            {
                for (int j = 0; j < COLS; j++)
                {
                cout << board[i][j];
                }
                cout << endl;
            }
        return;
    }

/*�Ĥ��ĥ�\��*/
void generateShip(char board[][COLS], int size)
{
    int iStart,jStart,ort;
    Randomize:
    do
    {
        iStart = rand()%ROWS;
        jStart = rand()%COLS;
        ort = rand()%2;
    } while (board[iStart][jStart] == 'S');

/*�����\��*/
    if (ort == 0)
    {
/*�T�O��ĥ���|�W�X����*/
        while (jStart + size >= COLS)
            {
                jStart = rand()%COLS;
            }
/*�T�O��ĥ�����|*/
        for (int j = jStart; j < jStart + size; j++)
            {
                if (board[iStart][j] == 'S')
                goto Randomize;
            }
/*�p�����W�z����A�����m��ĥ*/
        for (int j = jStart; j < jStart + size; j++)
            {
                        board[iStart][j] = 'S';
            }
    }
/*�����\��*/
    if (ort == 1)
    {
        while (iStart + size >= ROWS)
            {
                iStart = rand()%ROWS;
            }
        for (int i = iStart; i < iStart + size; i++)
            {
                if (board[i][jStart] == 'S')
                goto Randomize;
            }
        for (int i = iStart; i < iStart + size; i++)
            {
                board[i][jStart] = 'S';
            }
    }

    return;
}
void checkBoard(char board[][COLS], bool &victory)
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (board[i][j] == 'S')
            victory = false;
        }
    }
}
