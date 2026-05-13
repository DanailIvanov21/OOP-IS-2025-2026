#include "Laptop.h"
#include <stdexcept>

Laptop::Laptop()
    : Device(), os(OSType::Windows), hasThunderbolt(false), ports(0) {}

Laptop::Laptop(const char* m, const char* b, int p,
               OSType o, bool t, int prt)
    : Device(m, b, p), os(o), hasThunderbolt(t), ports(0) {
    setPorts(prt);
}

OSType Laptop::getOS() const { return os; }
bool Laptop::getHasThunderbolt() const { return hasThunderbolt; }
int Laptop::getPorts() const { return ports; }

void Laptop::setOS(OSType o) { os = o; }
void Laptop::setHasThunderbolt(bool h) { hasThunderbolt = h; }

void Laptop::setPorts(int p) {
    if (p < 0)
        throw std::invalid_argument("Ports cannot be negative");
    ports = p;
}

void Laptop::print(std::ostream& osStream) const {
    osStream << "Laptop: " << (brand ? brand : "N/A")
             << " " << (model ? model : "N/A")
             << ", price: " << price
             << ", OS: "
             << (os == OSType::MacOS ? "MacOS" :
                 os == OSType::Linux ? "Linux" : "Windows")
             << ", ports: " << ports
             << ", " << (hasThunderbolt ? "Thunderbolt" : "USB");
}

void Laptop::saveToFile(std::ostream& osStream) const {
    osStream << "LAPTOP\n";
    osStream << (brand ? brand : "") << "\n";
    osStream << (model ? model : "") << "\n";
    osStream << price << "\n";
    osStream << (os == OSType::MacOS ? 0 :
                 os == OSType::Linux ? 1 : 2) << "\n";
    osStream << (hasThunderbolt ? 1 : 0) << "\n";
    osStream << ports << "\n";
}

void Laptop::loadFromFile(std::istream& is) {
    char buffBrand[256], buffModel[256];
    int p, osCode, t, prt;

    if (!is.getline(buffBrand, 256))
        throw std::runtime_error("Failed to read laptop brand");
    if (!is.getline(buffModel, 256))
        throw std::runtime_error("Failed to read laptop model");
    if (!(is >> p))
        throw std::runtime_error("Failed to read laptop price");
    if (!(is >> osCode))
        throw std::runtime_error("Failed to read laptop OS");
    if (!(is >> t))
        throw std::runtime_error("Failed to read laptop port type");
    if (!(is >> prt))
        throw std::runtime_error("Failed to read laptop ports");
    is.ignore();

    setBrand(buffBrand);
    setModel(buffModel);
    setPrice(p);

    if (osCode == 0) os = OSType::MacOS;
    else if (osCode == 1) os = OSType::Linux;
    else os = OSType::Windows;

    hasThunderbolt = (t != 0);
    setPorts(prt);
}

Device* Laptop::clone() const {
    return new Laptop(*this);
}
