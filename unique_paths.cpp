#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	// Write your code here.
    // this is a permutation problem
    // let matrix be [3][7], 
    // then one possible path is : drrrdrrr
    // permuatations of this are going to be the required answer
    
    int term = m + n - 1;
    double ans = 1;
    for(int i = 1; i < m; ++i) {
        ans *= (term -i) / (double)i;
    }
    return int(round(ans));
}
