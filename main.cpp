#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// The size of the game board
const int BOARD_SIZE = 3;

// The markers for the player and computer
const char PLAYER_MARKER = 'X';
const char COMPUTER_MARKER = 'O';

// The game board
char board[BOARD_SIZE][BOARD_SIZE];

// Initializes the game board with empty cells
void initialize_board() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            board[row][col] = ' ';
        }
    }
}

// Prints the game board to the console
void print_board() {
    cout << "-------------\n";
    for (int row = 0; row < BOARD_SIZE; row++) {
        cout << "|";
        for (int col = 0; col < BOARD_SIZE; col++) {
            cout << " " << board[row][col] << " |";
        }
        cout << "\n-------------\n";
    }
}

// Checks whether a player has won the game
bool check_win(char marker) {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; row++) {
        bool row_win = true;
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] != marker) {
                row_win = false;
                break;
            }
        }
        if (row_win) {
            return true;
        }
    }
    // Check columns
    for (int col = 0; col < BOARD_SIZE; col++) {
        bool col_win = true;
        for (int row = 0; row < BOARD_SIZE; row++) {
            if (board[row][col] != marker) {
                col_win = false;
                break;
            }
        }
        if (col_win) {
            return true;
        }
    }
    // Check diagonals
    bool diag1_win = true;
    bool diag2_win = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] != marker) {
            diag1_win = false;
        }
        if (board[i][BOARD_SIZE - i - 1] != marker) {
            diag2_win = false;
        }
    }
    if (diag1_win || diag2_win) {
        return true;
    }
    return false;
}

// Checks whether the game has ended in a draw
bool check_draw() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == ' ') {
                return false;
            }
        }
    }
    return true;
}

// The player's turn
void player_turn() {
    int row, col;
    cout << "Enter row and column (1-" << BOARD_SIZE << "): ";
    cin >> row >> col;
    row--;
    col--;
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != ' ') {
        cout << "Invalid move! Try again.\n";
        player_turn();
    } else {
        board[row][col] = PLAYER_MARKER;
    }
}

// The computer's turn
void computer_turn() {
    srand(time(NULL));
    int row, col;
    do {
        row = rand() % BOARD_SIZE;
        col = rand() % BOARD_SIZE;
    } while (board[row][col] != ' ');
    cout << "Computer plays row " << row + 1 << " column " << col + 1 << ".\n";
    board[row][col] = COMPUTER_MARKER;
}

// The game loop
void play_game() {
    initialize_board();
    print_board();
    while (true) {
        player_turn();
        print_board();
        if (check_win(PLAYER_MARKER)) {
            cout << "You win!\n";
            break;
        }
        if (check_draw()) {
            cout << "It's a draw!\n";
            break;
        }
        computer_turn();
        print_board();
        if (check_win(COMPUTER_MARKER)) {
            cout << "You lose!\n";
            break;
        }
        if (check_draw()) {
            cout << "It's a draw!\n";
            break;
        }
    }
}

int main() {
    cout << "Welcome to TicTacToe!\n";
    play_game();
    return 0;
}
