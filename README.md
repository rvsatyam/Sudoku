# Sudoku
To run this program, 
1) sudo apt-get install build-essential gnome-devel
2) gcc size.c -o base `pkg-config --cflags --libs gtk+-3.0`
3) ./base

Program will start running.
Then, you can create sudoku. Also, you can solve given sudoku. You can take hint by using hint button.

For making sudoku, stack data structure is used for backtracking.
