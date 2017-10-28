/*****************************************************
*				queens.c (2017/2018) 	
*  				  Miamoto Musashi				 	
*							        											
* 	 > Program to solve N Queen Problem with 			
*	   Backtracking using one dimensional array.   	    
******************************************************


/***********************************************************************************/

/*---- Header Files ---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"

/*---- Constants ------------------------------------------------------------------*/

#define MAX 100

/*---- Extern Variables -----------------------------------------------------------*/

int number_of_queens; 
int matrix_problem[MAX][MAX];


/************************************************************************************/


/*---- Functions -------------------------------------------------------------------*/


/*
 *	This function will check if queen can be placed at matrix_problem[][number_of_queens]
 */

int canPlace(int row, int column){

	int i, j;

	/* Since we are filling one column at a time, we will check if : */


	/* no queen is placed in that particular row */

	for(i = 0; i < column; i++)
		if(matrix_problem[row][i] == 1)
			return 0;


	/* no queen is placed in the upper diagonal */

	for(i = row, j = column; i >= 0 && j >= 0; i--, j--)
		if(matrix_problem[i][j] == 1)
			return 0;


	/* no queen is placed in the lower diagonal */

	for(i = row, j = column; i < number_of_queens && j >= 0; i++, j--)
		if(matrix_problem[i][j] == 1)
			return 0;


	return 1;
}

/*
 *	This function will place the Queens one at a time with
 *  the backtracking property
 */

int placeQueens(int queen){

	int row;

	if (queen == number_of_queens) /*If true Problem is Solved*/
		return 1;

	for(row = 0; row < number_of_queens; row++)
		
		if(canPlace(row, queen)){

			matrix_problem[row][queen] = 1; /* Place the Queen*/
			

			if(placeQueens(queen+1)) /* Solve for next Queen - Recursion */
				return 1;

			/* If not possible backtrack*/

			matrix_problem[row][queen] = 0;	
		}

	return 0; /*No solution Found*/
}

/*
 *	This function will Solve the problem
 *  if the solution exists
 */


void solveNQueenProblem(){
	
	int i, j;

	if(placeQueens(0)){
		
		printf("Solution: \n");
		
		/* Print Matrix Solution */

		for(i = 0; i < number_of_queens; i++){  
			for(j = 0; j < number_of_queens; j++)
				printf(" %d",matrix_problem[i][j]);
			printf("\n");
		}
	
	}else
		printf("There Exists no Solution for Problem with %d Queens\n", number_of_queens);
}

/***********************************************************************************/


/*---- Main Function ---------------------------------------------------------------*/

int main(int argc, char *argv[]){

	int i, j;

	/* Treatment of Input*/

	if(argc < 2){
		printf("--> It is needed 1 argument to specify the number of queens.\n");
		printf("--> Do Something like this: ./queens 5\n");
		exit(EXIT_SUCCESS);
	}
	else{
		if(isNumber(argv[1]))
			number_of_queens = atoi(argv[1]);
		else{
			printf("--> Argument must be an integer, ex: 4,5,6 ...\n");
			printf("--> Please try Again\n");
			exit(EXIT_SUCCESS);
		}
	}

	/*  Create Matrix and Set all rows and columns to 0 */

	for(i = 0; i < number_of_queens; i++)
		for(j = 0; j < number_of_queens; j++)
			matrix_problem[i][j] = 0;

	/* Solve the Actual Problem*/
	
	solveNQueenProblem();

	exit(EXIT_SUCCESS);
}

/*---- End ---------------------------------------------------------------*/
