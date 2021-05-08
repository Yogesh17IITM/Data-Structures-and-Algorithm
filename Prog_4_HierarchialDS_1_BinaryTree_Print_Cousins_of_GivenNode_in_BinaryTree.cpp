/* Print cousins of given node in Binary Tree */

#include<iostream>
#include<queue>
using namespace std;

struct Node
{
	int _data;
	Node* pLeft, * pRight;
};

void CreateNode(Node *& opNode, int iVal)
{
	opNode = new Node;
	opNode->_data = iVal;
	opNode->pLeft = nullptr;
	opNode->pRight = nullptr;
}

void DisplayCousinNodes(Node * pRootNode, Node * pNodeToFind)
{
	if (pRootNode == pNodeToFind)
	{
		return;
	}
	
	queue<Node*> q;
	int size;
	Node* p;
		
	q.push(pRootNode);

	bool bIsFound = false;
	
	while (!q.empty() && !bIsFound)
	{
		size = q.size();			
		while (size)
		{			
			p = q.front();
			q.pop();
			if ((p->pLeft == pNodeToFind) ||
				(p->pRight == pNodeToFind))
			{
				bIsFound = true;
			}
			else
			{
				if (p->pLeft)
					q.push(p->pLeft);
				if (p->pRight)
					q.push(p->pRight);
			}
			size--;
		}		
	}

	if (bIsFound)
	{
		size = q.size();
		for (int idx = 0; idx < size; idx++)
		{
			p = q.front();
			q.pop();
			cout << p->_data << endl;
		}
	}
}

int main()
{
	Node* pNode = nullptr;
	CreateNode(pNode, 1);
	if (pNode)
	{
		// Level 1
		CreateNode(pNode->pLeft, 2);
		CreateNode(pNode->pRight, 3);

		// Level 2 (left)
		CreateNode(pNode->pLeft->pLeft, 4);
		CreateNode(pNode->pLeft->pRight, 5);

		// Level 2 (right)
		CreateNode(pNode->pRight->pLeft, 6);
		CreateNode(pNode->pRight->pRight, 7);

		DisplayCousinNodes(pNode, pNode->pLeft->pLeft);
	}
	return 0;
}