#include "stdafx.h"
#include "TAE3.h"
#include <algorithm> 
#include <cctype>
#include <locale>

TAE3::TAE3()
{
	sumcos = 0;
	sumsin = 0;
	avV = 0;
	avD = 0;
	dcnt = 0;
	sunh = 0;
	terr = 0;
	herr = 0;
	maxH = 0;
	step = 2000;
	header = true;
	tae_data = "";
	nextH = 0;
}

// trim from start (in place)
string trim(const string& str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return str;
	}
	size_t last = str.find_last_not_of(' ');
	return str.substr(first, (last - first + 1));
}

static inline string clr_str(std::string s) {
	
	string res = "";
	for (int i = 0; i != s.length(); i++)
	{
		if (((s[i] >= '0') && (s[i] <= '9')) || (s[i] == ' ') || (s[i] == '-') || (s[i] == '.') || (s[i] == '.'))
		{
			res += s[i];
		}
	}
	return res;
}

static inline void ltrim(std::string &s) {
	s.erase(s.begin(), std::find_if(s.begin(), s.end(), [](int ch) {
		return !std::isspace(ch);
	}));
}

// trim from end (in place)
static inline void rtrim(std::string &s) {
	s.erase(std::find_if(s.rbegin(), s.rend(), [](int ch) {
		return !std::isspace(ch);
	}).base(), s.end());
}

vector<string> split(const string& str, const string& delim)
{
	vector<string> tokens;
	size_t prev = 0, pos = 0;
	do
	{
		pos = str.find(delim, prev);
		if (pos == string::npos) pos = str.length();
		string token = str.substr(prev, pos - prev);
		rtrim(token);
		ltrim(token);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

void TAE3::addString(string str)
{
	string str1 = str;
	
	str1 = trim(str1);
	
	if (!header)
	{
		str1 = clr_str(str1);
		vector<string> data = split(str1, " ");
		if (data.size() < 6)
			return;
		char d_digits[5];
		float H = atof(data[0].c_str());
		int Hi = (int)(H * 1000);
		if (nextH==0)
			nextH = Hi+step;
		if (Hi>nextH)
		{
			tae_data = "" + tae_data + "" + str;
			tae_data += '\n';
			nextH = nextH + step;
		}
	}
	else
	{
		tae_data += str;
		tae_data += '\n';
	}
	if (str1[0] == 'H')
		header = false;
}

void TAE3::addString_legacy(string str2)
{
	
}

void TAE3::addSunString(string sun)
{
	
}

void TAE3::addTempErrorString(string terror)
{
	
}

void TAE3::addHumErrorString(string humerror)
{
	
}

void TAE3::compute()
{
	
}

void TAE3::saveResults(string filename)
{
	of.open(filename.c_str());
	of << tae_data;
	of.close();
}