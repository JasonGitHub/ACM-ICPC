#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int maxSum(const vector<vector<int> > &triangle) {
  vector<int> max_sum(triangle.size() + 1, 0);
  for (int i = triangle.size() - 1; i >= 0; --i) {
    for (int j = 0; j <= i; ++j) {
      max_sum[j] = triangle[i][j] + max(max_sum[j], max_sum[j + 1]);
    }
  }
  return max_sum[0];
}

int main() {
  int n;
  cin >> n;
  vector<vector<int> > triangle;
  cin.ignore(100, '\n');
  for (int i = 0; i < n; ++i) {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> row;
    int val;
    while (ss >> val) row.push_back(val);
    triangle.push_back(row);
  }
  cout << maxSum(triangle) << endl;
  return 0;
}
