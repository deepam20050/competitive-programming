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

const int N = 1e5 + 5;

int arr[N];
int cnt[N];

int main () {
  int n; scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", arr + i);
    ++cnt[arr[i]];
  }
  set < pii > st;
  vector < int > v;
  FOR(i, 1, n + 1) {
    if (cnt[arr[i]] > 1) {
      st.em(arr[i], i);
    }
    if (!cnt[i]) {
      v.eb(i);
    }
  }
  for (auto &e : v) {
    auto it = st.lb({e, -1});
    if (it == st.end()) {
      --it;
      arr[it->S] = e;
      st.erase(it);
      --cnt[it->F];
    } else {
      arr[it->S] = e;
      st.erase(it);
      --cnt[it->F];
    }
    if (cnt[it->F] == 1) {
      st.erase(st.lb({e - 1, -1}));
    }
  }
  printf("%d\n", sz(v));
  FOR(i, 1, n + 1) {
    printf("%d ", arr[i]);
  }
  return 0;
}
