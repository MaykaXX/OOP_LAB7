#include <iostream>
#include "../termcolor/termcolor.hpp"
#include "SingleList.cpp"
#include "DoubleList.cpp"

void Double_list() {
    std::cout<<termcolor::bright_yellow << "Double list"<<termcolor::reset << std::endl;

    DoubleList<int> double_list(2);
    double_list.push_front(10);
    double_list.push_back(20);
    try {
        double_list.pop_front();
        double_list.pop_front();
    }catch (const char* msg) {
        std::cout << "Error: " << msg << std::endl;
    }
    double_list.printList();
    double_list.pop_back();
    double_list.printList();
    std::cout << double_list.is_empty() << std::endl;

    double_list.insert(1234, 0);
    double_list.insert(2345, 1);
    double_list.printList();
    double_list.remove(0);
    double_list.printList();

    std::cout << double_list.find(2345) <<std::endl;

};

void Single_list () {
std::cout<<termcolor::bright_yellow << "Single list"<<termcolor::reset << std::endl;    SingleList<int> single_list(5);
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
                break;
            case 2:
                Double_list();
                break;
        }
    }
    return 0;

}
