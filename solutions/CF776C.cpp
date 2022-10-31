#include "bits/stdc++.h"

using namespace std;

using lli = long long;

const int N = 1e5 + 5;

lli pref[N];
int n, k;
vector < lli > pw;
map < lli, lli > cnt;

int main () {
  scanf("%d %d", &n, &k);
  lli mx = -1e18;
  for (int i = 1; i <= n; ++i) {
    int x;
    scanf("%d", &x);
    pref[i] = pref[i - 1] + 1ll * x;
    mx = max(pref[i], mx);
  }
  pw.emplace_back(1);
  if (k == -1) {
    pw.emplace_back(-1);
  } else if (abs(k) != 1) {
    lli curr = k;
    while (abs(curr) <= 1e14) {
      pw.emplace_back(curr);
      curr *= k;
    }
  }
  ++cnt[0];
  lli ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (auto &x : pw) {
      ans += cnt[pref[i] - x];
    }
    ++cnt[pref[i]];
  }
  printf("%lld\n", ans);
  return 0;
}
