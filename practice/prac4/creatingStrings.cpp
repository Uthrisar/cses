#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    sort(s.begin(),s.end());
    vector<string> ans;
    ans.emplace_back(s);
    while(next_permutation(s.begin(),s.end())){
        ans.emplace_back(s);
    }
    cout << ans.size() << endl;
    for(int i = 0; i < int(ans.size()); i++){
        cout << ans[i] << endl;
    }
}