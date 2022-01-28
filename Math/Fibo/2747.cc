// [Bronze3] 피보나치 수
// https://www.acmicpc.net/problem/2747

#include<iostream>
#include<vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n+1,0);
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;
    
    for(int i=3; i<=n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[n];
}

int main()
{
    solve();
    return 0;
}