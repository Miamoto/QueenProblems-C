/************************************************************
*		     README (2017/2018) 		    *
*		    -- Carlos Carvalho --	            *
*							    *
* 	 > Program to solve N Queen Problem with    	    *
*	   Backtracking using one dimensional array.        *
*************************************************************/

Prerequisites: No need to install softwares.

Running the tests: Run the program by typing make in the console and after that type ./queens N, where N is the NxN problem with N Queens. The output will give all the possible answers for the N queen problem.


				   Example of Input: make
				   	             ./queens 5 
				   
				   Example of Output: Lines: 1 2 3 4 5 

							     0 2 4 1 3 
							     0 3 1 4 2 
							     1 3 0 2 4 
							     1 4 2 0 3 
							     2 0 3 1 4 
							     2 4 1 3 0 
							     3 0 2 4 1 
							     3 1 4 2 0 
							     4 1 3 0 2 
							     4 2 0 3 1 /* result[i]=j; means queen at i-th row is placed at j-th column. */
				   					 			        

					For N >= 10 the answer will take more time to appear.
				  		
