
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAX_NODES 1000
#define MAX_EDGES 10000
int dist[MAX_NODES];
int edge[MAX_EDGES][3];

void bellmanford(int nodes, int edges, int start_node)
{

    for (int i = 0; i < nodes; i++)
    {
        if (i == start_node)
        {
            dist[i] = 0;
        }
        else
            dist[i] = INT_MAX;
    }
    for (int i = 1; i < nodes; i++)
    {
        for (int j = 0; j < edges; j++)
        {
            int source = edge[j][0];
            int destination = edge[j][1];
            int weight = edge[j][2];
            if (dist[source] != INT_MAX && weight + dist[source <= dist[destination]])
            {
                dist[destination] = dist[source] + weight;
            }
        }
    }
    for (int i = 0; i < edges; i++)
    {
        int source = edge[i][0];
        int destination = edge[i][1];
        int weight = edge[i][2];
            if(dist[source]!=INT_MAX && weight + dist[source<=dist[destination])
            {
                printf("Graph contains negative cycle");
                return;
            }
    }
    for (int i = 0; i < nodes; i++)
    {
            printf("Shortest distance from node %d to %d is %d\n", start_node, i, dist[i]);
    }
}

int main()
{
    int nodes, edges, start_node;
    printf("Enter number of nodes, edges and starting node");
    scanf("%d%d%d", &nodes, &edges, &start_node);
    printf("Enter details in the format <start><destination><weight>");
    for (int i = 0; i < edges; i++)
    {
            scanf("%d%d%d", &edge[i][0], &edge[i][1], &edge[i][2]);
    }
    bellmanford(nodes, edges, start_node);
    return 0;
}
