/*
    Find number of swaps required to get a sorted array
    using bubble sort
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Swap(int &iA, int &iB)
{
    int temp = iB;
    iB = iA;
    iA = temp;
}

int FindNoOfSwaps(int arr[], int n)
{
    int nSwaps = 0;
    bool bIsSwapped = false;

    for (int idx = 0; idx < n - 1; idx++) // n-1 => no. of pairs
    {
        for (int jdx = 0; jdx < n - idx - 1; jdx++) // n-idx-1 => since, for every iteration, last digit gets sorted
        {
            if (arr[jdx] > arr[jdx + 1])
            {
                swap(arr[jdx], arr[jdx + 1]);
                nSwaps++;
                bIsSwapped = true;
            }
        }

        // If no swapping happens for full iteration, break the loop here itself
        if (!bIsSwapped)
            break;
    }

    return nSwaps;
}

void Swap(int arr[], int iSourceIdx, int iTargetIdx)
{
    int temp = arr[iSourceIdx];
    arr[iSourceIdx] = arr[iTargetIdx];
    arr[iTargetIdx] = temp;
}

int FindMinNoOfSwaps(int arr[], int n)
{
    int nMinSwaps = 0;
    vector<int> tempArr;
    for (int idx = 0; idx < n; idx++)
        tempArr.push_back(arr[idx]);

    sort(tempArr.begin(), tempArr.end());

    // Lambda Expr.
    auto IndexOf = [&](int iElemVal) -> int
    {
        int oIndex = -1;
        for (int idx = 0; idx < n; idx++)
        {
            if (arr[idx] == iElemVal)
            {
                oIndex = idx;
                break;
            }
        }
        return oIndex;
    }; //

    /*
        While iterating over the array, check the current element,
        and if not in the correct place, replace that element with the
        index of the element which should have come in this place.
    */
    for (int idx = 0; idx < n; idx++)
    {
        if (arr[idx] != tempArr[idx])
        {
            Swap(arr, idx, IndexOf(tempArr[idx]));
            nMinSwaps++;
        }
    }
    return nMinSwaps;
}

int main()
{
    int arr1[] = {4, 3, 2, 1};
    int nArr1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << FindNoOfSwaps(arr1, nArr1) << endl;

    int arr2[] = {4, 3, 2, 1};
    int nArr2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << FindMinNoOfSwaps(arr2, nArr2) << endl;
    return 0;
}