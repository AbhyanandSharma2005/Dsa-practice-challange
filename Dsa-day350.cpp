#include <iostream>

int main() {
    int age;
    int count = 0;
    int total_income = 0;
    bool is_invalid = false;

    while (std::cin >> age && age != -1) {
        count++;
        if (count > 20) {
            is_invalid = true;
        }
        if (age <= 0 || age > 120) {
            is_invalid = true;
        }

        if (!is_invalid) {
            if (age < 17) {
                total_income += 200;
            } else if (age <= 40) {
                total_income += 400;
            } else {
                total_income += 300;
            }
        }
    }

    if (is_invalid) {
        std::cout << "INVALID INPUT" << std::endl;
    } else {
        std::cout << "Total income: " << total_income << " INR" << std::endl;
    }

    return 0;
}