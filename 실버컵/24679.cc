#include<iostream>
#include<vector>

using namespace std;
int t,even=0,odd=0;


void dfs(int x,int y, int z,int depth){

    int cnt = 0;
    if(x == 0) cnt ++;
    if(y == 0) cnt ++;
    if(z == 0) cnt ++;
    if(cnt >=2) {
        if(depth % 2 == 0) even++;
        else odd++;
        return;
    }
    if(x > 0 and y > 0){
        dfs(x-1,y-1,z,depth+1);
    }
    if (x > 0 and z > 0){
        dfs(x-1,y,z-1,depth+1);
    }
    if (y > 0 and z > 0){
        dfs(x,y-1,z-1,depth+1);
    }
}

void solution(){

    ios_base::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin >> t;
    vector<int> v(3);

    for(int i=0,x,y,z; i<t; i++){
        cin >> x >> y >> z;
        even = 0,odd =0;
        dfs(x,y,z,0);
        cout << x << ' ' << y  << ' ' << z  << " : ";
        cout << even << ' ' << odd << '\n';
    }
}

int main(){
    solution();
    return 0;
}