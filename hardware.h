#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdexcept>
class Hardware;
class Hardware
{
    private:
        std::string yearOut;
        std::string model;
    public:
        Hardware() = delete;
        Hardware(std::string year, std::string model);
        std::string getYear();
        std::string getModel();
        virtual std::string getDeviceType() = 0;
        virtual std::string toString() = 0;
};
class PC: public Hardware
{
    private:
        size_t cores;
        size_t ram;
    public:
        PC() = delete;
        PC(std::string year, std::string model, size_t cores, size_t ram);
        size_t getCores();
        size_t getRam();
        virtual std::string getDeviceType() override;
        virtual std::string toString() override;
};
class Monitor: public Hardware
{
    private:
        double screensize;
    public:
        Monitor() = delete;
        Monitor(std::string year, std::string model, double screensize);
        double getScreenSize();
        virtual std::string getDeviceType() override;
        virtual std::string toString() override;
};
class Printer: public Hardware
{
    private:
        double ink;
    public:
        Printer(std::string year, std::string model, double ink);
        double getInk();
        virtual std::string getDeviceType() override;
        virtual std::string toString() override;
};
class HardwareCollection
{
    private:
        std::vector<Hardware*> collection;
    public:
        void addHardware(Hardware* obj);
        void printAll();
        void saveToFile(std::string path);
};