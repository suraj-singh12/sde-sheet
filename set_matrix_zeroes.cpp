#include <bits/stdc++.h> 
using namespace std;
void setZeros(vector<vector<int>> &matrix)
{
	//keep col1 as marker
    bool flag = true;
    int n = matrix.size(), m = matrix[0].size();
    for(int i = 0; i < n; ++i) {
        if(matrix[i][0] == 0) flag = false;
        for(int j = 1; j < m; ++j) {
            if(matrix[i][j] == 0) 
                matrix[i][0] = matrix[0][j] = 0;
        }
    }
    
    // traverse in reverse way
    for(int i = n -1; i >= 0; i--) {
        for(int j = m -1; j >= 1; j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
        if(flag == false) 
            matrix[i][0] = 0;
    }
}
