#include<stdio.h>

#include<math.h>

#include<stdlib.h>

#include <limits.h>

#include<time.h> 

#include "stack.h"

int ran(){
	int n, max;
	time_t tt;
	srandom(time(&tt));
	n = random();
	return n;
		
}
void init(stack *s) {
	s->p = 0;
}
void push(stack *s, int no) {
	s->a[s->p++] = no;
}
int pop(stack *s) {
	int t;
	t = s->a[s->p - 1];
	s->p--;
	return t;
}
int peek(stack *s) 
{ 
   
    return s->a[s->p]; 
} 
int isempty(stack *s) {
	return s->p == 0;
}
int isfull(stack *s) {
	return s->p == MAX;
}

int incolumn(int x, int y, int num) {

	int i;
	
	for(i = 0; i < 9; i++) {

		if( i != x) {
	
			if(sudoku[i][y] == num) {

				//printf("incolumn 1\n");
		
				return 1;
			}
		
		}
		
	}

	//printf("incolumn 0\n");
	
	return 0;
	
}
int incolumn16(int x, int y, int num) {

	int i;
	
	for(i = 0; i < 16; i++) {

		if( i != x) {
	
			if(sudoku[i][y] == num) {

				//printf("incolumn 1\n");
		
				return 1;
			}
		
		}
		
	}

	//printf("incolumn 0\n");
	
	return 0;
	
}
int incolumn25(int x, int y, int num) {

	int i;
	
	for(i = 0; i < 25; i++) {

		if( i != x) {
	
			if(sudoku[i][y] == num) {

				//printf("incolumn 1\n");
		
				return 1;
			}
		
		}
		
	}

	//printf("incolumn 0\n");
	
	return 0;
	
}
int inrow(int x, int y, int num) {

	int i;
	
	for(i = 0; i < 9; i++) {

		if(i != y) {
	
			if(sudoku[x][i] == num) {
		
	//			printf("inrow 1\n");

					return 1;
			
			}

		}
		
	}
	
	//printf("inrow 0\n");

	return 0;
	
}
int inrow16(int x, int y, int num) {

	int i;
	
	for(i = 0; i < 16; i++) {

		if(i != y) {
	
			if(sudoku[x][i] == num) {
		
	//			printf("inrow 1\n");

					return 1;
			
			}

		}
		
	}
	
	//printf("inrow 0\n");

	return 0;
	
}
int inrow25(int x, int y, int num) {

	int i;
	
	for(i = 0; i < 25; i++) {

		if(i != y) {
	
			if(sudoku[x][i] == num) {
		
	//			printf("inrow 1\n");

					return 1;
			
			}

		}
		
	}
	
	//printf("inrow 0\n");

	return 0;
	
}


int insquare(int x, int y, int num) {

	int f, g;

	
		if(x < 3) {
	
			f = 0;
		
		}
	
		else if(x < 6) {
	
			f = 3;
		
		}
	
		else  {
		
			f = 6;
		
		}
	
		if(y < 3) {
	
			g = 0;
		
		}
	
		else if(y < 6) {
	
			g = 3;
		
		}
	
		else {
	
			g = 6;
		
		}

		

				

	int i, j;
	
	for(i = f; i < f + 3; i++) {
	
		for(j = g; j < g + 3; j++) {

			if(i != x || j != y) {
		
				if(sudoku[i][j] == num) {

	//				printf("insquare 1\n");					

					return 1;
				
				}

			}
			
		}
		
	}
	
	//printf("insquare 0\n");

	return 0;
	
}	
int insquare16(int x, int y, int num) {

	int f, g;

		if(x < 4) {
	
			f = 0;
		
		}
	
		else if(x < 8) {
	
			f = 4;
		
		}
	
		else if(x < 12) {
	
			f = 8;
		
		}

		else {

			f = 12;

		}	
	
		if(y < 4) {
	
			g = 0;
		
		}
	
		else if(y < 8) {
	
			g = 4;
		
		}
	
		else if(y < 12) {
	
			g = 8;
		
		}

		else {

			g = 12;

		}

			
	
	
	int i, j;
	
	for(i = f; i < f + 4; i++) {
	
		for(j = g; j < g + 4; j++) {

			if(i != x || j != y) {
		
				if(sudoku[i][j] == num) {

	//				printf("insquare 1\n");					

					return 1;
				
				}

			}
			
		}
		
	}
	
	//printf("insquare 0\n");

	return 0;
	
}
int insquare25(int x, int y, int num) {

	int f, g;		
	
		if(x < 5) {
	
			f = 0;
		
		}
	
		else if(x < 10) {
		
			f = 5;
		
		}
	
		else if(x < 15) {
	
			f = 10;
		
		}

		else if(x < 20){

			f = 15;

		}

		else{

			f = 20;

		}	
	
		if(y < 5) {
	
			g = 0;
		
		}
	
		else if(y < 10) {
	
			g = 5;
		
		}
	
		else if(y < 15) {
	
			g = 10;
		
		}

		else if(y < 20) {

			g = 15;

		}


		else {

			g = 20;

		}

				

	int i, j;
	
	for(i = f; i < f + 5; i++) {
	
		for(j = g; j < g + 5; j++) {

			if(i != x || j != y) {
		
				if(sudoku[i][j] == num) {

	//				printf("insquare 1\n");					

					return 1;
				
				}

			}
			
		}
		
	}
	
	//printf("insquare 0\n");

	return 0;
	
}			
void printsudoku(int arr[25][25] ) {

	int i, j;
			
	for(i = 0; i < 25; i++) {
	
		for(j = 0; j < 25; j++) {
		
			printf("%3d ", arr[i][j]);
			
		}
	
		printf("\n");
		
	}
	
}
void m(int x, int y){
	
	int i, j, r;
	
	for(i = x; i < 1; i++){
	
		for(j = y; j < 9; j++) {
		
			line:
		
			r = ran() % (9 + 1);
			
			if(r != 0) {
			
				if(!inrow(i, j, r)) {

						sudoku[i][j] = r;
				
				}
				
				else {
				
					goto line;
				
				}		
			}
			
			else {
			
				goto line;
			
			}
		
		}
	
	}
	

}
void m16(int x, int y){
	
	int i, j, r;
	
	for(i = x; i < 1; i++){
	
		for(j = y; j < 16; j++) {
		
			line:
		
			r = ran() % (16 + 1);
			
			if(r != 0) {
			
				if(!inrow16(i, j, r)) {

						sudoku[i][j] = r;
				
				}
				
				else {
				
					goto line;
				
				}		
			}
			
			else {
			
				goto line;
			
			}
		
		}
	
	}
	

}
void m25(int x, int y){
	
	int i, j, r;
	
	for(i = x; i < 1; i++){
	
		for(j = y; j < 25; j++) {
		
			line:
		
			r = ran() % (25 + 1);
			
			if(r != 0) {
			
				if(!inrow25(i, j, r) && !incolumn(i, j, r) && !insquare(i, j, r)) {

						sudoku[i][j] = r;
				
				}
				
				else {
				
					goto line;
				
				}		
			}
			
			else {
			
				goto line;
			
			}
		
		}
	
	}
	

}
