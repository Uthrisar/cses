#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        multiset<int> m;
        int to_rem_pos;
        for(int i = 0; i < k; i++){
            m.insert(nums[i]);
        }
        ans.push_back(*(--m.end()));
        to_rem_pos = 0;
        for(int i = k; i < nums.size(); i++)
            m.insert(nums[i]),
            m.erase(m.find(nums[to_rem_pos])),
            ans.push_back(*(--m.end())),
            to_rem_pos++;

        return ans;
    }
};

int main(){
    Solution s;
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for(auto & e: nums){
        cin >> e;
    }
    vector<int> ans = s.maxSlidingWindow(nums,k);
    for(auto & el : ans){
        cout << el <<" ";
    }
}