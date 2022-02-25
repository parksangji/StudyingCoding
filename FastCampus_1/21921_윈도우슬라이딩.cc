// https://www.acmicpc.net/problem/21921

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n,x;
bool flag = false;

vector<int> arr(250001);

void input(){
    cin >> n >> x;
    int sum = 0;
    for(int i=1,input; i<=n ;i++) 
    {
        cin >> input;
        sum += input;
        arr[i] += sum;
    }
}

void solution(){
    int answer = arr[x];
    int cnt = 0;
    for(int i=x ; i<=n; i++){
        int compare = arr[i] - arr[i-x];
        if(answer < compare){
            answer = compare;
            cnt = 1;
        }
        else if(answer == compare){
            cnt ++;
        }
    }

    if(answer == 0) cout << "SAD";
    else cout << answer << '\n' << cnt;
}

int main(){
    input();
    solution();

    return 0;
}