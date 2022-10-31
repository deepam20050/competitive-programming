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

const int N = 1e5 + 5;

int cnt[N];
int moves[N];
int n;

int main () {
  scanf("%d", &n);
  FOR(i, 0, n) {
    int a;
    scanf("%d", &a);
    int add = 0, p = 1;
    while (a) {
      if (p == 0) {
        ++cnt[a];
        moves[a] += add;
      } else {
        int x = a, c = 0;
        while (x < N) {
          ++cnt[x];
          moves[x] += add + c;
          x <<= 1;
          ++c;
        }
      }
      p = a & 1;
      a >>= 1;
      ++add;
    }
    ++cnt[a];
    moves[a] += add;
  }
  int ans = 1e9;
  FOR(i, 1, N) {
    if (cnt[i] == n) {
      ans = min(ans, moves[i]);
    }
  }
  printf("%d\n", ans);
  return 0;
}
