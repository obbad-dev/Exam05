#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unistd.h>

int countNegh(char **board, int row, int col, int rows, int coloms)
{
    int conter = 0;
    for (int r = row - 1; r <= row + 1; r++)
    {
        for (int c = col - 1; c <= col + 1; c++)
        {
            if (row == r && col == c) continue;
            if (c >= 0 && c < coloms && r >=0 && r < rows)
            {
                if (board[r][c] == 'O')
                    conter++;
            }
        }
    }
    return conter;
}

void applyGame(char ** board, int coloms, int rows)
{
   char **copy = calloc(rows, sizeof(char *));
   for (int i = 0; i < rows; i++)
   {
        copy[i] = calloc(coloms, sizeof(char));
        for (int j = 0; j < coloms; j++)
            copy[i][j] = board[i][j];
   }
   for (int row = 0 ; row < rows; ++row)
   {
        for (int col = 0; col < coloms; ++col)
        {
            int count = countNegh(board, row, col, rows, coloms);
            if (board[row][col] == 'O')
            {  
                if (count < 2 || count > 3)
                    copy[row][col] = ' ';
            }else {
                if (count == 3)
                    copy[row][col] = 'O';
            }
        }
   }
   for (int i = 0; i < rows; i++)
   {
        free(board[i]);
        board[i] = copy[i];
   }
   free (copy);
}
int main (int ac, char **av)
{
    if (ac != 4)
        return 1;
    int coloms = atoi(av[1]);
    int rows = atoi(av[2]);
    int iteration = atoi(av[3]);

    char **board = calloc(rows , sizeof(char *));
    for (int i = 0; i < rows; i++)
    {
        board[i] = calloc(coloms, sizeof(char));
        for (int j = 0; j < coloms; j++)
        {
            board[i][j] = ' ';
        }
    }

    int pen_r = 0, pen_c = 0;
    bool pen_down = false;
    char command;
    while (read(0, &command, 1) == 1)
    {
        switch (command){
            case 'w':
                pen_r--;
                break;
            case 'a':
                pen_c--;
                break;
            case 's':
                pen_r++;
                break;
            case 'd':
                pen_c ++; 
                break;
            case 'x':
                pen_down = !pen_down;
                break;
        }
        if (pen_down && pen_c >= 0 && pen_c < coloms && pen_r >= 0 && pen_r < rows)
            board[pen_r][pen_c] = 'O';
    }

    for (int i = 0; i < iteration; i++)
    {
        applyGame(board, coloms, rows);
    }
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0 ; j < coloms; ++j)
            putchar(board[i][j]);
        putchar('\n');
        free(board[i]);
    }
    free(board);
    return 0;
}