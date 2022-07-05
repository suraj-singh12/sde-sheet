#include <bits/stdc++.h> 

 long long expPow(int x, int n, int m) {
        if(n == 0) return 1;
        if(x == 1) {
            return (x % m);
        }
        long long term = expPow(x, n / 2, m);
        if(n & 1) {     // if n is odd
            // (a * b * c) % m = ( (a % m) * (b % m) ) * (c % m) % m;
            return (((term % m) * (term % m) % m) * (x % m) % m);
        }
        else 
            return ((term % m) * (term % m) % m);
    }
    int modularExponentiation(int x, int n, int m) {
        // Write your code here.   
        long long ans = expPow(x,n,m);
        return ans;
    }
