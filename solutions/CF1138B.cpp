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

const int N = 5005;

int n;
char s1[N], s2[N];
vector < int > both, clown, acrobat, neither;

int main () {
  scanf("%d", &n);
  scanf("%s", s1);
  scanf("%s", s2);
  FOR(i, 0, n) {
    if (s1[i] == '1' && s2[i] == '1') {
      both.eb(i + 1);
    } else if (s1[i] == '1') {
      clown.eb(i + 1);
    } else if (s2[i] == '1') {
      acrobat.eb(i + 1);
    } else {
      neither.eb(i + 1);
    }
  }
  if (sz(neither) & 1) {
    puts("-1");
  }
  bool swap = 0;
  if (sz(clown) < sz(acrobat)) {
    swap(clown, acrobat);
    swap ^= 1;
  }
  while (!both.empty()) {
    clown.eb(both.back());
    both.pop_back();
  }
  if (sz(clown) > sz(acrobat)) {
    swap(clown, acrobat);
    swap ^= 1;
  }
  int diff = sz(acrobat) - sz(clown);

  return 0;
}
