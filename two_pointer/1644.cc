//[Gold3] 소수의 연속합
// https://www.acmicpc.net/problem/1644

#include<iostream>
#include<vector>

using namespace std;

vector<int> IsPrime,prime;
int n;
void cheakPrime()
{
    for(int i=2; i*i <= n; i++)
    {
        if(IsPrime[i])
        {
            for(int j= i*i; j<= n; j+=i) IsPrime[j] = false;
        }
    }
    for(int i=2; i<= n ;i++)
        if(IsPrime[i]) 
            prime.push_back(i);
}

void twoPoint()
{
    int left = 0 ,right = 0,cnt = 0, sum = 0,answer = 0;
    while(1)
    {
        if(sum >= n) sum -= prime[left++];
        else if(right == prime.size()) break;
        else sum += prime[right++];

        if(sum == n) answer++;
    }
    cout << answer;

}

void solution()
{
    cin >> n;
    IsPrime.resize(n+1,true);
    cheakPrime();
    twoPoint();
}

int main()
{
    solution();
    return 0;
}