#ifndef PARAGRAPH_H
#define PARAGRAPH_H

#include "Sentence.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>

//Novelがファイルから読み取った1シーンをまとめて管理する係
//SentenceとCharaCGを持つ
//UIを継承した名前枠も*Novelから場所もらう
class Paragraph {
public:
  Paragraph(std::string ss);//Novelから****を受け取って一行ずつvectorに順次格納

  void Draw();//vectorのSentenceのDrawsentence,charaCGを回す

private:
  std::vector<Sentence> vSentence;
  std::vector<int> vCharaNo;

  std::vector<std::string> vCharaName = {
	  "",
	  "夏目漱石"
  };
  Sentence *charaName;
  int numSentence;
  int nowSentence;

  //CharaCG

};

#endif
