// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    vector < int > v;
    for (int i = 1; i <= n; i += i) {
      v.eb(i);
      n -= i;
    }
    if (n > 0) {
      v.eb(n);
      sort(all(v));
    }
    printf("%d\n", sz(v) - 1);
    for (int i = 1; i < sz(v); ++i) {
      printf("%d ", v[i] - v[i - 1]);
    }
    puts("");
  }
  return 0;
}