/* 
	Demonstration of Graph 
	BFS
*/

#include<iostream>
#include<vector>
#include<queue>
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

private:
	int _NbVertices;			// Totak no. of vertices/nodes
	vector<int>* _AdjList;		// A List stores the adjacent list of a given node.
};

Graph::Graph(int iVertices) : _NbVertices(iVertices)
{
	_AdjList = new vector<int>[_NbVertices];
}

Graph::~Graph()
{
}

void Graph::AddEdges(int u, int v)
{
	_AdjList[u].push_back(v);	// adding node 'v' to 'u's list
}

void Graph::BFS(int iVertex)
{
	bool* bIsVisited = new bool[_NbVertices];
	for (int idx = 0; idx < _NbVertices; idx++)
		bIsVisited[idx] = false;

	queue<int> qCurrNodes;
	bIsVisited[iVertex] = true;
	qCurrNodes.push(iVertex);
	while (!qCurrNodes.empty())
	{
		int size = qCurrNodes.size();
		while (size)
		{
			iVertex = qCurrNodes.front();
			cout << iVertex << endl;
			qCurrNodes.pop();

			for (auto & iCurrAdjNode: _AdjList[iVertex])
			{
				if (!bIsVisited[iCurrAdjNode])
				{
					qCurrNodes.push(iCurrAdjNode);
					bIsVisited[iCurrAdjNode] = true;
				}
			}
			size--;
		}
	}
}

int main()
{
	Graph g(4);

	// Creating graph with nodes.
	g.AddEdges(0, 1);
	g.AddEdges(0, 2);
	g.AddEdges(1, 2);
	g.AddEdges(2, 0);
	g.AddEdges(2, 3);
	g.AddEdges(3, 3);

	// BFS from given vertex
	g.BFS(2);
	
	return 0;
}