import java.util.* ;
import java.io.*; 
import java.util.ArrayList;

public class Solution {

	public static int LongestSubsetWithZeroSum(ArrayList<Integer> arr) {
        // optimal approach
        // use running sum concept, & HashMap 
        
        HashMap<Integer, Integer> hmap = new HashMap<Integer, Integer>();
        int runningSum = 0, maxLen = 0;
        
        for(int i = 0; i < arr.size(); ++i) {
            runningSum += arr.get(i);
            // normal part
            if(runningSum == 0) {
                maxLen = Math.max(maxLen, i + 1);
            }
            // main part of algo
            // if current runningSum is already in hashMap, that means we are 
            // visiting it again, i.e. sum from its previous occurence to current occurence index -1, was 0 
            if(hmap.get(runningSum) != null) {
                // don't use containsValue() function, it takes O(n),
                // but .get() takes O(1) 
                maxLen = Math.max(maxLen, i - hmap.get(runningSum));
            }
            else hmap.put(runningSum, i);
            // we don't insert the new occurence of previously existing sum,
            // because that ain't of any use, only first occurence is of use
            // to us, because we get max length of items making 0 with sumup
        }
        return maxLen;
	}
}
