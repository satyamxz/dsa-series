class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int startRow = 0;
        int endRow = matrix.size() - 1;

        int startCol = 0;
        int endCol = matrix[0].size() - 1;

        while (startRow <= endRow && startCol <= endCol) {

            // 1. Left → Right
            for (int col = startCol; col <= endCol; col++) {
                ans.push_back(matrix[startRow][col]);
            }
            startRow++;

            // 2. Top → Bottom
            for (int row = startRow; row <= endRow; row++) {
                ans.push_back(matrix[row][endCol]);
            }
            endCol--;

            // 3. Right → Left
            if (startRow <= endRow) {
                for (int col = endCol; col >= startCol; col--) {
                    ans.push_back(matrix[endRow][col]);
                }
                endRow--;
            }

            // 4. Bottom → Top
            if (startCol <= endCol) {
                for (int row = endRow; row >= startRow; row--) {
                    ans.push_back(matrix[row][startCol]);
                }
                startCol++;
            }
        }

        return ans;
    }
};