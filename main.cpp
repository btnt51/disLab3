#include <iostream>
#include "prototypes.h"

int main() {
    std::cout << "First list" << std::endl;
    auto *list = new MyList;
    Insert(list,1,1);
    Insert(list,2,2);
    Insert(list,3,3);
    Print(list);
    Delete(&list,3);
    Print(list);
    First(list);
    delete list;
    std::cout << std::endl;
    std::cout << "Second list example of First()";
    auto *anotherList = new MyList;
    First(anotherList);
    delete anotherList;
    std::cout << "\n";
    system("pause");
    return 0;
}
