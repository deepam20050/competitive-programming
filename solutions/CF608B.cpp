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

const int N = 2e5 + 5;

int pref[N];
string a, b;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> a >> b;
  int n = sz(a), m = sz(b);
  a = " " + a;
  b = " " + b;
  FOR(i, 1, m + 1) {
    pref[i] = pref[i - 1] + (b[i] == '1');
  }
  lli ans = 0;
  FOR(i, 1, n + 1) {
    int l = i, r = m - n + i;
    int sum = pref[r] - pref[l - 1];
    if (a[i] == '0') {
      ans += sum;
    } else {
      ans += r - l + 1 - sum;
    }
  }
  cout << ans;
  return 0;
}
