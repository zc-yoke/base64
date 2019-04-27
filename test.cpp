#include <iostream>
#include <string.h>
#include <fstream>
#include <assert.h>
#include "b64.h"
using namespace std;
int main()
{
    char pause[10];
    //==========测试字符串=============
    cout<<"start to test base64 library"<<endl;
    cout<<"input y to test encode and decode text string:";
    cin>>pause;
    const char* str="here is content";
    //转base64
    char* enc=b64_encode((unsigned char*)str,strlen(str));
    //转原文本
    unsigned char* decode=b64_decode(enc,strlen(enc));
    assert(memcmp(str,decode,strlen(str))==0);
    free(enc);
    free(decode);
    cout<<"success to test encode and decode text string!"<<endl;
    //==========测试文本文件=============
    cout<<"input y to test encode and decode text file:";
    cin>>pause;
    //将html文件内容全部读入内存
    //读取一个文件内容
    const char * textFilename = "test.txt";
    ifstream textFileStream(textFilename,ios::in);
    assert(textFileStream.is_open());
    //获得文件大小
    textFileStream.seekg(0, ios::end);
    size_t tetxFileSize=textFileStream.tellg();
    //将读取位置设置在文件头部
    textFileStream.seekg(0, ios::beg);
    char* textData = new char [tetxFileSize+1];
    memset(textData,0,tetxFileSize+1);
    textFileStream.read(textData,tetxFileSize);
    textFileStream.close();
    //将内容转换为base64
    char* htmlEnc=b64_encode((unsigned char*)textData,strlen(textData));
    //转原文本
    unsigned char* htmlDecode=b64_decode(htmlEnc,strlen(htmlEnc));
    //对比
    assert(memcmp(textData,htmlDecode,strlen(textData))==0);
    free(htmlEnc);
    free(htmlDecode);
    delete[] textData;
    cout<<"success to test encode and decode text file"<<endl;
    //==========测试二进制数据数组=============
    cout<<"input y to test encode and decode binary buffer in memory:";
    cin>>pause;
    unsigned char buffer[5]= {0x10,0x12,0x13,0x14,0x15};
    //将内容转换为base64
    char* bufferEnc=b64_encode(buffer,5);
    //转原数据
    size_t bufferLength=0;
    unsigned char* bufferDecode=b64_decode_ex(bufferEnc,strlen(bufferEnc),&bufferLength);
    //对比
    assert(bufferLength==5);
    assert(memcmp(bufferDecode,buffer,5)==0);
    free(bufferEnc);
    free(bufferDecode);
    cout<<"success to test encode and decode binary buffer in memory"<<endl;
    //==========测试二进制文件=============
    cout<<"input y to test encode and decode binary file:";
    cin>>pause;
    const char * binaryFilename = "bird.png";
    ifstream binaryFileStream(binaryFilename,ios::in|ios::binary);
    assert(binaryFileStream.is_open());
    //获得文件大小
    binaryFileStream.seekg(0, ios::end);
    size_t binaryFileSize=binaryFileStream.tellg();
    //将读取位置设置在文件头部
    binaryFileStream.seekg(0, ios::beg);
    unsigned char* bianryData = new unsigned char [binaryFileSize];
    binaryFileStream.read((char*)bianryData,binaryFileSize);
    binaryFileStream.close();
    //将内容转换为base64
    char* binaryEnc=b64_encode(bianryData,binaryFileSize);
    //转原数据
    size_t binaryFileBufferLength=0;
    unsigned char* binaryDecode=b64_decode_ex(binaryEnc,strlen(binaryEnc),&binaryFileBufferLength);
    //对比
    cout<<binaryFileBufferLength<<"<->"<<binaryFileSize<<endl;
    assert(binaryFileBufferLength==binaryFileSize);
    assert(memcmp(bianryData,binaryDecode,binaryFileSize)==0);
    free(binaryEnc);
    free(binaryDecode);
    delete[]bianryData;
    ofstream binaryFileOutStream("./test/bird.png",ios::out|ios::binary|ios::trunc);
    binaryFileOutStream.write((char*)binaryDecode,binaryFileBufferLength);
    binaryFileOutStream.close();
    cout<<"success to test encode and decode binary file"<<endl;
    cout<<"input y to exit base64 library test program:";
    cin>>pause;
    return 0;
}

