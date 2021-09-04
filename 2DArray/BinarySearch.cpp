/*
Write an efficient algorithm that searches for a target value in an m x n integer matrix. The matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/

// Binary search in sorted matrix
//explanation :  https://youtu.be/9KSU-SxoIEg
/*
Description - Given an n x n matrix and a number x, find the position of x in the matrix. In the given matrix, every row and column is sorted in increasing order.
Solution : Idea is to solve problem with row and column elimination reducing the search space. Before jumping at the solution, lets try to understand the concept that is actually allowing us to solve the problem in linear time.
Let’s start our search from the top-right corner of the array. There are three possible cases.
The number we are searching for is greater than the current number. This will ensure, that all the elements in the current row is smaller than the number we are searching for as we are already at the right-most element and the row is sorted. Thus, the entire row gets eliminated and we continue our search on the next row. Here elimination means we won’t search on that row again.
The number we are searching for is smaller than the current number. This will ensure, that all the elements in the current column is greater than the number we are searching for. Thus, the entire column gets eliminated and we continue our search on the previous column i.e. the column at the immediate left.
The number we are searching for is equal to the current number. This will end our search.
*/
#include<bits/stdc++.h>

using namespace std;

// Time : O(n+m) , space : O(1)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size()-1;

    while (row < matrix.size() && col >= 0) {
        
        if (target == matrix[row][col])
            return true;
        
        target > matrix[row][col] ? row++ : col--;
    }
    
    return false;
}
/*
pair<int,int> searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0, col = matrix[0].size()-1;
    while (row < matrix.size() && col >= 0) {
        
        if (target == matrix[row][col])
            return make_pair(row,col);
        
        target > matrix[row][col] ? row++ : col--;
    }
    return make_pair(-1,-1);
}
*/
int main()
{

return 0;
}