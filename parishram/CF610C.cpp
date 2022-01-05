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

string inverse (string &x) {
  string ans;
  for (auto &c : x) {
    ans += c == '+' ? '*' : '+';
  }
  return ans;
}

vector < string > solve (int k) {
  if (k == 0) {
    return {"+"};
  }
  vector < string > ans;
  auto p = solve(k - 1);
  for (auto &s : p) {
    ans.eb(s + s);
    ans.eb(s + inverse(s));
  }
  return ans;
}

int main () {
  int k;
  scanf("%d", &k);
  auto res = solve(k);
  for (auto &s : res) {
    cout << s << '\n';
  }
  return 0;
}
