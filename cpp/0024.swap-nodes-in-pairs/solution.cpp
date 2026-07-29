// Created by Gavin at 2026/07/29 10:48
// leetgo: 1.4.15
// https://leetcode.cn/problems/swap-nodes-in-pairs/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* cur = head;
        if (!head) return head;
        if (!head->next) return head;
        int num = 0;
        while (head && head->next) {
            num = head->val;
            head->val = head->next->val;
            head->next->val = num;;
            head = head->next->next;
        }
        return cur;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);

	Solution *obj = new Solution();
	auto res = obj->swapPairs(head);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
