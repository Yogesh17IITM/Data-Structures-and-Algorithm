/*
    Find if there is a triplet in a Balanced BST that adds to zero

                6
              /   \
         -13        14
            \       / \  
            -8     13  15
                   /
                  7

        Triplet with sum 0 : {-13, 6, 7}
*/

#include<iostream>
using namespace std;

struct Node
{
    int _data;
    Node* pLeft, *pRight;
};

// Create BST
Node* InsertNode(Node* ipNode, int iVal)
{    
    if (nullptr == ipNode)
    {
        // Root Node
        ipNode = new Node;
        ipNode->_data = iVal;
        ipNode->pLeft = ipNode->pRight = nullptr;
    }
    else
    {
        // BST 
        // If value is lesser than parent node value, then store it in left Node
        // Else, store it in right node.
        if (iVal < ipNode->_data)
        {
            ipNode->pLeft = InsertNode(ipNode->pLeft, iVal);
        }
        else
        {
            ipNode->pRight = InsertNode(ipNode->pRight, iVal);
        }
    }
    return ipNode;
}

void ConvertBSTintoDLL(Node*& opHead, Node*& opTail, Node* ipNode)
{
    // Convert all nodes such that starting from head, traversing towards right
    // will pass all nodes till tail (DLL).

    if (nullptr == ipNode)
        return;

    // 1. Convert Left subtree
    if (ipNode->pLeft)
        ConvertBSTintoDLL(opHead, opTail, ipNode->pLeft);

    ipNode->pLeft = opTail;
    if (nullptr == opTail)  // Code hits here for first time
    {
        // Left most node --> Head node (found)
        opHead = ipNode;
    }
    else
    {
        // append node to the right of prev. node.
        opTail->pRight = ipNode;
    }

    // Update tail node every time
    opTail = ipNode;

    // 2. Convert Right subtree
    if (ipNode->pRight)
        ConvertBSTintoDLL(opHead, opTail, ipNode->pRight);
}

bool IsTriplets(Node* ipHead, Node* ipTail, int iSum)
{
    while (ipHead != ipTail)
    {
        int CurrSum = ipHead->_data + ipTail->_data;
        if (CurrSum == iSum)
            return true;
        else if (CurrSum < iSum)
        {
            // If sum is less, then traverse to right for getting higher value
            ipHead = ipHead->pRight;
        }
        else
        {
            // If sum is mode, then travers to left for getting lesser value
            ipTail = ipTail->pLeft;
        }
    }
    return false;
}

bool IsTripletFound(Node* ipNode)
{
    if (nullptr == ipNode)    
        return false;
    
    // 1. Convert BST into DLL (Doubly Linked List)
    //    Head Node --> Node 1 --> .. --> Tail Node
    //    Doubly Linked list contains two nodes:
    //    One for forward traversal and the other for backward.
    Node* pHead = nullptr;
    Node* pTail = nullptr;
    ConvertBSTintoDLL(pHead, pTail, ipNode);

    while ((pHead->pRight != pTail) && (pHead->_data < 0))
    {
        if (IsTriplets(pHead->pRight, pTail, (-1 * pHead->_data)))
        {
            return true;
        }
        else
        {
            // Take next node for checking triplets
            pHead = pHead->pRight;
        }
    }
    return false;
}



int main()
{
    Node* pNode = nullptr;
    pNode = InsertNode(pNode, 6);
    pNode = InsertNode(pNode, -13);
    pNode = InsertNode(pNode, -8);
    pNode = InsertNode(pNode, 14);
    pNode = InsertNode(pNode, 13);
    pNode = InsertNode(pNode, 15);
    pNode = InsertNode(pNode, 7);

    if (IsTripletFound(pNode))
        cout << "Triplet Found" << endl;
    else    
        cout << "Triplet NOT Found" << endl;
    
    return 0;
}