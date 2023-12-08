#include <iostream>
#include <vector>
using namespace std;
class ArticulationPoints
{
private:
    int V;                     // Number of vertices
    vector<vector<int>> graph; // Adjacency list representation of the
     vector<int> disc; // Discovery time of each vertex during
    vector<int> low; // Earliest visited vertex reachable from
     vector<int>parent;                  // Parent of each vertex in the DFS tree
    vector<bool> articulationPoints; // Mark vertices as articulation points
    int time;                        // Variable to keep track of discoverytime 
    int children;               // Number of children of a vertex in the
    public : ArticulationPoints(int vertices) : V(vertices), graph(vertices), disc(vertices, -1), low(vertices, -1), parent(vertices, -1), articulationPoints(vertices, false), time(0), children(0) {}
    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }
    // DFS function for finding articulation points and checking
    void dfs(int u)
    {
        disc[u] = low[u] = time++;
        for (int v : graph[u])
        {
            if (disc[v] == -1)
            {
                children++;
                parent[v] = u;
                dfs(v);
                low[u] = min(low[u], low[v]);
                // Check for articulation points
                if ((low[v] >= disc[u] && parent[u] != -1) || (parent[u] == -1 && children > 1))
                {
                    articulationPoints[u] = true;
                }
            }
            else if (v != parent[u])
            {
                low[u] = min(low[u], disc[v]);
            }
        }
        children = 0;
    }
    // Function to find articulation points and check biconnectivity
    void findArticulationPoints()
    {
        for (int i = 0; i < V; ++i)
        {
            if (disc[i] == -1)
            {
                children = 0;
                dfs(i);
            }
        }
        // Check if the graph contains articulation points
        bool containsArticulationPoints = false;
        for (int i = 0; i < V; ++i)
        {
            if (articulationPoints[i])
            {
                containsArticulationPoints = true;
                break;
            }
        }
        // Print the result
        if (containsArticulationPoints)
        {
            cout << "Graph contains articulation points." << endl;
        }
        else
        {
            cout << "Graph does not contain articulation points." << endl;
        }
    }
};
int main()
{
    ArticulationPoints ap(5);
    ap.addEdge(0, 1);
    ap.addEdge(1, 2);
    ap.addEdge(2, 0);
    ap.addEdge(1, 3);
    ap.addEdge(3, 4);
    ap.findArticulationPoints();
    return 0;

}