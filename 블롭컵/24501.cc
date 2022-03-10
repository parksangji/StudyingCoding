#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int n,m;

vector<string> arr;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    arr.resize(n);
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
}


 

void solution(){
    vector<vector<long long>> E,S,M;
    E.resize(n,vector<long long>(m));
    S.resize(n,vector<long long>(m));
    M.resize(n,vector<long long>(m));

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            long long e1 = 0,e2 = 0,e3 = 0,s1 = 0,s2 = 0,s3 = 0,m1 = 0,m2 =0 ,m3= 0;
            if(i){
                e1 = E[i-1][j];
                s1 = S[i-1][j];
                m1 = M[i-1][j];
            }
            if(j){
                e2 = E[i][j-1];
                s2 = S[i][j-1];
                m2 = M[i][j-1];
            }
            if(i and j){
                e3 = E[i-1][j-1];
                s3 = S[i-1][j-1];
                m3 = M[i-1][j-1];
            }
            E[i][j] = e1 + e2 - e3;
            S[i][j] = s1 + s2 - s3;
            M[i][j] = m1 + m2 - m3;

            if(arr[i][j] == 'E'){
                E[i][j]++;
            }
            else if(arr[i][j] == 'S'){
                S[i][j] += E[i][j];
            }
            else if(arr[i][j] == 'M'){
                M[i][j] += S[i][j];
            }
            E[i][j] %= 1000000007, S[i][j] %= 1000000007 , M[i][j] %= 1000000007;
            if(E[i][j] < 0) E[i][j] += 1000000007;
            if(S[i][j] < 0) S[i][j] += 1000000007;
            if(M[i][j] < 0) M[i][j] += 1000000007;
        }
    }

    cout << M[n-1][m-1] ;
}


int main(){
    input();
    solution();

    return 0;
}