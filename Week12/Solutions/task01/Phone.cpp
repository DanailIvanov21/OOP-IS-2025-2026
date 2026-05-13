#include "Phone.h"
#include <stdexcept>

Phone::Phone()
    : Device(), cameras(0), lockType(SecurityLockType::Fingerprint) {}

Phone::Phone(const char* m, const char* b, int p,
             int c, SecurityLockType lt)
    : Device(m, b, p), cameras(0), lockType(lt) {
    setCameras(c);
}

int Phone::getCameras() const { return cameras; }
SecurityLockType Phone::getLockType() const { return lockType; }

void Phone::setCameras(int c) {
    if (c < 0)
        throw std::invalid_argument("Cameras cannot be negative");
    cameras = c;
}

void Phone::setLockType(SecurityLockType lt) {
    lockType = lt;
}

void Phone::print(std::ostream& os) const {
    os << "Phone: " << (brand ? brand : "N/A")
       << " " << (model ? model : "N/A")
       << ", price: " << price
       << ", cameras: " << cameras
       << ", lock: " << (lockType == SecurityLockType::FaceRecognition
                         ? "FaceRecognition" : "Fingerprint");
}

void Phone::saveToFile(std::ostream& os) const {
    os << "PHONE\n";
    os << (brand ? brand : "") << "\n";
    os << (model ? model : "") << "\n";
    os << price << "\n";
    os << cameras << "\n";
    os << (lockType == SecurityLockType::FaceRecognition ? 0 : 1) << "\n";
}

void Phone::loadFromFile(std::istream& is) {
    char buffBrand[256], buffModel[256];
    int p, c, lt;

    if (!is.getline(buffBrand, 256))
        throw std::runtime_error("Failed to read phone brand");
    if (!is.getline(buffModel, 256))
        throw std::runtime_error("Failed to read phone model");
    if (!(is >> p))
        throw std::runtime_error("Failed to read phone price");
    if (!(is >> c))
        throw std::runtime_error("Failed to read phone cameras");
    if (!(is >> lt))
        throw std::runtime_error("Failed to read phone lock type");
    is.ignore();

    setBrand(buffBrand);
    setModel(buffModel);
    setPrice(p);
    setCameras(c);
    lockType = (lt == 0 ? SecurityLockType::FaceRecognition
                        : SecurityLockType::Fingerprint);
}

Device* Phone::clone() const {
    return new Phone(*this);
}
