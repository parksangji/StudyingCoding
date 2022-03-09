#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n;

vector<int> arr;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >>n;
    arr.resize(n+1,0);
    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }
}

void solution(){

    int answer = 0,left = 1,right = n;

    while(left < right){
        answer = max(answer, min(arr[left],arr[right]) * (right-left-1));
        if(arr[left] < arr[right]) left++;
        else right--;
    }
    
    cout << answer;
}

int main(){
    input();
    solution();
    return 0;
}