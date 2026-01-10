/**
 * Stack Vs Queue
 *
 * Stack: LIFO (Last In First Out)
 *      Example:
 *          Class - Object Life Cycle. Consider a inherited class.
 *          During creation, the parent object constructed first, then the child ones
 *          During deletion, the order is reverse.
 *
 * Queue: FIFO (First In First Out)
 *      Example:
 *          - Queue in ticket counter.
 *          - Browser cache clearing mechanism. If cache limit exceeded, the older ones will be
 *            deleted first
 */

#include <iostream>
using namespace std;

template <typename T>
struct Node
{
    T _data;
    Node *_pNext = nullptr;
    Node *_pPrev = nullptr;
    Node(const T iData) : _data(iData) {};
};

template <typename T>
class LinkedList
{
protected:
    Node<T> *_pHead = nullptr;
    Node<T> *_pTail = nullptr;
    size_t _size = 0;

    void deleteNode(Node<T> *pNode)
    {
        if (!pNode)
            return;

        // case 1: Node is head
        if (pNode == _pHead)
        {
            _pHead = pNode->_pNext;
            if (_pHead)
                _pHead->_pPrev = nullptr;
        }
        // case 2: Node is tail
        else if (pNode == _pTail)
        {
            _pTail = pNode->_pPrev;
            if (_pTail)
                _pTail->_pNext = nullptr;
        }
        else
        {
            if(pNode->_pPrev)
                pNode->_pPrev->_pNext = pNode->_pNext;
            
            if(pNode->_pNext)
                pNode->_pNext->_pPrev = pNode->_pPrev;
        }

        delete pNode;
        _size--;
    }

public:
    void push(T iElem)
    {
        if (!_pHead)
        {
            _pHead = new Node<T>(iElem);
            _pTail = _pHead;
        }
        else
        {
            _pTail->_pNext = new Node<T>(iElem);
            Node<T> *pPrev = _pTail;
            _pTail = _pTail->_pNext;
            _pTail->_pPrev = pPrev;
        }
        _size++;
    }

    size_t size() { return _size; }
    bool isEmpty() { return (_size == 0); }

    void print()
    {
        Node<T> *pCurr = _pHead;
        while (pCurr != nullptr)
        {
            cout << pCurr->_data << "\t";
            pCurr = pCurr->_pNext;
        }
        cout << endl;
    }

    virtual void pop() = 0;
};

template <typename T>
class Stack : public LinkedList<T>
{
public:
    void pop() override
    {
        // LIFO - remove the latest element
        this->deleteNode(this->_pTail);
    }
};

template <typename T>
class Queue : public LinkedList<T>
{
public:
    void pop() override
    {
        // FIFO - remove the oldest element
        this->deleteNode(this->_pHead);
    }
};

int main()
{
    int arr[] = {4, 5, 2, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    Stack<int> stk;
    for (int idx = 0; idx < size; idx++)
    stk.push(arr[idx]);
    
    cout << "\nStack: "<<"size: "<<stk.size()<< endl;
    stk.print();
    stk.pop();
    stk.print();

    Queue<int> q;
    for (int idx = 0; idx < size; idx++)
        q.push(arr[idx]);

    cout << "\nQueue: "<<"size: "<<q.size()<< endl;
    q.print();
    q.pop();
    q.print();
}
