#include <iostream>
#include "Four.h"

int main() {
    try {
        Four num1("123");
        Four num2("32");
        
        std::cout << "Number 1: " << num1.toString() << std::endl;
        std::cout << "Number 2: " << num2.toString() << std::endl;
        
        Four sum = num1.add(num2);
        std::cout << "Sum: " << sum.toString() << std::endl;
        
        Four diff = num1.subtract(num2);
        std::cout << "Difference: " << diff.toString() << std::endl;
        
        std::cout << "num1 equals num2: " << (num1.equals(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 less than num2: " << (num1.lessThan(num2) ? "true" : "false") << std::endl;
        std::cout << "num1 greater than num2: " << (num1.greaterThan(num2) ? "true" : "false") << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}