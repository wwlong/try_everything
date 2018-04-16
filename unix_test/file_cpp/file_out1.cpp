#include <iostream>
#include <fstream>


int main()
{
    std::ofstream out("haha.txt");
    if(out.is_open()) {
        out << "hahaha" << std::endl;

        out.close();
    }

    else {
        std::cout << "failed to open file\r\n";
    }

    return 0;
}
