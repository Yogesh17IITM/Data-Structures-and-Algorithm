/* This program demonstrates the following:
1) Reverse a linked list 
2) Delete a node from the linked list

Input: Head of following linked list 
        1->2->3->4->NULL 
    
Output: Linked list should be changed to, 
        4->3->2->1->NULL
*/

#include<iostream>
using namespace std;

struct Node 
{
    int _data;
    Node * _pNext;
    Node(int iData) : _data(iData), _pNext(nullptr){}
};

class LinkedList
{
    Node * _pHead, *_pTail;
public:  
    LinkedList() : _pHead(nullptr), _pTail(nullptr){}
    
    void CreateNode(Node *& opNode, int iData)
    {
        if(nullptr == opNode)
            _pHead = _pTail = new Node(iData);
        else
        {
            _pTail->_pNext = new Node(iData);
            _pTail = _pTail->_pNext;
        }
        opNode = _pTail;
    }
    
    // Time Complexity : O(n)
    // space complexity: O(1)
    void ReverseLinkedList()
    {
        Node * prev = nullptr;
        Node * next = nullptr;
        
        _pTail = _pHead;
        Node * pTemp = _pHead;
        while(pTemp != nullptr)
        {
            next = pTemp->_pNext;            
            pTemp->_pNext = prev;
            prev = pTemp;
            pTemp = next;                
        }
        _pHead = prev;
    }
    
    void DeleteNode(int iKey)
    {
        if(_pHead->_data == iKey)
        {
            Node * pTemp = _pHead;
            _pHead = _pHead->_pNext;
            delete pTemp;            
            return;
        }
        
        Node * pTemp = _pHead;
        while(pTemp->_pNext != _pTail)
        {
            if(iKey == pTemp->_pNext->_data)
            {
                Node * NodeToDelete = pTemp->_pNext;
                pTemp->_pNext = pTemp->_pNext->_pNext;
                delete NodeToDelete;
                return;
            }
            pTemp = pTemp->_pNext;
        }
        
        if(_pTail->_data == iKey)
        {
            delete _pTail;
            _pTail = pTemp;
            _pTail->_pNext = nullptr;
            return;
        }
    }
    
    void PrintList()
    {
        Node * pTemp = _pHead;
        while(pTemp != nullptr) 
        {
            cout<<pTemp->_data<<" ";
            pTemp = pTemp->_pNext;
        }
        cout<<endl;
    }
};

int main()
{
    Node * pNode = nullptr;
    
    LinkedList obj;
    obj.CreateNode(pNode, 1);
    obj.CreateNode(pNode, 2);
    obj.CreateNode(pNode, 3);
    obj.CreateNode(pNode, 4);
    
    obj.ReverseLinkedList();
    obj.PrintList();
    
    obj.DeleteNode(1);
    obj.PrintList();
    
    return 0;
}
