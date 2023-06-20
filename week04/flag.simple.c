#include <stdio.h>
#define N_ROWS 6
#define N_COLS 12


char flag[N_ROWS][N_COLS] = {
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'},
    {'#', '#', '#', '#', '#', '.', '.', '#', '#', '#', '#', '#'}
};

int main(void) {

f_row_init: ;
    int row = 0;
f_row_cond:
    if (row >= 6) goto f_row_false;


f_col_init: ;
    int col = 0;
f_col_cond:
    if (col >= 12) goto f_col_false;
    printf("%c", flag[row][col]);
f_col_step:
    col++;
    goto f_col_cond;
f_col_false:

    printf("\n");
f_row_step:
    row++;
    goto f_row_cond;
f_row_false:
    return 0;
}
