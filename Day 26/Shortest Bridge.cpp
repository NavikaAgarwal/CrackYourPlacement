class Solution {
public:
   int n, m;
    int Q[10000];  
    int head = 0;
    int tail = 0; 
    void dfs(vector <vector <int>> &a, int x, int y) {
        if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] == 1) {
            a[x][y] = 2;
            Q[tail++] = x * m + y;
            dfs(a, x + 1, y);
            dfs(a, x - 1, y);
            dfs(a, x, y + 1);
            dfs(a, x, y - 1);
        }
    }
    int bfs(vector <vector <int>> &a) {
        int d[5] = {0, 1, 0, -1, 0}; 
        while(head != tail){
            int zz = Q[head++]; 
            int xx = zz / m, yy = zz % m;  
            for (int k = 0; k < 4; k++) {
                int x = xx + d[k], y = yy + d[k + 1];
                if (x < 0 || y < 0 || x == n || y == n || a[x][y] > 1) continue;  
             if (a[x][y] == 1) return a[xx][yy] - 2; 
               
                a[x][y] = a[xx][yy] + 1;  
                Q[tail++] = x * m + y;    
            }
        } 
        return -1;
    }
    int shortestBridge(vector<vector<int>>& a) {
        ios_base::sync_with_stdio(0);
        cin.tie(NULL);
        n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 1) {
                    dfs(a, i, j);
                    return bfs(a);
                }
            }
        }
        return -1;
    }
};
