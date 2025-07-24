#include<bits/stdc++.h>
#define ff first
#define ss second
using namespace std;

int n, m;

vector<string> grid(1000);

vector<pair<int,int>> movements = {{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int i, int j){
    return i >= 0 && j >= 0 && i < n && j < m && grid[i][j] == '.';
}

bool isBoundary(int i, int j){
    return (i == 0 || j == 0 || i == n-1 || j == m-1) && grid[i][j] == '.';
}

char direct(pair<int,int> p1, pair<int,int> p2){
    if(p1.ff == p2.ff){
        if(p1.ss > p2.ss){
            return 'L';
        } else {
            return 'R';
        }
    } else {
        if(p1.ff > p2.ff){
            return 'U';
        } else {
            return 'D';
        }
    }
}

void bfs(){
    queue<pair<int,int>> q;
    vector<vector<bool>> vis(n,vector<bool>(m,false));
    vector<vector<pair<int,int>>> par(n,vector<pair<int,int>>(m,{-1,-1}));
    vector<pair<int,int>> dest;
    int ai, aj;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == 'M'){
                q.push({i,j});
                vis[i][j] = 1;
                par[i][j] = {i,j};
            } else if(grid[i][j] == 'A'){
                q.push({i,j});
            }
            if(isBoundary(i,j)){
                dest.push_back({i,j});
            }
        }
    }
    q.push(make_pair(ai,aj));

    while(!q.empty()){
        pair<int,int> v = q.front();
        int vx = v.ff;
        int vy = v.ss;
        q.pop();
        for(auto &move : movements){
            int nx = move.ff+vx;
            int ny = move.ss+vy;
            if(!isValid(nx,ny) || vis[nx][ny]) continue;
            q.push({nx,ny});
            vis[nx][ny] = 1;
            par[nx][ny] = {vx,vy};
        }
    }

    vector<pair<int,int>> ans;
    bool isTrue = 0;
    for(auto &point : dest){
        int dx = point.ff;
        int dy = point.ss;
        vector<pair<int,int>> temp;
        while(par[dx][dy] != make_pair(dx,dy)){
            temp.push_back({dx,dy});
            int px = par[dx][dy].ff;
            int py = par[dx][dy].ss;
            dx = px;
            dy = py;
        }
        temp.push_back({dx,dy});
        if(grid[dx][dy] == 'A'){
            isTrue = 1;
            ans = temp;
            break;
        }
    }
    if(isTrue){
        cout << "YES" << endl;
        cout << ans.size()-1 << endl;
        reverse(ans.begin(),ans.end());
        string s = "";
        for(int i = 1; i < int(ans.size()); i++){
            s += direct(ans[i-1],ans[i]);
        }
        cout << s;
    } else {
        cout << "NO";
    }
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >>grid[i];
    }
    bfs();
}
