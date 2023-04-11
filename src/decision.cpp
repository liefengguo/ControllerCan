#include "decision.h"

Decision::Decision()
    : ctrlActive_(false),
      tgtGear_(0),
      throtVal_(0),
      brkVal_(0),
      angle_(0) {}

Decision::Decision(uint8_t ctrlActive,  uint8_t tgtGear, double throtVal, double brkVal, double angle)
    : ctrlActive_(ctrlActive),
      tgtGear_(tgtGear),
      throtVal_(throtVal),
      brkVal_(brkVal),
      angle_(angle) {}

void Decision::setCtrlActive(uint8_t value) {
    ctrlActive_ = value;
}

void Decision::setThrotVal(double value) {
    throtVal_ = value;
}

void Decision::setBrkVal(double value) {
    brkVal_ = value;
}

void Decision::setAngle(double value) {
    angle_ = value;
}

void Decision::setTgtGear(uint8_t value) {
    tgtGear_ = value;
}

void Decision::copyFrom(const Decision& other) {
    // 如果Decision类是派生自另一个类BaseDecision，则可以按如下方式实现copyFrom方法：
    // const auto& derived = dynamic_cast<const Decision&>(other);
    ctrlActive_ = other.ctrlActive_;
    throtVal_ = other.throtVal_;
    brkVal_ = other.brkVal_;
    angle_ = other.angle_;
    tgtGear_ = other.tgtGear_;
}

uint8_t Decision::getCtrlActive() const {
    return ctrlActive_;
}

double Decision::getThrotVal() const {
    return throtVal_;
}

double Decision::getBrkVal() const {
    return brkVal_;
}

double Decision::getAngle() const {
    return angle_;
}

uint8_t Decision::getTgtGear() const {
    return tgtGear_;
}