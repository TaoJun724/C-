
//���ļ�IO�����ı��������Ʒ�ʽ��ʾ�����ļ��Ķ�д


#define  _CRT_SECURE_NO_WARNINGS  1
#include<iostream>
#include<string>
#include<fstream>
using namespace std;

struct ServerInfo
{
	char ip[32];//һ��ip��
	int port;//�˿ں�
};

//�����Ʒ�ʽ�������ļ�
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

//�ı���ʽ�������ļ�
struct TextConfigManager
{
public:
	TextConfigManager(const char* configfile = "server.config")
		:_configfile(configfile)
	{}
	//c������Ҫ�Ȱ�����itoa��д
	void Write(const ServerInfo& info)
	{
		ofstream  openfile(_configfile);
		openfile << info.ip << endl;
		openfile << info.port << endl;
		openfile.close();
	}
	//c����Ҫ�ȶ��ַ�������atoi
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

//�����ƵĲ���
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