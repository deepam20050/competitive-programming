// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

int main () {
  int tc;
  cin >> tc;
  while (tc--) {
    int n;
    cin >> n;
    if (n == 1) cout << "a\n";
    else cout << string(n / 2, 'a') + (n & 1 ? "bc" : "b") + string(n / 2 - 1, 'a') << '\n';
  }
  return 0;
}