#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    sort(intervals.begin(), intervals.end());
    int n = intervals.size();
    vector<vector<int>> ans;
    for(int i = 0; i < n; ++i) {
        bool flag = false;
        int startPoint = intervals[i][0];
        int endPoint = intervals[i][1];
        while(i+1 < n && endPoint >= intervals[i+1][0]) {
            i++;
            endPoint = max(intervals[i][1], endPoint);
        }

        ans.push_back({startPoint, endPoint});
    }
    return ans;
}
