//wrong code need to modify it correctly;


#include<bits/stdc++.h>
using namespace std;
vector<int> ans;
int n;

void subset(int idx, vector<int> nums, int curr_sum, int tot_sum){
    if(idx == n+1) return;
    if(2*curr_sum == tot_sum){
        ans = nums;
        return;
    }
    subset(idx+1, nums, curr_sum, tot_sum);
    nums.push_back(idx);
    subset(idx+1, nums, curr_sum+idx, tot_sum);
    nums.pop_back();
}

int main(){
    cin >> n;
    int tot_sum = n*(n+1)/2;
    subset(1,{},0,tot_sum);
    int j = 0;
    vector<int> ans2;
    for(int i = 1; i <= n; i++){
        if(i != ans[j]){
            ans2.push_back(i);
        }else{
            j++;
        }
    }
    cout << ans.size() << endl;
    for(auto v: ans){
        cout << v << " ";
    }
    cout << endl << ans2.size() << endl;
    for(auto v: ans2){
        cout << v << " ";
    }
}