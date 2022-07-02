/*
    Finding longest path in a undirected tree using BFS

        0
       /
      1
     / \
 9--2	6 -- 8
   / \   \
  4   3   7
   \
    5

Output:
    5 4 2 1 6 7
    (Longest path is from 5 to 7 and distance 5)

Approach:
    Call BFS twice --> to get the longest distance node
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// Since some of the vertices contains more than 2 branches,
// we can handle through 'Adjacent Node method'
class Tree // Not Graph, because there is no loop. eg. if we connect 5 and 3, it will become loop -> Graph
{
public:
    Tree(int iNbVertices);
    ~Tree();

    void AddEdges(int u, int v);
    pair<int, int> BFS(int u);

    pair<int, int> FindLongestPath(int &ioSource); // return <Node, Dist>

private:
    int _NbVertices;

    vector<int> *_pAdj = nullptr;
    bool *_bIsVisited = nullptr;
    int *_pDist = nullptr;

    void Init();
};

Tree::Tree(int iNbVertices) : _NbVertices(iNbVertices)
{
    _pAdj = new vector<int>[_NbVertices];
    _bIsVisited = new bool[_NbVertices];
    _pDist = new int[_NbVertices];
}

Tree::~Tree()
{
    if (_pAdj)
        delete[] _pAdj;
    if (_bIsVisited)
        delete[] _bIsVisited;
    if (_pDist)
        delete[] _pDist;
}

void Tree::Init()
{
    if (_pDist && _bIsVisited)
    {
        for (int idx = 0; idx < _NbVertices; idx++)
        {
            _pDist[idx] = -1; // dummy value
            _bIsVisited[idx] = false;
        }
    }
}

void Tree::AddEdges(int u, int v)
{
    // Undirected Tree (means connection b/w U --> V is same as V-->U)
    _pAdj[u].push_back(v);
    _pAdj[v].push_back(u);
}

pair<int, int> Tree::BFS(int iStartNode)
{
    Init();

    // Update distance and visitedflag of startNode
    if (_pDist && _bIsVisited)
    {
        _pDist[iStartNode] = 0;
        _bIsVisited[iStartNode] = true;
    }

    queue<int> q;
    q.push(iStartNode);

    while (!q.empty()) // loop for each level in the tree
    {
        int temp = q.front();
        q.pop();

        for (auto &iAdj : _pAdj[temp]) // loop for each vertex at each level
        {
            if (!_bIsVisited[iAdj] && (_pDist))
            {
                _bIsVisited[iAdj] = true;
                q.push(iAdj);
                _pDist[iAdj] = _pDist[temp] + 1; // update the dist of each adj nodes
            }
        }
    }

    int MaxDistance = 0;
    int NodeIdx = -1;
    for (int idx = 0; idx < _NbVertices; idx++)
    {
        if (_pDist[idx] > MaxDistance)
        {
            MaxDistance = _pDist[idx];
            NodeIdx = idx;
        }
    }

    return make_pair(NodeIdx, MaxDistance);
}

pair<int, int> Tree::FindLongestPath(int &ioSource)
{
    pair<int, int> t1, t2; // <Node, dist>

    // 1) BFS 1st call
    t1 = BFS(ioSource);
    ioSource = t1.first; // update Source/Start Node

    // 2) BFS 2nd call
    t2 = BFS(ioSource);
    return t2;
}

int main()
{
    Tree obj(10);

    // 1. Create Graph with Nodes
    obj.AddEdges(0, 1);
    obj.AddEdges(1, 2);
    obj.AddEdges(2, 3);
    obj.AddEdges(2, 9);
    obj.AddEdges(2, 4);
    obj.AddEdges(4, 5);
    obj.AddEdges(1, 6);
    obj.AddEdges(6, 7);
    obj.AddEdges(6, 8);

    // 2. Find the longest path using BFS twice
    int SourceNode = 0;
    pair<int, int> LongestDestNode = obj.FindLongestPath(SourceNode);

    cout << "Longest Path: " << SourceNode << " --> " << LongestDestNode.first << endl;
    cout << "Length: " << LongestDestNode.second << endl;

    return 0;
}