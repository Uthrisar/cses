#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> s(n),f(n),v(n);
    for(int i = 0; i < n; i++){
        cin >> s[i];
    }
    for(int i = 0; i < n; i++){
        cin >> f[i];
    }
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }

    vector<int> p(n);

    for(int i = 0; i < n; i++){
        int count = 0;
        for(int j = 0; j < n; i++){
            if(f[j] <= s[i]){
                count++;
            }
        }
        p[i] = count;
    }

    for(int i = 0; i < n; i++){
        cout << p[i] << "\t";
    }
}