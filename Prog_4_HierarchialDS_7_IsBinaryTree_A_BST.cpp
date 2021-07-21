/*
    Check if a given binary tree is BST

                   10
           5             16
        4     7
     1           11
*/
#include<iostream>
#include<limits.h>
using namespace std;

struct Node
{
    int _data;
    Node * _pLeft, *_pRight;
    Node(int iData) : _data(iData), _pLeft(nullptr), _pRight(nullptr){}
};

class Tree
{
public:
    Tree(){};

    void CreateNode(Node *& opNode, int iData)
    {
        if(nullptr == opNode)
        {
            opNode = new Node(iData);
        }
    }

    bool IsBST(Node * ipNode, int iLeftData, int iRightData)
    {
        if(ipNode == nullptr)
            return true;

        if((ipNode->_data <= iLeftData) || (ipNode->_data > iRightData))
            return false;
        
        return (IsBST(ipNode->_pLeft, iLeftData, ipNode->_data) 
               && IsBST(ipNode->_pRight, ipNode->_data, iRightData));
    }
};

int main()
{
    Tree obj;

    Node * pRoot = nullptr;
    obj.CreateNode(pRoot, 10);
    obj.CreateNode(pRoot->_pLeft, 5);
    obj.CreateNode(pRoot->_pRight, 16);
    obj.CreateNode(pRoot->_pLeft->_pLeft, 4);
    obj.CreateNode(pRoot->_pLeft->_pRight, 7);
    obj.CreateNode(pRoot->_pLeft->_pLeft->_pLeft, 1);
    obj.CreateNode(pRoot->_pLeft->_pLeft->_pRight, 11);   

    if(obj.IsBST(pRoot, INT_MIN, INT_MAX))
        cout<< "Given tree is BST"<<endl;
    else
        cout<< "Given tree is NOT BST"<<endl;

    return 0;
}