#ifndef _GRAPHMETHOD_H_
#define _GRAPHMETHOD_H_

#include "ListGraph.h"
#include "MatrixGraph.h"

bool BFS(Graph* graph, int vertex);
bool DFS(Graph* graph, int vertex);
bool DFS_R(Graph* graph, bool* isVisit, int vertex, bool isStart);
bool Kruskal(Graph* graph);
bool Dijkstra(Graph* graph, int vertex);
bool Bellmanford(Graph* graph, int s_vertex, int e_vertex);
bool FLOYD(Graph* graph);

#endif
