#include <bits/stdc++.h> 
vector<vector<long long int>> printPascal(int n) 
{
    vector<vector<long long>> ans;
    ans.emplace_back(vector<long long> {1});
    if(n == 1) return ans;
    
    ans.push_back(vector<long long> {1, 1});
    if(n == 2) return ans;
    
    for(int i = 3; i <= n; ++i) {
        int prevIndx = i -2;
        int curIndx = i -1;
        
        vector<long long> v(i);
        ans.push_back(v);
        ans[curIndx][0] = ans[curIndx][i-1] = 1;
        int k = 1;
        for(int start = 1; start <= prevIndx; ++start) {
            ans[curIndx][k++] = ans[prevIndx][start-1] + ans[prevIndx][start];
        }
    }
    return ans;
}
