#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

vector < int > ans[N];

void rekt () {
  cout << -1 << '\n';
  exit(0);
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  string s; cin >> s;
  vector < int > zeros, ones;
  int nxt = 0;
  FOR(i, 1, sz(s) + 1) {
    if (s[i - 1] == '0') {
      if (!ones.empty()) {
        int x = ones.back(); ones.pop_back();
        ans[x].eb(i);
        zeros.eb(x);
      } else {
        int x = ++nxt; 
        ans[x].eb(i);
        zeros.eb(x);
      }
    } else {
      if (zeros.empty()) rekt();
      int x = zeros.back(); zeros.pop_back();
      ans[x].eb(i);
      ones.eb(x);
    }
  } 
  if (!ones.empty()) rekt();
  cout << nxt << '\n';
  FOR(i, 1, nxt + 1) {
    cout << sz(ans[i]) << " ";
    for (auto &e : ans[i]) {
      cout << e << " ";
    }
    cout << '\n';
  }
  return 0;
}