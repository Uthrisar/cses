#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<pair<long long,long long>> points(n+1);
    for(int i = 1; i <= n; i++){
        int x, y;
        cin >> x >> y;
        points[i].first = x;
        points[i].second = y;
    }
    long long area = 0;
    for(int i = 1; i <= n-1; i++){
        area += (points[i].first*points[i+1].second-points[i+1].first*points[i].second);
    }
    area += points[n].first*points[1].second-points[1].first*points[n].second;
    cout << abs(area) << endl;
}