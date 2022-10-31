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

int main () {
  int n; scanf("%d", &n);
  vector < int > v(n);
  for (auto &e : v) {
    scanf("%d", &e);
  }
  sort(all(v));
  reverse(all(v));
  if (v.back()) {
    puts("-1");
    exit(0);
  }
  reverse(all(v));
  int s = accumulate(all(v), 0) % 3;
  if (s) {
    bool ok = 0;
    for (auto it = v.begin(); it != v.end(); ++it) {
      if (*it % 3 == s) {
        v.erase(it);
        ok = 1;
        break;
      }
    }
    for (auto it = v.begin(); !ok && it != v.end(); ++it) {
      if (*it % 3) {
        v.erase(it);
        break;
      }
    }
    for (auto it = v.begin(); !ok && it != v.end(); ++it) {
      if (*it % 3) {
        v.erase(it);
        break;
      }
    }
  }
  reverse(all(v));
  while (sz(v) > 1 && v.front() == 0) {
    v.pop_back();
  }
  for (auto &e : v) {
    printf("%d", e);
  }
  return 0;
}