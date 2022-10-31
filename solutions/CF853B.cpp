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

const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int inf = 1e9;
const lli infll = 1e18;

vector < pii > to[M], from[M];
int toCost[N], fromCost[N];
lli pref[M], suff[M];

int n, m, k;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m >> k;
  FOR(i, 0, m) {
    int d, f, t, c;
    cin >> d >> f >> t >> c;
    if (!t) {
      to[d].eb(c, f);
    } else {
      from[d].eb(c, t);
    }
  }
  fill(toCost, toCost + n + 1, inf);
  fill(fromCost, fromCost + n + 1, inf);
  FOR(i, 0, M) pref[i] = suff[i] = infll;
  int seen = 0;
  lli curr = 0;
  FOR(i, 1, M) {
    for (auto [cost, u] : to[i]) {
      if (toCost[u] == inf) {
       ++seen;
       curr += cost;
       toCost[u] = cost;
      } else if (cost < toCost[u]){
        curr -= toCost[u] - cost;
        toCost[u] = cost;
      }
    }
    if (seen == n) {
      pref[i] = curr;
    }
  }
  seen = 0;
  curr = 0;
  for (int i = M - 1; i >= 1; --i) {
    for (auto [cost, v] : from[i]) {
      if (fromCost[v] == inf) {
        ++seen;
        curr += cost;
        fromCost[v] = cost;
      } else if (cost < fromCost[v]) {
        curr -= fromCost[v] - cost;
        fromCost[v] = cost;
      }
    }
    if (seen == n) {
      suff[i] = curr;
    }
  }
  lli ans = infll;
  for (int i = 1; i + k < M; ++i) {
    int l = i;
    int r = i + k - 1;
    if (pref[l - 1] < infll && suff[r + 1] < infll) {
      ans = min(ans, pref[l - 1] + suff[r + 1]);
    }
  }
  if (ans == infll) ans = -1;
  cout << ans << '\n';
  return 0;
}
