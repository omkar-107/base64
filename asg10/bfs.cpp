#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class BipartiteGraph
{
private:
    int V;                     // Number of vertices
    vector<vector<int>> graph; // Adjacency list representation of the graph
    vector<int> colors;        // Colors assigned to vertices
public:
    BipartiteGraph(int vertices) : V(vertices), graph(vertices),
                                   colors(vertices, -1) {}
    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        graph[u].push_back(v);
        graph[v].push_back(u); // Assuming an undirected graph
    }
    // Function to check if the graph is bipartite using BFS
    bool isBipartite()
    {
        for (int i = 0; i < V; ++i)
        {
            if (colors[i] == -1)
            {
                if (!bfs(i))
                {
                    return false; // The graph is not bipartite
                }
            }
        }
        return true; // The graph is bipartite
    }
    // BFS function for checking bipartiteness
    bool bfs(int start)
    {
        queue<int> q;
        q.push(start);
        colors[start] = 0; // Assign the first color
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int v : graph[u])
            {
                if (colors[v] == -1)
                {
                    colors[v] = 1 - colors[u]; // Assign the opposite color
                    q.push(v);
                }
                else if (colors[v] == colors[u])
                {
                    return false; // The graph is not bipartite
                }
            }
        }
        return true; // The connected component is bipartite
    }
};
int main()
{
    BipartiteGraph bg(6); // Example with 6 vertices
    bg.addEdge(0, 1);
    bg.addEdge(0, 2);
    bg.addEdge(1, 3);
    bg.addEdge(2, 4);
    bg.addEdge(3, 5);
    bg.addEdge(4, 5);
    if (bg.isBipartite())
    {
        cout << "The graph is bipartite." << endl;
    }
    else
    {
        cout << "The graph is not bipartite." << endl;
    }
    return 0;
}