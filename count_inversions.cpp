#include <bits/stdc++.h> 

long long merge(long long *arr, long long *tmp, int left, int mid, int right) {
    long long inv_cnt = 0;
    int i = left, j = mid +1, k = left;
    while((i <= mid) && (j <= right)) {
        if(arr[i] <= arr[j]) {
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
            // count all the inversions possible
            inv_cnt += (mid -i + 1);
        }
    }

    while(i <= mid) {
        tmp[k++] = arr[i++];
    }
    while(j <= right) {
        tmp[k++] = arr[j++];
    }
    for(int i = left; i <= right; ++i) {
        arr[i] = tmp[i];
    }
    return inv_cnt;
}

long long mergeSort(long long *arr, long long *tmp, int left, int right)  
{
    long long inv_cnt = 0;
    if(right > left) {
        int mid = left + (right - left)/2;
        inv_cnt += mergeSort(arr, tmp, left, mid);
        inv_cnt += mergeSort(arr, tmp, mid +1, right);

        inv_cnt += merge(arr, tmp, left, mid, right);
    }
    return inv_cnt;
}

long long getInversions(long long *arr, int n){
    long long tmp[n];
    return mergeSort(arr, tmp, 0, n-1);
}
