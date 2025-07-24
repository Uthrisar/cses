#include<bits/stdc++.h>
using namespace std;

int main(){
    int maxX = 1e6+1;
    vector<int> x(maxX,0);
    vector<int> numDivisorsCount(maxX,0);
    for(int i = 1; i < maxX; i++){
        for(int j = i; j < maxX; j += i){
            if(j % i == 0){
                numDivisorsCount[j]++;
            }
        }
    }
    int n; cin >> n;
    while(n--){
        int x; cin >> x;
        cout << numDivisorsCount[x] << "\n";
    }
}