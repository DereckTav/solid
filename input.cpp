#include <iostream>
#include <memory>

class IInput {
public:
    virtual std::string getInput() = 0;
};

class Keyboard : public IInput {
public:
    std::string getInput() override {
        return "User input from keyboard";
    }
};

class Mouse : public IInput {
public:
    std::string getInput() override {
        return "User input from mouse";
    }
};

// Right now this code assumes that input will come from the keyboard, 
// but we would like to be able to create an InputProcessor that 
// accepts input from the mouse (and potentially other input devices
// in the future). Note that each InputProcessor only needs to deal
// with one device.
class InputProcessor {
public:
    void processInput(IInput& device) {
        if (typeid(device) == typeid(Keyboard)) {
            std::cout << "Using Keyboard device\n";
        }
        else if (typeid(device) == typeid(Mouse)) {
            std::cout << "Using Mouse device\n";
        }

        std::string input = device.getInput();
        std::cout << "Processing: " << input << std::endl;
    }
};

// For demonstration
int main() {
    InputProcessor processor;
    Mouse mouse;
    processor.processInput(mouse);
}
