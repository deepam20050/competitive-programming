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

string s;

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  cin >> s;
  set < string > S;
  int ans = 0;
  queue < string > q;
  S.em(s);
  q.em(s);
  while (!q.empty() && sz(S) < k) {
    auto x = q.front();
    q.pop();
    FOR(i, 0, sz(x)) {
      auto y = x;
      y.erase(i, 1);
      if (S.find(y) == S.end() && sz(S) + 1 <= k) {
        S.em(y);
        ans += n - sz(y);
        q.em(y);
      }
    }
  }
  if (sz(S) != k) {
    cout << "-1";
  } else {
    cout << ans;
  }
  return 0;
}
