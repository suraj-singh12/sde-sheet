#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    // lets use hashSet here
    unordered_map<int, int> mpp;    // store count as value
    vector<vector<int>> ans;
    for(auto x : arr) {
        // x + y = s;   so   s - x = y;
        if(mpp.find(s - x) != mpp.end()) {
            for(int i = 0; i < mpp[s-x]; ++i) {
                vector<int> tmp {min(x, s-x), max(x, s-x)};
                ans.emplace_back(tmp);
            }
        } 
        mpp[x]++;
    }
    sort(ans.begin(), ans.end());
    return ans;
}
