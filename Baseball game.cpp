class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> nums;
        for(int i=0;i<ops.size();i++){
            if(ops[i]=="+"){
                int ans=0;
                ans+=nums.top();
                int store=nums.top();
                nums.pop();
                ans+=nums.top();
                int store2=nums.top();
                nums.push(store);
                nums.push(ans);
            }
            else if(ops[i]=="C"){
                nums.pop();
            }
            else if(ops[i]=="D"){
                int ans=0;
                int val=nums.top();
                ans=2*val;
                nums.push(ans);
            }
            else{
                nums.push(stoi(ops[i]));
            }
        }
        int ans=0;
        while(!nums.empty()){
            ans+=nums.top();
            nums.pop();
        }
        return ans;
    }
};