#include <bits/stdc++.h> 
#include <vector>

// TC: O(m+n)
bool findTargetInMatrix(vector < vector < int >> & matrix, int m, int n, int target) {
        int i = 0, j = matrix[0].size() -1;
        
        while(i < matrix.size() && target > matrix[i][j])  
            i++;
        if(i < matrix.size()) {
        while(j >=0 && target < matrix[i][j]) 
            j--;
        }
        if(i >= matrix.size() || j < 0) return false;
        if(target == matrix[i][j]) return true;
        return false;
}
