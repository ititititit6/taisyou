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

	//ファイル走査ポインタ
	int currntPointer;
	int currentFileSize;


};

/*
ファイル命名規則
テキスト:
	シナリオ:Scene{Scene番号}.txt
	キャラ対応表:CharaNo.txt



キャラ立ち絵:
{キャラ番号}_{パターン}.xxx


BGM:
BGM{BGM番号}.mp3




*/




#endif