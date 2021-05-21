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
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Graph
{
public:
	Graph(int iNbVertices);
	~Graph();

	void AddEdges(int u, int v);
	pair<int, int> BFS(int u);

	int FindLongestPath(int iSource);

private:
	int _NbVertices;
	vector<int>* _pAdj;
};

Graph::Graph(int iNbVertices) : _NbVertices(iNbVertices)
{
	_pAdj = new vector<int>[_NbVertices];
}

Graph::~Graph()
{
}

void Graph::AddEdges(int u, int v)
{
	_pAdj[u].push_back(v);
	_pAdj[v].push_back(u);
}

pair<int, int> Graph::BFS(int u)
{
	int* Distance = new int[_NbVertices];
	bool* bIsVisited = new bool[_NbVertices];

	for (int idx = 0; idx < _NbVertices; idx++)
	{
		Distance[idx] = -1;
		bIsVisited[idx] = false;
	}

	Distance[u] = 0;
	bIsVisited[u] = true;

	queue<int> q;
	q.push(u);

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();

		for (auto & iAdj: _pAdj[temp])
		{
			if (!bIsVisited[iAdj])
			{
				bIsVisited[iAdj] = true;
				q.push(iAdj);
				Distance[iAdj] = Distance[temp] + 1;
			}
		}
	}

	int MaxDistance = 0;
	int NodeIdx = -1;
	for (int idx = 0; idx < _NbVertices; idx++)
	{
		if (Distance[idx] > MaxDistance)
		{
			MaxDistance = Distance[idx];
			NodeIdx = idx;
		}
	}

	return make_pair(NodeIdx, MaxDistance);
}

int Graph::FindLongestPath(int iSource)
{
	pair<int, int> t1, t2;
	t1 = BFS(iSource);

	t2 = BFS(t1.first);

	cout << "Longest Path: " << t1.first << " --> " << t2.first << endl;
	cout << "Length: " << t2.second << endl;

	return 0;
}

int main()
{
	Graph obj(10);

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
	obj.FindLongestPath(0);
	return 0;
}