/*
Find the height of the Binary tree?

           3
        /     \
      2        5
    /        /   \
   1        4     6
                   \
                    7

Output:
    3
*/

#include <iostream>
using namespace std;

struct Node
{
    int _data;
    Node *_pLeft;
    Node *_pRight;

    Node(int iData) : _data(iData)
    {
        _pLeft = _pRight = nullptr;
    }
};

class DFS
{
public:
    void CreateBST(Node *&ipNode, int iData);
    int FindHeight(Node *ipNode);
};

void DFS::CreateBST(Node *&ipNode, int iData)
{
    if (nullptr == ipNode)
    {
        ipNode = new Node(iData);
    }
    else
    {
        if (iData < ipNode->_data)
        {
            CreateBST(ipNode->_pLeft, iData);
        }
        else
        {
            CreateBST(ipNode->_pRight, iData);
        }
    }
}

int DFS::FindHeight(Node *ipNode)
{
    int LeftHeight = 0;
    int RightHeight = 0;

    // similar to post-order traveral (Left-Right-Data)
    if (ipNode && ipNode->_pLeft)
    {
        LeftHeight = 1 + FindHeight(ipNode->_pLeft);
    }

    if (ipNode && ipNode->_pRight)
    {
        RightHeight = 1 + FindHeight(ipNode->_pRight);
    }

    return (LeftHeight < RightHeight) ? RightHeight : LeftHeight;
}

int main()
{
    Node *pNode = nullptr;

    DFS *pDFS = nullptr;
    pDFS->CreateBST(pNode, 3);
    if (pNode)
    {
        pDFS->CreateBST(pNode, 2);
        pDFS->CreateBST(pNode, 1);
        pDFS->CreateBST(pNode, 5);
        pDFS->CreateBST(pNode, 4);
        pDFS->CreateBST(pNode, 6);
        pDFS->CreateBST(pNode, 7);

        cout << "Height: " << pDFS->FindHeight(pNode) << endl;
    }

    return 0;
}