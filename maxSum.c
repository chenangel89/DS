int maxSum(int** grid, int gridSize, int* gridColSize){
    int max_sum = 0;
    for (int i = 1; i <= gridSize - 2; i++) {
        for (int j = 1; j <= gridColSize[i] - 2; j++) {
            int sum = 0;
            // 計算 hourglass 的和
            sum += grid[i-1][j-1] + grid[i-1][j] + grid[i-1][j+1]
                 + grid[i][j]
                 + grid[i+1][j-1] + grid[i+1][j] + grid[i+1][j+1];
            // 更新最大和值
            max_sum = (max_sum > sum) ? max_sum : sum;
        }
    }
    return max_sum;
}
