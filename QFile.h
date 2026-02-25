#pragma once
#include <string>
#include <stdio.h>

class QFile
{
public:
	QFile();
	~QFile();

public:
	bool open(const char* filename, const char* mode);
	bool isOpen() const;
	bool readAll(std::string& content) const;
	void close();

public:
	static bool readTextfile(const char* filename, std::string& content);

private:
	FILE* m_file = NULL;
	std::string m_filename;
	std::string m_mode;
};

