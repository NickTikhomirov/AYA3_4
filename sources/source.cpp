// Copyright 2018 Your Name <your_email>

#include <header.hpp>
#include <unordered_map>
#include <iostream>

using std::cout;
using boost::filesystem::path;
using boost::filesystem::directory_entry;
using boost::filesystem::directory_iterator;
using std::unordered_map;
using std::string;
using std::make_pair;

int main(
	int argc,
	char *argv[]
) {
	unordered_map<string, unordered_map<string, DataKit>> contents;
	path path_to_ftp;
	if (argc == 1) path_to_ftp = (path(argv[0])).parent_path();
	else path_to_ftp = path(argv[1]);

	cout << "Begin searching!\n";

	for (const directory_entry& y : directory_iterator{ path_to_ftp }) {
		for (const directory_entry& x : directory_iterator{ y }) {
			if (is_right_file(x.path())) {
				string name = x.path().string();
				size_t slash = name.rfind('/');
				name.erase(slash);
				slash = name.rfind('/');
				name = name.substr(slash+1);
				string id = x.path().stem().string().substr(9, 8);

				cout << name << "  " << x.path().filename() << "\n";

				if (contents.find(name) == contents.end()) {
					contents.insert(
						make_pair(
							name,
							unordered_map<string, DataKit>{
								{id, DataKit{ x.path().stem().string() }}
					}));
				} else if (contents[name].find(id) == contents[name].end()) {
					contents[name].insert(make_pair(id, DataKit{ x.path().stem().string() }));
				} else contents[name][id].examine(x.path().stem().string());
			}
		}
	}

	cout << "Finish searching.\n\n\nBegin naming best results\n";
	for (auto thing : contents) {
		for (auto things_thing : thing.second) {
			cout << thing.first << "  Account:" << things_thing.first << " files:"
				<< things_thing.second.counter << " lastdate:" << things_thing.second.date << "\n";
		}
	}
}
