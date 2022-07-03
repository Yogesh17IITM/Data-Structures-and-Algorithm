/*
    Demonstration of Graph using BFS

    0 ----> 1
    ^       |
    |       v
    |------>2 --> 3 --> 4

    (Directed graph)

    Print all the connected nodes for the given key
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
public:
    Graph(int iVertices);
    ~Graph();

    // Create Graph with given edges.
    void AddEdges(int u, int v);

    // BFS
    void BFS(int iVertex);

    void ResetFlag();

private:
    int _NbVertices;                 // Totak no. of vertices/nodes
    vector<int> *_AdjList = nullptr; // A List stores the adjacent list of a given node.
    bool *_bIsVisited = nullptr;
};

Graph::Graph(int iVertices) : _NbVertices(iVertices)
{
    _AdjList = new vector<int>[_NbVertices];
    _bIsVisited = new bool[_NbVertices];
    ResetFlag();
}

Graph::~Graph()
{
    if (_AdjList)
        delete[] _AdjList;
    if (_bIsVisited)
        delete[] _bIsVisited;
}

void Graph::ResetFlag()
{
    for (int idx = 0; idx < _NbVertices; idx++)
        _bIsVisited[idx] = false;
}

void Graph::AddEdges(int u, int v)
{
    _AdjList[u].push_back(v); // adding node 'v' to 'u's list (directed graph)
}

void Graph::BFS(int iVertex)
{
    // Update the visited flag
    _bIsVisited[iVertex] = true;

    queue<int> qCurrNodes;
    qCurrNodes.push(iVertex);

    while (!qCurrNodes.empty())
    {
        int size = qCurrNodes.size();
        while (size)
        {
            iVertex = qCurrNodes.front();
            cout << iVertex << endl;
            qCurrNodes.pop();

            for (auto &iCurrAdjNode : _AdjList[iVertex])
            {
                if (!_bIsVisited[iCurrAdjNode])
                {
                    qCurrNodes.push(iCurrAdjNode);
                    _bIsVisited[iCurrAdjNode] = true;
                }
            }
            size--;
        }
    }
}

int main()
{
    Graph g(5);

    // Creating graph with nodes.
    g.AddEdges(0, 1);
    g.AddEdges(0, 2);
    g.AddEdges(1, 2);
    g.AddEdges(2, 3);
    g.AddEdges(3, 4);

    // Print all the connected nodes of given vertex using BFS
    g.BFS(2);

    // Connect the following edge and try again
    cout << "---------------------" << endl;
    g.ResetFlag();
    g.AddEdges(2, 0); // result changes due to directed graph (0->2 is NOT same as 2 -> 0)
    g.BFS(2);

    return 0;
}