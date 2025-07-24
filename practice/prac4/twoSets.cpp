#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n%4 == 1 || n%4 == 2){
        cout << "NO\n";
    } else {
        vector<int> v1,v2;

        if(n%4 == 0){
            for(int i = 1; i <= n; i += 4){
                v1.push_back(i);
                v2.push_back(i+1);
                v2.push_back(i+2);
                v1.push_back(i+3);
            }
        }

        if(n%4 == 3){
            v1.push_back(1);
            v1.push_back(2);
            v2.push_back(3);
            for(int i = 4; i <= n; i += 4){
                v1.push_back(i);
                v2.push_back(i+1);
                v2.push_back(i+2);
                v1.push_back(i+3);
            }
        }

        cout << "YES\n";
        cout << v1.size() << "\n";
        for(int i = 0; i < int(v1.size()); i++){
            cout << v1[i] << " ";
        }
        cout <<"\n"<<v2.size()<<"\n";
        for(int i = 0; i < int(v2.size()); i++){
            cout << v2[i] <<" ";
        }
    }
}