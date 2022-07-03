/*
    Check if a given binary tree is BST

                   10
                 /    \
              /         \
           5              16
         /   \
        4      7
       /        \
     1          (11)
*/
#include <iostream>
#include <limits.h>
using namespace std;

struct Node
{
    int _data;
    Node *_pLeft, *_pRight;
    Node(int iData) : _data(iData), _pLeft(nullptr), _pRight(nullptr) {}
};

class Tree
{
public:
    Tree(){};

    void CreateNode(Node *&opNode, int iData)
    {
        if (nullptr == opNode)
        {
            opNode = new Node(iData);
        }
    }

    bool IsBST(Node *ipNode, Node *pLeft = nullptr, Node *pRight = nullptr)
    {
        if (ipNode == nullptr)
            return true;

        // Is Left data valid?
        if (pLeft != nullptr && (pLeft->_data > ipNode->_data))
            return false; // coz. left data cannot be greater than curr data.

        // Is Right data valid?
        if (pRight != nullptr && (pRight->_data < ipNode->_data))
            return false; // coz. right data cannot be lesser than curr data.

        return (IsBST(ipNode->_pLeft, pLeft, ipNode) &&
                IsBST(ipNode->_pRight, ipNode, pRight));
    }
};

int main()
{
    Tree obj;

    Node *pRoot = nullptr;
    obj.CreateNode(pRoot, 10);
    obj.CreateNode(pRoot->_pLeft, 5);
    obj.CreateNode(pRoot->_pRight, 16);
    obj.CreateNode(pRoot->_pLeft->_pLeft, 4);
    obj.CreateNode(pRoot->_pLeft->_pRight, 7);
    obj.CreateNode(pRoot->_pLeft->_pLeft->_pLeft, 1);

    // Lambda funtion to print if it is BST
    auto PrintIsBST = [&](Node *ipRoot)
    {
        if (obj.IsBST(ipRoot))
            cout << "Given binary tree is BST" << endl;
        else
            cout << "Given binary tree is NOT BST" << endl;
    };

    // Case a) It is BST
    PrintIsBST(pRoot);

    // case b) Not a BST
    obj.CreateNode(pRoot->_pLeft->_pRight->_pRight, 11);
    PrintIsBST(pRoot);

    return 0;
}