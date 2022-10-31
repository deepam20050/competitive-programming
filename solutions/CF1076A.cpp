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

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  string s;
  cin >> s;
  FOR(i, 1, n) {
    if (s[i] < s[i - 1]) {
      cout << s.substr(0, i - 1) + s.substr(i) << '\n';
      return 0;
    }
  }
  cout << s.substr(0, n - 1);
  return 0;
}
