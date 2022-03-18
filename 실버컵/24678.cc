#include<iostream>
#include<vector>

using namespace std;
/*
void dfs(int x,int y, int z,int depth){

    int cnt = 0;
    if(x == 0) cnt ++;
    if(y == 0) cnt ++;
    if(z == 0) cnt ++;

    if(cnt >=2) {
        if(depth % 2 == 0) R++;
        else B++;
        return;
    }
    if(x > 0 and y > 0){
        dfs(x-1,y-1,z+1,depth+1);
    }
    else if (x > 0 and z > 0){
        dfs(x-1,y+1,z-1,depth+1);
    }
    else if (y > 0 and z > 0){
        dfs(x+1,y-1,z-1,depth+1);
    }
}*/

void solution(){

    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    int t,even=0,odd=0;
    cin >> t;
    vector<int> v(3);

    for(int i=0; i<t; i++){
        cin >> v[0] >> v[1] >> v[2];
        even = 0,odd =0;
        for(int i=0; i<3; i++){
            if(v[i] % 2 == 0) even++;
            else odd++;
        }
        if(even == 3 or even == 2) cout << "R" << '\n';
        else cout << "B" << '\n';
    }
}

int main(){
    solution();
    return 0;
}
