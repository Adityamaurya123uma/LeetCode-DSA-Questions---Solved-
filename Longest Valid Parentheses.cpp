class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0,right=0,maxlen=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                left++;
            if(s[i]==')')
                right++;
            if(left==right)
                maxlen=max(maxlen,2*left);
		//when we traverse from left to right ,if right becomes more than left then we enter into invalid state
            else if(right>=left){
                left=0;
                right=0;
            }
        }
        left=0,right=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='(')
                left++;
            if(s[i]==')')
                right++;
            if(left==right)
                maxlen=max(maxlen,2*right);
		//when we traverse from right to left ,if left becomes more than right we enter into inavild state
            else if(left>=right){
                left=0;
                right=0;
            }
        }
        return maxlen;
    }
};