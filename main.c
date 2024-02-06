#include <stdio.h>
#include <math.h>
#include "my_mat.h"

int main(){

    int matrix[10][10];
    int i, j, res;
    char user_input;

    while(scanf(" %c", &user_input) != EOF && user_input != 'D' && user_input != '\n'){

        if (user_input == 'A'){
            get_values(matrix);
        }

        if (user_input == 'B'){
            scanf(" %d %d",&i, &j);
            if(i != j){
                int visited[10] = {0};
                res = is_path_exists(matrix, i, j, visited);
                if(res == 1){
                    printf("True\n");
                }
                else{
                    printf("False\n");
                }
            }
            else{
                printf("False\n");
            }
        }

        if (user_input == 'C'){
            scanf(" %d %d",&i, &j);
            res = shortest_path(matrix, i, j);
            printf("%d\n", res);
        }
        scanf(" %c", &user_input);
    }

    return 0;
}