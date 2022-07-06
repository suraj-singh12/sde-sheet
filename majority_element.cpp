#include <bits/stdc++.h> 
int findMajorityElement(int arr[], int n) {
    // optimized : O(n): using Boyer Moore's Voting Algo
    // intution: the element present > N/2 times can only be one
	int e = arr[0], cnt = 1;
    for(int i = 0; i < n; ++i) {
        if(cnt == 0) {
            e = arr[i];
            cnt++;
        }
        else if(arr[i] == e) cnt++;
        else cnt--;
    }
    // now ensure if e is for sure present > n/2 times
    cnt = 0;
    for(int i = 0; i < n; ++i) {
        if(arr[i] == e) cnt++;
    }
    if(cnt > int(floor(n / 2.0))) return e;
    return -1;        // if e is present < n/2 times, that means no majority elem is there
}
