#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "Sentence.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

//Novel���t�@�C������ǂݎ����1�V�[�����܂Ƃ߂ĊǗ�����W
//Sentence��CharaCG������
//UI���p���������O�g��*Novel����ꏊ���炤
class Paragraph {
public:
  Paragraph(std::string ss);//Novel����****���󂯎���Ĉ�s����vector�ɏ����i�[

  void Draw();//vector��Sentence��Drawsentence,charaCG����

private:
  std::vector<Sentence> vSentence;
  std::vector<int> vCharaNo;

  std::vector<std::string> vCharaName = {
	  "",
	  "�Ėڟ���"
  };
  Sentence *charaName;
  int numSentence;
  int nowSentence;

  //CharaCG

};

#endif
