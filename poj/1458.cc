#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max_common_subsequence(string s1, string s2) {
  vector<vector<int> > max_len(s1.size() + 1, vector<int>(s2.size() + 1, 0));
  for (int i = 1; i <= s1.size(); ++i) {
    for (int j = 1; j <= s2.size(); ++j) {
      if (s1[i - 1] == s2[j - 1]) {
        max_len[i][j] = max_len[i - 1][j - 1] + 1;
      } else {
        max_len[i][j] = max(max_len[i - 1][j], max_len[i][j - 1]);
      }
    }
  }
  return max_len[s1.size()][s2.size()];
}

int main() {
  string s1, s2;
  while (cin >> s1 >> s2) {
    cout << max_common_subsequence(s1, s2) << endl;
  }
  return 0;
}
