
#include <string>
#include <string_view>

constexpr std::string to_lower(std::string_view s)
{
	std::string copy{};
	copy.reserve(s.size());

	for (char c : s)
		if (c >= 'A' && c <= 'Z')
			copy += std::tolower(c); // copy += ('a' + (c - 'A'))
		else
			copy += c;
	return copy;
}

constexpr std::string to_upper(std::string_view s)
{
	std::string copy{};
	copy.reserve(s.size());

	for (char c : s)
		if (c >= 'a' && c <= 'z')
			copy += std::toupper(c); // copy += ('A' + (c - 'a'))
		else
			copy += c;
	return copy;
}

// toupper, tolower, reverse, countVowels, countConsonants, isPalindrome,
// trim, trimleft, trimright, contains
// replace, startsWith, endsWith, split, 