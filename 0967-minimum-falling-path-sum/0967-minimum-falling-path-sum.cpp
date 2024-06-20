class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& matrix) {
            int n = matrix.size() ; // as n x n matrix 

            int dp[n][n] ; // as n = 5
            int res = INT_MAX ; 

            for( int i = 0 ; i< n ; i++ ) {
                //intialize the first row of dp array same as matrix first row 
                dp[0][i] = matrix[0][i] ;
            }

            int down , diagonal_left , diagonal_right ; 

            for( int row = 1 ; row < n ; row++ ) {
                for( int col = 0 ; col < n ; col++ ) {

                    down = dp[row - 1][col] ;
                    diagonal_left = (col > 0) ? dp[row - 1][col - 1] : INT_MAX ;
                    diagonal_right = (col < n - 1) ? dp[row - 1][col + 1] : INT_MAX ;

                    dp[ row ][ col ] = matrix[ row ][ col ] + min(down , min( diagonal_left , diagonal_right )) ; 
                }
            } 

            for( int last = 0 ; last < n ; last++ ) {
                res = min ( res , dp[ n-1 ][ last ] ) ; 
            }

            return res ; 




            
        }
};