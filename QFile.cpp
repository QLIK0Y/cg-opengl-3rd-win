#include "QFile.h"
#include <errno.h> // for errno_t on MSVC

QFile::QFile() : m_file(NULL) {
}

QFile::~QFile() {
	close();
}

bool QFile::open(const char* filename, const char* mode) {
	// If a file is already open, close it first.
	close();

	// fopen_s signature (MSVC): errno_t fopen_s(FILE** pFile, const char* filename, const char* mode);
	errno_t err = fopen_s(&m_file, filename, mode);
	if (err == 0 && m_file != NULL) {
		m_filename = filename;
		m_mode = mode;
		return true;
	}

	// Ensure m_file is NULL on failure.
	m_file = NULL;
	return false;
}

bool QFile::isOpen() const {
	return m_file != NULL;
}

void QFile::close() {
	if (m_file != NULL) {
		fclose(m_file);
		m_file = NULL;
	}
}

bool QFile::readAll(std::string& content) const {
	if (!isOpen()) {
		return false;
	}

	// Seek to end to determine file size
	if (fseek(m_file, 0, SEEK_END) != 0) {
		return false;
	}

	long size = ftell(m_file);
	if (size < 0) {
		// ftell failed; attempt to restore position and return error
		fseek(m_file, 0, SEEK_SET);
		return false;
	}

	// Seek back to beginning
	if (fseek(m_file, 0, SEEK_SET) != 0) {
		return false;
	}

	// Use std::string to manage the buffer safely.
	size_t sz = static_cast<size_t>(size);
	content.resize(sz);

	if (sz > 0) {
		size_t read = fread(&content[0], 1, sz, m_file);
		if (read != sz) {
			// Short read: resize to actual bytes read
			content.resize(read);
			// Note: could check ferror/more handling if desired
		}
	}

	return true;
}

bool QFile::readTextfile(const char* filename, std::string& content) {
	QFile file;
	if (!file.open(filename, "r")) {
		return false;
	}
	return file.readAll(content);
}