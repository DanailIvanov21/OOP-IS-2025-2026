#include "Computer.h"
#include <cstring>
#include <stdexcept>

void Computer::freeDynamic() {
    delete[] videoModel;
    videoModel = nullptr;

    delete[] peripherals;
    peripherals = nullptr;
    perCount = 0;
}

void Computer::copyDynamic(const Computer& other) {
    char* newVideo = nullptr;
    if (other.videoModel) {
        newVideo = new char[strlen(other.videoModel) + 1];
        strcpy(newVideo, other.videoModel);
    }

    MyString* newPer = nullptr;
    if (other.perCount > 0) {
        newPer = new MyString[other.perCount];
        for (size_t i = 0; i < other.perCount; i++)
            newPer[i] = other.peripherals[i];
    }

    freeDynamic();
    videoModel = newVideo;
    peripherals = newPer;
    perCount = other.perCount;
}

Computer::Computer(double cpu, const char* video, int psu, int ram)
    : cpuPower(cpu), videoModel(nullptr), psuPower(psu), ram(ram),
      peripherals(nullptr), perCount(0) {
    setVideoModel(video);
}

Computer::Computer(const Computer& other)
    : cpuPower(other.cpuPower), videoModel(nullptr),
      psuPower(other.psuPower), ram(other.ram),
      peripherals(nullptr), perCount(0) {
    copyDynamic(other);
}

Computer& Computer::operator=(const Computer& other) {
    if (this != &other) {
        Computer temp(other);
        freeDynamic();

        cpuPower = temp.cpuPower;
        psuPower = temp.psuPower;
        ram = temp.ram;

        videoModel = temp.videoModel;
        peripherals = temp.peripherals;
        perCount = temp.perCount;

        temp.videoModel = nullptr;
        temp.peripherals = nullptr;
    }
    return *this;
}

Computer::~Computer() {
    freeDynamic();
}

void Computer::setCpuPower(double p) {
    if (p < 0) throw std::invalid_argument("Invalid CPU power");
    cpuPower = p;
}

void Computer::setVideoModel(const char* v) {
    if (!v) throw std::invalid_argument("Null video model");
    char* newV = new char[strlen(v) + 1];
    strcpy(newV, v);
    delete[] videoModel;
    videoModel = newV;
}

void Computer::setPsuPower(int p) {
    if (p < 0) throw std::invalid_argument("Invalid PSU power");
    psuPower = p;
}

void Computer::setRam(int r) {
    if (r < 0) throw std::invalid_argument("Invalid RAM");
    ram = r;
}

double Computer::getCpuPower() const { return cpuPower; }
const char* Computer::getVideoModel() const { return videoModel; }
int Computer::getPsuPower() const { return psuPower; }
int Computer::getRam() const { return ram; }
