#include <iostream>
#include <string>
#include <random>


int chooseRandomNumber() {
    auto low{0}, high{0};
    std::cout << "minimum border :";
    std::cin >> low;
    std::cout << "\nmaximum border:";
    std::cin >> high;
    std::cout << "\n";

    std::random_device random;
    std::uniform_int_distribution range{low, high};
    return range(random);
}

int askNumber(const auto &nickname) {
    int chosen_number;
    std::cout << nickname << " choose a number";
    std::cin >> chosen_number;
    std::cout << "\n";
    return chosen_number;
}

int main() {

    const auto cpt_max{5};
    std::string nickname;
    std::cout << "nickname :";
    std::cin >> nickname;
    bool continue_ = true;
    while (continue_) {
        auto cpt{0};
        auto secret_number = chooseRandomNumber();
        system("cls");
        std::cout << "Your Welcome ! You have 5 rounds !\n";
        while (cpt < cpt_max) {
            std::cout << "(" << ++cpt << "/" << cpt_max << ") ";
            auto chosen_number = askNumber(nickname);
            if (chosen_number > secret_number)
                std::cout << "it's smaller\n";
            else if (chosen_number < secret_number)
                std::cout << "it's bigger\n";
            else if (chosen_number == secret_number) {
                std::cout << "Good job, you win !";
                break;
            }
            if (cpt == cpt_max && chosen_number != secret_number)
                std::cout << "You lost! The secret number was : " << secret_number << "\n";
        }


        std::cout << "do you want to continue ? [yes/no] : ";
        std::string question;
        std::cin >> question;
        if (question != "yes")
            continue_ = false;
    }


}
