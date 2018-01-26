#include "File.h"

File::File() {
	headerPath = HEADER_PATH;
	archivePath = ARCHIVE_PATH;
	currentDir = "../";
}


File::~File() {
	//closeArc();
}

