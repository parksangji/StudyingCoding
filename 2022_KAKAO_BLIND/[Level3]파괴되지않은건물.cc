#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int N = board.size(),M = board[0].size();
    vector<vector<int>> tmp(N+1,vector<int>(M+1,0));
    for(auto s : skill)
    {
        int type = s[0],r1 = s[1],c1 = s[2], r2 = s[3], c2 = s[4], degree = s[5];
        if(type == 1) degree = -degree;
        
        tmp[r1][c1] += degree;
        tmp[r2+1][c2+1] += degree;
        tmp[r1][c2+1] -= degree;
        tmp[r2+1][c1] -= degree;
    }
    for(int i=0; i<N+1; ++i)
        for(int j=0; j<M; ++j)
            tmp[i][j+1] += tmp[i][j];
    
    for(int j=0; j<M+1; ++j)
        for(int i=0; i<N; ++i)
            tmp[i+1][j] += tmp[i][j];
    
    for(int i=0; i<N ; i++)
        for(int j=0; j<M; j++)
            if(board[i][j] + tmp[i][j] >0) answer++;
    
    return answer;
}