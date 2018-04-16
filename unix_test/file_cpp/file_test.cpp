#include <iostream>
#include <fstream>
/*
 *  cpp file operation
 * */
/*
 *  文件的类
 *  打开
 *  读写
 *  关闭
 * */
using namespace std;
int main()
{
    string filename = "ftest.txt";
    std::fstream fp(filename, fp.out | fp.in | fp.app);
    if(!fp.is_open()) {
        cout << "fp open failed\n";
        return -1;
    }
    /*
     *  先测试写
     * */
    string write_str = "hahaha,write to file\n";
    fp << write_str;
    string msg = "123456";
    fp.write(msg.c_str(),  msg.length());
    /*
     *  测试读 
     * */
    fp.seekp(0);
    string rdstr;
    std::getline(fp, rdstr, (char)EOF);
    cout << rdstr << endl;
    fp.close();
    return 0;
}
