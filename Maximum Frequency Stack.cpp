class FreqStack {
public:
    unordered_map<int,stack<int>>mp1;
    unordered_map<int,int>mpf;
    int mf=0;
    FreqStack() {
        
    }
    
    void push(int val) {
        if(mpf.find(val)==mpf.end()){
            mpf[val]=1;
        }else{
            mpf[val]++;
        }
        mf=max(mf,mpf[val]);
        mp1[mpf[val]].push(val);
    }
    
    int pop() {
        int ans=mp1[mf].top();
        mp1[mf].pop();
        mpf[ans]--;
        if(mp1[mf].empty()){
            mf--;
        }
        return ans;
    }
};

