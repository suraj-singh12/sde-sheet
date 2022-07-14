import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution {
	public static int subarraysXor(ArrayList<Integer> arr, int k) {
        // read the modified function prototype, let X = k instead (for simplicy); and x has no relation to this X , these are different.
        
        // do two things: keep a hashMap -> element: count
        // and if runningXor == k origcnt++;
        // if(runningXor ^ k) is in map, origcnt += map[current ^ k];
        // we doing this becuase x ^ k = runningXor; if we can find how many number of times such x subset exists, we automatically get the no of subsets with k xor
        // so x ^ k = runningXor => runningXor ^ k = x; now if you find such an x, in hashMap, add its count (which will be equal to no of its corresponding subarrays with xor k)
        if(arr.size() < 1) return 0;
        
        HashMap<Integer, Integer> mpp = new HashMap<>();
        int runningXor = 0;
        int totalCnt = 0;
        for(int i = 0; i < arr.size(); ++i) {
            runningXor ^= arr.get(i);
            if(runningXor == k) totalCnt++;
            
            // main part of algo (checking for x in map)
            if(mpp.get(runningXor ^ k) != null) {
                totalCnt += mpp.get(runningXor ^ k);
            }
            // update map 
            if(mpp.get(runningXor) != null) 
                mpp.put(runningXor, mpp.get(runningXor) + 1);
            else mpp.put(runningXor, 1);
        }
        return totalCnt;
	}
}
