#include <bits/stdc++.h> 
void reverseArr(vector<int> &v, int start, int end) {
    while(start < end) {
        v[start] = v[start] ^ v[end];
        v[end] = v[start] ^ v[end];
        v[start] = v[start] ^ v[end];
        start++;
        end--;
    }
}
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    /*
        approach: 
        from end 
        1. find an elem i.e. a[i] < a[i+1]
        2. find an elme i.e. a[j] > a[i] 
        3. swap (a[i], a[j])
        4. reverse(arr, i+1, n-1)
    */
    if(n <= 1) return permutation;
    
    int indFirst = n - 2;
    while(indFirst >= 0 && permutation[indFirst] > permutation[indFirst+1])
        indFirst--;
    
    if(indFirst > -1) {
        int j = n -1;
        while(permutation[j] <= permutation[indFirst]) j--;
        swap(permutation[j], permutation[indFirst]);
    }
    reverseArr(permutation, indFirst+1, n-1);
    return permutation;
}
