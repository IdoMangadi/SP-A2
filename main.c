#include <stdio.h>
#include <math.h>
#include "my_mat.h"

int main(){

    int matrix[10][10];
    int i, j, res;

    char user_input;
    scanf(" %c", &user_input);

    while(user_input != 'D'){
        if (user_input == 'A'){
            get_values(matrix);
        }

        if (user_input == 'B'){
            scanf(" %d %d", &i, &j);
            res = is_path_exists(matrix, i, j);
            if(res == 1){
                printf("True");
            }
            else{
                printf("False");
            }
        }

        if (user_input == 'C'){
            scanf(" %d %d",&i, &j);
            res = shortest_path(matrix, i, j);
            printf("%d", res);
        }
        scanf("%c", &user_input);
    }

    return 0;
}