// Created by Gavin at 2026/01/24 22:39
// leetgo: 1.4.15
// https://leetcode.cn/problems/reverse-linked-list-ii/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
private:
    void reverseLinkedList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        while (cur != nullptr) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
    }

public:
    ListNode* reverseBetween(ListNode *head, int left, int right) {
        ListNode *dummyNode = new ListNode(-1);
        dummyNode->next = head;

        ListNode *pre = dummyNode;
        for (int i = 0; i < left - 1; ++i) {
            pre = pre->next;
        }
        ListNode *rightNode = pre;
        for (int i = 0; i < right - left + 1; ++i) {
            rightNode = rightNode->next;
        }
        ListNode *leftNode = pre->next;
        ListNode *curr = rightNode->next;
        pre->next = nullptr;
        rightNode->next = nullptr;
        reverseLinkedList(leftNode);
        pre->next = rightNode;
        leftNode->next = curr;
        return dummyNode->next;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	ListNode* head;
	LeetCodeIO::scan(cin, head);
	int left;
	LeetCodeIO::scan(cin, left);
	int right;
	LeetCodeIO::scan(cin, right);

	Solution *obj = new Solution();
	auto res = obj->reverseBetween(head, left, right);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
