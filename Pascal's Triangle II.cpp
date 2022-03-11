class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> temp(rowIndex+1,1);

        for(int i=0;i<rowIndex;i++){        
            for(int j=i;j>0;j--){
                temp[j] = temp[j] + temp[j-1];
            }
        }    
        
        return temp;
    }
};