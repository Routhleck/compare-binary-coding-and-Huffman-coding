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
	return size; //单位是：byte
}

int main() {

	//时间相关
	time_t t = time(NULL);
	struct tm now_time;
	localtime_s(&now_time, &t);
	int timeRecord1 = 0;
	int timeRecord2 = 0;

	//设置路径
	string srcPath("F:\\c++_sourceCode\\discreteMath\\huff\\Huffman效率问题\\Huffman效率问题\\压缩文件1.txt");
	string dstPath_Huff("F:\\c++_sourceCode\\discreteMath\\huff\\Huffman效率问题\\压缩目录\\压缩文件1.huff");
	string dstPath_Bin("F:\\c++_sourceCode\\discreteMath\\huff\\Huffman效率问题\\压缩目录\\压缩文件1.bin");
	
	//哈夫曼计时开始
	cout << "哈夫曼编码开始..." << endl;
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord1 = now_time.tm_min * 60 + now_time.tm_sec;

	//哈夫曼编码
	Encode(srcPath,dstPath_Bin);

	//计算哈夫曼压缩率
	int target = GetFileSize(dstPath_Huff);
	int src = GetFileSize(srcPath);
	double rate_Huff = ((double)target / (double)src) * 100;
	cout << "哈夫曼编码压缩率为:" << rate_Huff << "%" << endl;

	//哈夫曼计时结束
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord2 = now_time.tm_min * 60 + now_time.tm_sec;
	int timeCount_Huff = timeRecord2 - timeRecord1;
	cout << "哈夫曼编码耗时为:" << timeCount_Huff << "s" << endl;

	//二进制计时开始
	cout << "二进制编码开始..." << endl;
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord1 = now_time.tm_min * 60 + now_time.tm_sec;

	//二进制编码
	BinEncode(srcPath,dstPath_Bin);

	//计算二进制压缩率
	target = GetFileSize(dstPath_Bin);
	src = GetFileSize(srcPath);
	double rate_Bin = ((double)target / (double)src) * 100;
	cout << "二进制编码压缩率为:" << rate_Bin << "%" << endl;

	//二进制计时结束
	time(&t);
	localtime_s(&now_time, &t);
	timeRecord2 = now_time.tm_min * 60 + now_time.tm_sec;
	timeCount_Huff = timeRecord2 - timeRecord1;
	cout << "二进制编码耗时为:" << timeCount_Huff <<"s" << endl;
}