// https://www.acmicpc.net/problem/1655
// [Gold2] 가운데를 말해요
#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> arr;
int n;

void init(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input(){
    cin >> n;
    arr.resize(n,0);
    for(int i=0; i<n; i++) 
        cin >> arr[i];
}

void solution(){

    priority_queue<int,vector<int>,greater<int>> minqueue;
    priority_queue<int> maxqueue;

    for(int i=0; i<n; i++){
        int value = arr[i];

        if(maxqueue.size() == minqueue.size()) maxqueue.push(value);
        else minqueue.push(value);

        if(!maxqueue.empty() and !minqueue.empty() and (maxqueue.top() > minqueue.top())){
 
            int maxValue = maxqueue.top();
            int minValue = minqueue.top();

            maxqueue.pop(),minqueue.pop();

            maxqueue.push(minValue);
            minqueue.push(maxValue);
        }
        cout << maxqueue.top() << '\n';
    }
}

int main(){
    init();
    input();
    solution();

    return 0;
}

