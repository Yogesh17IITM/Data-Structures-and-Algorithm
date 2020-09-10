/*
Topic : Sorting

Objective: 
    To demonstrate Bubble sort algorithm

Key Topics:
    - Bubble sort
    - swapping variables
*/

#include <iostream>

using namespace std;

void Sort_using_BubbleSort(int iarr[], int iSize);
void swap(int * ipA, int * ipB);
void PrintArray(int iArr[], int iSize);

int main()
{
    int ListOfInts[]{3,56,1,44,54,45};
    
    // sort     
    int nSize = sizeof(ListOfInts)/sizeof(int);
    Sort_using_BubbleSort(ListOfInts, nSize);

    // display
    PrintArray(ListOfInts, nSize);
}

void Sort_using_BubbleSort(int iarr[], int iSize)
{
    for(int idx=0; idx<(iSize-1); idx++)
    {
        bool IsSwapped = false;
        for(int jdx=0; jdx<(iSize-idx-1); jdx++)
        {
            if (iarr[jdx] > iarr[jdx+1])
            {
                // swap the data
                swap(&iarr[jdx], &iarr[jdx+1]);
                IsSwapped = true;
            }            
        }

        if (!IsSwapped)
            break;
    }
}

void swap(int * ipA, int * ipB)
{
    *ipA = *ipA + *ipB;
    *ipB = *ipA - *ipB;
    *ipA = *ipA - *ipB;
}

void PrintArray(int iArr[], int iSize)
{
    for (int i = 0; i < iSize; i++)
    {
        cout<<"val: "<<iArr[i]<<endl;
    }    
}