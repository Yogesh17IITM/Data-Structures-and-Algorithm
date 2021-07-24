/*
    Implement Quick Sort Algorithm - Divide and Conquer

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

int PartitionIdx(int Arr[], int iLowIdx, int iHighIdx)
{
    int pivot = Arr[iHighIdx];
    int idx = iLowIdx-1;

    for(int jdx=iLowIdx; jdx<iHighIdx; jdx++)
    {
        if(Arr[jdx] <= pivot)
        {
            idx++;
            swap(Arr[idx], Arr[jdx]);
        }
    }
    swap(Arr[idx+1], Arr[iHighIdx]);
    return (idx+1);
}

void QuickSort(int Arr[], int iLowIdx, int iHighIdx)
{
    if(iLowIdx < iHighIdx)
    {
        int iPartitionIdx = PartitionIdx(Arr, iLowIdx, iHighIdx);
        QuickSort(Arr, iLowIdx, iPartitionIdx-1);
        QuickSort(Arr, iPartitionIdx+1, iHighIdx);
    }
}

void PrintArr(int Arr[], int nSize)
{    
    for(int idx=0; idx<nSize; idx++)
        cout<<Arr[idx]<<" ";
    cout<<endl;
}

int main()
{
    int Arr[] = {43, 45, -1, 6, 7};
    int nArr = sizeof(Arr)/sizeof(Arr[0]);

    cout<<"Before Sort: ";
    PrintArr(Arr, nArr);

    QuickSort(Arr, 0, nArr-1);

    cout<<"After Sort: ";
    PrintArr(Arr, nArr);

    return 0;
}