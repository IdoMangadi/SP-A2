#include <stdio.h>

void selectItems(float weights[], float values[], char *strings[], int numStrings){

    //Building the table:
    //Initiate row 0 and column 0 to be 0:
    float dp[numStrings+1][21];
    for(int i=0; i<21; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<21; i++){
        dp[i][0] = 0;
    }

    //Generating the DP 2D array:
    for(int i=1; i<numStrings+1; i++){
        for(int j=1; j<21; j++){
            //If the weight of the current i is bigger then what we can remove:
            if(j <= weights[i-1]){
                dp[i][j] = dp[i][j-1]; //continue computing without loading it
            }
            else{
                dp[i][j] = (dp[i-1][j] > values[i-1] + dp[i-1][(int)(j-weights[i-1])]) ? dp[i-1][j] : values[i-1] + dp[i-1][(int)(j-weights[i-1])];
                //TODO: add the item name to the returning object.
            }

        }
    }

    //TODO: return (somehow) dp[numStrings][20] as the value of the items added to the final list.
}

int main2(){
    
    //Input from user:
    char items[5]; 
    float values[5];
    float weights[5];


    //Activate function:


    //Printing:




    return 0;
}