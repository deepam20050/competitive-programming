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

const lli MAX = 1e18;

vector < pair < lli, lli > > a;
lli x0, y00, ax, ay, bx, by;
lli xs, ys, t;
bool used[1233];

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> x0 >> y00 >> ax >> ay >> bx >> by;
  cin >> xs >> ys >> t;
  a = {{x0, y00}};
  while ((MAX - bx) / ax >= a.back().F && (MAX - by) / ay >= a.back().S) {
    lli new_x = ax * a.back().F + bx;
    lli new_y = ay * a.back().S + by;
    a.eb(new_x, new_y);
  }
  int ans = 0;
  FOR(i, 0, sz(a)) {
    FOR(j, i, sz(a)) {
      auto [xi, yi] = a[i];
      auto [xj, yj] = a[j];
      lli len = xj - xi + yj - yi; 
      lli lft = abs(xs - xi) + abs(ys - yi);
      lli rgt = abs(xs - xj) + abs(ys - yj);
      if (len <= t - lft || len <= t - rgt) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans;
  return 0;
}
