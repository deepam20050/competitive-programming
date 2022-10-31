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

const int N = 2e5 + 5;

int a[N];
stack < int > s;
int ans[N];
int l[N], r[N];

int main () {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n + 1) scanf("%d", a + i);
  FOR(i, 1, n + 1) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    l[i] = s.empty() ? 0 : s.top();
    s.em(i);
  }
  while (!s.empty()) s.pop();
  for (int i = n; i >= 1; --i) {
    while (!s.empty() && a[s.top()] >= a[i]) {
      s.pop();
    }
    r[i] = s.empty() ? n + 1 : s.top();
    s.em(i);
  }
  FOR(i, 1, n + 1) {
    int len = r[i] - l[i] - 1;
    ans[len] = max(ans[len], a[i]);
  }
  for (int i = n; i >= 1; --i) {
    ans[i] = max(ans[i + 1], ans[i]);
  }
  FOR(i, 1, n + 1) {
    printf("%d ", ans[i]);
  }
  return 0;
}
