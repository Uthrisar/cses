#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N), B(M+1);
    for(int i = 0; i < N; i++){
        cin >> A[i];
    }
    for(int i = 1; i <= M; i++){
        cin >> B[i];
    }
    for(int i = 1; i <= M; i++){
        int C = 0;
        int hand = A[B[i]];
        A[B[i]] = 0;
        while(hand > 0){
            C++;
            A[(B[i]+C)%N]++;
            hand--;
        }
    }
    for(int i = 0; i < N; i++){
        cout << A[i] << " ";
    }
}