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

const int N = 6e6 + 5;
const int LN = 30;

int idx;
int siz[N];
int trie[N][2];

void insert (int x) {
  int curr = 0;
  for (int i = LN - 1; i >= 0; --i) {
    int d = x >> i & 1;
    if (trie[curr][d] == 0) {
      trie[curr][d] = ++idx;
    }
    curr = trie[curr][d];
    ++siz[curr];
  }
}

void remove (int x) {
  int curr = 0;
  for (int i = LN - 1; i >= 0; --i) {
    int d = x >> i & 1;
    if (trie[curr][d] == 0) {
      trie[curr][d] = ++idx;
    }
    curr = trie[curr][d];
    --siz[curr];
  }
}

void query (int x) {
  int curr = 0, ans = 0;
  for (int i = LN - 1; i >= 0; --i) {
    int d = x >> i & 1;
    if (siz[trie[curr][d ^ 1]]) {
      ans |= 1 << i;
      curr = trie[curr][d ^ 1];
    } else {
      curr = trie[curr][d];
    }
  }
  printf("%d\n", ans);
}

int main () {
  int nq;
  scanf("%d", &nq);
  insert(0);
  while (nq--) {
    char s[5];
    int x;
    scanf("%s %d", s, &x);
    if (s[0] == '+') {
      insert(x);
    } else if (s[0] == '-') {
      remove(x);
    } else {
      query(x);
    }
  }
  return 0;
}
