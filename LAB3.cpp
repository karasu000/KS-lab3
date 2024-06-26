﻿#include <bits/stdc++.h>
using namespace std;
 
// Function which modifies the array
void KSwapMaximum(int arr[], int n, int k)
{
    for (int i = 0; i < n - 1 && k > 0; ++i) {
 
        // Here, indexPosition is set where we
        // want to put the current largest integer
        int indexPosition = i;
        for (int j = i + 1; j < n; ++j) {
 
            // If we exceed the Max swaps
            // then break the loop
            if (k <= j - i)
                break;
 
            // Find the maximum value from i+1 to
            // max k or n which will replace
            // arr[indexPosition]
            if (arr[j] > arr[indexPosition])
                indexPosition = j;
        }
 
        // Swap the elements from Maximum indexPosition
        // we found till now to the ith index
        for (int j = indexPosition; j > i; --j)
            swap(arr[j], arr[j - 1]);
 
        // Updates k after swapping indexPosition-i
        // elements
        k -= indexPosition - i;
    }
}
 
// Driver code
int main()
{
    for (int i = 0; i < 1099999; i++) { 
        int arr[100];
        for (int i = 0; i < 100; i++) {
            arr[i] = rand() % 100 + 1; 
        }
        int n = sizeof(arr) / sizeof(arr[0]);
        int k = 3;
        KSwapMaximum(arr, n, k);
    }
        cout << "OK";
    return 0;
}