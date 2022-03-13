#include<iostream>
#include<vector>

using namespace std;

int n,sum = 0,notsum;

void solution(){
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    
    cin >> n;

    vector<int> arr;
    arr.resize(n+1,0);
    //콘텐츠 흥미도
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    notsum = sum;
    //my view에 등록 여부 : 등록 1 , 미등록 0
    for(int i=0,my; i<n; i++){
        cin >> my;

        if(my){
            notsum -= arr[i];
        }
        else continue;
    }

    cout << sum << '\n' << notsum;
}

int main(){
    solution();
    return 0;
}