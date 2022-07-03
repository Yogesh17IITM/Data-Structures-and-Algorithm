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

Note:
    'Balanced BST' -> (Height_left_subtree) ~ (Height_Right_subtree) <= 1

Approach:
    1) Convert BST into array (sorted)
    2) Check if any triplet exists based on two pointer approach
*/

#include <iostream>
#include <vector>
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
    vector<int> sortedVec;

public:
    void InsertNode(Node *&ioNode, int iData);
    void CreateListUsingInOrder(const Node *pNode);
    bool IsTripletExists(int iSum);
};

bool BST::IsTripletExists(int iSum)
{
    // vec.size() - 2 --> here '-2' because of 2 pointer approach (left and right)
    for (int idx = 0; idx < sortedVec.size() - 2; idx++)
    {
        int leftIdx = idx + 1;               // Pointer to advance from left
        int rightIdx = sortedVec.size() - 1; // Pointer to advance from right

        while (leftIdx < rightIdx)
        {
            int CurrSum = sortedVec[idx] + sortedVec[leftIdx] + sortedVec[rightIdx];
            if (CurrSum == iSum)
            {
                return true; // triplet found
            }
            else
            {
                if (CurrSum < iSum)
                    leftIdx++; // Increment the left idx to increase the CurrSum towards 'iSum'
                else
                    rightIdx--; // Decement the right Idx to decrease the CurrSum towards 'iSum'
            }
        }
    }
    return false; // triplet not found
}

void BST::InsertNode(Node *&ioNode, int iData)
{
    if (nullptr == ioNode)
        ioNode = new Node(iData);
    else
    {
        if (iData < ioNode->_data)
            InsertNode(ioNode->_pLeft, iData);
        else
            InsertNode(ioNode->_pRight, iData);
    }
}

void BST::CreateListUsingInOrder(const Node *pNode)
{
    // Inorder traversal approach: (L)eft, (D)ata, (R)ight -> [LDR]
    if (pNode)
    {
        CreateListUsingInOrder(pNode->_pLeft);
        sortedVec.push_back(pNode->_data);
        CreateListUsingInOrder(pNode->_pRight);
    }
}

int main()
{
    int arr[] = {6, -13, 14, -8, 13, 15, 7};
    int nArr = sizeof(arr) / sizeof(arr[0]);

    BST bst;
    Node *pRoot = nullptr;
    for (int idx = 0; idx < nArr; idx++)
        bst.InsertNode(pRoot, arr[idx]);

    if (pRoot)
        bst.CreateListUsingInOrder(pRoot);

    int sumForTriplet = 0;
    if (bst.IsTripletExists(sumForTriplet))
        cout << "Triplet Exists" << endl;
    else
        cout << "Triplet doesn't Exists" << endl;

    return 0;
}
