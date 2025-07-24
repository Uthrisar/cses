#include<bits/stdc++.h>
using namespace std;

int n, m;
char arr[1001][1001];
bool vis[1001][1001];

bool check(int x, int y){
    if(x < 1 || x > n || y < 0 || y > m)
    return false;
    if(arr[x][y] == '#')
    return false;
    if(vis[x][y] == true)
    return false;
    return true;
}

void dfs(int x, int y) {
    vis[x][y] = true;

    if(check(x-1, y)) dfs(x-1, y);
    if(check(x, y-1)) dfs(x, y-1);
    if(check(x+1, y)) dfs(x+1, y);
    if(check(x, y+1)) dfs(x, y+1);
}


int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(vis[i][j] == false && arr[i][j] == '.'){
                dfs(i, j);
                ans++;
            }
        }
    }
    cout << ans ;
}