// splicing lists
#include <iostream>
#include <list>

int main() {
    std::list<int> mylist1, mylist2;
    std::list<int>::iterator it;

    // set some initial values:
    for (int i = 1; i <= 4; ++i)
        mylist1.push_back(i);      // mylist1: 1 2 3 4

    for (int i = 1; i <= 3; ++i)
        mylist2.push_back(i * 10);   // mylist2: 10 20 30

    it = mylist1.begin();
    ++it;                         // points to 2

    mylist1.splice(it, mylist2); // mylist1: 1 10 20 30 2 3 4
    // mylist2 (empty)
    // "it" still points to 2 (the 5th element)

    mylist2.splice(mylist2.begin(), mylist1, it);
    // mylist1: 1 10 20 30 3 4
    // mylist2: 2
    // "it" is now invalid.
    it = mylist1.begin();
    std::advance(it, 3);           // "it" points now to 30

    mylist1.splice(mylist1.begin(), mylist1, it, mylist1.end());
    // mylist1: 30 3 4 1 10 20

    std::cout << "mylist1 contains:";
    for (it = mylist1.begin(); it != mylist1.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    std::cout << "mylist2 contains:";
    for (it = mylist2.begin(); it != mylist2.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}
//entire list (1)
//void splice (iterator position, list& x);
//single element (2)
//void splice (iterator position, list& x, iterator i);
//element range (3)
//void splice (iterator position, list& x, iterator first, iterator last);
//Transfer elements from list to list
//Transfers elements from x into the container, inserting them at position.
//
//This effectively inserts those elements into the container and removes them from x, altering the sizes of both containers. The operation does not involve the construction or destruction of any element. They are transferred, no matter whether x is an lvalue or an rvalue, or whether the value_type supports move-construction or not.
//
//The first version (1) transfers all the elements of x into the container.
//The second version (2) transfers only the element pointed by i from x into the container.
//The third version (3) transfers the range [first,last) from x into the container.