#include "util.h"
#include <execution>
#include <algorithm>


ReaderFile::ReaderFile(std::string fileName)
{
	coutReadWord = 0;
	file.open(fileName);
}

int ReaderFile::getCountReadWord()
{
	return coutReadWord;
}

bool  ReaderFile::isOpen()
{
	return file.is_open();
}

std::string ReaderFile::getNextWord()
{
	std::string str;

	if (file.is_open())
	{
		file >> str;
		
		std::for_each(str.begin(), str.end(), [](char& c) { c = std::tolower(c);});

		//str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) { return !std::isspace(ch);}));

		//str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {return !std::isspace(ch);}).base(), str.end());

		str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](unsigned char ch) { 
			return std::isalnum(ch) || std::isalnum(ch); }));

		str.erase(std::find_if(str.rbegin(), str.rend(), [](unsigned char ch) {return std::isalnum(ch) || std::isalnum(ch); }).base(), str.end());

		if (str.length()>0)
		{
			coutReadWord++;
		}
		
		return str;
	}
	throw std::exception("file is not open");
}

void ReaderFile::close()
{
	file.close();
}

ReaderFile::~ReaderFile()
{
	if (file.is_open())
	{
		file.close();
	}
}

bool ReaderFile::isEOF()
{
	return file.eof();
}