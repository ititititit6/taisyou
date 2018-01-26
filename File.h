#ifndef FILE_H
#define FILE_H

#include <string>
#include <iostream>
#include <fstream>
#include <DxLib.h>

#include "const.h"

class File {
public:
	File();
	~File();

	//for read
	void readHeader();

	void openArc();
	void closeArc();

	void readFile(std::string fileName);
	void seekFile();
	void fileSize();

	//for archive
	void writeHeader();
	//void fileSize(); void ??
	void zip();


private:
	std::string headerPath;
	std::string archivePath;

	std::string currentDir;

	//�t�@�C�������|�C���^
	int currntPointer;
	int currentFileSize;


};

/*
�t�@�C�������K��
�e�L�X�g:
	�V�i���I:Scene{Scene�ԍ�}.txt
	�L�����Ή��\:CharaNo.txt



�L���������G:
{�L�����ԍ�}_{�p�^�[��}.xxx


BGM:
BGM{BGM�ԍ�}.mp3




*/




#endif