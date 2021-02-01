#define MAX 625
typedef struct stack{
	int a[MAX];
	int p;
}stack;

int ran();
void init(stack *s);
void push(stack *s, int no);
int pop(stack *s) ;
int peek(stack *s);
int isempty(stack *s);
int isfull(stack *s);
int incolumn(int x, int y, int num);
int inrow(int x, int y, int num);
int insquare(int x, int y, int num);
int incolumn16(int x, int y, int num);
int inrow16(int x, int y, int num);
int insquare16(int x, int y, int num);
int incolumn25(int x, int y, int num);
int inrow25(int x, int y, int num);
int insquare25(int x, int y, int num);
void printsudoku(int arr[25][25] );
void m(int x, int y);
int sudoku[25][25], answer[25][25], n;
