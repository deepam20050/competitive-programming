#include "bits/stdc++.h"
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back

using lli = long long;
using pii = pair < int, int >;

void test_case() {
  int n; cin >> n;
  double ans1 = 3.5;
  for (int i = 2; i <= n; ++i) {
    double ans2 = 0;
    for (int j = 1; j <= 6; ++j) {
      ans2 += max(ans1, (double)j) / 6;
    }
    ans1 = ans2;
  }
  cout << fixed << setprecision(10);
  cout << ans1 << '\n';
}

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int nt = 1;
  while (nt--) {
    test_case();
  }
  return 0;
}
