#include <stdio.h>
#include <stdlib.h>
char board[3][3] = {

    {' ', ' ', ' '},

    {' ', ' ', ' '},

    {' ', ' ', ' '}

};

char player1 = 'x';
int embity_sapce();
char result;

void clearboard();

void displayboard();

void play();

void switchplayers();

char checkrows();

char checkcolumns();

char diagonal1();

char diagonal2();

char checkwinner();

int main()

{

    clearboard();

    while (1)

    {

        play();
        result = checkwinner();
        if (result == 'x' || result == 'o')

        {
            printf("winner is %c ", result);
            break;
        }
        else if (result == 'n') //no winner 
        {
            printf("no one wins");
            break;
        }
    }

    return 0;
}






int  embity_sapce()

{

    for (int i = 0; i < 3; i++)
    {

        for (int j = 0; j < 3; j++)

        {
            if(board[i][j]==' ')
            {
                return 1;
            }
        
        }

    }
    return 0;
}




void displayboard()

{

    for (int i = 0; i < 3; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            printf("%c | ", board[i][j]);
        }

        printf("\n------------\n");
    }
}

void clearboard()

{

    for (int i = 0; i < 3; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            printf("   | ", board[i][j]);
        }

        printf("\n------------\n");
    }
}

void switchplayers()

{

    if (player1 == 'x')

    {

        player1 = 'o';
    }

    else

    {

        player1 = 'x';
    }
}

void play()

{
    int row, column;
    int flag = 0;
    while (1)
    {
        printf("please enter where to play (row , coulmn) \n");

        scanf("%d %d", &row, &column);

        if (board[row][column] == ' ')
        {
            board[row][column] = player1;
            displayboard();
            switchplayers();
            break;
        }

        else if (board[row][column] != ' ')
        {
            printf(" this place is already occupied \n");
            break;

        }
    }
}

char checkrows()

{

    for (int i = 0; i < 3; i++)
{
        // x  '' o
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])

            return board[i][0];
    }

    return ' ';
}

char checkcolumns()

{

    for (int i = 0; i < 3; i++)

    {

        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])

            return board[0][i];
    }

    return ' ';
}

char diagonal1()

{

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2])

    {

        return board[0][0];
    }

    return ' ';
}

char diagonal2()

{

    if (board[2][0] == board[1][1] && board[2][0] == board[0][2])

    {

        return board[2][0];
    }

    return ' ';
}

char checkwinner()

{

    if (checkrows() != ' ')

    {

        return checkrows();
    }

    else if (checkcolumns() != ' ')

    {

        return checkcolumns();
    }

    else if (diagonal1() != ' ')

    {

        return diagonal1();
    }

    else if (diagonal2() != ' ')

    {

        return diagonal2();
    }
    else if(embity_sapce()==1)
    {
        return ' ';
    }

    return 'n';
}
