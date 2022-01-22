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

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

string s;
queue < int > pos[30];
int p[N];
int bit[N];

void update (int idx) {
  while (idx > 0) {
    ++bit[idx];
    idx -= idx & -idx;
  }
}

int query (int idx) {
  int ret = 0;
  while (idx < N) {
    ret += bit[idx];
    idx += idx & -idx; 
  }
  return ret;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  cin >> s;
  auto t = s;
  reverse(all(s));
  lli ans = 0;
  FOR(i, 0, sz(s)) {
    pos[s[i] - 'a'].em(i + 1);
  }
  vector < pii > v;
  FOR(i, 0, sz(t)) {
    p[i] = pos[t[i] - 'a'].front();
    pos[t[i] - 'a'].pop();
    v.eb(p[i], i + 1);
  }
  sort(all(v));
  for (auto [ignore, idx] : v) {
    int add = query(idx);
    ans += 1ll * add;
    update(idx);
  }
  cout << ans;
  return 0;
}
