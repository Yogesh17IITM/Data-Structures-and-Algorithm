/* 
	Finding shortest path in an unweighted graph 
	using BFS 
	      
			1----0     7---- 6
			|	 |   / |   / |
			|	 |  /  |  /  |
			2	 3 /___4 /---5

	Source: 0
	Destination: 7

	Find the shorted path b/w source and destination:
	Shortest Path: 0 -- 3 -- 5	
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

	void AddEdges(int u, int v);
	bool BFS(int iSource, int iDestination);

	int FindShortestPathUsingBFS(int iSource, int iDestination);

private:
	int _NbVertices;
	vector<int>* _pAdj;

	int* _pShortestDistance;
	int* _pPreceedingNode;
};

Graph::Graph(int iVertices) : _NbVertices(iVertices)
{
	_pAdj = new vector<int>[_NbVertices];
	_pShortestDistance = new int[_NbVertices];
	_pPreceedingNode = new int[_NbVertices];

	for (int idx = 0; idx < _NbVertices; idx++)
	{
		_pShortestDistance[idx] = 0;
		_pPreceedingNode[idx] = -1;
	}
}

Graph::~Graph()
{
}

void Graph::AddEdges(int u, int v)
{
	_pAdj[u].push_back(v);
	_pAdj[v].push_back(u);
}

// Time Complexity: O(V + E)
// where V: Vertices and E: Edges
bool Graph::BFS(int iSource, int iDestination)
{
	bool* bIsVisited = new bool[_NbVertices];
	for (int idx = 0; idx < _NbVertices; idx++)
		bIsVisited[idx] = false;

	bIsVisited[iSource] = true;
	_pShortestDistance[iSource] = 0;

	queue<int> q;
	q.push(iSource);
	while (!q.empty())
	{
		int size = q.size();
		while (size)
		{
			int temp = q.front();
			q.pop();

			for (auto & iAdjNode: _pAdj[temp])
			{
				if (!bIsVisited[iAdjNode])
				{
					bIsVisited[iAdjNode] = true;
					q.push(iAdjNode);

					_pShortestDistance[iAdjNode] = _pShortestDistance[temp] + 1;
					_pPreceedingNode[iAdjNode] = temp;

					if (iAdjNode == iDestination)
					{
						return true;
					}
				}
			}

			size--;
		}
	}
	return false;
}

int Graph::FindShortestPathUsingBFS(int iSource, int iDestination)
{
	int oShortestDistance = 0;
	if (BFS(iSource, iDestination))
	{
		oShortestDistance = _pShortestDistance[iDestination];
		cout << "Shortest Path: ";

		vector<int> vPath;
		vPath.push_back(iDestination);

		int temp = _pPreceedingNode[iDestination];		
		while (temp != -1)
		{			
			vPath.push_back(temp);
			temp = _pPreceedingNode[temp];
		}

		for (int idx = vPath.size()-1; idx >=0; idx--)
		{
			cout << vPath[idx] << " ";
		}
		cout << endl;
	}
	else
	{
		cout << "Source and Destination nodes are NOT connected" << endl;
	}
	return oShortestDistance;
}

int main()
{
	Graph Obj(8);
	Obj.AddEdges(0, 1);
	Obj.AddEdges(0, 3);
	Obj.AddEdges(1, 2);
	Obj.AddEdges(3, 4);
	Obj.AddEdges(3, 7);
	Obj.AddEdges(4, 5);
	Obj.AddEdges(4, 6);
	Obj.AddEdges(4, 7);
	Obj.AddEdges(5, 6);
	Obj.AddEdges(6, 7);

	int Source = 0;
	int Destination = 7;

	// Finding Shortest Path
	cout << Obj.FindShortestPathUsingBFS(Source, Destination) << endl;

	return 0;
}