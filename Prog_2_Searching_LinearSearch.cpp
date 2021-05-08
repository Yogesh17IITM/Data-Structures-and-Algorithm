/*
Topic : Searching [Linear Search]

Objective: 
    To demonstrate how to do basic search using linear search algorithm

Key Topics:
    - Linear Search [focus here]
    - Bubble sort
    - Data structures and algorithms - a short intro

Discussions:
    - Best case: key is found at first item
    - Worst case: key is not found
    - Search time increased with increase of items in the array.
    - If we are unaware of data, linear search is the only option.
    - To speed up the search, data needs to be sorted (increasing/decreasing order if number or alphabetical if char/string)
    - For custom data types (class/structure), we have to decide "by which parameter" we are going to sort    

DATA STRUCTURES AND ALGORITHMS:
    - Data structures: The way how do we store datas
    - Algorithms: Deals with how do we access those datas stored in the data structures. 
    
Note: Performace or complexity of an algorithm is determined by "Big 'O' Notation"
*/

#include<iostream>
using namespace std;

int Locate(int iArr[], size_t iSize, int iKey);     // For Search  (Linear Search)
void SortArray(int arr[], size_t size);             // For Sort (bubble sort)
void swap(int * ipA, int *ipB);
void DisplayArray(int arr[], size_t size);

int main()
{    
    int uniqueArrList[]{9,3,4,5,13,44,534,45};  // Unique array list (no repeated values)
    int keysToSearch[]{44, 55};                 // Keys to search in the array   

    size_t sizeArr = sizeof(uniqueArrList)/sizeof(int);
    size_t nKeys = sizeof(keysToSearch)/sizeof(int);

    SortArray(uniqueArrList, sizeArr);
    DisplayArray(uniqueArrList, sizeArr);

    for (size_t i = 0; i < nKeys; i++)
    {
        if (-1 != Locate(uniqueArrList, sizeArr, keysToSearch[i]))
            cout << "The given Key: " << keysToSearch[i] << " found at index: " << Locate(uniqueArrList, sizeArr, keysToSearch[i]) << endl;
        else
            cout << "The given Key: " << keysToSearch[i] << " is NOT found!" <<endl;
    }
    return 0;
}

// Search for key in the given array
int Locate(int iArr[], size_t iSize, int iKey)
{
    int oKeyFoundAt = -1;
    for(size_t i=0; i<iSize; i++)
    {
        if  (iKey == iArr[i])
            oKeyFoundAt = i;
    }
    return oKeyFoundAt;
}

void SortArray(int iArr[], size_t iSize)
{
    for (size_t i = 0; i < iSize-1; i++)
    {
        bool IsValueSwapped = false;
        for(size_t j = 0; j < iSize-1-i; j++)
        {
            if (iArr[j] > iArr[j+1]) 
            {
                swap(&iArr[j], &iArr[j+1]);
                IsValueSwapped = true;
            }
        }

        if (!IsValueSwapped)
            break;
    }    
}

void swap(int * ipA, int *ipB)
{
    if (ipA && ipB)
    {
        int temp = *ipA + *ipB;
        *ipA = temp - *ipA;
        *ipB = temp - *ipA;
    }    
}

void DisplayArray(int iArr[], size_t iSize)
{
    for (size_t i = 0; i < iSize; i++)
    {
        cout << iArr[i]<<" ";
    }    
    cout<<endl;
}