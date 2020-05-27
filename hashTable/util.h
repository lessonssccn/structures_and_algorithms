#pragma once
#include <string>
#include <fstream>

class ReaderFile
{
	std::ifstream file;
	int coutReadWord;
public:
	ReaderFile(std::string fileName);
	bool isOpen();
	bool isEOF();
	std::string getNextWord();
	void close();
	int getCountReadWord();
	~ReaderFile();
	
};