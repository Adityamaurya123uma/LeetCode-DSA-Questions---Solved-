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