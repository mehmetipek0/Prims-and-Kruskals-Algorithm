// Kruskal's algorithm in C

#include <stdio.h>

#define MAX 30

typedef struct edge {
  int u, v, w;
} edge;

typedef struct edge_list {
  edge data[MAX];
  int n;
} edge_list;

edge_list e_list;

int graph[MAX][MAX], n;
edge_list spanlist;

void kruskalAlgorithm();
int find(int belongs[], int vertexno);
void applyUnion(int belongs[], int c1, int c2);
void sort();
void print();

// Applying Krushkal Algorithm
void kruskalAlgorithm() {
  int belongs[MAX], i, j, cno1, cno2;
  e_list.n = 0;

  for (i = 1; i < n; i++)
    for (j = 0; j < i; j++) {
      if (graph[i][j] != 0) {
        e_list.data[e_list.n].u = i;
        e_list.data[e_list.n].v = j;
        e_list.data[e_list.n].w = graph[i][j];
        e_list.n++;
      }
    }

  sort();

  for (i = 0; i < n; i++)
    belongs[i] = i;

  spanlist.n = 0;

  for (i = 0; i < e_list.n; i++) {
    cno1 = find(belongs, e_list.data[i].u);
    cno2 = find(belongs, e_list.data[i].v);

    if (cno1 != cno2) {
      spanlist.data[spanlist.n] = e_list.data[i];
      spanlist.n = spanlist.n + 1;
      applyUnion(belongs, cno1, cno2);
    }
  }
}

void applyUnion(int belongs[], int c1, int c2) {
  int i;

  for (i = 0; i < n; i++)
    if (belongs[i] == c2)
      belongs[i] = c1;
}

int find(int belongs[], int vertexno) {
  return (belongs[vertexno]);
}

// Printing the result
void print() {
  int i, cost = 0;

  for (i = 0; i < spanlist.n; i++) {
    printf("\n%d - %d : %d", spanlist.data[i].u, spanlist.data[i].v, spanlist.data[i].w);
    cost = cost + spanlist.data[i].w;
  }

  printf("\nSpanning tree cost: %d", cost);
}

// Sorting algorithm
void sort() {
  int i, j;
  edge tmp;

  for (i = 1; i < e_list.n; i++)
    for (j = 0; j < e_list.n - 1; j++)
      if (e_list.data[j].w > e_list.data[j + 1].w) {
        tmp = e_list.data[j];
        e_list.data[j] = e_list.data[j + 1];
        e_list.data[j + 1] = tmp;
      }
}


int main() {
  int i, j, total_cost;

  n = 5;

  graph[0][0] = 0;
  graph[0][1] = 1;
  graph[0][2] = 7;
  graph[0][3] = 0;
  graph[0][4] = 0;
  graph[0][5] = 0;


  graph[1][0] = 1;
  graph[1][1] = 0;
  graph[1][2] = 5;
  graph[1][3] = 4;
  graph[1][4] = 3;
  graph[1][5] = 0;

  graph[2][0] = 7;
  graph[2][1] = 5;
  graph[2][2] = 0;
  graph[2][3] = 0;
  graph[2][4] = 6;
  graph[2][5] = 0;

  graph[3][0] = 0;
  graph[3][1] = 4;
  graph[3][2] = 0;
  graph[3][3] = 0;
  graph[3][4] = 2;
  graph[3][5] = 0;

  graph[4][0] = 0;
  graph[4][1] = 3;
  graph[4][2] = 6;
  graph[4][3] = 2;
  graph[4][4] = 0;
  graph[4][5] = 0;

  kruskalAlgorithm();
  print();
  return 0;
}
