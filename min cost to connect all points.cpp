You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].
The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, 
where |val| denotes the absolute value of val.
Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.

Example 1:
Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation: 

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:
Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
    
class Solution {
public:
    int getParent(vector<int>& parents, int idx){
        if(parents[idx]==idx){
            return idx;
        }
        parents[idx] = getParent(parents, parents[parents[idx]]);
        return parents[idx];
    }
    int minCostConnectPoints(vector<vector<int>>& points) {   
        int n = points.size();
        vector<int> parents(n);        
        iota(parents.begin(), parents.end(), 0);
        int ans = 0;
        int edges = 0;
        priority_queue<vector<int>> pq;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(i!=j){
                     pq.push({-1*(abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])), i, j});
                }
            }
        }
        
        while(edges!=n-1){    
            vector<int> edge = pq.top();
            int p1 = getParent(parents, edge[1]);
            int p2 = getParent(parents, edge[2]);
            if(p1!=p2) {
                ans += -1*edge[0];
                parents[p1] = p2;
                edges++;
            }
            pq.pop();
        }
        return ans;
    }
};
