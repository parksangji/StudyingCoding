#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,k,sum = 0;

vector<int> arr,tmp;


void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> n >> k;
    arr.resize(n+k,0);
    tmp.resize(n,0);
    for(int i=0,input; i<n ;i++){
        cin >> tmp[i];
        sum += tmp[i];
        arr[i] = sum;
    }
    for(int i=n,j = 0; i< n+k; i++){
        sum += tmp[j++];
        arr[i] = sum;
    }
}


void solution(){

    int answer = 0;
    for(int i=k; i<arr.size(); i++){
        answer = max(arr[i] - arr[i-k],answer);
    }
    cout << answer;
}

int main(){
    input();
    solution();

     return 0;
}