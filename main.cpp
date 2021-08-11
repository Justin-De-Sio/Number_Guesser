#include <iostream>
#include <string>
#include <random>


int ChooseRandomNumber(const auto &low, const auto &high) {

    std::random_device random;
    std::uniform_int_distribution range{low, high};
    return range(random);
}

int askNumber(const auto &nickname) {
    int chosen_number;
    std::cout << nickname << " choose a number between 0 and 100 :";
    std::cin >> chosen_number;
    std::cout << "\n";
    return chosen_number;
}

int main() {
    const auto LOW{0};
    const auto HIGH{100};

    std::string nickname;
    std::cout << "nickname :";
    std::cin >> nickname;

    auto cpt{0};
    std::cout << "Your Welcome ! You have 5 rounds !\n" ;
    auto secret_number = ChooseRandomNumber(LOW, HIGH);
    while (cpt<5) {
        std::cout <<"("<< ++cpt << "/5) ";
        auto chosen_number = askNumber(nickname);
        if (chosen_number > secret_number)
            std::cout << "it's smaller\n";
        else if (chosen_number < secret_number)
            std::cout << "it's bigger\n";
        else if (chosen_number == secret_number) {
            std::cout << "Good job, you win !" ;
            break;
        }
    }


}
