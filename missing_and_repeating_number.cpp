#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here 
    int XOR = 0;
    // xor 1 to n
    for(int i = 1; i <= n; ++i) {
        XOR ^= i;
    }
    // xor all arr[i]
    for(int i = 0; i < n; ++i) {
        XOR ^= arr[i];
    }

    // got x ^ y
    // now find the rightmost set bit
    int bit = 0;
    while(!(XOR & (1<<bit))) bit++;

    // make two baskets
    int xor1 = 0, xor2 = 0, mask = (1<<bit);
    for(int i = 0; i < n; ++i) {
        if(arr[i] & mask) { xor1 ^= arr[i];  }
        else {  xor2 ^= arr[i];  }
    }

    // now xor the baskets accordingly with 1->n
    for(int i = 1; i <= n; ++i) {
        if(i & mask) {
            xor1 ^= i;
        } else {  xor2 ^= i;  }
    }

    // now xor1, and xor2 contains the numbers
    bool flag = false;
    for(int i = 0; i < n; ++i) {
        if(xor1 == arr[i])  {
            flag = true;
            break;
        }
    }
    // if flag is true then xor1 is present in array
    if(flag) 
        return pair<int, int> {xor2, xor1};
    
    return pair<int, int> {xor1, xor2};
}
