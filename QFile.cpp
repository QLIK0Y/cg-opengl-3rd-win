#include "QFile.h"

QFile::QFile(const char* fullpath, const char* mode) {
	m_filename = fullpath;
	m_file = fopen(fullpath, mode);
}

QFile::~QFile() {
	if (m_file != NULL) {
		fclose(m_file);
	}
}

bool QFile::isOpen() const {
	return m_file != NULL;
}

const char* QFile::readAll() const {
	ftelll(m_file, 0, SEEK_END);
	
}