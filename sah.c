#include <stdlib.h>
#include <stdio.h>
#define N 8 //dimensiunea tablei de sah 

int sol[N][N]; //matrice pentru tabla de sah

int valid(int x, int y, int sol[N][N]) {     //verificam daca pozitia respectiva se afla pe tabla si daca este nevizitata
    if(x >= 0 && x < N&& y >= 0 && y < N&& sol[x][y] == -1)
        return 1;
    else
        return 0;
}

void print_solution() {
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++){
            if(sol[x][y]>9)
              printf("%d ", sol[x][y]);
            else
             printf("%d  ", sol[x][y]);
        }
        printf("\n");
    }
}

int knight_path(int x, int y, int move, int sol[N][N], int xMove[N], int yMove[N]) {
    int xNext, yNext;
    if (move == N * N)     //la fiecare mutare pe care o facem verificam daca am parcurs toata tabla
        return 1;

    for (int k = 0; k < 8; k++) {
        xNext = x + xMove[k];
        yNext = y + yMove[k];
        if (valid(xNext, yNext, sol) == 1) {     //verificam daca pozitia este ocupata sau nu
                sol[xNext][yNext] = move;// in matrice salvaam numarul mutarii
            if (knight_path(xNext, yNext, move + 1, sol, xMove, yMove) == 1)
                return 1;
            else
                sol[xNext][yNext] = -1;// mutam piesa inapoi si facem backtracking 
        }
    }
    return -1;
}

int knight_path_solution() {
    for (int x = 0; x < N; x++)    
        for (int y = 0; y < N; y++)
            sol[x][y] = -1;      // toata matricea o initializam cu -1 (nevizitata)
  
    //toate miscarile pe care calu le poate lua

    int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };

    sol[0][0] = 0;     //pozitia de start

    if (knight_path(0, 0, 1, sol, xMove, yMove) == -1) {
        printf("Solutia nu exista!");
        return -1;
    }
    else
        print_solution();
    return 1;
}

int main() {
    knight_path_solution();
}