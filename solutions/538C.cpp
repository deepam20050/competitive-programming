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

const int M = 1e5 + 5;

int d[M], h[M];

inline int abso (int x) {
  return x < 0 ? -x : x;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int n, m; cin >> n >> m;
  FOR(i, 1, m + 1) {
    cin >> d[i] >> h[i];
  }
  int hmax = max(0, h[1] + (d[1] - 1));
  FOR(i, 2, m + 1) {
    int diff = d[i] - d[i - 1];
    int mx = min((int)1e8, h[i - 1] + diff);
    int mi = max(0, h[i - 1] - diff);
    if (!(mi <= h[i] && h[i] <= mx)) {
      cout << "IMPOSSIBLE";
      exit(0);
    } 
    int x = h[i] - h[i - 1] + diff >> 1;
    hmax = max(hmax, h[i - 1] + x);
  }
  hmax = max(hmax, h[m] + n - d[m]);
  cout << hmax << '\n';
  return 0;
}