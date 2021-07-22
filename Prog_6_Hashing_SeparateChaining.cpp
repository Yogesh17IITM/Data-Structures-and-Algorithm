/* Demonstration of Hashmap - Separate chainging 

input:
    Arr = {3, 5, 11, 25, 13}

Store values based on Hash Idx:     
    Hash Idx : Val % ArrSize 
    Indices  : 0 1 2 3 4  

Example:
    3%5 = 3, 5%5 = 0, 11%5 = 1

    Idx   Values
     0      5 -> 25 (Collison is prevented here)
     1      11
     2
     3      3 -> 13
     4

Time to insert: O(1) -> Fastest ever than O(logn)
*/ 

#include<iostream>
#include<list>
using namespace std;

class Hash
{
    int _BucketSize;
    list<int> * _pList;
public:
    Hash(int iSize) : _BucketSize(iSize)
    {
        _pList = new list<int>[_BucketSize];
    }

    int HashIndex(int iKey)
    {
        return iKey%_BucketSize;
    }

    void Insert(int iKey)
    {   
        int HashIdx = HashIndex(iKey);
        _pList[HashIdx].push_back(iKey);
    }

    void Delete(int iKey)
    {
        int HashIdx = HashIndex(iKey);
        list<int>::iterator it;
        for(it=_pList[HashIdx].begin(); it!=_pList[HashIdx].end(); it++)
        {
            if(*it == iKey)
                break;
        }

        if(it != _pList[HashIdx].end())
            _pList[HashIdx].erase(it);
    }

    void Display()
    {
        for(int idx=0; idx<_BucketSize; idx++)
        {
            for(auto & iVal : _pList[idx])
                cout<<iVal<<" ";
            cout<<endl;
        }
    }
};

int main()
{
    int Arr[] = {3, 5, 11, 25, 13};
    int nArr = sizeof(Arr)/sizeof(Arr[0]);

    Hash obj(nArr);
    for(int idx=0; idx<nArr; idx++)
        obj.Insert(Arr[idx]);

    // Diplay values in Hash Table
    obj.Display();
    cout<<"-----------"<<endl;

    // Delete a Key and Display values
    obj.Delete(11);
    obj.Display();

    return 0;
}
