#pragma once

#include <cstdint>

class Bitmask {
public:
    Bitmask();

    auto setMask(Bitmask& other) -> void;
    [[nodiscard]] auto getMask() const -> uint32_t;

    [[nodiscard]] auto getBit(int pos) const -> bool;
    auto setBit(int pos, bool on) -> void;

    auto setBit(int pos) -> void;
    auto clearBit(int pos) -> void;

    auto clear() -> void;
private:
    uint32_t bits;
};