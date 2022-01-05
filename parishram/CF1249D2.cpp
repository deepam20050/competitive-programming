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

int l[N], r[N];
vector < int > lines[N];
set < pii, greater < pii > > st;
int cnt[N], sub[N];
bitset < N > ans;

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 1, n + 1) {
    scanf("%d %d", l + i, r + i);
    ++cnt[l[i]];
    --cnt[r[i] + 1];
    lines[l[i]].eb(i);
    lines[r[i] + 1].eb(-i);
  }
  FOR(i, 1, N) cnt[i] += cnt[i - 1];
  int currSub = 0;
  FOR(i, 1, N) {
    currSub += sub[i];
    for (auto &e : lines[i]) {
      if (e > 0) {
        st.emplace(r[e], e);
      } else {
        auto tmp = mp(r[-e], -e);
        if (st.find(tmp) != st.end()) st.erase(tmp);
      }
    }
    while (cnt[i] - currSub > k) {
      auto longest = st.begin();
      int idx = longest->S;
      st.erase(longest);
      ++currSub;
      --sub[r[idx] + 1];
      ans[idx] = 1;
    }
  }
  printf("%d\n", (int)ans.count());
  FOR(i, 1, n + 1) if (ans[i]) printf("%d ", i);
  return 0;
}
