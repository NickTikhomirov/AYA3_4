// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <boost/filesystem.hpp>
#include <string>

using std::string;
using std::size_t;
using boost::filesystem::path;

bool is_right_file(path a);
size_t getTwoNumbers(string s, size_t m);


struct DataKit{
	size_t date = 0;
	size_t counter = 0;
	DataKit() {}
	DataKit(string r);
	void examine(string);
};





#endif // INCLUDE_HEADER_HPP_
