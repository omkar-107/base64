#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class HamiltonianCycle
{
private:
    int V;                     // Number of vertices
    vector<vector<int>> graph; // Adjacency matrix representation of the graph
    vector<int> path;          // Hamiltonian Cycle path
public:
    HamiltonianCycle(int vertices) : V(vertices), graph(vertices,
                                                        vector<int>(vertices, 0)) {}
    // Function to add an edge to the graph
    void addEdge(int u, int v)
    {
        graph[u][v] = 1;
        graph[v][u] = 1; // Assuming an undirected graph
    }
    // Function to print the Hamiltonian Cycle path
    void printHamiltonianCycle()
    {
        cout << "Hamiltonian Cycle: ";
        for (int vertex : path)
        {
            cout << vertex << " ";
        }
        cout << path[0] << endl; // To complete the cycle
    }
    // Recursive function to find Hamiltonian Cycle
    bool findHamiltonianCycle(int pos)
    {
        // Base case: If all vertices are included in the path
        if (pos == V)
        {
            // Check if there is an edge from the last added vertex to the
               return (graph[path[pos - 1]][path[0]] == 1);
        }
        // Try different vertices as the next candidate in Hamiltonian Cycle
        for (int v = 1; v < V; v++)
        {
            if (graph[path[pos - 1]][v] == 1 && find(path.begin(), path.end(),
                                                     v) == path.end())
            {
                path[pos] = v;
                if (findHamiltonianCycle(pos + 1))
                    return true;
                // Backtrack
                path[pos] = -1;
            }
        }
        return false;
    }
    // Function to find Hamiltonian Cycle
    void findAndPrintHamiltonianCycle()
    {
        path.resize(V, -1);
        // Start from the first vertex (0)
        path[0] = 0;
        if (findHamiltonianCycle(1))
        {
            printHamiltonianCycle();
        }
        else
        {
            cout << "No Hamiltonian Cycle exists." << endl;
        }
    }
};
int main()
{
    HamiltonianCycle hc(5);
    hc.addEdge(0, 1);
    hc.addEdge(0, 3);
    hc.addEdge(1, 2);
    hc.addEdge(1, 3);
    hc.addEdge(1, 4);
    hc.addEdge(2, 4);
    hc.addEdge(3, 4);
    hc.findAndPrintHamiltonianCycle();
    return 0;
}