// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;


int n, k;
vector < int > ans;

int main () {
  scanf("%d %d", &n, &k);
  int g = 0;
  FOR(i, 0, n) {
    int x;
    scanf("%d", &x);
    g = __gcd(g, x % k);
  }
  int s = 0;
  FOR(i, 0, k) {
    ans.eb(s % k);
    s += g;
    s %= k;
  }
  sort(all(ans));
  ans.erase(unique(all(ans)), ans.end());
  printf("%d\n", sz(ans));
  for (auto &e : ans) {
    printf("%d ", e);
  }
  return 0;
}
