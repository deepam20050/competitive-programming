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

const int N = 505;

int a[N];
int n, m;
vector < pair < int, char > > ans;

void sed () {
  puts("NO");
  exit(0);
}

void solve (int l, int r, int add) {
  if (l == r) return;
  int idx = -1;
  int val = -1;
  FOR(i, l, r + 1) {
    if (a[i] > val) {
      if ((i > l && a[i - 1] < a[i]) || (i < r && a[i + 1] < a[i])) {
        idx = i;
        val = a[i];
      }
    }  
  }
  if (idx == -1) {
    sed();
  }
  if (idx < r && a[idx + 1] < a[idx]) {
    FOR(i, idx + 1, r + 1) {
      ans.eb(add + idx - l + 1, 'R');
    }
    for (int i = idx; i > l; --i) {
      ans.eb(add + i - l + 1, 'L');
    }
  } else {
    for (int i = idx; i > l; --i) {
      ans.eb(add + i - l + 1, 'L');
    }
    FOR(i, idx + 1, r + 1) {
      ans.eb(add + 1, 'R');
    }
  }
}

int main () {
  scanf("%d", &n);
  FOR(i, 1, n + 1) scanf("%d", a + i);
  scanf("%d", &m);
  int curr = 1;
  FOR(i, 1, m + 1) {
    int sum;
    scanf("%d", &sum);
    int l = curr;
    while (sum > 0) {
      if (curr > n) sed();
      sum -= a[curr];
      ++curr;
    }
    if (sum < 0) sed();
    solve(l, curr - 1, i - 1);
  }
  if (curr <= n) sed();
  puts("YES");
  for (auto &[idx, ch]: ans) {
    printf("%d %c\n", idx, ch);
  }
  return 0;
}
