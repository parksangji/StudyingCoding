#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> a, vector<int> b)
{
    for(int i=11; i>= 0; i--)
        if(a[i] != b[i]) return a[i] > b[i];
    return false;
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(12,-1);
    vector<int> comb(n+10);
    
    fill(comb.begin()+n,comb.end(),1);
    
    do{
        vector<int> tmp;
        int before = -1;
        for(int i=0; i<n+10; i++)
        {
            if(comb[i])
            {
                tmp.push_back(i - before - 1);
                before = i;
            }
        }
        tmp.push_back(n+10-before-1);
        
        int score = 0;
        
        for(int i=0; i<= 10; i++)
        {
            if(tmp[i] > info[i])  score += (10 - i);
            else if(info[i] != 0) score -= (10 - i);
        }
        if(score <= 0) continue;
        tmp.push_back(score);
        if(cmp(tmp,answer)) answer = tmp;
    }while(next_permutation(comb.begin(),comb.end()));
    if(answer[0] == -1) return {-1};
    answer.pop_back();
    return answer;
}