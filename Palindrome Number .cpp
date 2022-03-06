class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0){
            return false;
        }
        
        long  num = x;
        long reversedNum=0;
        while (x != 0) {
        long remainder = x % 10;
        reversedNum = reversedNum * 10 + remainder;
        x /= 10;
      }
        if (num == reversedNum) {
        return true;
      }
      else {
        return false;
      }
    }   
    
};