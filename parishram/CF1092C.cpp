#include "bits/stdc++.h"

using namespace std;

const int N = 1e3;

bitset < N > vis;
string s[N];
int m;

void solve (string S) {
  vis.reset();
  string ans = "";
  for (int i = 0; i < m; ++i) {
    if (!vis[s[i].size()] && S.substr(0, s[i].size()) == s[i]) {
      vis[s[i].size()] = 1;
      ans += "P";
    } else if (S.substr(S.size() - s[i].size(), s[i].size()) == s[i]) {
      ans += "S";
    } else {
      return;
    }
  }
  cout << ans;
  exit(0);
}

int main () {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  m = 2 * n - 2;
  string l = "";
  string r = "";
  for (int i = 0; i < m; ++i) {
    cin >> s[i];
    if (s[i].size() == n - 1) {
      if (l.empty()) l = s[i];
      else r = s[i];
    }
  }
  solve(l + r.substr(n - 2, 1));
  solve(r + l.substr(n - 2, 1));
  return 0;
}
