#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int V = 6;  // Number of vertices in the graph

int minDistance(const vector<int>& dist, const vector<bool>& sptSet) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }

    return min_index;
}

void printSolution(const vector<int>& dist) {
    cout << "Vertex \t Distance from Source\n";
    for (int i = 0; i < V; i++) {
        cout << i << " \t " << dist[i] << endl;
    }
}

void dijkstra(const vector<vector<int>>& graph, int src) {
    vector<int> dist(V, INT_MAX);
    vector<bool> sptSet(V, false);

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);

        sptSet[u] = true;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    vector<vector<int>> graph = {
        {0, 2, 0, 1, 0, 0},
        {0, 0, 0, 3, 10, 0},
        {4, 0, 0, 0, 0, 5},
        {0, 0, 2, 0, 2, 8},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0}
    };

    dijkstra(graph, 0);

    return 0;
}
