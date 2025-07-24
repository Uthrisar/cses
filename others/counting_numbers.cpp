#include<bits/stdc++.h>
using namespace std;

bool solve(string s){
    for(int i = 0; i < s.size()-1; i++){
        if(s[i] == s[i+1]){
            return false;
            break;
        }
    }
    return true;
}

int main(){
    long long a, b;
    cin >> a >> b;
    long long count = 0;
    for(long long i = a; i <= b; i++){
        string stri = to_string(i);
        count += int(solve(stri));
    }
    cout << count << endl;
}