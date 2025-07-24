#include<bits/stdc++.h>
using namespace std;

bool func(int i, int j, string& s){
    if(i == j) return 1;
    if(j = i+1){
        if(s[i] == s[j]) return 1;
        return 0;
    }
    return (func(i+1,j-1,s) || (s[i] == s[j]));
}

int main(){
    string s;
    cin >> s;
}