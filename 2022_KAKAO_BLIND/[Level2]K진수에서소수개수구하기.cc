#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

bool isPrime(long long n)
{
    if(n == 1) return false;
    for(int i=2; i <= sqrt(n); i++)
    {
        if((n % i) == 0) return false;
    }
    return true;
}

string change(int n,int k)
{
    string res;
    while(n)
    {
        res += to_string(n%k);
        n/=k;
    }
    reverse(res.begin(),res.end());
    return res;
}

int getPrime(string s)
{
    string tmp = "";
    int ret =0;
    for(auto c : s)
    {
        if(c == '0')
        {
            if(!tmp.empty() and isPrime(stoll(tmp)))
                ret++;
            tmp.clear();
        }
        else tmp.push_back(c);
        
    }
    if(!tmp.empty() and isPrime(stoll(tmp))) return ret+1;
    return ret;
}

int solution(int n, int k) {
    
    string s = change(n,k);
    return getPrime(s);
}