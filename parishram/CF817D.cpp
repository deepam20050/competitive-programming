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

const int N = 1e6 + 5;

int a[N];
int n;
stack < int > st;

vector < int > solve () {
  while (!st.empty()) {
    st.pop();
  }
  vector < int > v(n + 1);
  FOR(i, 1, n + 1) {
    while (!st.empty() && a[st.top()] <= a[i]) {
      st.pop();
    }
    v[i] = st.empty() ? 1 : st.top() + 1;
    st.em(i);
  }
  return v;
}

vector < int > solve2 () {
  while (!st.empty()) {
    st.pop();
  }
  vector < int > v(n + 1);
  for (int i = n; i >= 1; --i) {
    while (!st.empty() && a[st.top()] < a[i]) {
      st.pop();
    }
    v[i] = st.empty() ? n : st.top() - 1;
    st.em(i);
  }
  return v;
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) {
    scanf("%d", a + i);
  }
  auto mx_lft = solve();
  FOR(i, 1, n + 1) {
    a[i] = -a[i];
  }
  auto mi_lft = solve();
  FOR(i, 1, n + 1) {
    a[i] = -a[i];
  }
  auto mx_rgt = solve2();
  FOR(i, 1, n + 1) {
    a[i] = -a[i];
  }
  auto mi_rgt = solve2();
  lli ans = 0;
  FOR(i, 1, n + 1) {
    a[i] = -a[i];
    ans += a[i] * 1ll * (mx_rgt[i] - i + 1) * (i - mx_lft[i] + 1);
    ans -= a[i] * 1ll * (mi_rgt[i] - i + 1) * (i - mi_lft[i] + 1);
  }
  printf("%lld\n", ans);
  return 0;
}
