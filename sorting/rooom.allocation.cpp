#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>> v(n, vector<int>(3));
    for(int i=0; i<n; i++){
        cin>>v[i][0]>>v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(),v.end());
    set<pair<int,int>> st;
    vector<int> ans(n);
    int room_id = 1;
    for(int i=0; i<n; i++){
        auto it = st.upper_bound({v[i][0],-1});
        if(it != st.end()){
            it--;
            st.insert({v[i][1], it->second});
            ans[v[i][2]] = it->second;
            st.erase(it);
        } else {
            st.insert({v[i][1], room_id});
            ans[v[i][2]] = room_id;
            room_id++;
        }
    }
    cout<<room_id<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}