#include <bits/stdc++.h> 
// TC: O((n+m) * log((n+m)))
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int n, int m) {
    // boundary condition1 
    if(m == 0) {
        return arr1;
    } else if(n == 0) {
        // copy arr2 to arr1
        for(int i = 0; i < m; ++i) {
            arr1[i] = arr2[i];
        }
        return arr1;
    }
    
    int gap = int(ceil((n + m) / float(2)));
    
    while(gap > 0) {            // O(log(m+n))
        int i = 0, j = gap;
        while(j < n + m) {        // O(n+m)
            if(j < n) {
                if(arr1[i] > arr1[j]) swap(arr1[i], arr1[j]);
            } else if(i < n && j >= n) {
                int k = j - n;
                if(arr1[i] > arr2[k]) swap(arr1[i], arr2[k]);
            } else {
                int k = i - n, l = j - n;
                if(arr2[k] > arr2[l]) swap(arr2[k], arr2[l]);
            }
            i++; j++;
        }
        if(gap == 1) break;
        gap = int(ceil((gap) / float(2)));
    }
    // copy the sorted array2 into 1
    for(int i = 0; i < m; ++i) {
        arr1[n + i] = arr2[i];
    }
    return arr1;
}
