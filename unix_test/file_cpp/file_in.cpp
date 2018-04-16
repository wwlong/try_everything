#include <iostream>
#include <fstream>
#include <string>

using namespace std;
/*
 *  打开文件
 *  读
 *  关闭
 * */

int main()
{
    string str;
    char buf[256];
    std::ifstream in("haha.txt");
    if(!in.is_open()) {
        std::cerr << "file open failed\n";
        return -1;
    }
    int cnt = 0;
    while(!in.eof()) {
        getline(in, str);
        cout << str << cnt ++ << endl;

    }
    
    in.close();
    return 0;
} 
