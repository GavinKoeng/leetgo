// Created by Gavin at 2025/12/08 16:41
// leetgo: 1.4.15
// https://leetcode.cn/problems/rotate-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr) {
				return head;
		}
		int n = 1;
		ListNode* iter = head;
		while (iter->next != nullptr) {
				iter = iter->next;
				n++;
		}
		int add = n - k % n;
		if (add == n) {
				return head;
		}
		iter->next = head;
		while (add--) {
				iter = iter->next;
		}
		ListNode* ret = iter->next;
		iter->next = nullptr;
		return ret;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int k;
	LeetCodeIO::scan(cin, k);

	Solution *obj = new Solution();
	auto res = obj->rotateRight(head, k);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
