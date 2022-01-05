// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

char s[N];
int cnt[30];

int main () {
  scanf("%s", s);
  int n = (int)strlen(s);
  FOR(i, 0, n) ++cnt[s[i] - 'a'];
  int mid = -1;
  FOR(i, 0, 26) {
    if (cnt[i] & 1) {
      for (int j = 25; j > i; --j) {
        if (cnt[j] & 1) {
          ++cnt[i];
          --cnt[j];
          break;
        }
      }
    }
    if (cnt[i] & 1) mid = i;
  }
  FOR(i, 0, 26) {
    int x = cnt[i] >> 1;
    cnt[i] >>= 1;
    while (x--) printf("%c", i + 'a');
  }
  if (mid != -1) {
    printf("%c", mid + 'a');
  }
  for (int i = 25; i >= 0; --i) {
    while (cnt[i]--) {
      printf("%c", i + 'a');
    }
  }
  return 0;
}
