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

lli n;

int solve (lli num, int x, int y) {
  if (num > n) return 0;
  int ans = 0;
  lli lol = num;
  int c1 = 0, c2 = 0;
  while (lol > 0) {
    int d = lol % 10;
    c1 += d == x;
    c2 += d == y;
    lol /= 10;
  }
  ans += c1 != 0 && c2 != 0;
  ans += solve(num * 10 + x, x, y);
  ans += solve(num * 10 + y, x, y);
  return ans;
}

int solve2 (lli num, int x) {
  if (num > n) {
    return 0;
  }
  int ans = (num > 0) + solve2(num * 10 + x, x);
  if (num * 10 != 0) {
    ans += solve2(num * 10, x);
  }
  return ans;
}

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  int ans = 0;
  FOR(x, 1, 10) {
    ans += solve2(0, x);
    FOR(y, x + 1, 10) {
      ans += solve(0, x, y);
    }
  }
  cout << ans;
  return 0;
}