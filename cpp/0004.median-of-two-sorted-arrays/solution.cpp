// Created by Gavin at 2025/12/13 22:16
// leetgo: 1.4.15
// https://leetcode.cn/problems/median-of-two-sorted-arrays/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    int getKthElement(const vector<int>& nums1, const vector<int>& nums2, int k) {
      int m = nums1.size();
      int n = nums2.size();
      int index1 = 0, index2 = 0;

      while (true) {
        if (index1 == m) {
          return nums2[index2 + k - 1];
        }
        if (index2 == n) {
          return nums1[index1 + k - 1];
        }
        if (k == 1) {
          return min(nums1[index1], nums2[index2]);
        }
        int newIndex1 = min(index1 + k / 2 - 1, m - 1);
        int newIndex2 = min(index2 + k / 2 - 1, n - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2) {
          k -= newIndex1 - index1 + 1;
          index1 = newIndex1 + 1;
        } else {
          k -= newIndex2 - index2 + 1;
          index2 = newIndex2 + 1;
        }
      }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int totalLength = nums1.size() + nums2.size();
       if (totalLength % 2 == 1) {
         return getKthElement(nums1, nums2, (totalLength + 1) / 2);
       } else {
         return (getKthElement(nums1, nums2, totalLength / 2) + getKthElement(nums1, nums2, totalLength / 2 + 1)) / 2.0;
       }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<int> nums1;
	LeetCodeIO::scan(cin, nums1);
	vector<int> nums2;
	LeetCodeIO::scan(cin, nums2);

	Solution *obj = new Solution();
	auto res = obj->findMedianSortedArrays(nums1, nums2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
