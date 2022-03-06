#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX=1000011;
int d[MAX],p[MAX],order[MAX],res[MAX];
ll n,k,t;
bool vis[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>p[i];
	for(int i=1;i<=n;i++)cin>>d[i];
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		ll cnt=0;
		for(int j=i;!vis[j];j=d[j]){
			vis[j]=true;
			order[cnt++]=j;
		}
		for(ll j=0;j<cnt;j++){
			int cur=p[order[j]];
			ll idx=order[(j+k)%cnt];
			res[idx]=cur;
		}
	}
	for(int i=1;i<=n;i++)cout<<res[i]<<" ";
}