class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int m = matrix.size();
        int n = matrix[0].size();

        // Define boundaries
        int top = 0;
        int bottom = m - 1;
        int left = 0;
        int right = n - 1;

        // Traverse while there is a valid rectangle
        while (top <= bottom && left <= right) {

            // 1️⃣ Move LEFT → RIGHT (top row)
            for (int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            top++;   // top row is done

            // 2️⃣ Move TOP → BOTTOM (right column)
            for (int row = top; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            right--; // right column is done

            // 3️⃣ Move RIGHT → LEFT (bottom row)
            if (top <= bottom) {
                for (int col = right; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
                bottom--; // bottom row is done
            }

            // 4️⃣ Move BOTTOM → TOP (left column)
            if (left <= right) {
                for (int row = bottom; row >= top; row--) {
                    result.push_back(matrix[row][left]);
                }
                left++; // left column is done
            }
        }

        return result;
    }
};
