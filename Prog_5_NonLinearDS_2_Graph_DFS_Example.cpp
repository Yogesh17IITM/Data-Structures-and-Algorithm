/* Graph - DFS (recursive) */

#include<iostream>
#include<vector>
using namespace std;

class Graph
{
public:
	Graph(int iNbVertices);
	~Graph();

	void AddEdges(int u, int v);

	void DFS(int idx=0);
private:
	vector<int> * _AdjMatrix;
	int _NbVertices;
	bool* _bIsVisited;
};

Graph::Graph(int iNbVertices): _NbVertices(iNbVertices)
{
	_AdjMatrix = new vector<int>[_NbVertices];
	_bIsVisited = new bool[_NbVertices];
	for (int idx = 0; idx < _NbVertices; idx++)	
		_bIsVisited[idx] = false;	
}

Graph::~Graph()
{
}

// Connect adjacent nodes through edges.
void Graph::AddEdges(int u, int v)
{
	_AdjMatrix[u].push_back(v);
	_AdjMatrix[v].push_back(u);
}

// DFS recursive
void Graph::DFS(int idx)
{
	_bIsVisited[idx] = true;
	cout << idx << endl;
	for (auto & iAdjNodeIdx: _AdjMatrix[idx])
	{
		if(!_bIsVisited[iAdjNodeIdx])
			DFS(iAdjNodeIdx);
	}
}

int main()
{
	Graph g(5);
	g.AddEdges(0, 1);
	g.AddEdges(0, 4);
	g.AddEdges(1, 2);
	g.AddEdges(2, 0);
	g.AddEdges(2, 3);
	g.AddEdges(4, 3);

	// DFS starting from index 0
	g.DFS();

	return 0;
}