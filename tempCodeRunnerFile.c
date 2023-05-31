#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <stdbool.h>
#include <unistd.h>
#include <Windows.h>

void gotoxy(int x,int y) 
{ 
    COORD coord={0,0}; 
  	coord.X=x; 
 	coord.Y=y; 
 	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord); 
} 

void yellow() // player 1 color
{
    printf("\033[0;33m");
}

void cyan() // player 2 color
{
    printf("\033[0;36m");
}

void green() // player 3 color
{
    printf("\033[0;32m");
}

void red() // player 4 color
{
    printf("\033[1;31m");
}

void purple()
{
    printf("\033[0;35m");
}

void reset() // reset color
{
    printf("\033[0m");
}

void clrscr()
{
    system("cls||clear");
}

void intro()
{
    char c;
    yellow();
    gotoxy(42, 1);
    printf("=====================================\n");
    cyan();
    gotoxy(43, 2);
    printf("C H U T E S   A N D   L A D D E R S\n");
    green();
    gotoxy(51, 3);
    printf("by : Ysobella Torio\n");
    red();
    gotoxy(58, 4);
    printf("S11-B\n");
    yellow();
    gotoxy(42, 5);
    printf("=====================================\n\n");
    reset();

    printf("Read the [M]echanics or [S]tart the game? ");
    scanf(" %c", &c);
    c = tolower(c);

    while(c != 'm' && c != 's')
    {
        printf("Invalid Input. Please try again.\n");
        scanf(" %c", &c);
        c = tolower(c);
    }

    if(c == 'm')
    {
        yellow();
        gotoxy(56, 9);
        printf("MECHANICS\n");
        reset();
        printf("1. The game can be played by 2-4 human players, but you can also choose to play with pseudo-AI players.\n");
        printf("2. If a 6 is rolled in the virtual die, the same player will get to roll the die again.\n");
        printf("3. Players take turns rolling a single die to move their token by the number of squares indicated by the die rolled.\n");
        printf("4. When a player's token lands on the bottom of a ladder, the player moves up to the upper part of the ladder. \n");
        printf("5. If the player lands on the upper part of a chute, the token must be moved down to the bottom of the chute. \n");
        printf("6. The first player who brings their token to the last square of the track wins the game. \n\n");
        printf("Press ENTER to continue...\n");
        c = getchar();
        c = getchar();
        sleep(1);
        clrscr();
    }
    else
    {
        c = getchar();
        clrscr();
    }
}

int random()
{
    int nNum;
    // time as seed for random generator
    srand(time(NULL));
    nNum = rand() % 6 + 1;

    // singular or plural
    nNum == 1 ? printf("You moved %d step.\n", nNum) : printf("You moved %d steps.\n", nNum);

    return nNum;
}

void rollDice()
{
    char cDiceKey; // getchar value

    do // press D to roll the die
    {
        printf("Press D to roll the die.\n");
        // cDiceKey = getchar();
        scanf(" %c", &cDiceKey);
        cDiceKey = tolower(cDiceKey);
    } while (cDiceKey != 'd');
}

int playerCount()
{
    int nPlayerCount;
    printf("How many players do you want to play with? [1-3]: ");
    scanf("%d", &nPlayerCount);
    
    while (nPlayerCount < 1 || nPlayerCount > 3) // only accepts 1-3 as input
    {
        printf("Enter a value between 1 and 3 only.\n"); 
        scanf("%d", &nPlayerCount);
    }

    return nPlayerCount;
}

