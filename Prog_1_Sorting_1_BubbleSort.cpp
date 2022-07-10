/*
Topic : Sorting

Objective:
    To demonstrate Bubble sort algorithm

Key Topics:
    - Bubble sort [Efficient way]
    - swapping variables
*/

#include <iostream>

using namespace std;

void Sort_using_BubbleSort(int iarr[], int iSize);
void swap(int *ipA, int *ipB);
void PrintArray(int iArr[], int iSize);

int main()
{
    int ListOfInts[]{3, 56, 1, 44, 54, 45};

    // sort
    int nSize = sizeof(ListOfInts) / sizeof(int);
    Sort_using_BubbleSort(ListOfInts, nSize);

    // display
    PrintArray(ListOfInts, nSize);
}

void Sort_using_BubbleSort(int iarr[], int iSize)
{
    // Iterate over No. of Pairs
    // Here No. of pairs = (iSize - 1)
    for (int idx = 0; idx < (iSize - 1); idx++)
    {
        // Flag to check if there is any swapping happened [to increase efficiency]
        bool IsSwapped = false;
        for (int jdx = 0; jdx < (iSize - idx - 1); jdx++)
        {
            if (iarr[jdx] > iarr[jdx + 1])
            {
                // swap the data
                swap(&iarr[jdx], &iarr[jdx + 1]);
                IsSwapped = true;
            }
        }

        // If no swapping happened for one full iteration, then it is Sorted
        // Hence, break the loop
        if (!IsSwapped)
            break;
    }
}

void swap(int *ipA, int *ipB)
{
    // Swapping without using any extra variable
    if (ipA && ipB)
    {
        *ipA = *ipA + *ipB; // a = a+b
        *ipB = *ipA - *ipB; // b = a-b  // Now 'b' will contain 'a' value
        *ipA = *ipA - *ipB; // a = a-b  // Now 'a' will contain 'b' value
    }
}

void PrintArray(int iArr[], int iSize)
{
    for (int i = 0; i < iSize; i++)
    {
        cout << "val: " << iArr[i] << endl;
    }
}