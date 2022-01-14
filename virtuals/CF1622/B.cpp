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

int p[N];
char s[N];
int n;
int q[N];
set < int > vals;

void gen (char c) {
  FOR(i, 1, n + 1) {
    if (s[i] == c) continue;
    auto it = vals.lower_bound(p[i]);
    int to_rem = -1;
    if (*it == p[i]) {
      q[i] = p[i];
      to_rem = p[i];
    } else {
      int diff1 = 2e9;
      int diff2 = 2e9;
      auto it2 = it;
      if (it != vals.end()) {
        diff1 = abs(*it - p[i]);
      }
      if (it != vals.begin()) {
        --it2;
        diff2 = abs(*it2 - p[i]);
      }
      if (diff1 >= diff2) {
        q[i] = *it2;
        vals.erase(it2);
      } else {
        q[i] = *it;
        vals.erase(it);
      }
    }
    vals.erase(to_rem);
  }
}

void solve () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", p + i);
  }
  scanf("%s", s + 1);
  int zeros = count(s + 1, s + n + 1, '0');
  vals.clear();
  FOR(i, 1, zeros + 1) vals.em(i);
  gen('1');
  vals.clear();
  FOR(i, zeros + 1, n + 1) vals.em(i);
  gen('0');
  FOR(i, 1, n + 1) {
    printf("%d%c", q[i], " \n"[i == n]);
  }
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
