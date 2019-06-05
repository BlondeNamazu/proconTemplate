/*{{{*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define vi vector<int>
#define vl vector<ll>
#define vb vector<bool>
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
vector<string> fileInput(string filename){
  vector<string> inp;
  ifstream ifs(filename);
  if(!ifs){
    return {"\0"};
  }
  string str;
  while(getline(ifs,str)){
    ll start = 0;
    REP(i,str.length()){
      char c = str[i];
      if(c==' ' || c=='\n'){
        inp.push_back(str.substr(start,i-start));
        start = i+1;
      }
    }
    inp.push_back(str.substr(start,str.length()-start));
  }
  return inp;
}
/*}}}*/
int main() {
  ll n;
  cin >> n;
  cout << ans<< endl;
  return 0;
}
