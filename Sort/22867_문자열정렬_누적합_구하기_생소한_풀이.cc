#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int n;
vector<pair<string,int>> v;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;
    for(int i=0; i<n; i++){
        string in,out;
        cin >> in >> out;
        v.push_back({in,1});
        v.push_back({out,-1});
    }
}

void solution(){

    int sum = 0,ans = 0;
    sort(v.begin(),v.end());
    for(int i=0; i<n; i++){
        sum += v[i].second;
        ans = max(sum,ans);
    }    
    cout << ans;
}

int main(){
    input();
    solution();

    return 0;
}