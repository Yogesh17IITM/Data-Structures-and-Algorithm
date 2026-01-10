/**
 * Merge Sort Algorithm
 *
 * Approach:
 *      - Find the middle index of the array, divide it.
 *      - Recursively continue until it reaches the leaf node
 *      - sort and merge the sub-array
 *
 * Time Complexity:
 *      -Best, Worst, Average Case:
 *          - O(n log n)
 *
 * Space Complexity:
 *      - O(n) - Temporary arrays are used during merging to hold
 *      - Due to this, Mergesort is less memory efficient
 *      - It cannot sort without extra memory allocation
 */

#include <iostream>
#include <vector>

using namespace std;

void sortAndMergeSubArray(int arr[], int iLeftIdx, int iMidIdx, int iRightIdx)
{
    int nLeftSize = iMidIdx - iLeftIdx + 1;
    int nRightSize = iRightIdx - iMidIdx;

    vector<int> vLeft(nLeftSize), vRight(nRightSize);

    // Fill Left and right sub-array
    for (int idx = 0; idx < nLeftSize; idx++)
        vLeft[idx] = arr[iLeftIdx + idx];

    for (int jdx = 0; jdx < nRightSize; jdx++)
        vRight[jdx] = arr[iMidIdx + jdx + 1];

    // Sort the sub-array and merge the subarray
    int idx = 0, jdx = 0, kdx = iLeftIdx;
    while (idx < nLeftSize && jdx < nRightSize)
    {
        if (vLeft[idx] < vRight[jdx])
        {
            arr[kdx++] = vLeft[idx++];
        }
        else
        {
            arr[kdx++] = vRight[jdx++];
        }
    }

    // Check if any elements left out (sub-array size might not be always same)
    while (idx < nLeftSize)
    {
        arr[kdx++] = vLeft[idx++];
    }

    while (jdx < nRightSize)
    {
        arr[kdx++] = vRight[jdx++];
    }
}

void mergeSort(int arr[], int iLeftIdx, int iRightIdx)
{
    if (iLeftIdx >= iRightIdx)
        return;

    int midIdx = iLeftIdx + (iRightIdx - iLeftIdx) / 2;
    mergeSort(arr, iLeftIdx, midIdx);
    mergeSort(arr, midIdx + 1, iRightIdx);

    sortAndMergeSubArray(arr, iLeftIdx, midIdx, iRightIdx);
}

int main()
{
    int arr[] = {34, 566, -6, 0, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    auto printArr = [&arr, &size]()
    {
        cout << "\n Array:\t" << endl;
        for (int idx = 0; idx < size; idx++)
            cout << arr[idx] << "\t";
        cout << endl;
    };

    printArr();

    mergeSort(arr, 0, size - 1);
    printArr();

    return 0;
}
