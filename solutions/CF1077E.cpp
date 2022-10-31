// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int n;
int a[N];
vector < lli > freq;

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    scanf("%d", a + i);
  }
  a[n] = 2e9;
  sort(a, a + n);
  int cnt = 0, lst = a[0];
  FOR(i, 0, n + 1) {
    if (a[i] == lst) {
      ++cnt;
    } else {
      freq.eb(cnt);
      cnt = 1;
      lst = a[i];
    }
  }
  sort(all(freq));
  int ans = 0;
  FOR(i, 1, N) {
    lli pw = i;
    int sum = 0;
    auto it = freq.begin();
    FOR(jj, 0, 20) {
      if (pw > N) {
        ans = max(ans, sum);
        break;
      }
      auto it2 = lower_bound(it, freq.end(), pw);
      if (it2 == freq.end()) {
        ans = max(ans, sum);
        break;
      }
      sum += pw;
      pw += pw;
      it = it2 + 1;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
