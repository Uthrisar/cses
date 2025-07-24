#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> v1(n);
    for(int i=0; i<n; i++){
        cin>>v1[i];
    }
    sort(v1.begin(),v1.end());
    long long sum = 1;
    for(int i=0; i<n && v1[i] <= sum; i++){
        sum += v1[i];
    }
    cout<<sum;
}