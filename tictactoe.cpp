#include <iostream>
using namespace std;

void prnt(char b[3][3]) 
{
    cout << 
    "     1   2   3" << '\n' << 
    "    -----------" << '\n' << 
    " a | " << b[0][0] << " | " << b[0][1] << " | " << b[0][2] << " |" << '\n' << 
    "   | - + - + - |" << '\n' << 
    " b | " << b[1][0] << " | " << b[1][1] << " | " << b[1][2] << " |" << '\n' << 
    "   | - + - + - |" << '\n' <<
    " c | " << b[2][0] << " | " << b[2][1] << " | " << b[2][2] << " |" << '\n' << 
    "    -----------" << '\n' << '\n';
}

bool change(char b[3][3], char let, char num, char turn) 
{
    int row = let - 'a';
    int col = num - '1';
    if (b[row][col] == ' ') {
        b[row][col] = turn;
        return true;
    }
    return false;
}

int main()
{
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    cout << "\ninput format: \"a1\" if you wish to place your sign in the upper left corner\n\n";

    char win = ' ';
    string input;
    char turn = 'x';
    int turns = 0;
    while (win == ' ') {
        prnt(board);
        while (true) {
            cout << "player " << turn << "'s turn. input coordinates of desired turn: ";
            cin >> input;
            if (input.length() != 2) {
                cout << "\ndont try to break the program #3\n";
            }
            char letter = input[0];
            char number = input[1];
            if ((letter == 'a' || letter == 'b' ||letter == 'c') && (number == '1' || number == '2' || number == '3')) {
                if (change(board, letter, number, turn)) {
                    break;
                }
                else cout << "\ndont try to break the program #2\n";
            }
            else cout << "\ndont try to break the program\n";
        }
        cout << '\n';
        char* first = board[0];
        char* second = board[1];
        char* third = board[2];
        if ((first[0] == first[1] && first[1] == first[2] && first[0] != ' ') || 
            (second[0] == second[1] && second[1] == second[2] && second[1] != ' ') || 
            (third[0] == third[1] && third[1] == third[2] && third[1] != ' ') || 
            (first[0] == second[0] && second[0] == third[0] && first[0] != ' ') || 
            (first[1] == second[1] && second[1] == third[1] && second[1] != ' ') || 
            (first[2] == second[2] && second[2] == third[2] && second[2] != ' ') || 
            (first[0] == second[1] && second[1] == third[2] && first[0] != ' ') || 
            (first[2] == second[1] && second[1] == third[0] && second[1] != ' ')) 
        {
            win = turn;
            prnt(board);
            cout << "player " << turn << " won\n";
        }
        else if (turn == 'x')
            turn = 'o';
        else turn = 'x';
        turns++;
        if (turns == 9) {
            prnt(board);
            cout << "tie\n";
            break;
        }
    }

    //      1   2   3
    //     -----------
    //  a | x | o |   |
    //    | - + - + - |
    //  b |   | x |   |
    //    | - + - + - |
    //  c |   |   | o |
    //     -----------

    return 0;
}

