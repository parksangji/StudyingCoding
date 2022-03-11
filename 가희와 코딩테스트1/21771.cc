#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;

int r,c;

vector<string> matrix;

void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int rg,cg,rp,cp,cntG=0,cntP=0;
    cin >> r >> c;
    matrix.resize(r);
    cin >> rg >> cg >> rp >> cp;

    for(int i=0; i<r; i++){
        cin >> matrix[i];
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(matrix[i][j] == 'G') cntG++;
            else if(matrix[i][j] == 'P') cntP++;
        }
    }
    if(cntG == (rg * cg) and cntP < (rp * cp)) cout << 1;
    else cout << 0;
}

int main(){
    solution();
    return 0;
}

