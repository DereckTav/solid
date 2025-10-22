#include <iostream>
#include <sstream>
#include <string>

class DataProcessor {
public:
    int process(const std::string& data) const {
        std::istringstream iss(data);
        int number, sum = 0;
        while (iss >> number) {
            sum += number;
        }
        return sum;
    }
};

class Formatter {
public:
    std::string format(const std::string& title, int result) const {
        return "<h1>" + title + "</h1>\n<p>" + title + ": " + std::to_string(result) + "</p>";
    }
};

class Report {
public:
    std::string title;
    std::string data;
    DataProcessor processor;
    Formatter formatter;

    Report(const std::string& t, const std::string& d): title(t), data(d) {
        processor = DataProcessor(); 
        formatter = Formatter(); 
    }

    std::string generateReport() const {
        int result = processor.process(data);
        return formatter.format(title, result);
    }
};


// Included for demonstration
int main() {
    Report report("Total sales", "51 42 39 60");
    std::cout << report.generateReport();
}
