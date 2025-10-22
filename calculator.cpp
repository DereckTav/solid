#include <string>
#include <iostream>

class IDiscount {
public:
    virtual double apply(double amount) const = 0;
};

class NoDiscount : public IDiscount {
public:
    double apply(double amount) const override { return amount; }
};

class LoyalCustomerDiscount : public IDiscount {
public:
    double apply(double amount) const override { return amount * 0.95; }
};

class VIPCustomerDiscount : public IDiscount {
public:
    double apply(double amount) const override { return amount * 0.90; }
};

class DiscountCalculator {
public:
    double calculate(double amount, IDiscount& strategy) const {
        return strategy.apply(amount);
    }
};

// Included for demonstration
int main() {
    DiscountCalculator calc;
    double price = 1000;

    NoDiscount other;
    LoyalCustomerDiscount loyal;
    VIPCustomerDiscount vip;

    std::cout << "VIP Customer Price: " << calc.calculate(price, vip) << "\n";
    std::cout << "Loyal Customer Price: " << calc.calculate(price, loyal) << "\n";
    std::cout << "Other Customer Price: " << calc.calculate(price, other) << "\n";
}
