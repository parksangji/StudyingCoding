// https://www.acmicpc.net/problem/1339
// next_permutation

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>

using namespace std;

vector<string> word;
string alphabet;
int n;

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n;
    word.resize(n);
    for(int i=0; i<n; i++){
        cin >> word[i];
        for(int j=0; j<word[i].length();j++){
            alphabet.push_back(word[i][j]);
        }
    }
}

void solution(){
    //알파벳 중복 제거
    sort(alphabet.begin(),alphabet.end());
    alphabet.erase(unique(alphabet.begin(),alphabet.end()),alphabet.end());
    
    vector<int> value(alphabet.size());
    for(int i=0;i<alphabet.size();i++) value[i] = 9-i;
    sort(value.begin(),value.end());
    // 출력 값
    int answer = 0;
    char alpha[256];

    do
    {
        int sum = 0;
        for(int i=0; i<alphabet.size(); i++){
            alpha[alphabet[i]] = value[i];
        }
        for(int i=0; i<word.size();i++){
            int tmp = 0;
            for(int j=0; j<word[i].length();j++){
                tmp = tmp * 10 + alpha[word[i][j]];
            }
            sum += tmp;
        }
        answer = max(sum,answer);
    } while (next_permutation(value.begin(),value.end()));

    cout << answer;
    
}

int main(){
    input();
    solution();

    return 0;
}
