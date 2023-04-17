
#include <iostream>
#include <map>

using namespace std;

class Cantor {
public:
    Cantor() = default;
    virtual ~Cantor() = default;

    virtual double Rate(const std::string& abbreviation) const = 0;
};

class Currency {
public:
    Currency() = default;
    virtual ~Currency() = default;

    virtual double ConvertedToDollars(const Cantor& cantor) const = 0;
    virtual std::string Abbreviation() const = 0;
    virtual double Amount() const = 0;
};

class GBP : public Currency {
public:
    GBP(const string& abbreviation1, double money1)
        : abbreviation(abbreviation1), money(money1) {}

    double ConvertedToDollars(const Cantor& cantor) const {
        return money / cantor.Rate(abbreviation);
    }

    std::string Abbreviation() const {
        return abbreviation;
    }

    double Amount() const {
        return money;
    }

private:
    string abbreviation;
    double money;
};

class FakeUsdCantor : public Cantor {
public:
    FakeUsdCantor() {

        rates_ = {
          {"EUR", 0.85},
          {"JPY", 110.66},
          {"GBP", 0.73},
          {"CHF", 0.91},
          {"CAD", 1.25},
          {"AUD", 1.34},
          {"CNY", 6.47},
          {"HKD", 7.78},
          {"NZD", 1.44},
          {"KRW", 1153.89}
        };
    }

    double Rate(const std::string& abbreviation) const override {
        auto it = rates_.find(abbreviation);
        if (it != rates_.end()) {
            return it->second;
        }

        return 0.0;
    }

private:
    std::map<std::string, double> rates_;
};

int main() {
    GBP value("GBP", 111);

    FakeUsdCantor cantor;

    std::cout << "abreviation: " << value.Abbreviation() << std::endl;
    std::cout << "amount converted to: " << value.ConvertedToDollars(cantor) << std::endl;
    std::cout << "amount in GBP: " << value.Amount() << std::endl;
    
    return 0;
}

