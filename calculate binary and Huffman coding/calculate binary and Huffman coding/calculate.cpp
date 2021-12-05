#include <iostream>
#include <time.h>
#include "HuffmanTree.h"
#include "BinEncode.h"
#include <string>
#include <time.h>
using namespace std;

size_t GetFileSize(const std::string& file_name) {
	struct _stat info;
	_stat(file_name.c_str(), &info);
	size_t size = info.st_size;
	return size; //��λ�ǣ�byte
}

int main() {

	//ʱ�����
	time_t t = time(NULL);
	struct tm now_time;
	localtime_s(&now_time, &t);
	int timeRecord1 = 0;
	int timeRecord2 = 0;

	//����·��
	string srcPath("F:\\c++_sourceCode\\discreteMath\\huff\\HuffmanЧ������\\HuffmanЧ������\\ѹ���ļ�1.txt");
	string dstPath_Huff("F:\\c++_sourceCode\\discreteMath\\huff\\HuffmanЧ������\\ѹ��Ŀ¼\\ѹ���ļ�1.huff");
	string dstPath_Bin("F:\\c++_sourceCode\\discreteMath\\huff\\HuffmanЧ������\\ѹ��Ŀ¼\\ѹ���ļ�1.bin");
	
	//��������ʱ��ʼ
	cout << "���������뿪ʼ..." << endl;
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord1 = now_time.tm_min * 60 + now_time.tm_sec;

	//����������
	Encode(srcPath,dstPath_Bin);

	//���������ѹ����
	int target = GetFileSize(dstPath_Huff);
	int src = GetFileSize(srcPath);
	double rate_Huff = ((double)target / (double)src) * 100;
	cout << "����������ѹ����Ϊ:" << rate_Huff << "%" << endl;

	//��������ʱ����
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord2 = now_time.tm_min * 60 + now_time.tm_sec;
	int timeCount_Huff = timeRecord2 - timeRecord1;
	cout << "�����������ʱΪ:" << timeCount_Huff << "s" << endl;

	//�����Ƽ�ʱ��ʼ
	cout << "�����Ʊ��뿪ʼ..." << endl;
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord1 = now_time.tm_min * 60 + now_time.tm_sec;

	//�����Ʊ���
	BinEncode(srcPath,dstPath_Bin);

	//���������ѹ����
	target = GetFileSize(dstPath_Bin);
	src = GetFileSize(srcPath);
	double rate_Bin = ((double)target / (double)src) * 100;
	cout << "�����Ʊ���ѹ����Ϊ:" << rate_Bin << "%" << endl;

	//�����Ƽ�ʱ����
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord2 = now_time.tm_min * 60 + now_time.tm_sec;
	timeCount_Huff = timeRecord2 - timeRecord1;
	cout << "�����Ʊ����ʱΪ:" << timeCount_Huff <<"s" << endl;
}