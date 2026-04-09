#include <iostream>
#include "../termcolor/termcolor.hpp"
#include "SingleList.cpp"

void Double_list(){};

void Single_list () {
    SingleList<int> single_list(5);
    single_list.push_back(10);
    single_list.push_front(20);
    single_list.push_front(30);

    std::cout << "Size of single list = " << single_list.get_size() << std::endl;

    single_list.printList();

    single_list.pop_front();

    std::cout << "Size of single list = " << single_list.get_size() << std::endl;

    single_list.printList();

    single_list[0] = 67;
    single_list.printList();

    single_list.insert(222, 2);
    single_list.printList();

    single_list.remove(3);
    single_list.printList();

    std::cout << "index: "<< single_list.find(333) <<std::endl;
}

int main() {
    int choice = 0;
    std::cout<< termcolor::bright_magenta<<"~~~~Work with Lists~~~~"<<termcolor::reset<<std::endl;
    std::cout << "1. Single list" << std::endl;
    std::cout << "2. Double list" << std::endl;
    std::cout << "3. Exit" << std::endl;

    while (choice != 3) {
        std::cout << "Choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                Single_list();
            case 2:
                Double_list();
        }
    }
    return 0;

}
