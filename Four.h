#ifndef FOUR_H
#define FOUR_H

#include <string>
#include <vector>
#include <stdexcept>

class Four {
private:
    std::vector<unsigned char> digits;
    
    void removeLeadingZeros();
    void validateDigit(unsigned char digit) const;
    
public:
    Four();
    Four(const size_t& n, unsigned char value = 0);
    Four(const std::initializer_list<unsigned char>& values);
    Four(const std::string& str);
    Four(const Four& other);
    Four(Four&& other) noexcept;
    
    virtual ~Four() noexcept;
    
    Four& operator=(const Four& other);
    Four& operator=(Four&& other) noexcept;
    
    Four add(const Four& other) const;
    Four subtract(const Four& other) const;
    
    bool equals(const Four& other) const;
    bool lessThan(const Four& other) const;
    bool greaterThan(const Four& other) const;
    
    std::string toString() const;
    size_t size() const;
    bool isEmpty() const;
    
    const std::vector<unsigned char>& getDigits() const;
};

#endif