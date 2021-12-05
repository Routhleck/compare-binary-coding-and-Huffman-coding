#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include "BinEncode.h"
using namespace std;

void BinEncode(string filename, string saveto) {

	ifstream src(filename, ios::binary);
	if (!src.is_open()) {
		cerr << "无法打开指定的文件：" + filename << endl;
		return;
	}
	//读取&写入

	ofstream outFile(saveto, ios::out | ios::binary);	
	string content;
	unsigned char buff;
	while (src.read(reinterpret_cast<char*>(&buff), 1)) {
		content += buff;
		//outfile << convert(content) << endl;
		outFile.write((char*)&buff, sizeof(buff));
	}

	outFile.close();

}