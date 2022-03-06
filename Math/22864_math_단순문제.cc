#include<iostream>
#include<vector>


using namespace std;

int a,b,c,m;

void soltuion(){
    cin >> a >> b >> c >> m;

    int stress = 0;
    int work =0;
    for(int i=0; i<24; i++){

        if(stress + a <= m){
            stress += a;
            work += b;
        }
        else{
            stress -= c;
            if(stress < 0) stress =0;
        }
    }

    cout << work;
}

int main(){
    soltuion();
}