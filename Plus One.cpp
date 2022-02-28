class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int index = digits.size()-1;
        
        while(index>=0){
            if(digits[index] == 9){
                digits[index]=0;
            }else{
                digits[index]++;
                return digits;
            }
            index--;
        }
        
        digits.insert(digits.begin(),1);
        
        return digits;
        
    }
};