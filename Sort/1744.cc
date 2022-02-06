//[Glod4] 수 묶기
//acmicpc.net/problem/1744
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void solve()
{
    int n,answer =0;
    cin >> n;
    vector<int> possitive,nagative;
    for(int i=0,input; i<n; i++) 
    {
        cin >> input;
        if(input > 1) possitive.push_back(input);
        else if(input <= 0) nagative.push_back(input);
        else if(input == 1) answer++;
        else continue;
    }
    sort(possitive.rbegin(),possitive.rend());
    sort(nagative.begin(),nagative.end());

    for(int i=0; i<possitive.size(); i+=2)
    {
        if(i < possitive.size()-1) answer += (possitive[i] * possitive[i+1]);
        else answer += possitive[i];
    }
    for(int i=0; i<nagative.size(); i+=2)
    {
        if(i < nagative.size()-1) answer += (nagative[i] * nagative[i+1]);
        else answer += nagative[i];
    }
    cout << answer;
}

int main()
{
    init();
    solve();

    return 0;
}