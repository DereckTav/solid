#include <iostream>

class IFlyable {
public:
    virtual void fly() = 0;
};

class Bird {
public:
    virtual void lay_egg() {
            std::cout << "Egg\n";
        }
};

class Ostrich : public Bird{};

class Eagle : public Bird, public IFlyable {
public:
    void fly() override {
        std::cout << "Eagle is flying\n";
    }
};

int main() {

    Eagle eagle;
    Ostrich ostrich;
    
    eagle.lay_egg();
    eagle.fly();

    ostrich.lay_egg();
}
