#include <stdio.h>

#define STRING_LEN 21
#define ITEMS_AMOUNT 6
#define CAPACITY 15

int knapSack(int weights[ITEMS_AMOUNT], int values[ITEMS_AMOUNT], int selected_bool[ITEMS_AMOUNT]){

    //Building the table:
    //Initiate row 0 and column 0 to be 0:
    int dp[ITEMS_AMOUNT+1][CAPACITY+1];
    for(int i=0; i<CAPACITY+1; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<ITEMS_AMOUNT+1; i++){
        dp[i][0] = 0;
    }

    //Generating the DP 2D array:
    for(int i=1; i<ITEMS_AMOUNT+1; i++){
        for(int j=1; j<CAPACITY+1; j++){
            //If the weight of the current i is bigger then what we can remove:
            if(j <= weights[i-1]){
                dp[i][j] = dp[i][j-1]; //continue computing without loading it
            }
            else{
                // dp[i][j] = (dp[i-1][j] >= values[i-1] + dp[i-1][j-weights[i-1]]) ? dp[i-1][j] : values[i-1] + dp[i-1][(int)(j-weights[i-1])];
                if(dp[i-1][j] > values[i-1] + dp[i-1][(int)(j-weights[i-1])]){
                    dp[i][j] = dp[i-1][j];
                }
                else{ //Means we added the (i-1) item
                    dp[i][j] = values[i-1] + dp[i-1][j-weights[i-1]];
                    selected_bool[i-1] = 1;
                }


            }

        }
    }

    return dp[ITEMS_AMOUNT][CAPACITY];
}

int main(){
    
    //Input from user:
    //Items names:
    char items[ITEMS_AMOUNT][STRING_LEN];
    for(int i=0; i<ITEMS_AMOUNT; i++){
        scanf(" %s", items[i]);
    }
    //Items values:
    int values[ITEMS_AMOUNT];
    for(int i=0; i<ITEMS_AMOUNT; i++){
        scanf(" %d", &values[i]);
    }
    //Items weights:
    int weights[ITEMS_AMOUNT];
    for(int i=0; i<ITEMS_AMOUNT; i++){
        scanf(" %d", &weights[i]);
    }

    //Activate function:
    int selected_bool[ITEMS_AMOUNT] = {0};
    int max_values_sum = knapSack(weights, values, selected_bool);

    //Printing:
    printf("Maximum profit: %d\n", max_values_sum);


    //To handle the ',' we will count how many items there are in the bag:
    int counter = 0;
    for(int i=0; i<ITEMS_AMOUNT; i++){
        if(selected_bool[i] == 1){
            counter++;
        }
    }
    printf("Items that give the maximum profit: [");
    for(int i=0; i<ITEMS_AMOUNT; i++){
        if(selected_bool[i] == 1){
            printf("%s", items[i]);
            counter--;
            if(counter > 0){ //Means ther are more items to print
                printf(",");
            }
        }
    }
    printf("]\n");

    return 0;
}