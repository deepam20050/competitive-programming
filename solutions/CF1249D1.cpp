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

const int N = 205;

int l[N], r[N];
vector < int > ans;
int cnt[N];
set < int > st;

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    scanf("%d %d", l + i, r + i);
    st.insert(i);
    FOR(j, l[i], r[i] + 1) ++cnt[j];
  }
  FOR(i, 1, N) {
    while (cnt[i] > k) {
      int curr = -1;
      for (auto &idx : st) {
        if (l[idx] <= i && i <= r[idx] && (curr == -1 || r[idx] > r[curr])) {
          curr = idx;
        }
      }
      ans.eb(curr + 1);
      FOR(j, l[curr], r[curr] + 1) --cnt[j];
      st.erase(curr);
    }
  }
  printf("%d\n", sz(ans));
  for (auto &e: ans) printf("%d ", e);
  return 0;
}
