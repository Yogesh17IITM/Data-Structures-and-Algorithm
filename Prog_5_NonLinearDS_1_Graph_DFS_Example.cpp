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
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

const int NMax = 10000;
vector<int> vecPair[NMax];	// Array Of Vector containing Pair Details
bool bIsVisited[NMax];		// Flag to identify if the node is visited already

// Connect Nodes through Edges
void ConnectPair(int u, int v)
{
	vecPair[u - 1].push_back(v-1);
	vecPair[v - 1].push_back(u-1);
}

// Depth First Search (Recursive)
// Visit all nodes, then update flag and minimum value
void DFS(int iNodeIdx, int iArr[], int & ioMin)
{	
	ioMin = min(iArr[iNodeIdx], ioMin);
	bIsVisited[iNodeIdx] = true;
	for (int idx : vecPair[iNodeIdx])	
	{
		if(!bIsVisited[idx])
			DFS(idx, iArr, ioMin);
	}
}

// Find Sum of minimum element of all connected Components or Nodes
int SumOfMinimum(int iArr[], int iSize)
{
	int oSum = 0;

	for (int idx = 0; idx < iSize; idx++)
	{
		if (!bIsVisited[idx])
		{
			int minimum = iArr[idx];	
			DFS(idx, iArr, minimum);
			oSum += minimum;
		}
	}
	return oSum;
}

int main()
{
	int arr[] = { 4, 5, 3, 2, 8 };
	int ArrSize = sizeof(arr) / sizeof(arr[0]);
	int nPair = 2;

	// Connect pairs through edges
	ConnectPair(1, 4);
	ConnectPair(4, 5);		

	// Display Sum
	cout << SumOfMinimum(arr, ArrSize) << endl;

	return 0;
}