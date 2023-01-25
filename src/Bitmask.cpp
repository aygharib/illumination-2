#include "Bitmask.h"

#include <cstdint>

Bitmask::Bitmask() : bits(0) {}

auto Bitmask::setMask(Bitmask &other) -> void {
    bits = other.getMask();
}

auto Bitmask::getMask() const -> uint32_t {
    return bits;
}

auto Bitmask::getBit(int pos) const -> bool {
    return (bits & (1 << pos)) != 0;
}

auto Bitmask::setBit(int pos, bool on) -> void {
    on ? setBit(pos) : clearBit(pos);
}

auto Bitmask::setBit(int pos) -> void {
    bits = bits | 1 << pos;
}

auto Bitmask::clearBit(int pos) -> void {
    bits = bits & ~(1 << pos);
}

auto Bitmask::clear() -> void {
    bits = 0;
}