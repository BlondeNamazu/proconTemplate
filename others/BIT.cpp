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
class BIT{
    vl bit;
    map<ll,ll> mp;
    ll n;
    vl origin;
  public:
    void init(vl given){
      origin = given;
      n = origin.size();
      bit = vl(n+1,0);
      REP(i,n){
        mp.insert(make_pair(origin[i],0));
      }
      ll cnt = 1;
      for(auto itr=mp.begin();itr!=mp.end();itr++){
        mp[(*itr).first] = cnt++;
      }
    }
    ll sum(ll k){
      // assume k is 0-origin
      // return sum of 1~k+1 elements
      ll i=mp[origin[k]];
      ll ret = 0;
      while(i>0){
        ret += bit[i];
        i -= (i&-i);
      }
      return ret;
    }
    void add(ll k){
      // asssume k is 0-origin
      // increment bit elements related to k
      ll i=mp[origin[k]];
      while(i<=n){
        bit[i] += 1;
        i += (i&-i);
      }
    }
    ll calcInversion(){
      ll ret = 0;
      REP(i,n){
        ret += i-sum(i);
        add(i);
        REP(j,bit.size()) cout << bit[j] << " ";
        cout << endl;
      }
      return ret;
    }
};

int main() {
  ll n;
  cin >> n;
  vl ar(n);
  REP(i,n) cin >> ar[i];
  BIT bit;
  bit.init(ar);
  cout << bit.calcInversion() << endl;
  return 0;
}
