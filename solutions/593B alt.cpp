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

lli y_1[N], y2[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n; cin >> n;
  int x1, x2; cin >> x1 >> x2;
  FOR(i, 0, n) {
    int k, b; cin >> k >> b;
    y_1[i] = k * 1ll * x1 + b;
    y2[i] = k * 1ll * x2 + b;
  }
  vector < int > v1(n);
  iota(all(v1), 0);
  vector < int > v2(n);
  iota(all(v2), 0);
  sort(all(v1), [&] (int l, int r) {
    return y_1[l] == y_1[r] ? y2[l] <= y2[r] : y_1[l] < y_1[r];
  });
  sort(all(v2), [&] (int l, int r) {
    return y2[l] == y2[r] ? y_1[l] <= y_1[r] : y2[l] < y2[r];
  });
  FOR(i, 0, n) {
    if (v1[i] != v2[i]) {
      cout << "YES\n";
      exit(0);
    }
  }
  cout << "NO\n";
  return 0;
}