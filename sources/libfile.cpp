// Copyright 2018 Your Name <your_email>

#include "header.hpp"



using boost::filesystem::path;
using std::string;
using std::size_t;
using std::stoi;



bool is_right_file(path a) {
	if (a.extension().string() != ".txt") return false;
	a = a.stem();
	if (a.extension().string() == ".old") return false;
	string name = a.string();
	if (name.length() != 25) return false;
	size_t pos = name.find("balance");
	if (pos != 0) return false;
	name.erase(name.begin(), name.begin() + 7);
	for (size_t i : {0, 9}) {
		if (name[i] != '_') return false;
		string nums = name.substr(i+1, i+8);
		for (size_t p = 0; p < nums.length(); ++p) {
			if (nums[p]<'0' || nums[p]>'9') return false;
		}
	}
	return true;
}


size_t getTwoNumbers(string s, size_t m) {
	size_t a = s[m]-'0';
	size_t b = s[m + 1] - '0';
	return a * 10 + b;
}


DataKit::DataKit(string r) {
	examine(r);
}

void DataKit::examine(string s) {
	++counter;
	size_t a = stoi(s.substr(17, 8));
	if (a > date) date = a;
}
