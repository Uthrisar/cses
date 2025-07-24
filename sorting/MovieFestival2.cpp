#include <bits/stdc++.h>
using namespace std;

struct Movie {
    int start, end;
};

bool cmp(const Movie &a, const Movie &b) {
    return a.end < b.end;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<Movie> movies(n);
    for (int i = 0; i < n; i++) {
        cin >> movies[i].start >> movies[i].end;
    }
    sort(movies.begin(), movies.end(), cmp);
    multiset<int> clubMembers;
    for(int i = 0; i < k; i++) {
        clubMembers.insert(0);
    }
    int ans = 0;
    for(const auto &movie : movies) {
        auto it = clubMembers.upper_bound(movie.start);
        if(it != clubMembers.begin()){
            it--;
            clubMembers.erase(it);
            clubMembers.insert(movie.end);
            ans++;
        }
    }
    cout<<ans;
}
