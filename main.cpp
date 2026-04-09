#include <iostream>
#include "SingleList.cpp"

int main() {

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

    return 0;

}
