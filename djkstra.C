#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <limits.h> //dont forget to include this
#define V 9

int minDist(int dist[V], bool sptSet[V])
{
    int min_index, i;
    int min = INT_MAX;
    for (i = 0; i < V; i++)
    {
        if (sptSet[i] == false && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void printSol(int dist[V])
{
    printf("Vertex\t\tMin Dist from src\n");
    for (int i = 0; i < V; i++)
    {
        printf("%d\t\t\t\t%d\n", i, dist[i]);
    }
}

void Djkstra(int graph[V][V], int src)
{
    int dist[V];
    bool sptSet[V];
    int i, v;
    for (i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        sptSet[i] = false;
    }
    dist[src] = 0;

    for (i = 0; i < V - 1; i++)
    {
        int u = minDist(dist, sptSet);
        sptSet[u] = true; // sptSet[u] and not sptSpt[i]
        for (v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }
    printSol(dist);
}

int main()
{
    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                       {4, 0, 8, 0, 0, 0, 0, 11, 0},
                       {0, 8, 0, 7, 0, 4, 0, 0, 2},
                       {0, 0, 7, 0, 9, 14, 0, 0, 0},
                       {0, 0, 0, 9, 0, 10, 0, 0, 0},
                       {0, 0, 4, 14, 10, 0, 2, 0, 0},
                       {0, 0, 0, 0, 0, 2, 0, 1, 6},
                       {8, 11, 0, 0, 0, 0, 1, 0, 7},
                       {0, 0, 2, 0, 0, 0, 6, 7, 0}};

    Djkstra(graph, 0);
}
