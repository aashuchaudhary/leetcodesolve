class Solution {
public:
    // Method to count the number of islands in the grid
    int numIslands(vector<vector<char>>& grid) {
        int count = 0; // Initialize island count to zero

        // Loop through each row of the grid
        for(int i = 0; i < grid.size(); i++) {
            // Loop through each column of the current row
            for(int j = 0; j < grid[0].size(); j++) {
                // Check if the current cell is land ('1')
                if(grid[i][j] == '1') {
                    count++; // Found an island, increment the count
                    // Start DFS to mark all connected land cells
                    dfs(grid, i, j);
                }
            }
        }
        return count; // Return the total number of islands found
    }

    // Depth-First Search function to mark connected land cells
    void dfs(vector<vector<char>>& grid, int i, int j) {
        // Check for out-of-bounds conditions
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size())
            return; // If out of bounds, stop the search

        // Check if the current cell is not land
        if(grid[i][j] != '1')
            return; // If not land, stop the search

        // Mark the current cell as visited by changing '1' to '2'
        grid[i][j] = '2';

        // Recursively call DFS for neighboring cells (up, down, left, right)
        dfs(grid, i - 1, j); // Up
        dfs(grid, i + 1, j); // Down
        dfs(grid, i, j + 1); // Right
        dfs(grid, i, j - 1); // Left
    }
};
