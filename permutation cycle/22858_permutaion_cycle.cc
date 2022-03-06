#include<iostream>
#include<vector>
#include<iostream>
#include<map>

using namespace std;

int n,k;

vector<int> s,d,p;

void solution(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> k;

    s.resize(n+1);
    d.resize(n+1);
    p.resize(n+1);

    for(int i=1; i<=n; i++) cin >> s[i];
    for(int i=1; i<=n; i++) cin >> d[i];

    for(int i=0; i<k; i++){

        for(int j=1; j<= n ;j++){
            p[d[j]] = s[j];
        }
        s = p;
    }

    for(int i=1; i<= n ; i++){
        cout << s[i] << ' ';
    }
}

int main(){
    solution();
    return 0;
}