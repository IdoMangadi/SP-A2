/**
 * Function that gets the matrix values from the user:
*/
int get_values(int *matrix[][10]);

/**
 * Function that uses DFS to check whether there is a path from vertix 'a' to vertix 'b'.
*/
int is_path_exists (int matrix[][10], int i, int j);

/**
 * Fuction that uses the Floyd-Warshall algorithm to find the shortest path from 'a' to 'b'.
*/
int shortest_path(int matrix[][10], int a, int b);