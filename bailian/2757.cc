#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 人人为我
int max_len_increasing_subsequence(const vector<int> &a) {
  const int n = a.size();
  vector<int> max_len(n, 1);
  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (a[j] < a[i]) {
        max_len[i] = max(max_len[i], max_len[j] + 1);
      }
    }
  }
  return *max_element(max_len.begin(), max_len.end());
}

// 我为人人
int max_len_increasing_subsequence_1(const vector<int> &a) {
  const int n = a.size();
  vector<int> max_len(n, 1);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (a[j] > a[i]) {
        max_len[j] = max(max_len[j], max_len[i] + 1);
      }
    }
  }
  return *max_element(max_len.begin(), max_len.end());
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
