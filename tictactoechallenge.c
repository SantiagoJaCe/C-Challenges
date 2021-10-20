/* Challenge: Write a program that plays tic-tac-toe with
a friend */
#include "stdio.h"
#include "stdlib.h"

//Functions
char boardprint (char board[9]); //Printing the board
int turn (char board[9]); //Turns for each player
int checkWin (char board[9]); //Checks for win or draw


//Main
void main(void) {
    char board[9]={49,50,51,52,53,54,55,56,57};

    int win=0;
    int coord=0;
    int turn1=0;
    int turn2=0;

    system("clear");

    while (win==0){
        boardprint(board);

        printf("\n\nPlayer 1's turn");
        coord=turn(board);
        board[coord]='X';
        win=checkWin(board);
        turn1+=1;
        if (win==1)
            break;

        
        if (turn1==5){
            printf("\n######It's a draw!######");
            break;
        }
        
        system("clear");

        boardprint(board);
        printf("\n\nPlayer 2's turn");
        coord=turn(board);
        board[coord]='O';
        win=checkWin(board);
        turn2+=1;

        system("clear");

    }


    if (win==1&&turn1>turn2)
        printf("######Player 1 wins!######");

    else if (win==1)
        printf("######Player 2 wins!######");
    

}

//Board Display
char boardprint(char board[9]){
    printf("\n          TicTacToe Game          \nPlayer 1: X            Player 2: O\n");
    printf("\n");
    for (int i=0;i<9;i++){

        if (i==3||i==6)
            printf("\n           ------------\n           |");

        else if (i==0)
            printf("           |");  

        printf(" %c |",board[i]);
    }
}

//Player turns
int turn (char board[9]){

    turn:
    int coordinate=0;

    printf("\nChoose a coordinate: ");
    scanf("%d",&coordinate);

    coordinate-=1;

    if (coordinate<0 || coordinate>8){
        printf("\nInvalid coordinate, try again: ");
        goto turn;
    }
    else if (board[coordinate]=='X' || board[coordinate]=='O'){
        printf("\nInvalid coordinate, try again: ");
        goto turn;
    }

    return coordinate;

}

//Check for win or draw
int checkWin (char board[9]){
    if (board[0]==board[1]&&board[1]==board[2]){
        return 1;
    }

    else if (board[3]==board[4]&&board[4]==board[5]){
        return 1;
    }

    else if (board[6]==board[7]&&board[7]==board[8]){
        return 1;
    }

    else if (board[0]==board[3]&&board[3]==board[6]){
        return 1;
    }

    else if (board[1]==board[4]&&board[4]==board[7]){
        return 1;
    }

    else if (board[2]==board[5]&&board[5]==board[8]){
        return 1;
    }

    else if (board[0]==board[4]&&board[4]==board[8]){
        return 1;
    }

    else if (board[2]==board[4]&&board[4]==board[6]){
        return 1;
    }

    else
        return 0;

}