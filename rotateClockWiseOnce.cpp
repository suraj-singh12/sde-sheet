#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    int row1 = 0, rowN = n -1;    // horizontal limits
    int col1 = 0, colN = m -1;    // vertical limits
    int save1 = 0, save2 = 0;     
    
    while(row1 < rowN && col1 < colN) {
        // row1
        int var1 = mat[row1][colN];
        for(int i = colN; i > col1; --i) {
            mat[row1][i] = mat[row1][i-1];
        }
        
        // rowN
        int var2 = mat[rowN][col1];
        for(int i = col1; i < colN; ++i) {
            mat[rowN][i] = mat[rowN][i+1];
        }
        // col1 
        for(int i = row1; i < rowN; ++i) {
            mat[i][col1] = mat[i+1][col1];
        }
        // colN
        for(int i = rowN; i > row1; --i) {
            mat[i][colN] = mat[i-1][colN];
        }
        mat[row1+1][colN] = var1;
        mat[rowN-1][col1] = var2;
        
        col1++;  colN--;
        row1++;  rowN--;
    }
}
