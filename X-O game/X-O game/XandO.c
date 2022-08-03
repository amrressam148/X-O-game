#include<stdio.h>
#include <conio.h>

char arr[3][3] = { '1', '2', '3', '4','5', '6', '7', '8', '9'};


void Display() {
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%c", arr[i][j]);
			printf(" ");
		}
		printf("\n");
	}
}
void play(char Player)
{
	char choice;
	printf("Player %c, enter a number:  ", Player);

	scanf("%c", &choice);
	
	for (int i = 0; i < 3; i++)
	{

		for (int j = 0; j < 3; j++)
		{ 
			if (arr[i][j] == choice) {
				arr[i][j] = Player;
				break;
			}
		}	
		break;
	}
	if (Player == 'X')
	{
		Player = 'O';
	}
	else
	{
		Player = 'X';
	}
	
}

	

char WIN() {
	int Xcounter = 0, Ocounter = 0 , gameCounter=0;

	//1stCondition----win condition on each row for both players----//
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] != 'X' && arr[i][j] != 'O')
				gameCounter++;
			

			if (arr[i][j] == 'X')

				Xcounter++;

			else if (arr[i][j] == 'O')

				Ocounter++;

			if (Xcounter == 3 || Ocounter == 3)

				if (Xcounter > Ocounter)

					 return 'X';

				else return 'O';
		}
		Xcounter = 0 ; Ocounter = 0; //to restart couunting for the new row 
	}
	//2ndCondition----win condition on each col for both players----//
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[j][i] == 'X')

				Xcounter++;

			else if (arr[j][i] == 'O')

				Ocounter++;

			if (Xcounter == 3 || Ocounter == 3)

				if (Xcounter > Ocounter)

					return 'X';

				else return 'O';
		}

		Xcounter = 0; Ocounter = 0; //to restart couunting for the new col 
	}

	//3rdCondition----win condition on main diagonal for both players----//

	if (arr[0][0] == 'X' && arr[1][1] == 'X' && arr[2][2] == 'X') return 'X';

	else if (arr[0][0] == 'O' && arr[1][1] == 'O' && arr[2][2] == 'O') return 'O';

	//4thCondition----win condition on the another diagonal for both players----//
	else if (arr[0][2] == 'X' && arr[1][1] == 'X' && arr[2][0] == 'X') return 'X';

	else if (arr[0][2] == 'O' && arr[1][1] == 'O' && arr[2][0] == 'O') return 'O';

	//---  Draw Condition??  ---//
	if (gameCounter == 0) return 'Z';

	return '.';
}
int main() {
	char Player;
	while (WIN()=='.')
	{
		Display();
	    play(&Player);
		
	}
	Display();
	if (WIN() == 'Z')
		printf("No Winner......DRAW");
	else
		printf("\n CONGRATS..THE WINNER IS PLAYER :  %c", WIN());
		
	}
	