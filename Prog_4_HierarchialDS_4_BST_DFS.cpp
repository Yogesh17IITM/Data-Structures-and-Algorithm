/*
Create a BST from the given array and search an element from the BST using DFS

Given array = { 50, 12, 1, 32, 11, 12, 4, 1 }
Element to Search = 12

Expected Output:
    Elem 12 is at: 1

Note: return '-1' if the element is NOT found
*/

#include <iostream>
using namespace std;

struct Node
{
    int _data;
    int _Index;
    Node *_pLeft = nullptr;
    Node *_pRight = nullptr;
    Node(int iData, int iIdx) : _data(iData), _Index(iIdx) {}
};

class BST
{
    static BST *_pBST;
    BST(){};

public:
    static BST *CreateInstance();

    void InsertNode(Node *&ioNode, int iData, int iIdx);
    int FindElement(int iKey, const Node *pNode); // return Idx
    void Inorder(const Node *ipNode);
};

// Initialize static variable
BST *BST::_pBST = nullptr;

// Singleton class - Only One object created.
BST *BST::CreateInstance()
{
    if (nullptr == _pBST)
        _pBST = new BST();
    return _pBST;
}

void BST::Inorder(const Node *ipNode)
{
    if (nullptr == ipNode)
        return;

    // InOrder Traversal : LDR (result will be sorted)
    Inorder(ipNode->_pLeft);
    cout << ipNode->_Index << " " << ipNode->_data << endl;
    Inorder(ipNode->_pRight);
}

int BST::FindElement(int iKey, const Node *pNode)
{
    int oIdx = -1;

    if (pNode)
    {
        if (iKey == pNode->_data)
        {
            // Element found. Return the Idx.
            oIdx = pNode->_Index;
        }
        else
        {
            // Check if the key exists in Left or Right Sub-tree
            if (iKey < pNode->_data)
            {
                // Check if Key is in Left sub-tree
                oIdx = FindElement(iKey, pNode->_pLeft);
            }
            else
            {
                // Check if Key is in Right sub-tree
                oIdx = FindElement(iKey, pNode->_pRight);
            }
        }
    }
    return oIdx;
}

void BST::InsertNode(Node *&ioNode, int iData, int iIdx)
{
    // Check if it Root Node
    if (nullptr == ioNode)
        ioNode = new Node(iData, iIdx);
    else
    {
        // It is NOT a root node. Insert to Left or Right based on comparison
        if (iData < ioNode->_data)
        {
            // Insert to Left
            InsertNode(ioNode->_pLeft, iData, iIdx);
        }
        else
        {
            // Insert to Right
            InsertNode(ioNode->_pRight, iData, iIdx);
        }
    }
}

int main()
{
    // INPUTS
    int arr[] = {50, 12, 1, 32, 11, 18, 4, 3};
    int TargetElem = 12;

    int nArr = sizeof(arr) / sizeof(arr[0]);

    BST *pBST = BST::CreateInstance();
    if (pBST)
    {
        Node *pRoot = nullptr;

        // 1) Create BST from the array
        for (int idx = 0; idx < nArr; idx++)
            pBST->InsertNode(pRoot, arr[idx], idx);

        // 2) Print all data in BST
        if (nArr && pRoot)
            pBST->Inorder(pRoot);

        // 3) Find the element in BST and get the index
        if (pRoot)
        {
            cout << "Element " << TargetElem << " is at: ";
            cout << pBST->FindElement(TargetElem, pRoot) << endl;
        }
    }
}