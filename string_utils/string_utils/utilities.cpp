
#include <string>
#include <string_view>
#include <cassert>

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
	// For now won't check on non-ASCII
	assert(to_lower("hello") == "hello");
	assert(to_lower("Hello") == "hello");
	assert(to_lower("HELLO") == "hello");
	assert(to_lower("H") == "h");
	assert(to_lower("h") == "h");
	assert(to_lower("") == "");
	assert(to_lower("1HeLLo123") == "1hello123");
	assert(to_lower("!@#") == "!@#");
	assert(to_lower(" Hi ") == " hi ");

	assert(to_upper("HELLO") == "HELLO");
	assert(to_upper("hELLO") == "HELLO");
	assert(to_upper("hello") == "HELLO");
	assert(to_upper("H") == "H");
	assert(to_upper("h") == "H");
	assert(to_upper("") == "");
	assert(to_upper("1HeLlo123") == "1HELLO123");
	assert(to_upper("!@#") == "!@#");
	assert(to_upper(" Hi ") == " HI ");

	assert(reverse("HELLO") == "OLLEH");
	assert(reverse("HE") == "EH");
	assert(reverse("H") == "H");
	assert(reverse("") == "");
	assert(reverse("a b ") == " b a");
	assert(reverse(reverse("hello")) == "hello");

	return 0;
}

// toupper, tolower, reverse, countVowels, countConsonants, isPalindrome,
// trim, trimleft, trimright, contains
// replace, startsWith, endsWith, split, 