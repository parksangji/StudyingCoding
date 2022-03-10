#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n;

vector<int> arr,tmp;

void input(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin >> n;

    arr.resize(n,0);

    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }
}

void solution(){
    input();
    tmp.push_back(arr[0]);
    tmp.push_back(arr[n-1]);
    for(int i=1;i<n-1; i++){
        tmp.push_back(arr[i] + min(arr[i-1],arr[i+1]));
    }

    cout << *max_element(tmp.begin(),tmp.end());
}

int main(){
    solution();
    return 0;
}