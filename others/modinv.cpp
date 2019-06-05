/*{{{*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define pii pair<int,int>
#define pll pair<ll,ll>
// pll pp; -> (pp.first,pp.second)
// vector<vl> pp(n,vl(2)); sort(pp.begin(),pp.end(),[](vl a,vl b){return a[0]<b[0];});

#define REP(i,n) for(ll (i)=0;(i)<(n);(i)++)
#define RREP(i,n) for(ll (i)=(n)-1;(i)>=0;(i)--)
#define FOR(i,a,b) for(ll (i)=(a);(i)<(b);(i)++)
#define FORR(i,a,b) for(ll (i)=(b)-1;(i)>=(a);(i)--)
#define DEBUG(x) cout << #x << ": " << x << endl
#define CHMAX(a,b) a=max((a),(b))
#define CHMIN(a,b) a=min((a),(b))
/*}}}*/

ll MOD = 1e9+7;
vl modinv(ll n){
  vl inv(n+1,1);
  FOR(i,2,n+1){
    inv[i] = (MOD-MOD/i)*inv[MOD%i]%MOD;
  }
  return inv;
}

int main() {
  ll n;
  cin >> n;
  vl inv = modinv(n);
  REP(i,inv.size()) cout << i << "\t: " << inv[i] << endl;
  return 0;
}
