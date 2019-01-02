
//用文件IO流用文本及二进制方式演示配置文件的读写


#define  _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct ServerInfo
{
	char ip[32];//一个ip号
	int port;//端口号
};

//二进制方式的配置文件
struct BinaryConfigManager
{
public:
	BinaryConfigManager(const char* configfile = "server.config")
		:_configfile(configfile)
	{}

	void Write(const ServerInfo& info)
	{
		ofstream  openfile(_configfile, ifstream::in | ifstream::binary);
		openfile.write((const char*)&info, sizeof(ServerInfo));
		openfile.close();
	}

	void Read(ServerInfo& info)
	{
		ifstream infile(_configfile, ifstream::out | ifstream::binary);
		infile.read((char*)&info, sizeof(ServerInfo));
		infile.close();
	}
private:
	string _configfile;
};

//文本方式的配置文件
struct TextConfigManager
{
public:
	TextConfigManager(const char* configfile = "server.config")
		:_configfile(configfile)
	{}
	//c语言需要先把整型itoa再写
	void Write(const ServerInfo& info)
	{
		ofstream  openfile(_configfile);
		openfile << info.ip << endl;
		openfile << info.port << endl;
		openfile.close();
	}
	//c语言要先读字符串，再atoi
	void Read(ServerInfo& info)
	{
		ifstream infile(_configfile);
		infile >> info.ip;
		infile >> info.port;
		infile.close();
	}
private:
	string _configfile;
};

//二进制的测试
void BinaryTest()
{
	BinaryConfigManager file1;
	ServerInfo write;
	ServerInfo read;
	strcpy(write.ip, "127.0.0.1");
	write.port = 80;
	file1.Write(write);
	file1.Read(read);
	cout << read.ip << endl;
	cout << read.port << endl;
}

void TextTest()
{
	TextConfigManager file;
	ServerInfo write;
	ServerInfo read;
	strcpy(write.ip, "127.0.0.1");
	write.port = 80;
	file.Write(write);
	file.Read(read);
	cout << read.ip << endl;
	cout << read.port << endl;
}
int main()
{
	  BinaryTest();
	  TextTest();
	system("pause");
}