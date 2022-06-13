// Prim's Algorithm in C

#include<stdio.h>
#include<stdbool.h> 

#define INF 9999999
#define V 4

int G[V][V] = {
  {0, 1, 4, 3},
  {1, 0, 0, 2},
  {4, 0, 0, 5},
  {3,2, 5, 0}};

int main() {
  int edge_no;  
  int total_cost = 0;
  int selected[V];

  memset(selected, false, sizeof(selected));
  
  edge_no = 0;
  selected[0] = true;

  int x;  //  row number
  int y;  //  col number
  printf("Edge : Weight\n");

  while (edge_no < V - 1) {

    int min = INF;
    x = 0;
    y = 0;
	int i, j;
	
    for (i = 0; i < V; i++) {
      if (selected[i]) {
        for (j = 0; j < V; j++) {
          if (!selected[j] && G[i][j]) { 
            if (min > G[i][j]) {
              min = G[i][j];
              x = i;
              y = j;
            }
          }
        }
      }
    }
    printf("%d - %d : %d\n", x, y, G[x][y]);
    total_cost += G[x][y];
    selected[y] = true;
    edge_no++;
  }
  printf("Total Cost: %d", total_cost);
  return 0;
}
