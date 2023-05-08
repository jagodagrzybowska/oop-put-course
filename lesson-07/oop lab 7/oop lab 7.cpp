
#include <iostream>
#include <cmath>
#include <stdexcept>
#include <string>

class LogarithmException : public std::invalid_argument {
public:
    explicit LogarithmException(const std::string& mess)
        : std::invalid_argument(mess) {}
};

class Logarithm {
public:
    Logarithm(double base, double argument) {

        if ((base < 0) || (base == 1))
        {
            throw LogarithmException("wrong base - base has to be positive (excluding 1)");
        }
        if (argument <= 0)
        {
            throw LogarithmException("wrong argument - argument has to be positive");
        }
        base_ = base;
        argument_ = argument;
    }

    double Calculate() const {
        return std::log(argument_) / std::log(base_);
    }

private:
    double base_;
    double argument_;
};

int main() {

    try {
        Logarithm(-2, 10);
    }
    catch (const LogarithmException& e) {
        std::cerr << "Caught an exception: " << e.what() << std::endl;
    }

    return 0;
}