int AI()
{
    char cHA;
    printf("Do you want to play with another human or an AI? [H] or [A]: ");
    scanf(" %c", &cHA);
    cHA = tolower(cHA);

    while (cHA != 'a' && cHA != 'h')
    {
        printf("Invalid input. Please try again: ");
        scanf(" %c", &cHA);
    }

    if (cHA == 'a')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int candl(int nScore) 
{
    switch (nScore)
    {
        // ladders
        case 1: nScore = 38; break;
        case 4: nScore = 14; break;
        case 8: nScore = 30; break;
        case 21: nScore = 42; break;
        case 28: nScore = 65; break;
        case 50: nScore = 67; break;
        case 71: nScore = 92; break;
        case 88: nScore = 100; break;

        // chutes
        case 17: nScore = 3; break;
        case 32: nScore = 10; break;
        case 36: nScore = 6; break;
        case 48: nScore = 26; break;
        case 62: nScore = 18; break;
        case 87:  nScore = 24; break;
        case 95: nScore = 56; break;
        case 97: nScore = 78; break;

        default:
        nScore = nScore;
    }
    
    return nScore;
}

void board(int nP1, int nP2, int nP3, int nP4)
{
    int nRow, nCol;
    int nNum = 111;

    for(nRow = 10; nRow >= 1; nRow--)
    {
        if (nNum > 0)
        {
            if (nRow % 2 == 0)
            {
                nNum -= 11;
                 for (nCol = 10; nCol >= 1; nCol--)
                {
                    if(nNum == nP1)
                    {
                        yellow();
                        printf("[P1]\t");
                        reset();
                    }
                    else if(nNum == nP2)
                    {
                        cyan();
                        printf("[P2]\t");
                        reset();
                    }
                    else if(nNum == nP3)
                    {
                        green();
                        printf("[P3]\t");
                        reset();
                    }
                    else if(nNum == nP4)
                    {
                        red();
                        printf("[P4]\t");
                        reset();
                    }
                    else
                    {
                        printf("[%d]\t", nNum);
                    }
                    nNum--;
                }
            }
            else
            {
                nNum -= 9;
                for (nCol = 10; nCol >= 1; nCol--)
                {   
                    if(nNum == nP1)
                    {
                        yellow();
                        printf("[P1]\t");
                        reset();
                    }
                    else if(nNum == nP2)
                    {
                        cyan();
                        printf("[P2]\t");
                        reset();
                    }
                    else if(nNum == nP3)
                    {
                        green();
                        printf("[P3]\t");
                        reset();
                    }
                    else if(nNum == nP4)
                    {
                        red();
                        printf("[P4]\t");
                        reset();
                    }
                    else
                    {
                        printf("[%d]\t", nNum);
                    }
                    nNum++;
                }
                    
            }
            printf("\n");
        }
    }
}

void game (int *nPos, int nAI, bool bP1Turn)
{
    if (nAI == 0 || bP1Turn == true)
    {
        rollDice();
    }
    
    int nDice = random();
    *nPos = *nPos + nDice; 
    // score exceeds 100
    if (*nPos > 100)
    {
        *nPos -= (*nPos - 100) * 2;
    }
    printf("You are currently on tile %d\n\n", *nPos);
            
    // chutes and ladders
    int nCandl = candl(*nPos); // variable for the candl function

    if (nCandl > *nPos)
    {
        printf("You reached a ladder! Moving up to %d\n", nCandl);
    }
    else if (nCandl < *nPos)
    {
        printf("You landed on a chute! Going down to %d\n", nCandl);
    }
            
    *nPos = nCandl;
            
    // rolling the die again (6)
    while (nDice == 6 && *nPos != 100) 
    {
        //char c = getchar();
        printf("\nYou rolled a 6! You get to roll the die again.\n");

        if (nAI == 0 || bP1Turn == true)
        {
            rollDice();
        }
        else
        {
            char c = getchar();
            sleep(1);
        }

        nDice = random();
        *nPos = *nPos + nDice; 
        // score exceeds 100
        if (*nPos > 100)
        {
            *nPos -= (*nPos - 100) * 2;
        }
        printf("You are currently on tile %d\n\n", *nPos);

        // chutes and ladders
        nCandl = candl(*nPos); // variable for the candl function

        //printf("[TEST] nCandl = %d\n", nCandl); //[TEST]

        if (nCandl > *nPos)
        {
            printf("You reached a ladder! Moving up to %d\n", nCandl);
        }
        else if (nCandl < *nPos)
        {
            printf("You landed on a chute! Going down to %d\n", nCandl);
        }
                
        *nPos = nCandl;        
    }
}

void mainGame(int nP1, int nP2, int nP3, int nP4, int nPC, int nAI) // recursive
{
    bool bP1Turn, bP2Turn, bP3Turn, bP4Turn; // player turn
    bool bWin = false;

    bP1Turn = true;

    do 
    {
        // ----- PLAYER 1 ------
        if (bP1Turn == true)
        {   
            board(nP1, nP2, nP3, nP4);
            yellow();
            printf("\n\n= = = P L A Y E R  1 = = =\n");
            reset();

            game (&nP1, nAI, bP1Turn);

            printf("Press ENTER to continue...\n");
            char c = getchar();
            c = getchar();
            sleep(1);
            clrscr();

            if (nP1 == 100)
            {
                bP1Turn = false;
                board(nP1, nP2, nP3, nP4);
                yellow();
                printf("\n\nCongratulations Player 1!\n");
                cyan();
                printf("You won the game!\n\n");
                reset();
                bWin == true;
            }
            else
            {
                bP1Turn = false;
                bP2Turn = true;
            }    
        }

        // ----- PLAYER 2 ------
        if (bP2Turn == true)
        {
            board(nP1, nP2, nP3, nP4);
            cyan();
            printf("\n\n= = = P L A Y E R  2 = = =\n");
            reset();

            game (&nP2, nAI, bP1Turn);

            printf("Press ENTER to continue...\n");
            char c = getchar();
            if (nAI == 0) // double getchar for human players
            {
                c = getchar();
            }
            sleep(1);
            clrscr();

            if (nP2 == 100)
            {
                bP1Turn = false;
                bP2Turn = false;
                bP3Turn = false;
                bP4Turn = false;
                board(nP1, nP2, nP3, nP4);
                yellow();
                printf("\n\nCongratulations Player 2!\n");
                cyan();
                printf("You won the game!\n\n");
                reset();
                bWin == true;
            }
            else
            {
                if (nPC > 1)
                {
                    bP2Turn = false;
                    bP3Turn = true;
                }
                else
                {
                    bP2Turn = false;
                    mainGame(nP1, nP2, nP3, nP4, nPC, nAI);
                }
            }
        }

        // ----- PLAYER 3 ------
        if (bP3Turn == true)
        {
            board(nP1, nP2, nP3, nP4);
            green();
            printf("\n\n= = = P L A Y E R  3 = = =\n");
            reset();

            game (&nP3, nAI, bP1Turn);

            printf("Press ENTER to continue...\n");
            char c = getchar();
            if (nAI == 0)
            {
                c = getchar();
            }
            sleep(1);
            clrscr();

            if (nP3 == 100)
            {
                bP1Turn = false;
                bP2Turn = false;
                bP3Turn = false;
                bP4Turn = false;
                board(nP1, nP2, nP3, nP4);
                yellow();
                printf("\n\nCongratulations Player 3!\n");
                cyan();
                printf("You won the game!\n\n");
                reset();
                bWin == true;
            }
            else
            {
                if (nPC > 2)
                {
                    bP4Turn = true;
                    bP3Turn = false;
                }
                else
                {
                    bP3Turn = false;
                    mainGame(nP1, nP2, nP3, nP4, nPC, nAI);
                }
            }
        }

        // ----- PLAYER 4 ------
        if (bP4Turn == true)
        {
            board(nP1, nP2, nP3, nP4);
            red();
            printf("\n\n= = = P L A Y E R  4 = = =\n");
            reset();

            game (&nP4, nAI, bP1Turn);

            printf("Press ENTER to continue...\n");
            char c = getchar();
            if (nAI == 0)
            {
                c = getchar();
            }
            sleep(1);
            clrscr();

            if (nP4 == 100)
            {
                bP1Turn = false;
                bP2Turn = false;
                bP3Turn = false;
                bP4Turn = false;
                board(nP1, nP2, nP3, nP4);
                yellow();
                printf("\n\nCongratulations Player 4!\n");
                cyan();
                printf("You won the game!\n\n");
                reset();
                bWin == true;        
            }
            else
            {
                bP4Turn = false;
                mainGame(nP1, nP2, nP3, nP4, nPC, nAI);
            }
        }

    } while (bWin == false);
}

void chutesAndLadders()
{
    cyan();
    printf("LADDERS:                         CHUTES:\n");
    reset();
    printf("1 ---> 38                        17 ---> 3\n");
    printf("4 ---> 14                        32 ---> 10\n");
    printf("8 ---> 30                        36 ---> 6\n");
    printf("21 ---> 42                       48 ---> 26\n");
    printf("28 ---> 65                       62 ---> 18\n");
    printf("50 ---> 67                       87 ---> 24\n");
    printf("71 ---> 92                       95 ---> 56\n");
    printf("88 ---> 100                      97 ---> 78\n\n");
    printf("Press ENTER to continue...\n");
}

int main()
{
    char c;
    intro();
    chutesAndLadders();

    struct players // struct for player data
    {
        int nPos;
    } ;

    int nNum; // declaring variable of dice
    struct players P1, P2, P3, P4; // declaration for structures for player progress
    P1.nPos = 0;
    P2.nPos = 0;
    P3.nPos = 0;
    P4.nPos = 0;

    c = getchar();
    sleep(1);
    clrscr();

    int nPC = playerCount(); // getting return value of playerCount function

    int nAI = AI(); // returns 1 or 0

    mainGame(P1.nPos, P2.nPos, P3.nPos, P4.nPos, nPC, nAI);

    return 0;
}