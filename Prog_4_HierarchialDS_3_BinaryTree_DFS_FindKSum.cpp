/*
Print all k-sum paths in a binary tree using DFS

Input : k = 5  
        Root of below binary tree:
           1
        /     \
      3        -1
    /   \     /   \
   2     1   4     5                        
        /   / \     \                    
       1   1   2     6    

Output :
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
    Node * _pLeft, * _pRight;
    Node(int iData) : _data(iData),_pLeft(nullptr),_pRight(nullptr)
    {        
    }
};

class Tree
{
    vector<int> _vPath;
public:
    Tree(){};
    void CreateNode(Node *& ipNode, int iData);
    void PrintPath(vector<int> vPath, int iStartIdx);
    void PrintKSumPath(Node * ipRoot, int k);    
};

void Tree::CreateNode(Node *& ipNode, int iData)
{
    if(nullptr == ipNode)
    {
        ipNode = new Node(iData);
    }
}

void Tree::PrintPath(vector<int> vPath, int iStartIdx)
{
    for(int idx=iStartIdx; idx<vPath.size(); idx++)
    {
        cout << vPath[idx]<< " ";
    }
    cout<<endl;
}

// Time Complexity: O(n * h * h)
// where n -> no. of nodes and h -> height of tree
void Tree::PrintKSumPath(Node * ipRoot, int k)      
{
    if(!ipRoot)
        return;

    // Inorder Traversal : DLR (Data-Left-Right)    // O(n)
    _vPath.push_back(ipRoot->_data);
    PrintKSumPath(ipRoot->_pLeft, k);
    PrintKSumPath(ipRoot->_pRight, k);
   
    // Find the sum of paths
    int sum = 0;
    for(int idx = _vPath.size()-1; idx>=0; idx--)   // Max Space Complexity: O(h)
    {
        sum += _vPath[idx];
        if(sum == k)
            PrintPath(_vPath, idx);
    }

    // Delete the node value at each last visit
    _vPath.pop_back();
}

int main()
{
    Tree obj;
    Node * pRoot = nullptr;
    
    // Create Binary Tree
    obj.CreateNode(pRoot, 1);
    obj.CreateNode(pRoot->_pLeft, 3);
    obj.CreateNode(pRoot->_pRight, -1);
    obj.CreateNode(pRoot->_pLeft->_pLeft, 2);
    obj.CreateNode(pRoot->_pLeft->_pRight, 1);
    obj.CreateNode(pRoot->_pRight->_pLeft, 4);
    obj.CreateNode(pRoot->_pRight->_pRight, 5);
    obj.CreateNode(pRoot->_pLeft->_pRight->_pLeft, 1);
    obj.CreateNode(pRoot->_pRight->_pLeft->_pLeft, 1);
    obj.CreateNode(pRoot->_pRight->_pLeft->_pRight, 2);
    obj.CreateNode(pRoot->_pRight->_pRight->_pRight, 6);

    obj.PrintKSumPath(pRoot, 5);

    return 0;
}