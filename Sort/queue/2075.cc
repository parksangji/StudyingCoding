// [Gold5] N번째 큰 수
// https://www.acmicpc.net/problem/2075

#include<iostream>
#include<queue>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n,input;
    cin >> n;
    priority_queue<long long,vector<long long>,greater<long long>> pq;

    for(int i=0 ;i <n ;i++)
        for(int j=0; j<n; j++)
        {
            cin >> input;
            pq.push(input);
            if(pq.size() > n)
                pq.pop();
        }
    cout << pq.top();
}

int main()
{
    init();
    solve();
    return 0;
}