#include<iostream>
#include<vector>

using namespace std;

int n,d,k,c;

vector<int> arr;
vector<int> sushi(3001,0);

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
void input()
{
    cin >> n >> d >> k >> c;
    arr.resize(n,0);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    for(int i=0; i<k;  i++)
    {
        arr.push_back(arr[i]);
    }
}
void solve()
{
    sushi[c] = 1;
    int tmp = 0,answer;
    for(int i=0; i<k ; i++)
    {
        if(++sushi[arr[i]] == 1) tmp++;
    }
    answer = tmp;

    for(int i=1; i<=n; i++)
    {
        sushi[arr[i-1]]--;
        if(sushi[arr[i-1]] == 0) tmp--;

        sushi[arr[i+k-1]]++;
        if(sushi[arr[i+k-1]]==1) tmp++;

        answer = max(answer,tmp);
    }

    cout << answer + 1;
}

int main()
{
    init();
    input();
    solve();

    return 0;
}