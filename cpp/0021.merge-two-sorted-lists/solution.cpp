// Created by gavin at 2026/08/04 23:42
// leetgo: 1.4.17
// https://leetcode.cn/problems/merge-two-sorted-lists/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) {
            return list2;
        } else if (list2 == nullptr) {
            return list1;
        } else if (list1->val < list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list2->next, list1);
            return list2;
        }
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* list1;
	LeetCodeIO::scan(cin, list1);
	ListNode* list2;
	LeetCodeIO::scan(cin, list2);

	Solution *obj = new Solution();
	auto res = obj->mergeTwoLists(list1, list2);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
