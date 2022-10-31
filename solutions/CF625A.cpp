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

int main () {
  lli n, a, b, c;
  cin >> n >> a >> b >> c;
  if (a <= b - c) {
    cout << n / a;
  } else {
    n -= b;
    lli ans = 0;
    if (n >= b - c) {
      ans += n / (b - c);
      n %= (b - c);
    }
    n += b;
    while (n >= b) {
      ++ans;
      n -= b - c;
    }
    ans += n / a;
    printf("%lld\n", ans);
  }
  return 0;
}
