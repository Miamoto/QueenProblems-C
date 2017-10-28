/************************************************************
*					Rainhas.c (2017/2018) 					*
*					-- Carlos Carvalho --			        *
*															*
* 		 > Program to solve N Queen Problem with 			*
*		   Backtracking using one dimensional array.   	    *
*************************************************************/


/***********************************************************************************/

/*---- Header Files ---------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "numbers.h"

/*---- Constants ------------------------------------------------------------------*/

#define MAX_QUEENS 100

/*---- Extern Variables -----------------------------------------------------------*/

int number_of_queens; 
int result[MAX_QUEENS]; /* result[i]=j; means queen at i-th row is placed at j-th column. */
									


/************************************************************************************/


/*---- Functions -----------------------------------------------------------*/

/*
 *	This function will check if queen can be placed at (x2,y2). 
 *	Can queen at x2 row be placed at y2 column?
 */

int canPlace(int x2, int y2){

	int a, b;

	for(int i = 0; i < x2; i++){
		
		/* |x1-x2|==|y1-y2| means they are placed in same diagonals. */
		a = abs(i - x2); 
		b = abs(result[i] - y2);
		
		if((result[i] == y2) || (a == b)) 
			return 0;
	}

	return 1;
}

/*
 *  This function will place N Queens if possible
 *  This function goes in search for all answers
 */
	
void solveNQueenProblem(int x, int size){

	int i, j;
	
	for(i = 0; i < size; i++)
		if(canPlace(x,i)){
			result[x] = i;
			if(x == size-1){
				printf("       ");
				for(j = 0; j < number_of_queens; j++)
					printf("%d ", result[j] + 1);
				printf("\n");
			}
			solveNQueenProblem(x+1,size);
							
		}
}

/***********************************************************************************/



/*---- Main Function ---------------------------------------------------------------*/


int main (int argc, char *argv[]){

	int i;

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

	if(number_of_queens < 4){
		printf("--> No solutions for %dX%d with %d queens.\n", number_of_queens,number_of_queens,number_of_queens);
		printf("--> Try with a number bigger then 3.\n");
		exit(EXIT_SUCCESS);
	}
	
	for(i = 0; i < number_of_queens; i++)
		result[i] = 0;

	/* Solve the Actual Problem*/

	printf("Solutions:\n");
	printf("Lines: \n");
	
	for(i = 0; i < number_of_queens; i++)
		printf("%d ", i+1);
	
	printf("\n");

	solveNQueenProblem(0,number_of_queens);

	exit(EXIT_SUCCESS);
}

/*---- End ---------------------------------------------------------------*/

