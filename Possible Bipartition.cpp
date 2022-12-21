class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        // typical Bipartition 
        if(dislikes.size()<1)   return true;
        
        bool b=true;
        unordered_map<int,unordered_set<int>> um;
        unordered_map<int,unordered_set<int>>::iterator umi;
        vector<int> vt(N+1,0);

        // Record Edges 
        for( int i=1; i<=N; i++){
            unordered_set<int> us;
            um.emplace( i, us);
        }
        
        for( int i=0; i<dislikes.size(); i++){
            umi=um.find(dislikes[i][0]);
            if(umi->second.find(dislikes[i][1])==umi->second.end())  umi->second.emplace(dislikes[i][1]);
            umi=um.find(dislikes[i][1]);
            if(umi->second.find(dislikes[i][0])==umi->second.end())  umi->second.emplace(dislikes[i][0]);
        }
        
        // DFS
        for( int i=1; i<=N; i++){
            if(vt[i]==0){// guranteed to visit all connected part 
                vt[i]=1;
                b=dfs( i, vt, um );
            }
            if(!b)  return false;
        }
        
        return b;
    }
    
    bool dfs( int i, vector<int>& vt, unordered_map<int,unordered_set<int>>& um ){
        bool b;
        unordered_map<int,unordered_set<int>>::iterator umi=um.find(i);
        
        for( unordered_set<int>::iterator usi=umi->second.begin(); usi!=umi->second.end(); usi++){
            if(vt[*usi]==0){
                vt[*usi]=vt[i]*-1;
                b=dfs( *usi, vt, um);
                if(!b)  return false;
            }else if(vt[*usi]==vt[i]){
                return false;
            }
        }
        
        return true;
    }
};