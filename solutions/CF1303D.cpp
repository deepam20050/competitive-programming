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

const int LN = 63;

int freq[LN];
lli n;
int m;

void solve () {
  scanf("%lld %d", &n, &m);
  memset(freq, 0, sizeof freq);
  lli sum = 0;
  FOR(i, 0, m) {
    int x;
    scanf("%d", &x);
    ++freq[__lg(x)];
    sum += x;
  }
  if (sum < n) {
    puts("-1");
    return;
  }
  int ans = 0;
  FOR(i, 0, LN) {
    if (n >> i & 1) {
      if (freq[i]) {
        --freq[i];
      } else {
        int j = i + 1;
        while (!freq[j]) ++j;
        while (j > i) {
          ++ans;
          --freq[j];
          freq[j - 1] += 2;
          --j;
        }
        --freq[i];
      }
    }
    freq[i + 1] += freq[i] >> 1;
  }
  printf("%d\n", ans);
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
