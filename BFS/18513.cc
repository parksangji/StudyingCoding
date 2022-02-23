// [GOLD5] 샘터
// https://www.acmicpc.net/problem/18513

#include<iostream>
#include<vector>
#include<queue>
#include<set>
#include<unordered_set>

using namespace std;
int n,k;
unordered_set<long long> s;
queue<long long> q;

int dx[] = {-1,1};

void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

void input()
{
    cin >> n >> k;
    
    for(int i=0,input; i<n; i++)
    {
        cin >> input;

        q.push(input);
        s.insert(input);
    }
}

long long bfs()
{
    long long answer = 0,distance = 1,house = 0;
    while(!q.empty())
    {
        int size = q.size();
        while(size--)
        {
            int cur = q.front();
            q.pop();

            for(int i=0; i<2; i++)
            {
                int next = cur + dx[i];

                if(s.count(next) < 1)
                {
                    s.insert(next);
                    house++;
                    answer += distance;
                    if(house == k) return answer;
                    q.push(next);

                }
            }
        }
        distance++;
    }
}
void solution()
{
    init();
    input();
    cout << bfs();
}

int main()
{
    solution();
    return 0;
}