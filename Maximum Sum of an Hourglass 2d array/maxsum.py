class Solution:
    def maxSum(self, grid: List[List[int]]) -> int:
        max_sum = -999999 # some negative value since we don't have INT_MIN

        rows = len(grid) # get the rows aka length of the array
        columns = len(grid[0]) # get the length of the columns which is how many elements in single row

        for i in range(0,rows-2): # loop through rows
            for j in range(0, columns-2): # loop through columns 
                SUM = (grid[i][j] + grid[i][j+1] + grid[i][j+2]) + (grid[i+1][j+1])+ (grid[i+2][j] + grid[i+2][j+1] + grid[i+2][j+2]) # get the summation of hourglass shape
                if ( SUM> max_sum): # compare it to the max_sum that behaves as INT_MIN
                    max_sum = SUM # if its bigger set it as the new max_sum

        return max_sum # return the value
