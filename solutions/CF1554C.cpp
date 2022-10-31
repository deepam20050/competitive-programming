// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n, m;
    scanf("%d %d", &n, &m);
    int ans = 0;
    ++m;
    bool done = 0;
    for (int i = 30; i >= 0; --i) {
      if ((n ^ ans) >= m) break;
      if ((n >> i & 1) == 0 && (m >> i & 1) == 1) {
        ans ^= 1 << i;
        done = 1;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}