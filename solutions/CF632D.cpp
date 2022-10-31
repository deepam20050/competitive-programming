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

const int N = 1e6 + 5;

int a[N];
int freq[N];
int cnt[N];
int n, m;

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 0, n) {
    scanf("%d", a + i);
    if (a[i] <= m) {
      ++freq[a[i]];
    }
  }
  FOR(i, 1, m + 1) {
    for (int j = i; j <= m; j += i) {
      cnt[j] += freq[i];
    }
  }
  int l = 0;
  FOR(i, 1, m + 1) {
    if (cnt[i] > cnt[l]) {
      l = i;
    }
  }
  vector < int > v;
  FOR(i, 0, n) {
   if (l > 0 && l % a[i] == 0) {
     v.eb(i + 1);
   }
  }
  if (l == 0) {
    l = 1;
  }
  printf("%d %d\n", l, sz(v));
  for (auto &e : v) {
    printf("%d ", e);
  }
  return 0;
}
