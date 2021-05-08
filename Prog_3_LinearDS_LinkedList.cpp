/* Demonstration of Linked List (Linear Data Structure) */

#include <iostream>
using namespace std;

class Node
{    
public:    
    int _data;
    Node * _pNext;
    Node(int idata) : _data(idata) {_pNext = NULL;};
};

class LinkedList
{   
    public: 
    Node * _phead = NULL;
    
    void add(int idata)
    {
        if (NULL == _phead)      // if node is empty
        {
            _phead = new Node(idata);            
        }
        else    // if node is not empty
        {
            Node * pNewNode = new Node(idata);
            // adding to the front;
            pNewNode->_pNext = _phead;
            _phead = pNewNode;
        }
    }    
};

int main()
{
    LinkedList * pMyList = new LinkedList();
    pMyList->add(1);
    pMyList->add(45);
    cout << pMyList->_phead->_data<<endl;
    cout << pMyList->_phead->_pNext->_data<<endl;
    return 0;
}