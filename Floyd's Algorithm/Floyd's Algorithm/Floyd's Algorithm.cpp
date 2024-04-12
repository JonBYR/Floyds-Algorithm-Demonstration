// Floyd's Algorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
const int V = 4; //number of nodes within a graph
const int INF = 999999; //infinity must be a very large number
void print(int dist[][V])
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF) cout << "INF" << " ";
            else cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}
void Floyd(int dist[][V]) 
{
    int i, j, k;
    for (k = 0; k < V; k++) 
    {
        for (i = 0; i < V; i++) 
        {
            for (int j = 0; j < V; j++) 
            {
                int currentDist = dist[i][j]; //current distance from i to j
                int sourceDist = dist[i][k]; //distance from start position to node k
                int destDist = dist[k][j]; //distance from node k to destination
                if (sourceDist == INF) continue;
                if (destDist == INF) continue; //if infinity there is no route to get from i to j from k (or k is itself) and therefore continue to next iteration
                int comp = sourceDist + destDist; //combined distance from source to destination via k
                if (comp < currentDist) dist[i][j] = comp; //if going to i to j is shorter using node k, then update dist[i][j]
            }
        }
    }
    print(dist);
}

int main()
{
    int graph[V][V] = { {0, 5, INF, 10 },{6, 0, 3, INF},{7, INF, 0, 1},{INF, 2, 4, 0} };
    Floyd(graph);
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
