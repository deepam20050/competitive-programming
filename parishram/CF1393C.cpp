#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

using pi = pair < int, int >;

int a[N], cnt[N], b[N];

int n;

bool f (int x) {
  memset(cnt, 0, sizeof cnt);
  for (int i = 0; i < n; ++i) {
    ++cnt[a[i]];
  }
  set < pi, greater < pi > > st;
  for (int i = 1; i <= n; ++i) {
    if (cnt[i] > 0) {
      st.insert({cnt[i], i});
    }
  }
  for (int i = 0; i < n; ++i) {
    if (i >= x && cnt[b[i - x]]) {
      st.insert({cnt[b[i - x]], b[i - x]});
    }
    if (st.empty()) {
      return 0;
    }
    b[i] = st.begin() -> second;
    st.erase(st.begin());
    --cnt[b[i]];
  }
  return 1;
}

int main() {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }
    int l = 0, r = n;
    for (int i = 0; i < 20; ++i) {
      int m = l + r >> 1;
      if (f(m)) {
        l = m;
      } else {
        r = m;
      }
    }
    printf("%d\n", l - 1);
  }
  return 0;
}
