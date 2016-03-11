#include "walk.h"

using std::cout;
using std::endl;

int main() {
	auto i = 0u;
	for (auto& elem : os::walk("c:\\windows")) {
		cout << "Root path = " << elem.root << endl;
		cout << "Dirs = ";
		for (auto& dir : elem.dirs) {
			cout << dir.filename() << " ";
		}
		cout << endl << "Files = ";
		for (auto& file : elem.files) {
			cout << file.filename() << " ";
		}
		cout << endl;
		if (i == 4) {
			break;
		}
		++i;
	}
}