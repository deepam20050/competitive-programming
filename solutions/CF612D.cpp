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

const int N = 1e6 + 5;

vector < pii > lines;
vector < pii > ans;

int main () {
  int n, k;
  scanf("%d %d", &n, &k);
  FOR(i, 0, n) {
    int l, r;
    scanf("%d %d", &l, &r);
    lines.eb(l, 0);
    lines.eb(r, 1);
  }
  sort(all(lines));
  int sum = 0, lst = 0;
  for (auto [x, what] : lines) {
    if (what) {
      --sum;
      if (sum == k - 1) {
        ans.eb(lst, x);
      }
    } else {
      ++sum;
      if (sum == k) {
        lst = x;
      }
    }
  }
  printf("%d\n", sz(ans));
  for (auto [l, r] : ans) {
    printf("%d %d\n", l, r);
  }
  return 0;
}
