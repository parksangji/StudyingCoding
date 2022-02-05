//[Silver2] 좌표 압축
// https://www.acmicpc.net/problem/18870

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;
vector<int> arr;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input(){
    cin >> n;
    arr.resize(n,0);
    for(int i=0; i<n; i++) cin >> arr[i];
}

void solve(){
    vector<int> tmp(arr);
    sort(tmp.begin(),tmp.end());
    tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
    for(int i=0; i<n; i++)
    {
        cout << lower_bound(tmp.begin(),tmp.end(),arr[i]) - tmp.begin() << " ";
    }
}

int main()
{
    init();
    input();
    solve();
}