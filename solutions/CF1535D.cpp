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

const int PWN = 1 << 19;

char s[PWN];
int n;

struct SegTree {
  int t[PWN];
  int combine (const int &L, const int &R, int nx) {
    int ret = 0;
    if (s[nx] == '0') {
      ret = R;
    } else if (s[nx] == '1') {
      ret = L;
    } else {
      ret = L + R;
    }
    return ret;
  }
  void build (int nx, int lx, int rx) {
    if (lx == rx) {
      t[nx] = 1;
      if (s[nx] == '?') {
        t[nx] = 2;
      }
      return;
    }
    int midx = lx + rx >> 1;
    build(nx << 1, lx, midx);
    build(nx << 1 | 1, midx + 1, rx);
    t[nx] = combine(t[nx << 1], t[nx << 1 | 1], nx);
  }
  void update2 (int nx) {
    while (nx) {
      if ((nx << 1) > n) {
        t[nx] = 1;
        if (s[nx] == '?') {
          t[nx] = 2;
        }
      } else {
        t[nx] = combine(t[nx << 1], t[nx << 1 | 1], nx);
      }
      nx >>= 1;
    }
  }
} tree1;

int main () {
  int k;
  scanf("%d", &k);
  n = (1 << k) - 1;
  scanf("%s", s + 1);
  reverse(s + 1, s + n + 1);
  tree1.build(1, 1, n);
  int nq;
  scanf("%d", &nq);
  while (nq--) {
    int pos;
    char ch;
    scanf("%d %c", &pos, &ch);
    pos = n - pos + 1;
    s[pos] = ch;
    tree1.update2(pos);
    printf("%d\n", tree1.t[1]);
  }
  return 0;
}
