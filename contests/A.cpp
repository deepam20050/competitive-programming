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
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    if (a == 0) {
      cout << 1 << '\n';
    } else {
      cout << a + 2 * b  + 1<< '\n';
    }
  }
  return 0;
}
