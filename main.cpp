#include <iostream>


using namespace std;

char matrix[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char player = 'X';
void table();
void input();
void togglePlayer();
char win();


int main() {
	int numberOfPlayers, tieTurn = 0;
	cout << "Welcome to TIC TAC TOE!" << endl;
	table();
	cout << "\n1: VS Bot \n"
		 	"2: VS Player2 \n"
		 	"Who you want to play with?: ";
	cin >> numberOfPlayers;
	cout << "\n";
	table();
	
	if (numberOfPlayers == 1) {
		cout << "I'm busy :)";
	}
	
	if (numberOfPlayers == 2) {
		while(1) {
			input();
			tieTurn++;
			cout << "PLAYER 1: <X>    PLAYER 2: <O>\n";
			table();
			if (win() == 'X') {
				cout << "X wins!" << endl;
				break;
			} else if (win() == 'O') {
				cout << "O wins!" << endl;
				break;
			} else if (win() == 'T' && tieTurn == 9) {
				cout << "Tie" << endl;
				break;
			}
			togglePlayer();
		}
	}
	return 0;
}

void table() {
	system("cls");
	cout << "Tic Tac Toe \n \n";
	int i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

void input() {
	int x;
	
	cout << "\nPlayer " << player << " enter a position: ";
	cin >> x;
	
	if (x == 1)	{
		if (matrix[0][0] == '1') {
			matrix[0][0] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	} else if (x == 2) {
		if (matrix[0][1] == '2') {
			matrix[0][1] = player;
		} else { 
			cout << "Choose another position!" << endl;
			input();
		}
	} else if (x == 3) {
		if (matrix[0][2] == '3') {
			matrix[0][2] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	} else if (x == 4)			
		if (matrix[1][0] == '4') {
			matrix[1][0] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	else if (x == 5)	
		if (matrix[1][1] == '5') {
			matrix[1][1] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	else if (x == 6)	
		if (matrix[1][2] == '6') {
			matrix[1][2] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	else if (x == 7)		
		if (matrix[2][0] == '7') {
			matrix[2][0] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	else if (x == 8)	
		if (matrix[2][1] == '8') {
			matrix[2][1] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	else if (x == 9)	
		if (matrix[2][2] == '9') {
			matrix[2][2] = player;
		} else {
			cout << "Choose another position!" << endl;
			input();
		}
	else 
		cout << "INVALID" << endl;
}

void togglePlayer() {
	if (player == 'X')
		player = 'O';
	else player = 'X';
}
	
char win() {
	int i, j = 0;
	//PLayer X
	for (i = 0; i < 3; i++) {
			if (matrix[i][j] == 'X' && matrix[i][j+1] == 'X' && matrix[i][j+2] == 'X') 
				return 'X';
	}
	for (i = 0; i < 3; i++) {
			if (matrix[j][i] == 'X' && matrix[j+1][i] == 'X' && matrix[j+2][i] == 'X') 
				return 'X';
	}
	
	/*
	if (matrix[0][0] == 'X' && matrix[0][1] == 'X' && matrix[0][2] == 'X') 
		return 'X';
	if (matrix[1][0] == 'X' && matrix[1][1] == 'X' && matrix[1][2] == 'X') 
		return 'X';
	if (matrix[2][0] == 'X' && matrix[2][1] == 'X' && matrix[2][2] == 'X') 
		return 'X';
	
	if (matrix[0][0] == 'X' && matrix[1][0] == 'X' && matrix[2][0] == 'X') 
		return 'X';
	if (matrix[0][1] == 'X' && matrix[1][1] == 'X' && matrix[2][1] == 'X') 
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][2] == 'X' && matrix[2][2] == 'X') 
		return 'X';
	*/
	if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') 
		return 'X';
	if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') 
		return 'X';

		
	//Player O
	for (i = 0; i < 3; i++) {
		if (matrix[i][j] == 'O' && matrix[i][j+1] == 'O' && matrix[i][j+2] == 'O') 
			return 'O';
	}
	for (i = 0; i < 3; i++) {
		if (matrix[j][i] == 'O' && matrix[j+1][i] == 'O' && matrix[j+2][i] == 'O') 
			return 'O';
	}
	
	/*
	if (matrix[0][0] == 'O' && matrix[0][1] == 'O' && matrix[0][2] == 'O') 
		return 'O';
	if (matrix[1][0] == 'O' && matrix[1][1] == 'O' && matrix[1][2] == 'O') 
		return 'O';
	if (matrix[2][0] == 'O' && matrix[2][1] == 'O' && matrix[2][2] == 'O') 
		return 'O';
	
	if (matrix[0][0] == 'O' && matrix[1][0] == 'O' && matrix[2][0] == 'O') 
		return 'O';
	if (matrix[0][1] == 'O' && matrix[1][1] == 'O' && matrix[2][1] == 'O') 
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][2] == 'O' && matrix[2][2] == 'O') 
		return 'O';
	*/
	if (matrix[0][0] == 'O' && matrix[1][1] == 'O' && matrix[2][2] == 'O') 
		return 'O';
	if (matrix[0][2] == 'O' && matrix[1][1] == 'O' && matrix[2][0] == 'O') 
		return 'O';
	
	
	return 'T';
	
}


char aI() {
}
	

	
