/* Challenge: The program generates a random number
from 0 to 20, then the user will have to input a guess,
the user can only guess from 0-20, the program will
indicate to the user if each guess is too high or too low and
lastly, the player only has 5 attempts. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //Creating the random number
    time_t t;
    srand((unsigned)time(&t));
    int number=rand()%21;

    
    //Guessing
    int guess=0;
    for(int attempt=1;attempt<=5;++attempt){
        printf("Enter your guess (Only numbers between 0-20): \n");
        scanf("%d",&guess);

        if (guess>20 || guess<0){
            printf("ERROR: You lost an attempt because you typed a number outside the range :(, try again.\n");
        }

        else if (guess==number){
            printf("Congratulations! You guessed it\n");
            break;
        }

        else if (guess<number){
            printf("Wrong! My number is larger, this was your attempt number %d\n", attempt);
        }

        else{
            printf("Wrong! My number is smaller, this was your attempt number %d\n", attempt);
        }


    }

    printf("##########The END##########");
    scanf("%d",&guess);
}