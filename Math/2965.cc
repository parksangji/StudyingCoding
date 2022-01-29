// [Bronze3] 캥거루 세마리
//https://jeonggyun.tistory.com/76

#include <iostream>

using namespace std;

void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    cout << ((b-a) > (c-b) ? b- a : c - b) -1; 
}

int main(void)
{
    solve();

    return 0;
}