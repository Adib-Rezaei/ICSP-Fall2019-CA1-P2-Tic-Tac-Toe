#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//prototypes
void reset_game(char[], char[]);
void draw_board(char[]);
int check_the_input(int);
int playing(int, int, char[], char[]);
int check_winning(int, int, char[], char[]);
int check_draw(char[]);
int new_play(int, char[], char[]);

int main() {
	//declaring
	char square[9] = { ' ', ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ' };
	char num[9] = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
	int player = 1, player_input, new_game=0;

	/*main loop*/
	while (1) {
		/*board*/
		draw_board(square);

		/*asking the player to enter a valid number*/

		printf("Player %d turn, please enter a number from 1 to 9: ", player);
		/*what happens if the player doesn't enter a valid number*/

		if (scanf("%d", &player_input)) {
			if (check_the_input(player_input) == 0)
				continue;
		}
		else {
			printf("\nInvalid character\n");
			scanf("%c", &player_input);
			continue;
		}

		/*main rules*/ // playing 
		if (playing(player_input, player, square, num))
			continue;

		/*the logic of winning*/
		if (check_winning(player, new_game, num, square)) {
			if (new_play(new_game, square, num)) {
				player = 1;
				continue;
			}
			else
				break;
		}
		//checks if the game is draw or not
		if (check_draw(square)) {
			draw_board(square);
			printf("\nDraw!\n");
			if (new_play(new_game, square, num)) {
				player = 1;
				continue;
			}
			else
				break;
		}
		
		/*changing the player*/
		if (player == 1)
			player = 2;
		else player = 1;


	}
	/*end*/
	printf("\n\nGood bye!");
	scanf("%d", &player_input);
	return 0;
}

void draw_board(char square[]) {
	/*Show the board*/
	printf("\t|\t|\n    %c   |   %c   |   %c   \n", square[0], square[1], square[2]);
	printf("________|_______|_______\n");
	printf("\t|\t|\n    %c   |   %c   |   %c   \n", square[3], square[4], square[5]);
	printf("________|_______|_______\n");
	printf("\t|\t|\n    %c   |   %c   |   %c   \n", square[6], square[7], square[8]);
}

	//prints invalid input if the input was anything except 1 to 9
int check_the_input(int player_input) {
	if (player_input != 1 && player_input != 2 && player_input != 3 && player_input != 4 && player_input != 5 && player_input != 6 && player_input != 7 &&
		player_input != 8 && player_input != 9) {
		printf("invalid input, please try again\n");
		return 0;
	}
	else
		return 1;
}
	//checks if the square is used or not , if used prints error, else allocate that square with relevent character
int playing(int player_input, int player, char square[], char num[]) {
	for (int i = 0; i < 9; i++) {
		if (player_input == i + 1 && square[i] == ' ') {
			if (player == 1) num[i] = square[i] = 'X';
			else num[i] = square[i] = 'O';
			return 0;
		}

		else if (player_input == i + 1 && square[i] != ' ') {
			printf("\nThis square is used, please try again\n");
			return 1;
		}
	}
}

		//see if the row , coloumn and diagnal is the same or not if yes prints congrats to the relevent player
int check_winning(int player, int new_game, char num[], char square[]) {
	if (num[0] == num[1] && num[1] == num[2] || num[0] == num[3] && num[3] == num[6] || num[0] == num[4] && num[4] == num[8] ||
		num[1] == num[4] && num[4] == num[7] || num[2] == num[5] && num[5] == num[8] || num[3] == num[4] && num[4] == num[5] ||
		num[6] == num[7] && num[7] == num[8] || num[2] == num[4] && num[4] == num[6]) {
		draw_board(square);
		printf("\ncongratulations, player %d wins\n", player);
		return 1;
	}
	else
		return 0;
}
	//asks the player if he/she wants to play or not, if yes resets the board, not coming out from loop
int new_play(int new_game, char square[], char num[]) {
	printf("Enter 1 if you wanna start a new game, otherwise enter 2: ");
	scanf("%d", &new_game);
	if (new_game == 1) {
		reset_game(square, num);
		return 1;
	}
	else
		return 0;
}
	//resets the board of the game and allocate the valuable with new elements
void reset_game(char square[], char num[]) {
	for (int i = 0; i < 9; i++) {
		square[i] = ' ';
	}
	num[0] = '1', num[1] = '2', num[2] = '3', num[3] = '4', num[4] = '5', num[5] = '6', num[6] = '7', num[7] = '8', num[8] = '9';
}
	//checks if the game is draw or not by checking the squares is allocated with something or not
int check_draw(char square[]) {
	if (square[1] != ' ' && square[2] != ' ' && square[3] != ' ' && square[4] != ' ' && square[5] != ' ' && square[6] != ' ' &&
		square[7] != ' ' && square[8] != ' ' && square[0] != ' ') {
		return 1;
	}
	else
		return 0;
}