#pragma once

#include <experimental/filesystem>
#include <experimental/generator>
#include <experimental/resumable>
#include <iostream>
#include <iterator>
#include <vector>

namespace os {
inline namespace v1 {
namespace detail {
	using path = std::experimental::filesystem::path;
	template <typename... Ts> using generator = std::experimental::generator<Ts...>;
}

struct WalkEntry {
	WalkEntry(detail::path const& root, std::vector<detail::path> const& dirs, std::vector<detail::path> const& files);
	detail::path root;
	std::vector<detail::path> dirs;
	std::vector<detail::path> files;
};

detail::generator<WalkEntry> walk(detail::path rootDir, bool followLinks = false);

}
}