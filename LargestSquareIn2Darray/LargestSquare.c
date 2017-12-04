#include <stdio.h>


/*The problem: Given a Matrix of 0's and 1's, Find the size of the biggest square submatrix
				that conatins no 1's

		Sample input 1
					0 0 0
					0 0 0
					0 0 0
		output: 3


		Sample input 2
					1 0 0 1
					0 0 0 0 
					0 0 0 0
					1 0 0 1
		output: 2
*/


#define ROW 5
#define COLUMN 7

void input(int rows, int columns, int matrix[][columns]);
void output(int rows, int columns, int matrix[][columns]);
int  biggestSquare(int rows, int columns,int matrix[][columns]);
int  helper(int rows,int columns, int startRow, int startCol, int matrix[][columns]);

/*
	biggestSquare function will figure out the larget squre of 0's
	helper function will help the biggestSquare function to determiine the largest square of zeros
*/


int main(int argc,char**argv)
{

	int matrix[ROW][COLUMN];

	input(ROW,COLUMN,matrix);
	output(ROW,COLUMN,matrix);
	printf("Largest square of 0's is: %i\n",biggestSquare(ROW,COLUMN,matrix));

	return 0;
}


void input(int rows, int columns, int matrix[][columns])
{

	int i,j;
	
	//Scanning forinput below
	//This does not check if the user input is a valid integer or 1/0
	for(i=0;i<ROW; i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			printf("Please input [%i][%i]: ",i,j);
			scanf("%i",&matrix[i][j]);
		}
	}

	printf("\n");
}

void output(int rows, int columns, int matrix[][columns])
{
	int i,j;

	for(i=0;i<ROW; i++)
	{
		for(j=0;j<COLUMN;j++)
		{
			printf("%i  ",matrix[i][j]);
		}
		printf("\n");
	}
}


int  biggestSquare(int rows, int columns,int matrix[][columns])
{
	
	int i,j, potMax;
	int max = 0; //assuming max dimension of square is 0
	
		for(i = 0; i<rows; i++)
		{
			for(j = 0; j<columns; j++)
			{
				if(matrix[i][j] == 0)
				{
					potMax = helper(rows,columns, i,j, matrix);
					if(max < potMax )
						max = potMax;		
				}
			}
		}
	return max;
}

int  helper(int rows,int columns, int startRow, int startCol, int matrix[][columns])
{
	int count = 1; //will keep track of dimention of largest square
				   //we will initialize to 1 since if we enter this function, you have detected
				   // a 1
	int i,j;


	// below for loop counts the dimension of the potential square
	for(i = startRow + 1, j=startCol+1; i<rows && j<columns; i++, j++)
	{
		//checks to see if both symetrical horizontal and vertical are 0
		//keeps track of dimension of square in counter variable
		if(matrix[startRow][j]==0 && matrix[i][startCol]==0)
			count++;
		else
			break;
	}

	//below for loop checks the inner potential square
	for(i = startRow + 1; i<count + startRow; i++)
	{
		for(j = startCol + 1; j<count + startCol; j++)
		{
			//this is when you encounter a 1 in your matrix
			if(matrix[i][j] != 0)
			{
				count = j -1;
			}
		}
	}

	return count;
}


