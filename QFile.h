#pragma once
#include <string>
#include <stdio.h>

class QFile
{
public:
	QFile(const char* fullpath, const char* mode);
	~QFile();

public:
	bool isOpen() const;
	const char* readAll() const;

private:
	FILE* m_file;
	std::string m_filename;
};

