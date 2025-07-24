#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e3+5;
int col[MAXN];
int dist[MAXN];
vector<pair<int,int>> graph[MAXN];

int dijkstra(int src, int dest){
	fill(dist,dist+MAXN,INT_MAX);
	set<pair<int,int>> st;
	st.insert({0,src});
	while(st.size() > 0){
		auto pr = *st.begin();
		int u = pr.second;
		int dist_u = pr.first;
		st.erase(st.begin());
		for(auto child : graph[u]){
			int v = child.first;
			int wt = child.second;
			if(dist_u+wt < dist[v]){
				dist[v] = dist_u+wt;
				st.insert({dist[v],v});
			}
		}
	}
	return dist[dest];
}

int main() {
	int N,M;
	cin>>N>>M;
	for(int i=1; i<=M; i++){
		int u,v,wt;
		cin>>u>>v>>wt;
		graph[u].push_back({v,wt});
		graph[v].push_back({u,wt});
	}
	for(int i=1; i<=N; i++){
		cin>>col[i];
	}
	cout << dijkstra(1,N);
}