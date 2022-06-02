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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 4e5 + 5;

int cnt[N];

int main () {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int nq, k; cin >> nq >> k;
  memset(cnt, -1, sizeof cnt);
  set < int > st;
  int ans = 0;
  FOR(i, 0, nq) {
    int x; cin >> x;
    int r = x % k;
    if (cnt[r] == -1) {
      cnt[r] = r;
    } else {
      cnt[r] += k;
    }
    st.em(cnt[r]);
    while (st.find(ans) != st.end()) {
      ++ans;
    }
    cout << ans << '\n';
  }
  return 0;
}