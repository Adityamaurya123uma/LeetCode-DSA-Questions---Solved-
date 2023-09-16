Medium
Topics
Companies
Hint
You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where 
heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you
hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, 
and you wish to find a route that requires the minimum effort.

A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.
Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than 
route [1,3,5,3,5].
Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.

class Solution {
public:
    struct node {
        int r, c, v;
    };
    
    struct compare {
      bool operator() (node o1, node o2) {
          return o1.v > o2.v;
      }  
    };
    
    int min_val[100][100];
    
    int f_abs(int a) {
        if(a < 0) return -a;
        return a;
    }
    
    int move[4][2] = {{1, 0}, {-1, 0}, {0,1}, {0,-1}};        
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int N = heights.size();
        int M = heights[0].size();
        for (int i=0; i<N; i++) {
            for (int j=0; j<M; j++) {
                min_val[i][j] = 1000000;
            }
        }
        
        // Dijkstra to find shortest value
        priority_queue<node, vector<node>, compare> pq;
        min_val[0][0] = 0;
        pq.push({0, 0, 0});
        node cur;
        int nr, nc, v;
        while(!pq.empty()) {
            cur = pq.top(); pq.pop();
            if(cur.v != min_val[cur.r][cur.c]) continue;
            if(cur.r == N-1 && cur.c == M-1) break;
            for (int i=0; i<4; i++) {
                nr = cur.r + move[i][0];
                nc = cur.c + move[i][1];
                if(nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
                v = f_abs(heights[cur.r][cur.c] - heights[nr][nc]);
                if(v < cur.v) v = cur.v; // get maximum val comparing to previous val
                if(v < min_val[nr][nc]) {
                    min_val[nr][nc] = v;
                    pq.push({nr, nc, v});
                }
            }
        }
        
        return min_val[N-1][M-1];
    }
};
