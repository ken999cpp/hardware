#include <iostream>
#include <fstream>
#include <string>
int main()
{
    std::ifstream inf("SomeText.txt");
    if (!inf)
    {
        std::cerr << "Can't open the file" << std::endl;
        return -1;
    }
    else
    {
        while (inf)
        {
            std::string str;
            std::getline(inf, str);
            std::cout << str << std::endl;
        }
    }
    inf.close();
    return 0;
}