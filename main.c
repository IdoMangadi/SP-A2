#include <stdio.h>
#include <math.h>

int main(){

    int matrix[10][10];

    char user_input;
    scanf("%c", &user_input);

    while(user_input != 'D'){
        if (user_input == 'A'){
            get_values(matrix);
        }

        if (user_input == 'B'){
            int i, j;
            scanf("%d%d",i, j);
            is_path_exists(matrix, i, j);
        }

        if (user_input == 'C'){
            int i, j;
            scanf("%d%d",i, j);
            shortest_path(matrix, i, j);
        }
    }

    return 0;
}