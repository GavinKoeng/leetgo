// Created by Gavin at 2026/01/19 15:40
// leetgo: 1.4.15
// https://leetcode.cn/problems/replace-words/

#include <bits/stdc++.h>
#include "LC_IO.h"
using namespace std;

// @lc code=begin

class Solution {
public:
    vector<string_view> split(string &str, char ch) {
        int pos = 0;
        int start = 0;
        string_view s(str);
        vector<string_view> ret;
        while (pos < s.size()) {
            while (pos < s.size() && s[pos] == ch) {
                pos++;
            }
            start = pos;
            while (pos < s.size() && s[pos] != ch) {
                pos++;
            }
            if (start < s.size()) {
                ret.emplace_back(s.substr(start, pos - start));
            }
        }
        return ret;
    }

    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string_view> dictionarySet;
        for (auto &root: dictionary) {
            dictionarySet.emplace(root);
        }
        vector<string_view> words = split(sentence, ' ');
        for (auto &word :words) {
            for (int j = 0; j < word.size(); j++) {
                if (dictionarySet.count(word.substr(0, 1 + j))) {
                    word = word.substr(0, 1 + j);
                    break;
                }
            }
        }
        string ans;
        for (int i = 0; i < words.size() - 1; i++) {
            ans.append(words[i]);
            ans.append(" ");
        }
        ans.append(words.back());
        return ans;
    }
};

// @lc code=end

int main() {
	ios_base::sync_with_stdio(false);
	stringstream out_stream;

	vector<string> dictionary;
	LeetCodeIO::scan(cin, dictionary);
	string sentence;
	LeetCodeIO::scan(cin, sentence);

	Solution *obj = new Solution();
	auto res = obj->replaceWords(dictionary, sentence);
	LeetCodeIO::print(out_stream, res);
	cout << "\noutput: " << out_stream.rdbuf() << endl;

	delete obj;
	return 0;
}
