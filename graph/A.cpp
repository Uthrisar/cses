#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin >> tc;
    while(tc--){
        int x, y;
        cin >> x >> y;
        cout << min(x,y) << " " <<max(x,y) <<"\n";
    }
}