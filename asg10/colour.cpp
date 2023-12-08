#include <iostream>
#include <vector>
using namespace std;
class GraphColoring
{
private:
    int V;                     // Number of vertices
    vector<vector<int>> graph; // Adjacency matrix representation of the graph
    vector<int> colors;        // Colors assigned to vertices
public:
    GraphColoring(int vertices) : V(vertices), graph(vertices,
                                                     vector<int>(vertices, 0)),
                                  colors(vertices, -1) {}
    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming an undirected graph
    }
    // Function to print the colors assigned to each vertex
    void printColors()
    {
        cout << "Vertex Colors:" << endl;
        for (int i = 0; i < V; ++i)
        {
            cout << "Vertex " << i << ": Color " << colors[i] << endl;
        }
    }
    // Function to check if it's safe to color a vertex with a given color
    bool isSafe(int v, int c)
    {
        for (int i = 0; i < V; ++i)
        {
            if (graph[v][i] && c == colors[i])
            {
                return false; // The color is already used by an adjacent
                
            }
        }
        return true;
    }
    // Recursive function to assign colors to vertices
    bool graphColoringUtil(int v)
    {
        // Base case: All vertices are colored
        if (v == V)
        {
            return true;
        }
        // Try different colors for the current vertex
        for (int c = 0; c < V; ++c)
        {
            if (isSafe(v, c))
            {
                colors[v] = c;
                // Recur to assign colors to the rest of the vertices
                if (graphColoringUtil(v + 1))
                {
                    return true;
                }
                // If assigning color c doesn't lead to a solution, backtrack
                colors[v] = -1;
            }
        }
        return false;
    }
    // Function to assign colors to vertices and print the result
    void colorGraph()
    {
        if (graphColoringUtil(0))
        {
            cout << "Graph can be colored with " << V << " colors." << endl;
            printColors();
        }
        else
        {
            cout << "Graph cannot be colored with " << V << " colors." << endl;
        }
    }
};
int main()
{
    GraphColoring gc(4); // Example with 4 vertices
    gc.addEdge(0, 1);
    gc.addEdge(0, 2);
    gc.addEdge(1, 2);
    gc.addEdge(1, 3);
    gc.colorGraph();
    return 0;
}