/*
Binary Tree:

                      20
                    /    \
                  8       22
                /   \    /   \
              5      3 4     25
                    / \
                  10    14

Print the tree in the following views:
    1) Bottom view      -> 5 10 4 14  25
    2) Left Side View   -> 20 8 5 10
    3) Right Side View  -> 20 22 25 14
*/

#include <iostream>
#include <queue>
#include <Map>
using namespace std;

struct Node
{
    int _data;
    int _HDist;
    int _VDist;
    Node *_pLeft = nullptr;
    Node *_pRight = nullptr;
    Node(int iData) : _data(iData)
    {
        _HDist = -1;
        _VDist = -1;
    }
};

class BinaryTree
{
public:
    void CreateNode(Node *&ipNode, int iData);
    void PrintBottomView(Node *ipNode);
    void PrintLeftOrRightView(Node *ipNode, bool bIsLeftView = true);
};

void BinaryTree::CreateNode(Node *&ipNode, int iData)
{
    if (nullptr == ipNode)
        ipNode = new Node(iData);
    else
        cout << "Node already exists" << endl;
}

void BinaryTree::PrintBottomView(Node *ipNode)
{
    if (nullptr == ipNode)
        return;

    int HorizDist = 0;
    ipNode->_HDist = HorizDist;

    map<int, int> mHDistNode; // Map b/w Horizontal distance and the node data
    queue<Node *> q;
    q.push(ipNode);

    while (!q.empty()) // Iterate from Root level to downwards
    {
        int size = q.size();
        while (size) // Iterate same level nodes.
        {
            Node *pTemp = q.front();
            q.pop();

            HorizDist = pTemp->_HDist;            // Update Horizontal Distance
            mHDistNode[HorizDist] = pTemp->_data; // Update map with data corresponding to the distance

            if (pTemp->_pLeft)
            {
                q.push(pTemp->_pLeft);
                pTemp->_pLeft->_HDist = HorizDist - 1;
            }

            if (pTemp->_pRight)
            {
                q.push(pTemp->_pRight);
                pTemp->_pRight->_HDist = HorizDist + 1;
            }
            size--;
        }
    }

    // Print the Bottom View
    cout << "Bottom View: ";
    for (auto it = mHDistNode.begin(); it != mHDistNode.end(); it++)
        cout << it->second << " ";
    cout << endl;
}

void BinaryTree::PrintLeftOrRightView(Node *ipNode, bool bIsLeftView)
{
    if (nullptr == ipNode)
        return;

    int VertDist = 0;
    ipNode->_VDist = VertDist;

    map<int, int> mVDistNode; // Map b/w vertical distance and the node data
    queue<Node *> q;

    // Lambda Expr. to push Nodes
    auto q_push = [&](Node *ipNode)
    {
        if (ipNode)
            q.push(ipNode);
    };

    q_push(ipNode);
    while (!q.empty())
    {
        int size = q.size();
        while (size)
        {
            Node *pTemp = q.front();
            q.pop();

            // Update map data corresp. to the current distance
            mVDistNode[VertDist] = pTemp->_data;

            if (bIsLeftView)
            {
                q_push(pTemp->_pRight);
                q_push(pTemp->_pLeft);
            }
            else
            {
                q_push(pTemp->_pLeft);
                q_push(pTemp->_pRight);
            }
            size--;
        }
        VertDist++;
    }

    // Print appropriate view
    string oStr = (bIsLeftView) ? "Left View: " : "Right View: ";
    cout << oStr;
    for (auto it = mVDistNode.begin(); it != mVDistNode.end(); it++)
        cout << it->second << " ";
    cout << endl;
}

int main()
{
    Node *pRoot = nullptr;
    BinaryTree obj;

    // Create Binary Tree
    obj.CreateNode(pRoot, 20);
    obj.CreateNode(pRoot->_pLeft, 8);
    obj.CreateNode(pRoot->_pRight, 22);
    obj.CreateNode(pRoot->_pLeft->_pLeft, 5);
    obj.CreateNode(pRoot->_pLeft->_pRight, 3);
    obj.CreateNode(pRoot->_pRight->_pLeft, 4);
    obj.CreateNode(pRoot->_pRight->_pRight, 25);
    obj.CreateNode(pRoot->_pLeft->_pRight->_pLeft, 10);
    obj.CreateNode(pRoot->_pLeft->_pRight->_pRight, 14);

    obj.PrintBottomView(pRoot);             // Print Bottom View
    obj.PrintLeftOrRightView(pRoot);        // Print Left View
    obj.PrintLeftOrRightView(pRoot, false); // Print Right View
    return 0;
}