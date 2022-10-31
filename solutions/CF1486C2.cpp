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

int ask (int l, int r) {
  if (l == r) return -1;
  cout << "? " << l << " " << r << endl;
  int ret;
  cin >> ret;
  return ret;
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int s = ask(1, n);
  if (ask(1, s) == s) {
    int l = 1, r = s - 1;
    FOR(i, 0, 18) {
      int m = l + r + 1 >> 1;
      if (ask(m, s) == s) {
        l = m;
      } else {
        r = m;
      }
    }
    cout << "! " << l << endl;
  } else {
    int l = s + 1, r = n;
    FOR(i, 0, 18) {
      int m = l + r >> 1;
      if (ask(s, m) == s) {
        r = m;
      } else {
        l = m;
      }
    }
    cout << "! " << r << '\n';
  }
  return 0;
}