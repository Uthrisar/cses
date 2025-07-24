#include<bits/stdc++.h>
using namespace std;

int func(int i){
    if(i == 0) return 0;

    int s = i;
    int gr_digit = 0;
    while(s > 0) {
        int rem = s % 10;
        gr_digit = max(gr_digit, rem);
        s /= 10;
    }
    return func(i - gr_digit) + 1;

}

int main(){
    int num;
    cin >> num;
    cout << func(num);
}