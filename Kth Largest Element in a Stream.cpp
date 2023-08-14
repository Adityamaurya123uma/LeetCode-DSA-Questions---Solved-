class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int size;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size){
            pq.pop();
        }
        
        return pq.top();
    }
};


////

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
       priority_queue<int>pq;
        
        for(auto i:nums){
            pq.push(i);
        }
        
        while(k!=1)
        {
            pq.pop();
            k--;
        }        
        return pq.top();
    }
};
