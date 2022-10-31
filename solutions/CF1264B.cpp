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
  array < int, 4 > cnt;
  FOR(i, 0, 4) scanf("%d", &cnt[i]);
  int total = accumulate(all(cnt), 0);
  FOR(i, 0, 4) {
    if (!cnt[i]) continue;
    auto freq = cnt;
    vector < int > ans = {i};
    --freq[i];
    int x = i;
    FOR(j, 1, total) {
      if (x - 1 >= 0 && freq[x - 1]) {
        --freq[x - 1];
        ans.eb(x - 1);
        --x;
      } else if (x + 1 < 4 && freq[x + 1]) {
        --freq[x + 1];
        ans.eb(x + 1);
        ++x;
      } else {
        break;
      }
    }
    if (sz(ans) == total) {
      puts("YES");
      for (auto &e : ans) {
        printf("%d ", e);
      }
      exit(0);
    }
  }
  puts("NO");
  return 0;
}
