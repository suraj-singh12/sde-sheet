#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    // better way; tracking index not required
    int mini = prices[0], maxi = 0;
    for(int i = 1; i < prices.size(); ++i) {
        mini = min(mini, prices[i]);
        maxi = max(prices[i] - mini, maxi);
    }
    return maxi;
}

/*
#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int minIndx = 0, maxIndx = 0;
    int mini = prices[0], maxi = prices[0];
    int maxProfit = 0;
    for(int i = 1; i < prices.size(); ++i) {
        if(prices[i] < mini) {
            mini = prices[i];
            minIndx = i;
        }
        if(prices[i] > maxi) {
            maxi = prices[i];
            maxIndx = i;
        }
        if(minIndx < maxIndx) {
            maxProfit = max(maxi - mini, maxProfit);
        } else {
            maxi = prices[i];
            maxIndx = i;
        }
    }
    return maxProfit;
}
*/
