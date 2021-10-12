/* Challenge: Create a program that uses a 2D array, this program
will find the total rainfall for each year, the average yearly rainfall and 
the average rainfall each month. Initial rainfall amounts are hard-coded */

#include "stdio.h"

int main(){
    
    
    float matrix[5][12]= {
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,4.3,2.1,0.8,0.2,0.2,1.1,2.3,6.1,8.4},
        {7.2,9.9,8.4,3.3,1.2,0.8,0.4,0.0,0.6,1.7,4.3,6.2},
        {7.6,5.6,3.8,2.8,3.8,0.2,0.0,0.0,0.0,1.3,2.6,5.2}
    };

printf("##################################################\n");
//Getting the total rainfall in a year

    float totalR[5]={0};
    float sum=0;

    for (int i=0;i<5;++i){
        for (int x=0;x<12;++x){
            sum += matrix[i][x];
        }
        printf("Year: %d    Total rainfall: %.2f\n",i+2011,sum);
        totalR[i]=sum;
        sum=0;
    }

printf("##################################################\n");
//Getting the yearly average

    for (int i=0;i<5;++i){
        sum+=totalR[i];
    }
    sum=sum/5;
    printf("The yearly average is %.2f\n",sum);
    sum=0;

printf("##################################################\n");
//Getting the monthly average

    float averageM[12]={0};

    for (int i=0;i<12;++i){
        for(int x=0;x<5;++x){
            sum+=(matrix[x][i])/5;
        }
        printf("Month: %d     Average Rainfall: %.2f\n",i+1,sum);
        averageM[i]=sum;
        sum=0;

    }

    return 0;
}