/*
Fixing two nodes of a BST:

    Input Tree:
         10
        /  \
       5    8
      / \
     2   20

     In the above tree, nodes 20 and 8 must be swapped to fix the tree.

    Output tree:
         10
        /  \
       5    20
      / \
     2   8
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node
{
    int _data;
    Node *_pLeft = nullptr;
    Node *_pRight = nullptr;
    Node(int iData) : _data(iData) {}
};

class BST
{
    vector<int> _vec;
    vector<int> _sortedVec;
    queue<Node **> q;

    void SwapInOrder(Node *&ipNode, int &iIdx);
    void InOrder(Node *ipNode); // Should print the BST Nodes in a sorted order

public:
    void CreateNode(Node *&ipNode, int iData);
    void DisplayData(Node *ipNode);
    void SwapBSTNodes(Node *&ipNode);
};

void BST::CreateNode(Node *&ipNode, int iData)
{
    if (nullptr == ipNode)
        ipNode = new Node(iData);
}

void BST::InOrder(Node *ipNode)
{
    if (ipNode)
    {
        InOrder(ipNode->_pLeft);
        _vec.push_back(ipNode->_data);
        InOrder(ipNode->_pRight);
    }
}

void BST::DisplayData(Node *ipNode)
{
    _vec.clear();
    InOrder(ipNode);

    for (auto &iVec : _vec)
        cout << iVec << " ";
    cout << endl;
}

void BST::SwapInOrder(Node *&ipNode, int &iIdx)
{
    if (ipNode)
    {
        SwapInOrder(ipNode->_pLeft, iIdx);
        if (ipNode->_data != _sortedVec[iIdx])
        {
            q.push(&ipNode);
        }
        iIdx++;
        SwapInOrder(ipNode->_pRight, iIdx);
    }
}

void BST::SwapBSTNodes(Node *&ipNode)
{
    _sortedVec = _vec;
    sort(_sortedVec.begin(), _sortedVec.end());

    int idx = 0;
    SwapInOrder(ipNode, idx);

    // Check if 2 nodes in BST swapped
    if (2 == q.size())
    {
        Node **pNode1 = q.front();
        q.pop();

        Node **pNode2 = q.front();
        q.pop();

        // Swap the nodes
        Node *pTemp = *pNode1;
        *pNode1 = *pNode2;
        *pNode2 = pTemp;
    }
}

int main()
{
    Node *pRoot = nullptr;
    BST obj;

    obj.CreateNode(pRoot, 10);
    obj.CreateNode(pRoot->_pLeft, 5);
    obj.CreateNode(pRoot->_pRight, 8);
    obj.CreateNode(pRoot->_pLeft->_pLeft, 2);
    obj.CreateNode(pRoot->_pLeft->_pRight, 20);

    obj.DisplayData(pRoot);

    obj.SwapBSTNodes(pRoot);
    obj.DisplayData(pRoot);

    return 0;
}