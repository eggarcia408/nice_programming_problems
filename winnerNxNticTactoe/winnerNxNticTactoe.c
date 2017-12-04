#include <stdio.h>
#include <stdlib.h>


/* 
	This will be used to deterine winner of a NxN tic tac toe board
*/


void createBoard(char ***board_p, unsigned int size_p);
void initializeBoard(char **board_p, unsigned int size_p);
void printBoard(char **board_p, unsigned int size_p);
void directions(void);
int  userinput(char **board,int size_p, unsigned int row_p, unsigned int column_p, int who_p);
int  checkingforwinner(char **board, int size_p);
void cleanup(char ***board_p, int size_p);

int main(int argc, char **argv)
{
	int who; 				//will keep track whos turn it is
	unsigned int size;
	char **board;
	char input;
	unsigned int row,column; 	//will keep track of dimension that the user will input its X's and O's		
	int winner=0; 				// will be used to keep track of a winner:
								// 0 -> no winner yet    1-> X is winner(user 1)    2-> 0 is winner(user 2)
	int error; 					// -1 -> error   otherwise -> no error
		
	printf("Please enter dimension of tic tac toe board(NxN):  ");
	scanf("%i",&size);

	createBoard(&board,size);
	initializeBoard(board, size);
	printf("Initial Board\n");
	printBoard(board,size);
	directions();

	printf("\n\n\n");
	do
	{
		if( who%2 == 0)
			printf("Player 1 Turn\n");
		else
			printf("Player 2 Turn\n");
		
		printf("Please enter Your Dimensions(row first and then column)\n");
		scanf("%i%i",&row,&column);		
		error = userinput(board, size, row, column, who);
		if(error == -1)
		{
			printf("-----Error------\n");
			printf("Invalid DImension Or Position already Taken\n\n");
			continue; //so skip everything else
		}
		
		printf("Current State of Board\n");
		printBoard(board,size);
		winner = checkingforwinner(board,size);
		
		printf("\n\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n\n");
		if(winner == 1)
		{
			printf("Player 1 won\n");
		}
		if(winner == 2)
		{
			printf("Player 2 won\n");
		}
		
		who++;
	}
	while( winner == 0 && who != size*size);


	if(winner == 0)
	{
		printf("Cats Game\n\n");
	}
	
	cleanup(&board,size);
	return 0;

}





void cleanup(char ***board_p, int size_p)
{
	int i;
	for(i=0; i<size_p; i++)
	{
		free((*board_p)[i]);
	}
	free(*board_p);
}
	
void createBoard( char ***board_p,unsigned int size_p)
{

	int i;

	(*board_p) = (char**) malloc(sizeof(char*) * size_p); //first step to creat 2d array
	
	for(i = 0; i<size_p; i++)
	{
		(*board_p)[i] = (char*) malloc(sizeof(char)*size_p);
	}	

}



void initializeBoard(char **board_p, unsigned int size_p)
{

	int i,j;
	
	for( i = 0; i< size_p; i++) //[i] rows     [j] coloumn
	{
		for(j = 0; j<size_p;j++)
		{
			board_p[i][j] = '*';
		}
	}
}


void printBoard(char **board_p, unsigned int size_p)
{

	int i,j,k;
	for(i=0; i< size_p; i++) //[i] rows     [j] coloumn
	{
		for(j=0; j<size_p;j++)
		{
			printf("%c ",board_p[i][j]);
			if( j< (size_p - 1) ) //used to print a line
			{
				printf("|");
			}
		}
		printf("\n");
		for(j = 0; j< size_p-1;j++)
		{
				printf("---");
		}
		printf("\n");
	}		
	
}

void directions(void)
{
	printf("Directions: Each User Will enter the desired i(row) and j(column) location \n");
	printf("            User will alternate inputting there X's and O's \n");
	printf("            Player 1 will be X's and Player 2 will be O's \n");	
}


int userinput(char **board,int size_p, unsigned int row_p, unsigned int column_p, int who_p)
{

	//so if user entered invalid coordinates, the function will exit, returning an error(-1)	
	if( (row_p < 0) || (column_p < 0) || (row_p >= size_p) || (column_p >= size_p) )
	{
		return -1;
	}
	
	//Remeber player 1 is X's and Player 2 is O's

	if(who_p%2 == 0) //this is player 1's turn
	{
		if( board[row_p][column_p] == 'O'  ||   board[row_p][column_p] == 'X' )	
		{
			return -1; //this means an error have occured
		}

		else
		{
			board[row_p][column_p] = 'X';
		}
	}
	else //this is player 2's turn
	{
		if( board[row_p][column_p] == 'O'  ||   board[row_p][column_p] == 'X' )	
		{
			//this means an error have occured
			return -1;
		}
		else
		{
			board[row_p][column_p] = 'O';
		}
	}		

	return 1; //so if function gets to this point, no errors have occured
}


int  checkingforwinner(char **board, int size_p)
{
	int i,j;
	char userChar;
	int winner =0; //this will be used to keep track of the winner
				// 0 -> no winner   1--> player 1 winner  2--> player 2 winner

	///////////checking vertical columns in the tic tac toa board///////////////////
	
	for(j=0; j< size_p; j++ ) 
	{
		userChar = board[0][j];

		for(i=1;i<size_p;i++)
		{
			if( board[i][j] != userChar || userChar == '*')
			{
				break;
			}
		}

		//this means all matching characters in a column, so there is  winner
		if(i == size_p) 
		{
			if( userChar == 'X') //this means that player 1 won
				return 1;
			else
				return 2;
		}
	}
	///////////DOne Checking vertical columns///////////////



	//////////Checking horizontal columns/////////////////

	for(i = 0; i<size_p;i++)
	{
		userChar = board[i][0];
		
		for(j=1; j<size_p; j++)		
		{
			if(userChar != board[i][j] || userChar == '*')
				break;
		}

		if(j == size_p)
		{
			if (userChar == 'X')
				return 1;
			else
				return 2;
		}
	}
	///////////////Checking horizontal columns////////////////////


	///////Checking Diagnal From Top Left to Bottom Right//////////

	userChar = board[0][0];
	for(i=1; i<size_p; i++)
	{
		if(board[i][i] != userChar || userChar == '*')
			break;
	}

	if(i==size_p) //this is used to check for a winner
	{
		if(userChar == 'X')
			return 1;
		else
			return 0;
	}

	///////Done Checking Diagnal From Top Left to Bottom Right//////////

	userChar =board[size_p - 1][0]; 
	for(i=size_p - 2, j=1; i>=0 && j<size_p; i--,j++)
	{
		if(board[i][j] != userChar || userChar == '*')
			break;	
	}

	if(i== -1 && j==size_p) //this is used to check for a winner
	{
		if(userChar == 'X')
			return 1;
		else
			return 0;
	}
	
	///////Checking Diagnal From Bottom Left to Top Right//////////
	

	return 0; //if it reaches this point no winner has occured
}



