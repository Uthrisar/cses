#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin>>a[i];
    }
    stack<int> st;
    vector<int> ans(n, 0);
    for(int i=0; i<n; i++){
        while(!st.empty() && a[st.top()-1] > a[i]){
            st.pop();
        }
        if(!st.empty() && a[st.top()-1] < a[i]){
            ans[i] = st.top();
        }
        st.push(i+1);
    }
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
}