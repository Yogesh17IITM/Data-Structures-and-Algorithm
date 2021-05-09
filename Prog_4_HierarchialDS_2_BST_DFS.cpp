/* Find the given element in a BST (Binary Search Tree) 
   using DFS (Depth First Search) */

#include<iostream>
using namespace std;

class BST
{
    int _data;
    int _Idx;
    BST * _pLeft;
    BST* _pRight;
public:
    BST(int iData=0, int iIdx=0, BST *ipLeft=nullptr, BST* ipRight = nullptr) 
        : _pLeft(ipLeft),_pRight(ipRight), _data(iData), _Idx(iIdx)
    {
    }
    ~BST();
        
    BST * Insert(BST * pRoot, int iData, int iIdx);
    void Inorder(BST * ipRoot);

    bool FindElement(int & oIdx, BST* ipRoot, int iElementToSearch);
};

BST* BST::Insert(BST* pRoot, int iData, int iIdx)
{    
    if (nullptr == pRoot)
    {
        // Create root node        
        return new BST(iData, iIdx);
    }
    else
    {
        // Create sub-nodes
        if (iData > pRoot->_data)
        {
            // Create Right Node
            pRoot->_pRight = Insert(pRoot->_pRight, iData, iIdx);
        }
        else
        {
            pRoot->_pLeft = Insert(pRoot->_pLeft, iData, iIdx);
        }
    }

    return pRoot;
}

void BST::Inorder(BST * ipRoot)
{
    if (ipRoot)
    {
        Inorder(ipRoot->_pLeft);
        cout << "Val: " << ipRoot->_data;
        cout << " Idx: " << ipRoot->_Idx << endl;
        Inorder(ipRoot->_pRight);
    }
}

bool BST::FindElement(int & oIdx, BST* ipRoot, int iElementToSearch)
{
    bool obIsFound = false;
    oIdx = -1;
    if (ipRoot)
    {
        if (iElementToSearch == ipRoot->_data)
        {
            oIdx = ipRoot->_Idx;
        }
        else if (iElementToSearch > ipRoot->_data)
        {
            obIsFound = FindElement(oIdx, ipRoot->_pRight, iElementToSearch);
        }
        else
        {
            obIsFound = FindElement(oIdx, ipRoot->_pLeft, iElementToSearch);
        }
    }

    return (oIdx!=-1) ? true: false;
}

int main()
{
    int arr[] = { 50, 12, 1, 32, 11, 12, 4, 1 };
    int nArr = sizeof(arr) / sizeof(arr[0]);
        
    if (nArr > 0)
    {
        BST* pRoot = nullptr;
        for (int idx = 0; idx < nArr; idx++)
        {
            // BST stores elements in sorted order
            pRoot = pRoot->Insert(pRoot, arr[idx], idx);
        }
        
        // Print the sorted elements using tree traversal
        pRoot->Inorder(pRoot);  // In-Order tree traversal

        int iElemIdx = -1;
        int ElemToSearch = 32;
        if (pRoot->FindElement(iElemIdx, pRoot, ElemToSearch))
            cout << "Element Found: " << iElemIdx << endl;
    }

    return 0;
}