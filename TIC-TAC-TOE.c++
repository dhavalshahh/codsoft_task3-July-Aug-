#include <iostream>
using namespace std;

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
string name1, name2;
int choice;
int row, column;
char turn = 'X';
bool draw = false;
char response('y');

void structure()
{
    // It is basic structure of the game;

    cout << "\n\n";
    cout << name1 << " is [X]\t" << name2 << " is [0]\n\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "\n";
    cout << "\t\t_____|_____|_____\n";
    cout << "\t\t     |     |     \n";
    cout << "\t\t  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "\n";
    cout << "\t\t     |     |     \n";
}

void player_turn()
{
    // This function gets the player input and update the board

    if (turn == 'X')
    {
        cout << "\n"
             << name1 << "'s turn [X] :";
    }
    else if (turn == 'O')
    {
        cout << "\n"
             << name2 << "'s turn [O] :";
    }
    cin >> choice;

    // using switch case to get which row and column will update.
    switch (choice)
    {
    case 1:
        row = 0;
        column = 0;
        break;
    case 2:
        row = 0;
        column = 1;
        break;
    case 3:
        row = 0;
        column = 2;
        break;
    case 4:
        row = 1;
        column = 0;
        break;
    case 5:
        row = 1;
        column = 1;
        break;
    case 6:
        row = 1;
        column = 2;
        break;
    case 7:
        row = 2;
        column = 0;
        break;
    case 8:
        row = 2;
        column = 1;
        break;
    case 9:
        row = 2;
        column = 2;
        break;
    default:
        cout << "Invalid Move!!";
    }

    if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'X'; // updating the position of 'X' symbol
        turn = 'O';
    }
    else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
    {
        board[row][column] = 'O'; // updating the position of 'O' symbol
        turn = 'X';
    }
    else
    {
        cout << "Box already filled! \nPlease chose another box. \n\n"; // if input position is already filled
        player_turn();
    }
    structure();
}

bool checking()
{
    // checking the wining conditions .

    for (int i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return false;
        }
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0])
    {
        return false;
    }

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
            {
                return true;
            }

    draw = true;
    return false;
}

void reset_board()
{   //resetting the game board to play again
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = '1' + i * 3 + j;
        }
    }
}

void play()
{
    cout << "Enter the name of first player:";
    cin >> name1;
    cout << "Enter the name of second player:";
    cin >> name2;
    while (checking())
    {
        structure();
        player_turn();
        checking();
    }
    if (turn == 'X' && draw == false)
    {
        cout << name2 << " has won the game!!!!";
    }
    else if (turn == 'O' && draw == false)
    {
        cout << name1 << " has won the game!!!!";
    }
    else
    {
        cout << "\n\n It's a DRAW!!!\n\n";
    }
    // play again funtion
    char res;
    int count = 0;
    while (count == 0)
    {
        cout << "\nDo you want to play again(y/n)?";
        cin >> res;
        if (res == 'y' || res == 'Y')
        {
            reset_board();
            turn = 'X';
            play();
        }
        else
        {
            cout << "Thanks for playing!!!";
            count++;
        }
        count++;
    }
}

int main()
{
    cout<<"\t******  WELCOME TO THE TIC-TAC-TOE GAME!  *****"<<endl;
    cout << "Do you want to play the game(y/n)?";
    cin >> response;
    if (response == 'y' || response == 'Y' )
    {
        play();
    }
    else
    {
        cout << "Thanks for playing!!!";
    }
}
