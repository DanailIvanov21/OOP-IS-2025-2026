#pragma once
#include "Device.h"

enum class SecurityLockType {
    FaceRecognition = 0,
    Fingerprint = 1
};

class Phone : public Device {
private:
    int cameras;
    SecurityLockType lockType;

public:
    Phone();
    Phone(const char* model, const char* brand, int price,
          int cameras, SecurityLockType lock);

    Phone(const Phone& other) = default;
    Phone& operator=(const Phone& other) = default;
    ~Phone() override = default;

    int getCameras() const;
    SecurityLockType getLockType() const;

    void setCameras(int c);
    void setLockType(SecurityLockType lt);

    void print(std::ostream& os) const override;
    void saveToFile(std::ostream& os) const override;
    void loadFromFile(std::istream& is) override;
    Device* clone() const override;
};
