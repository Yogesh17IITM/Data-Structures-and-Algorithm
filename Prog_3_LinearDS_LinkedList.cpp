/* Demonstration of Linked List (Linear Data Structure) */

#include <iostream>
using namespace std;

struct Node
{
    int _data;
    Node * _pNext;
    Node(int idata) : _data(idata), _pNext(nullptr) {};
};

class LinkedList
{   
    Node * _pHead;
    Node * _pTail;
    
public: 
    LinkedList() : _pHead(nullptr), _pTail(nullptr) {}
 
    void CreateNode(int iData)
    {
        if(nullptr == _pHead)
        {
            _pHead = _pTail = new Node(iData);
        }
        else
        {
            // Create a new node and update Tail node.
            _pTail->_pNext = new Node(iData);
            _pTail = _pTail->_pNext;
        }
    }

    void PrintList()
    {
        Node * pNode = _pHead;
        while(pNode != nullptr)
        {
            cout<<pNode->_data;
            if(pNode->_pNext)
                cout<<"->";

            pNode = pNode->_pNext;
        }
        cout<<endl;
    }
};

int main()
{
    LinkedList NodeList;

    int Arr[] = {3, 45, 1, 32};
    int nArr = sizeof(Arr)/sizeof(Arr[0]);

    for(int idx=0; idx<nArr; idx++)
        NodeList.CreateNode(Arr[idx]);
    
    NodeList.PrintList();    
    return 0;
}