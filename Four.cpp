#include "Four.h"
#include <algorithm>
#include <stdexcept>

void Four::validateDigit(unsigned char digit) const {
    if (digit > 3) {
        throw std::invalid_argument("Digit must be between 0 and 3 for base-4 system");
    }
}

void Four::removeLeadingZeros() {
    while (digits.size() > 1 && digits.back() == 0) {
        digits.pop_back();
    }
}

Four::Four() {}

Four::Four(const size_t& n, unsigned char value) {
    validateDigit(value);
    digits.resize(n, value);
    removeLeadingZeros();
}

Four::Four(const std::initializer_list<unsigned char>& values) {
    for (auto it = values.begin(); it != values.end(); ++it) {
        validateDigit(*it);
        digits.push_back(*it);
    }
    std::reverse(digits.begin(), digits.end());
    removeLeadingZeros();
}

Four::Four(const std::string& str) {
    if (str.empty()) {
        return;
    }
    
    for (auto it = str.rbegin(); it != str.rend(); ++it) {
        char c = *it;
        if (c < '0' || c > '3') {
            throw std::invalid_argument("Invalid base-4 digit in string. Only 0-3 allowed.");
        }
        digits.push_back(static_cast<unsigned char>(c - '0'));
    }
    removeLeadingZeros();
}

Four::Four(const Four& other) : digits(other.digits) {}

Four::Four(Four&& other) noexcept : digits(std::move(other.digits)) {}

Four::~Four() noexcept {}

Four& Four::operator=(const Four& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

Four& Four::operator=(Four&& other) noexcept {
    if (this != &other) {
        digits = std::move(other.digits);
    }
    return *this;
}

Four Four::add(const Four& other) const {
    Four result;
    size_t maxSize = std::max(digits.size(), other.digits.size());
    unsigned char carry = 0;
    
    for (size_t i = 0; i < maxSize || carry; ++i) {
        unsigned char sum = carry;
        if (i < digits.size()) sum += digits[i];
        if (i < other.digits.size()) sum += other.digits[i];
        
        result.digits.push_back(sum % 4);
        carry = sum / 4;
    }
    
    return result;
}

Four Four::subtract(const Four& other) const {
    if (lessThan(other)) {
        throw std::invalid_argument("Result would be negative");
    }
    
    Four result;
    unsigned char borrow = 0;
    
    for (size_t i = 0; i < digits.size(); ++i) {
        unsigned char diff = digits[i] - borrow;
        if (i < other.digits.size()) {
            if (diff < other.digits[i]) {
                diff += 4;
                borrow = 1;
            } else {
                borrow = 0;
            }
            diff -= other.digits[i];
        } else {
            borrow = 0;
        }
        result.digits.push_back(diff);
    }
    
    result.removeLeadingZeros();
    return result;
}

bool Four::equals(const Four& other) const {
    return digits == other.digits;
}

bool Four::lessThan(const Four& other) const {
    if (digits.size() != other.digits.size()) {
        return digits.size() < other.digits.size();
    }
    
    for (int i = digits.size() - 1; i >= 0; --i) {
        if (digits[i] != other.digits[i]) {
            return digits[i] < other.digits[i];
        }
    }
    
    return false;
}

bool Four::greaterThan(const Four& other) const {
    return !lessThan(other) && !equals(other);
}

std::string Four::toString() const {
    if (digits.empty()) {
        return "0";
    }
    
    std::string result;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        result += static_cast<char>('0' + *it);
    }
    return result;
}

size_t Four::size() const {
    return digits.size();
}

bool Four::isEmpty() const {
    return digits.empty() || (digits.size() == 1 && digits[0] == 0);
}

const std::vector<unsigned char>& Four::getDigits() const {
    return digits;
}