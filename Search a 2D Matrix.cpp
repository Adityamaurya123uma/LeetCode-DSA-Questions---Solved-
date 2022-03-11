class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        bool flag = false;
        for(int i=0 ; i<m ; i++){
           int s = 0;
            int e = n-1;
            while(s<=e){
                int mid = s+(e-s)/2;
                if(matrix[i][mid]==target){
                    return true;
                }
                else if(matrix[i][mid]>target){
                    e = mid-1;
                }
                else{
                    s= mid+1;
                }
            // for(int j=0;i<n;i++){
            //     if(matrix[i]==matrix[j]){
            //         return true;
            //     }
            // }
            // }
            }}
        return flag;
        
    }
};