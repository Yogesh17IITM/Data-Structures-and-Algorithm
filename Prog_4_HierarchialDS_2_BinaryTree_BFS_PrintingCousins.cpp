/*
 Print cousins of given node in Binary Tree using
 Breadth First Search (BFS)

 Input : root of below tree
             1
           /   \
          2     3
        /   \  /  \
       4    5  6   7
       and pointer to a node say 5.

 Output : 6, 7
*/

#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int _data;
    // Create Left and Right Node -> Binary Tree
    Node *_pLeft = nullptr;
    Node *_pRight = nullptr;
    Node(int iData) : _data(iData) {}
};

class BinaryTree
{
public:
    void CreateNode(Node *&opNode, int iData);
    void PrintCousinNodes(Node *pRootNode, Node *pNodeToFind);
};

void BinaryTree::CreateNode(Node *&opNode, int iData)
{
    if (nullptr == opNode)
        opNode = new Node(iData);
}

void BinaryTree::PrintCousinNodes(Node *pRootNode, Node *pNodeToFind)
{
    bool bIsCousinFound = false;

    /*
    Handle case at Root Level:
        case a) pRootNode == pNodeToFind
        case b) pNodeToFind || pRootNode == nullptr
    */

    queue<Node *> q;
    if (pRootNode && pNodeToFind && pRootNode != pNodeToFind) // Handling case (a) & (b)
    {
        q.push(pRootNode);
        while (!q.empty() && !bIsCousinFound)
        {
            int size = q.size();
            while (size)
            {
                Node *curr = q.front();
                q.pop();

                // Check if target node found at next level
                if ((pNodeToFind == curr->_pLeft) || (pNodeToFind == curr->_pRight))
                {
                    bIsCousinFound = true;
                }
                else
                {
                    // Add Nodes of next level
                    if (curr->_pLeft)
                        q.push(curr->_pLeft);

                    if (curr->_pRight)
                        q.push(curr->_pRight);
                }
                size--;
            }
        }
    }

    if (bIsCousinFound && !q.empty())
    {
        while (!q.empty())
        {
            cout << q.front()->_data << " ";
            q.pop();
        }
        cout << endl;
    }
    else
    {
        cout << "No Cousin Exists!" << endl;
    }
}

int main()
{
    Node *pRoot = nullptr;
    BinaryTree t;

    t.CreateNode(pRoot, 1);

    // Level 1 (Left and Right node)
    t.CreateNode(pRoot->_pLeft, 2);
    t.CreateNode(pRoot->_pRight, 3);

    // Level 2 (left sub-tree)
    t.CreateNode(pRoot->_pLeft->_pLeft, 4);
    t.CreateNode(pRoot->_pLeft->_pRight, 5);

    // Level 2 (right sub-tree)
    t.CreateNode(pRoot->_pRight->_pLeft, 6);
    t.CreateNode(pRoot->_pRight->_pRight, 7);

    // Print Cousin Nodes
    t.PrintCousinNodes(pRoot, pRoot->_pLeft->_pLeft);
    return 0;
}