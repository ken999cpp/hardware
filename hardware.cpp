#include "hardware.h"
Hardware::Hardware(std::string year, std::string model): model(model)
{
    if (std::stoi(year))
    {
        yearOut = year;
    }
    else
    {
        throw std::invalid_argument("Invalid date");
    }
}
std::string Hardware::getYear()
{
    return yearOut;
}
std::string Hardware::getModel()
{
    return model;
}
PC::PC(std::string year, std::string model, size_t cores, size_t ram): Hardware(year, model)
{
    if (cores != 0 && ram != 0)
    {
        this -> cores = cores;
        this -> ram = ram;
    }
    else
    {
        throw std::invalid_argument("Cores and ram > 0");
    }
}
size_t PC::getCores()
{
    return cores;
}
size_t PC::getRam()
{
    return ram;
}
std::string PC::getDeviceType()
{
    return "PC";
}
std::string PC::toString()
{
    std::stringstream ss;
    std::string yearstr, modelstr, coresstr, ramstr;
    ss << getDeviceType() << "(" << getYear() << ") | " << getModel() << "; Core: " << getCores() << "; RAM: " << getRam();
    return ss.str();
}
Monitor::Monitor(std::string year, std::string model, double screensize) : Hardware(year, model)
{
    if (screensize > 0.0)
    {
        this -> screensize = screensize;
    }
    else
    {
        throw std::invalid_argument("Screensize must be > 0");
    }
}
double Monitor::getScreenSize()
{
    return screensize;
}
std::string Monitor::getDeviceType()
{
    return "Monitor";
}
std::string Monitor::toString()
{
    std::stringstream ss;
    std::string yearstr, modelstr, inches;
    ss << getDeviceType() << "(" << getYear() << ") | " << getModel() << "; Inches: " << getScreenSize();
    return ss.str();
}
Printer::Printer(std::string year, std::string model, double ink) : Hardware(year, model)
{
    if (ink >= 0.0)
    {
        this -> ink = ink;
    }
    else
    {
        throw std::invalid_argument("Ink must be >= 0");
    }
}
double Printer::getInk()
{
    return ink;
}
std::string Printer::getDeviceType()
{
    return "Printer";
}
std::string Printer::toString()
{
    std::stringstream ss;
    std::string yearstr, modelstr, inkstr;
    ss << getDeviceType() << "(" << getYear() << ") | " << getModel() << "; Ink: " << getInk() << "%";
    return ss.str();
}
void HardwareCollection::addHardware(Hardware* obj)
{
    if (obj != nullptr)
    {
        collection.push_back(obj);
    }
}
void HardwareCollection::printAll()
{
    for (const auto& obj: collection)
    {
        std::cout << obj -> toString() << std::endl;
    }
}
void HardwareCollection::saveToFile(std::string path)
{
    std::ofstream fout(path, std::ios::binary);
    if (fout.is_open())
    {
        for (const auto& obj: collection)
        {
            if (!obj)
            {
                continue;
            }
            fout << obj -> toString() << std::endl;
        }
        fout.close();
    }
    else
    {
        throw std::runtime_error("Can't open the file");
    }
}
// Пример работы
/* int main()
{
    HardwareCollection collect;
    PC pc("2005", "NewBrand", 8, 16);
    Monitor M("2020", "Hypersonic", 24);
    Printer P("2009", "Bomj", 44.2);
    std::cout << pc.toString() << std::endl;
    collect.addHardware(&pc);
    collect.addHardware(&M);
    collect.addHardware(&P);
    collect.printAll();
    collect.saveToFile("filehard.txt");
    return 0;
}
*/
