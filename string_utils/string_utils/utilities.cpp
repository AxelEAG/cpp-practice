
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


std::string trim(std::string_view s, char toTrim=' ')
{
	std::string copy{};
	copy.reserve(s.size());

	for (char c : s)
	{
		if (c != toTrim)
			copy += c;
	}
	return copy;
}

std::string trim_left(std::string_view s, char toTrim = ' ')
{
	std::size_t i{ 0 };
	while (i < s.size() && s[i] == toTrim)
		++i;

	return std::string{ s.substr(i) };
}

std::string trim_right(std::string_view s, char toTrim = ' ')
{
	std::size_t i { s.size() };
	while (i > 0 && s[i - 1] == toTrim)
		--i;

	return std::string{ s.substr(0, i) };
}

bool isDigit(char c)
{
	return(c >= '0' && c <= '9');
}

// Checks if string is just a number
bool isNumber(std::string_view s)
{
	if (s.size() == 0)
		return false;

	std::size_t i{ 0 };
	if (s[i] == '+' || s[i] == '-')
		++i;

	for ( ; i < s.size(); ++i)
	{
		if (!isDigit(s[i])
			return false;
	}

	return true;
}

// countVowels, countConsonants, isPalindrome,
// contains
// replace, startsWith, endsWith, split, 

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

	assert(trim("hello") == "hello");
	assert(trim(" he1lo") == "he1lo");
	assert(trim(",hello@,", ',') == "hello@");
	assert(trim(" ,hel,l,o, ", ',') == " hello ");
	assert(trim("h") == "h");
	assert(trim("", '.') == "");

	assert(trim_left("hello") == "hello");
	assert(trim_left("  hello") == "hello");
	assert(trim_left("a hello") == "a hello");
	assert(trim_left(",,,hello", ',') == "hello");
	assert(trim_left(",.,hello", ',') == ".,hello");
	assert(trim_left("h") == "h");
	assert(trim_left("", '.') == "");


	assert(trim_right("hello") == "hello");
	assert(trim_right("hello a") == "hello a");
	assert(trim_right("hello  ") == "hello");
	assert(trim_right("hello,,,", ',') == "hello");
	assert(trim_right("hello,.,", ',') == "hello,.");
	assert(trim_right("h") == "h");
	assert(trim_right("", '.') == "");

	assert(isDigit('1') == true);
	assert(isDigit('7') == true);
	assert(isDigit('a') == false);
	assert(isDigit('#') == false);
	assert(isDigit(' ') == false);

	assert(isNumber("1") == true);
	assert(isNumber("137123") == true);
	assert(isNumber("+1341") == true);
	assert(isNumber("-137841") == true);
	assert(isNumber("s137841") == false);
	assert(isNumber("-1378s41") == false);
	assert(isNumber("-137841#") == false);
	assert(isNumber("137841#") == false);




	return 0;
}
