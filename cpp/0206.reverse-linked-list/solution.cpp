// Created by Gavin at 2025/12/12 15:30
// leetgo: 1.4.15
// https://leetcode.cn/problems/reverse-linked-list/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
		ListNode* curr = head;
		while (curr) {
				ListNode* next = curr->next;
				curr->next = prev;
				prev = curr;
				curr = next;
		}
		return prev;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);

	Solution *obj = new Solution();
	auto res = obj->reverseList(head);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
