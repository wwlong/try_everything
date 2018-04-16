#include <iostream>
#include <fstream>

/*
 *  cpp file operation test
 *  open
 *  write 
 *  close 
 * */

using namespace std;
int main()
{
    const char *file_name = "ftest.txt";
    ofstream outfile(file_name, ios::trunc);
    if(!outfile.is_open()) {
        std::cout << "outfile not opened\n" << endl;
        return false;
    }
    std::string msg( "hahaha, file stream output test\n");

    std::cout << "msg.length() " << msg.length() << std::endl;
    //outfile.write(msg, msg.length());
    outfile << msg;
    outfile.close();
    
    return 0;
} 
