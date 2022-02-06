// [Gold5] 두 수의 합
// https://www.acmicpc.net/problem/9024
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int answer,n,k;
vector<int> arr;

void init()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void input()
{
    cin >> n >> k;
    arr.clear();
    arr.resize(n,0);
    for(int i=0; i<n ;i++) cin >> arr[i];
}
void solve()
{
    int min = INT32_MAX,start= 0 ,end = arr.size()-1;
    answer =0;
    sort(arr.begin(),arr.end());
    while(start< end)
    {
        int mid = (arr[start] + arr[end]);
        int compare = abs(k - mid);

        if(mid == k)
            start ++,end --;
        else if(mid < k)
            start++;
        else
            end --;

        if(compare < min)
        {
            min = compare;
            answer =1;
        }
        else if(compare == min)
        {
            answer++;
        }
    }
}

void solution()
{
    int t;
    cin >> t;
    while(t--)
    {
        input();
        solve();
        cout << answer << '\n';
    }
}

int main()
{
    solution();
    return 0;
}