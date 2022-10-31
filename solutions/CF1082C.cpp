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

const int N = 1e5 + 5;

pii arr[N];
vector < int > v[N];
lli best[N];

int main () {
  int n, m; scanf("%d %d", &n, &m);
  FOR(i, 0, n) {
    int a, b; scanf("%d %d", &a, &b);
    arr[i] = {a, b};
  }
  sort(arr, arr + n, greater < pii > ());
  FOR(i, 0, n) {
    auto [who, what] = arr[i];
    v[who].eb(what);
  }
  FOR(i, 1, m + 1) {
    lli sum = 0;
    FOR(j, 0, sz(v[i])) {
      sum += v[i][j];
      best[j + 1] += sum > 0 ? sum : 0;
    }
  }
  printf("%lld\n", *max_element(best, best + n + 1));
  return 0;
}