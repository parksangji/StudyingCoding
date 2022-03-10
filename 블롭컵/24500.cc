#include<iostream>
#include<vector>

using namespace std;

long long n,k=1;

void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    while(k < n) k = k * 2 + 1;
    if(k == n) cout << 1 << '\n' << k;
    else cout << 2 << '\n' << (k ^ n) << '\n' << n;
}

int main(){
    solution();
    return 0;
}