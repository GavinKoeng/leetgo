// Created by Gavin at 2026/01/20 10:14
// leetgo: 1.4.15
// https://leetcode.cn/problems/subdomain-visit-count/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        unordered_map<string, int> counts;
        for (auto &&cpdomain: cpdomains) {
            int space = cpdomain.find(' ');
            int count = stoi(cpdomain.substr(0, space));
            string domain = cpdomain.substr(space + 1);
            counts[domain] += count;
            for (int i = 0; i < domain.size(); i++) {
                if (domain[i] == '.') {
                    string subdomain = domain.substr(i + 1);
                    counts[subdomain] += count;
                }
            }
        }
        for (auto &&[subdomain, count] : counts) {
            ans.emplace_back(to_string(count) + " " + subdomain);
        }
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> cpdomains;
	LeetCodeIO::scan(cin, cpdomains);

	Solution *obj = new Solution();
	auto res = obj->subdomainVisits(cpdomains);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
