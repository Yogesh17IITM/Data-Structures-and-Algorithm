/*
    Implement Quick Sort Algorithm - Divide and Conquer

    Approach:
        - Pick the last element (Elem in MaxIdx) as Pivot
        - Find the exact sorted Index (Pivot Index) position of the Pivot Element by
          keeping all the elements less than pivot to the left side (idx < pivot Index) while
          the rest of the elements on the right side
        - Note: 
          While finding the pivot index, the other elements will not be sorted.

    Best/Average Case: O(nLogn) 
    Worst Case: O(n*n)
*/

#include<iostream>
using namespace std;

void swap(int & a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int getPartitionIdx(int Arr[], int iLowIdx, int iHighIdx)
{
    int &pivotElem = Arr[iHighIdx]; // alias of Arr[iHighIdx]
    int pivotIdx = iLowIdx-1;

    for(int jdx=iLowIdx; jdx<iHighIdx; jdx++)
    {
        if(Arr[jdx] <= pivotElem)
        {
            pivotIdx++;
            swap(Arr[pivotIdx], Arr[jdx]);
        }
    }
    pivotIdx++;
    swap(Arr[pivotIdx], pivotElem);
    return pivotIdx;
}

void QuickSort(int Arr[], int iLowIdx, int iHighIdx)
{
    if(iLowIdx < iHighIdx)
    {
        // Get the Partition Index
        int iPartitionIdx = getPartitionIdx(Arr, iLowIdx, iHighIdx);
        
        QuickSort(Arr, iLowIdx, iPartitionIdx-1);
        QuickSort(Arr, iPartitionIdx+1, iHighIdx);
    }
}

void PrintArr(int Arr[], int nSize)
{    
    for(int idx=0; idx<nSize; idx++)
        cout<<Arr[idx]<<"\t";
    cout<<endl;
}

int main()
{
    int Arr[] = {43, 45, -1, 6, 7, 0};
    int nArr = sizeof(Arr)/sizeof(Arr[0]);

    cout<<"\nBefore Sort:\n";
    PrintArr(Arr, nArr);

    QuickSort(Arr, 0, nArr-1);

    cout<<"\nAfter Sort:\n";
    PrintArr(Arr, nArr);

    return 0;
}