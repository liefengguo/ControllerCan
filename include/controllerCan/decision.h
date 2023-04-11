#ifndef DECISION_H
#define DECISION_H

#include <cstdint>
#include <initializer_list>
class Decision {
public:
    Decision();
    Decision(uint8_t ctrlActive, uint8_t tgtGear,double throtVal, double brkVal, double angle);
    void setCtrlActive(uint8_t value);
    void setTgtGear(uint8_t value);
    void setThrotVal(double value);
    void setBrkVal(double value);
    void setAngle(double value);
    void copyFrom(const Decision& other);
    uint8_t getCtrlActive() const;
    uint8_t getTgtGear() const;
    double getThrotVal() const;
    double getBrkVal() const;
    double getAngle() const;
private:
    uint8_t ctrlActive_;
    uint8_t tgtGear_;
    double throtVal_;
    double brkVal_;
    double angle_;
};
#endif // DECISION_H