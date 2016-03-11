#include "walk.h"

namespace os {
inline namespace v1 {

using namespace std::experimental::filesystem;
using std::vector;

WalkEntry::WalkEntry(path const& root, vector<path> const& dirs, vector<path> const& files) :
	root(root), dirs(dirs), files(files) {

}

detail::generator<WalkEntry> walk(path rootDir, bool followLinks /*= false*/) {
	auto options = followLinks ? 
		directory_options::follow_directory_symlink : 
		directory_options::none;
	recursive_directory_iterator it(rootDir, options), end;
	do {
		if (is_directory(rootDir)) {
			vector<path> dirs;
			vector<path> files;
			copy_if(
				directory_iterator{rootDir}, 
				directory_iterator{},
				back_inserter(dirs), 
				[] (auto& e) { return is_directory(e); });
			copy_if(directory_iterator{rootDir},
				directory_iterator{},
				back_inserter(files),
				[] (auto& e) { return !is_directory(e); });
			__yield_value WalkEntry(rootDir, dirs, files);
		}
		rootDir = *it;
	} while (++it != end);
}


}
}