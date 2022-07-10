#include <bits/stdc++.h> 

long long merge(vector<int> &nums, vector<int> &tmp, int left, int mid, int right) {
    // do the counting part
    long long inv_cnt = 0;
    int ind = mid +1;
    for(int i = left; i <= mid; ++i) {
        // for every ith count the no of elements in 2nd part of array  
        // such that nums[i] > 2 * nums[j]
        while((ind <= right) && (long long)(nums[i]) > 2ll * (long long)(nums[ind]))
            ind++;
        inv_cnt += (ind - (mid + 1));
    }
    
    // now sort the array
    int i = left, j = mid + 1, k = left;
    while((i <= mid) && (j <= right)) {
        if(nums[i] <= nums[j]) {
            tmp[k++] = nums[i++];
        } else {
            tmp[k++] = nums[j++];
        }
    }
    // if any array was big, it will still have elements remaning, so get them
    while(i <= mid) {
        tmp[k++] = nums[i];
        i++;
    }
    while(j <= right) {
        tmp[k++] = nums[j];
        j++;
    }
    
    // copy this tmp array into the nums (original one)
    for(int i = left; i <= right; ++i) {
        nums[i] = tmp[i];
    }
    return inv_cnt;
}
long long mergeSort(vector<int> &nums, vector<int> &tmp, int left, int right) {
    long long inv_cnt = 0;
    if(left < right) {
        int mid = left + (right - left) / 2;
        inv_cnt += mergeSort(nums, tmp, left, mid);
        inv_cnt += mergeSort(nums, tmp, mid+1, right);
        
        inv_cnt += merge(nums, tmp, left, mid, right);
    }
    return inv_cnt;
}
int reversePairs(vector<int> &arr, int n){
    // using nested for loops ; O(n^2)
    // using merge sort (optimised) : O(nlogn)
    vector<int> tmp(arr.size());
    return mergeSort(arr, tmp, 0, arr.size()-1);
}
