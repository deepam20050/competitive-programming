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
const int MX = 26;

struct Node {
  int freq[MX];
  Node () {
    memset(freq, 0, sizeof freq);
  }
  void clear () {
    memset(freq, 0, sizeof freq);
  }
};

Node unite (const Node &L, const Node &R) {
  Node ret;
  FOR(i, 0, MX) {
    ret.freq[i] = L.freq[i] + R.freq[i];
  }
  return ret;
}

Node t[N << 2];
char s[N];

void build (int lx, int rx, int x) {
  if (lx == rx) {
    t[x].freq[s[lx] - 'A'] = 1;
    return;
  }
  int midx = lx + rx >> 1;
  build(lx, midx, 2 * x);
  build(midx + 1, rx, 2 * x + 1);
  t[x] = unite(t[2 * x], t[2 * x + 1]);
}

Node query (int lx, int rx, int x, int ql, int qr) {
  if (lx > qr || rx < ql || lx > rx) {
    return Node();
  }
  if (ql <= lx && rx <= qr) {
    return t[x];
  }
  int midx = lx + rx >> 1;
  return unite(query(lx, midx, 2 * x, ql, qr), query(midx + 1, rx, 2 * x + 1, ql, qr));
}

void update (int lx, int rx, int x, int idx, int c) {
  if (lx == rx) {
    t[x].clear();
    t[x].freq[c] = 1;
    return;
  }
  int midx = lx + rx >> 1;
  if (idx <= midx) {
    update(lx, midx, 2 * x, idx, c);
  } else {
    update(midx + 1, rx, 2 * x + 1, idx, c);
  }
  t[x] = unite(t[2 * x], t[2 * x + 1]);
}

int main () {
  int tc;
  scanf("%d", &tc);
  FOR(tt, 0, tc) {
    printf("Case #%d:\n", tt + 1);
    scanf("%s", s);
    int n = strlen(s);
    memset(t, 0, sizeof t);
    build(0, n - 1, 1);
    int nq;
    scanf("%d", &nq);
    while (nq--) {
      char op[3];
      int l, r;
      scanf("%s %d %d", op, &l, &r);
      if (op[0] == 's') {
        sort(s + l, s + r + 1);
        FOR(i, l, r + 1) {
          update(0, n - 1, 1, i, s[i] - 'A');
        }
      } else {
        Node res = query(0, n - 1, 1, l, r);
        FOR(i, 0, MX) {
          printf("%d%c", res.freq[i], " \n"[i == MX - 1]);
        }
      }
    }
  }
  return 0;
}
