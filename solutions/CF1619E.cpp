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

void solve () {
  int n;
  scanf("%d", &n);
  vector < int > a(n), cnt(n + 1);
  for (auto &x : a) {
    scanf("%d", &x);
    ++cnt[x];
  }
  sort(all(a));
  stack < int > st;
  vector < lli > ans(n + 1, -1);
  lli sum = 0;
  for (int i = 0; i <= n; ++i) {
    if (i > 0 && cnt[i - 1] == 0) {
      if (st.empty()) {
        break;
      }
      int j = st.top();
      st.pop();
      sum += i - 1 - j;
    }
    ans[i] = sum + cnt[i];
    while (i > 0 && cnt[i - 1] > 1) {
      st.em(i - 1);
      --cnt[i - 1];
    }
  }
  for (auto &e : ans) {
    printf("%lld ", e);
  }
  puts("");
}

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    solve();
  }
  return 0;
}
