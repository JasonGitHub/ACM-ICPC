#include <iostream>
#include <vector>

using namespace std;

int max_len_increasing_subsequence(const vector<int> &a) {
  const int n = a.size();
  vector<int> max_len(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i]) {
        max_len[i] = max(max_len[i], max_len[j] + 1);
      }
    }
  }
  return max_len[n - 1];
}

int main() {
  int n, val;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  cout << max_len_increasing_subsequence(a) << endl;
  return 0;
}
