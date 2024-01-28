/*
Demonstration of Non-linear data structure (Graph)

Sum of the minimum elements in all connected components of an undirected graph

        [4]			[2]    [3]
       /  \
     [1]   [5]

Index:	1	2	3	4	5
Value:	4	5	3	2	8

Input:
    No. of Connected Pairs = 2
    1) [1] - [4]
    2) [4] - [5]

Output:
    Sum of Min elem of connect pairs:
    1) Min(Val[1], Val[4], Val[5]) = Min(4, 2, 8) = 2	(since 3 nodes interconnected)
    2) Val[2] = 5 (only node --> Which will be considered as Min)
    3) Val[3] = 3 (same as above)

    Sum = 2 + 5 + 3 = 10
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
    int _NbNodes;
    vector<int> *_pAdj = nullptr;
    bool *_bIsVisited = nullptr;

    void DFS(int &ioMinElem, int iArr[], int iCurrIdx);

    void BFS(int &ioMinElem, int iArr[], int iCurrIdx);

public:
    Graph(int iNbNodes);
    ~Graph();

    void ConnectNodes(int u, int v);
    int SumOfMinElem(int iArr[], int nArr);
};

Graph::Graph(int iNbNodes) : _NbNodes(iNbNodes)
{
    _pAdj = new vector<int>[_NbNodes];
    _bIsVisited = new bool[_NbNodes];
    for (int idx = 0; idx < _NbNodes; idx++)
        _bIsVisited[idx] = false;
}

Graph::~Graph()
{
    if (_pAdj)
        delete[] _pAdj;

    if (_bIsVisited)
        delete[] _bIsVisited;
}

void Graph::ConnectNodes(int u, int v)
{
    _pAdj[u - 1].push_back(v - 1); // since given idx: starts from 1, not 0
    _pAdj[v - 1].push_back(u - 1);
}

void Graph::DFS(int &ioMinElem, int iArr[], int iCurrIdx)
{
    // Comare and consider only the minimum value (NOT INDEX)
    ioMinElem = min(ioMinElem, iArr[iCurrIdx]);

    for (auto &iAdj : _pAdj[iCurrIdx])
    {
        // Check if the adjacent idx is not visited yet
        if (!_bIsVisited[iAdj])
        {
            // Update the visited flag for adjacent node
            _bIsVisited[iAdj] = true;

            // Call recursively for each adjacent node
            DFS(ioMinElem, iArr, iAdj);
        }
    }
}

void Graph::BFS(int &ioMinElem, int iArr[], int iCurrIdx)
{
    // BFS
    queue<int> q;
    q.push(iCurrIdx);
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        for (auto &adj : _pAdj[temp])
        {
            if (!_bIsVisited[adj])
            {
                _bIsVisited[adj] = true;
                ioMinElem = min(ioMinElem, iArr[adj]);
                q.push(adj);
            }
        }
    }
}

int Graph::SumOfMinElem(int iArr[], int nArr)
{
    int oSum = 0;
    for (int idx = 0; idx < nArr; idx++)
    {
        // Ensure if the current index is not visited yet
        if (!_bIsVisited[idx])
        {
            // Update the visited flag for current node
            _bIsVisited[idx] = true;

            int minElem = iArr[idx];
            DFS(minElem, iArr, idx); // for traversing to the connecting nodes

            // Alternatively, use BFS algo
            // BFS(minElem, iArr, idx);

            // Add-up the result
            oSum += minElem;
        }
    }
    return oSum;
}

int main()
{
    int arr[] = {4, 5, 3, 2, 8};
    int nArr = sizeof(arr) / sizeof(arr[0]);

    Graph g(nArr);
    g.ConnectNodes(1, 4);
    g.ConnectNodes(4, 5);

    cout << "Sum of Min. elem: " << g.SumOfMinElem(arr, nArr) << endl;

    return 0;
}