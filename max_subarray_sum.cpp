#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    if(n == 0) return 0;
    
    long long sum = arr[0], maxSum = 0;
    for(int i = 1; i < n; ++i) {
        if(sum > 0) 
            sum += arr[i];
        else 
            sum = arr[i];
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}
