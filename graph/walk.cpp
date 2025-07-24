#include<bits/stdc++.h>
using namespace std;

const int MAXN = 51;

vector<int> graph[MAXN];

int main(){
    int N,K;
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            int a;
            cin >> a;
            if(a == 1){
                graph[i].push_back(j);
            }
        }
    }
}