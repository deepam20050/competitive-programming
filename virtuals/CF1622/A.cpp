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
    lli v[3];
    cin >> v[0] >> v[1] >> v[2];
    int perm[] = {0, 1, 2};
    bool ok = 0;
    do {
      lli s1 = v[perm[0]], s2 = v[perm[1]], s3 = v[perm[2]];
      if (s1 + s2 == s3) {
        ok = 1;
      }
      if (s3 % 2 == 0 && s1 == s2) {
        ok = 1;
      }
    } while (next_permutation(perm, perm + 3));
    ok ? puts("YES") : puts("NO");
  }
  return 0;
}
