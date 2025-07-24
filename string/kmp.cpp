#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string pat){
    int n = pat.size();
    vector<int> pi(n, 0);
    int len = 0, i = 1;
    while(i<n){
        if(pat[i] == pat[len]){
            len++;
            pi[i] = len;
            i++;
        } else {
            if(len != 0){
                len = pi[len-1];
            } else {
                pi[i] = 0;
                i++;
            }
        }
    }
    return pi;
}

int main(){
    string text, pat;
    cin>>text>>pat;
    vector<int> pi = LPS(pat);
    int m = text.size(), n = pat.size();
    int i = 0, j = 0, ans = 0;
    while(m-i >= n-j){
        if(text[i] == pat[j]){
            i++; j++;
        }
        if(j == n){
            ans++;
            j = pi[j-1];
        } else if(i < m && text[i] != pat[j]){
            if(j != 0){
                j = pi[j-1];
            } else {
                i++;
            }
        }
    }
    cout<<ans;
}