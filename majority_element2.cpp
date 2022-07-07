#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &arr)
{
    // if we think logically, then there can be at max 2 elements
    // present > N / 3 times in the array
    // so using the extended moore's voting algo
    
    int e1 = -1, e2 = -1, c1 = 0, c2 = 0;
    for(auto x : arr) {
        if(e1 == x) c1++;
        else if(e2 == x) c2++;
        else if(c1 == 0) {
            e1 = x;   c1++;
        } else if(c2 == 0) {
            e2 = x;   c2++;
        } else {
            c1--; c2--;
        }
    }
    // now we have those element1, element2; check whether they are present > N / 3 time
    vector<int> ans;
    c1 = 0, c2 = 0;
    for(auto x : arr) {
        if(e1 == x) c1++;
        else if(e2 == x) c2++;
    }
    if(c1 > arr.size() / 3) ans.emplace_back(e1);
    if(c2 > arr.size() / 3) ans.emplace_back(e2);
    return ans;
}
