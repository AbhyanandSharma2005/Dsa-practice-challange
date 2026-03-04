class Solution {
    public int numSpecial(int[][] mat) {
        int m = mat.length;
        int n = mat[0].length;
        int res = 0;

        for( int i = 0; i < m; i++ ) {
            for( int j = 0; j < n; j++ ) {
                boolean flag = true;
                if( mat[i][j] == 1 ) {

                    for( int k = 0; k < m; k++ ) {
                        if( k != i && mat[k][j] != 0 ) {
                            flag = false;
                            break;
                        }
                    }
                    for( int l = 0; l < n; l++ ) {
                        if( l != j && mat[i][l] != 0 ) {
                            flag = false;
                            break;
                        }
                    }

                    if( flag ) {
                        res += 1;
                    }
                    break;
                }
            }
        }
        return res;
    }
}