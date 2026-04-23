
#include <string>
#include <string_view>

std::string to_lower(std::string_view s)
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

std::string to_upper(std::string_view s)
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

std::string reverse(std::string_view s)
{
	std::string copy{};
	copy.reserve(s.size());

	for (std::size_t i{ s.size()}; i > 0; --i)
	{
		copy += s[i - 1];
	}
	return copy;
}

int main()
{
	return 0;
}

// toupper, tolower, reverse, countVowels, countConsonants, isPalindrome,
// trim, trimleft, trimright, contains
// replace, startsWith, endsWith, split, 