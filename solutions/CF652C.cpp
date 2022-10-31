#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 3e5 + 5;

int pos[N];
int end_point[N];
int n, m;

int main () {
  scanf("%d %d", &n, &m);
  FOR(i, 1, n + 1) {
    int x;
    scanf("%d", &x);
    pos[x] = i;
  }
  FOR(i, 0, m) {
    int x, y;
    scanf("%d %d", &x, &y);
    if (pos[x] > pos[y]) {
      swap(x, y);
    }
    x = pos[x];
    y = pos[y];
    end_point[y] = max(end_point[y], x);
  }
  int lst = 0;
  lli ans = 0;
  FOR(i, 1, n + 1) {
    lst = max(lst, end_point[i]);
    ans += i - lst;
  }
  printf("%lld\n", ans);
  return 0;
}
