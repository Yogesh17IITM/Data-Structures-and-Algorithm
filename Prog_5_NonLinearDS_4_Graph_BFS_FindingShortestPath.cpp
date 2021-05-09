/* Finding shortest path in an unweighted graph 
   using BFS */

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
public:
	Graph(int iVertices);
	~Graph();

	void AddEdge(int u, int v);
	int FindShortestPath(int iSource, int iDestination);
	bool ModifiedBFS(int iSource, int iDestination);

private:
	vector<int>* _Adj;
	int _NbVertices;
	
	int* _Predecessor;
	int* _distance;
};

Graph::Graph(int iVertices) : _NbVertices(iVertices)
{
	_Adj = new vector<int>[_NbVertices];
	_Predecessor = new int[_NbVertices];
	_distance = new int[_NbVertices];
}

Graph::~Graph()
{
}

void Graph::AddEdge(int u, int v)
{
	_Adj[u].push_back(v);
	_Adj[v].push_back(u);
}

bool Graph::ModifiedBFS(int iSource, int iDestination)
{
	queue<int> q;
	bool* bIsVisited = new bool[_NbVertices];

	// Initialize all variables
	for (int idx = 0; idx < _NbVertices; idx++)
	{
		bIsVisited[idx] = false;
		_Predecessor[idx] = -1;
		_distance[idx] = INT_MAX;
	}
	
	bIsVisited[iSource] = true;
	_distance[iSource] = 0;
	q.push(iSource);

	// Standard BFS
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		// Traversing to adject nodes (using BFS).
		for (auto & iCurrVertex : _Adj[u])
		{
			if (!bIsVisited[iCurrVertex])
			{
				bIsVisited[iCurrVertex] = true;
				q.push(iCurrVertex);
				_distance[iCurrVertex] = _distance[u] + 1;
				_Predecessor[iCurrVertex] = u;

				if (iCurrVertex == iDestination)
				{
					return true;
				}
			}
		}
	}
	return false;
}

int Graph::FindShortestPath(int iSource, int iDestination)
{	
	if (false == ModifiedBFS(iSource, iDestination))
	{
		cout << "Source and destination is not connected" << endl;
	}

	vector<int> Path;

	int temp = iDestination;
	Path.push_back(temp);
	while (_Predecessor[temp] != -1)
	{
		Path.push_back(_Predecessor[temp]);
		temp = _Predecessor[temp];
	}

	for (int idx=Path.size()-1; idx>=0; idx--)
	{
		cout << Path[idx] << " ";
	}
	cout << endl;

	return _distance[iDestination];
}

int main()
{
	Graph g(8);
	g.AddEdge(0, 1);
	g.AddEdge(0, 3);
	g.AddEdge(1, 2);
	g.AddEdge(3, 4);
	g.AddEdge(3, 7);
	g.AddEdge(4, 5);
	g.AddEdge(4, 6);
	g.AddEdge(4, 7);
	g.AddEdge(5, 6);
	g.AddEdge(6, 7);

	int Source = 0;
	int Destination = 7;

	cout << g.FindShortestPath(Source, Destination) << endl;

	return 0;
}