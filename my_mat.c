#include <stdio.h>
#include <math.h>
#include <limits.h>


//Activated when user input is: A
int get_values (int matrix[10][10]){
    //printf("Enter the matrix values: ");

    int val;
    for (int i=0; i<10; i++){
        for (int j=0; j<10; j++){
            if(scanf(" %d", &val) == 1){
                matrix[i][j] = val;
            }
        }
    }
    return 0;
}


//Activated when user input is: B
int is_path_exists (int matrix[10][10], int a, int b, int visited[]){
    
    //validation check:
    if(a<0 || a>=10 || b<0 || b>=10){
        return 0;
    }
    //Check for direct edge:
    if(matrix[a][b] > 0){
        return 1;
    }

    //DFS algorithm:
    visited[a] = 1;

    for(int i=0; i<10; i++){
        if(matrix[a][i] > 0 && visited[i] == 0 && is_path_exists(matrix, i, b, visited) == 1){
            return 1;
        }
    }

    return 0;
}


//Activated when user input is: C
int shortest_path(int matrix[10][10], int a, int b){
    //If a is b:
    if(a==b){
        return -1;
    }

    //Copy the original matrix to temporary one:
    int tmp[10][10];
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            tmp[i][j] = matrix[i][j];
            //If there is no direct edge between the two vertixs:
            if(tmp[i][j] == 0 && i != j){
                tmp[i][j] = -1;
            }
        }
    }

    //Generating the Floyd-Warshall algorithm's table
    for(int k=0; k<10; k++){
        for(int i=0; i<10; i++){
            for(int j=0; j<10; j++){
                if(tmp[i][j] == -1){
                    tmp[i][j] = tmp[i][k]+tmp[k][j];
                    continue;
                }
                if(tmp[i][k]+tmp[k][j] == -1){
                    tmp[i][j] = tmp[i][j];
                    continue;
                }
                tmp[i][j] = (tmp[i][j] < tmp[i][k]+tmp[k][j]) ? tmp[i][j] : tmp[i][k]+tmp[k][j];
            }
        }
    }
    if(tmp[a][b] != INT_MAX){
       return tmp[a][b];
    }
    return -1;
    
}


