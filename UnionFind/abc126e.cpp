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

// n : num of nodes
ll n;
// m : num of queries
ll m;
// dat[i] : if({i is root}) -1 * {num of nodes under i} else {i's root}
vl dat;

// return x's root
ll root(ll x){
  return dat[x] < 0 ? x : dat[x]=root(dat[x]);
}

// make node a and node b belong to same group
void unite(ll a, ll b){
  a = root(a);
  b = root(b);
  if(a==b) return;
  // thanks to following line, {num of nodes under a}>={num of nodes under a} is true
  // tree height becomes smallest 
  if(-dat[a] < -dat[b]) swap(a,b);
  // {num of nodes under a} += {num of nodes under b}
  dat[a] += dat[b];
  // node b is no longer root, and b's root is a
  dat[b] = a;
}

int main() {
  cin >> n >> m;
  dat = vl(n,-1);
  REP(i,m) {
    ll ai,bi,d;
    cin >> ai >> bi >> d;
    ai--;
    bi--;
    unite(ai,bi);
  }
  ll ans = 0;
  REP(i,n) if(root(i)==i) ans++;
  cout << ans << endl;
  return 0;
}
