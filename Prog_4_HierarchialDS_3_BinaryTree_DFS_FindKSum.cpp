/* 
Print 'K' sum paths in a Binary Tree 

           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5
        /   / \     \
       1   1   2     6

Input : 
    k = 5

Output:
    3 2
    3 1 1
    1 3 1
    4 1
    1 -1 4 1
    -1 4 2
    5
    1 -1 5
*/

#include<iostream>
#include<vector>
using namespace std;

struct Node
{
    int _data;
    Node* _pLeft, * _pRight;
    Node(int iData) : _data(iData) 
    {
        _pLeft = nullptr;
        _pRight = nullptr;
    }
};

vector<int> vecPath;

void PrintPath(const vector<int> & iVecPath, int iStartIdx)
{
    for (int idx = iStartIdx; idx < iVecPath.size(); idx++)
    {
        cout << iVecPath[idx] << " ";
    }
    cout << endl;
}

// Print all paths that have sum = k
void PrintKSumPath(Node* ipNode, int iSum)
{
    if (!ipNode)
    {
        return;
    }

    // Pre-Order Traversal
    vecPath.push_back(ipNode->_data);
    PrintKSumPath(ipNode->_pLeft, iSum);
    PrintKSumPath(ipNode->_pRight, iSum);
    //
    
    int CalcSum = 0;
    for(int idx=vecPath.size()-1; idx>=0; idx--)
    {
        CalcSum += vecPath[idx];
        if (CalcSum == iSum)
        {
            PrintPath(vecPath, idx);
        }
    }
    vecPath.pop_back();
}

int main()
{
    Node* pNode = nullptr;

    // Creating Tree
    pNode = new Node(1);
    // Level 1
    pNode->_pLeft = new Node(3);
    pNode->_pRight = new Node(-1);
    // Level 2
    pNode->_pLeft->_pLeft = new Node(2);
    pNode->_pLeft->_pRight = new Node(1);    
    pNode->_pRight->_pLeft = new Node(4);
    pNode->_pRight->_pRight = new Node(5);
    // Level 3
    pNode->_pLeft->_pRight->_pLeft = new Node(1);
    pNode->_pRight->_pLeft->_pLeft = new Node(1);
    pNode->_pRight->_pLeft->_pRight = new Node(2);
    pNode->_pRight->_pRight->_pRight = new Node(6);

    int Sum = 5;
    PrintKSumPath(pNode, 5);

	return 0;
}