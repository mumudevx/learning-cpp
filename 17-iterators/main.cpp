#include <iostream>
#include <vector>
#include <iterator>
#include <forward_list>
#include <list>

int main() {
    // INPUT ITERATOR
/*  std::vector<int> numbers = {3, 5, 7, 9};
    std::istream_iterator<int> input(std::cin);
    std::copy(input, std::istream_iterator<int>(), std::back_inserter(numbers));*/

    // OUTPUT ITERATOR
/*  std::vector<int> nums = {1, 2, 3, 4};
    std::ostream_iterator<int> output(std::cout, ", ");
    std::copy(nums.begin(), nums.end(), output);*/

    // FORWARD ITERATOR
    std::forward_list<int> forwardNumberList = {11, 22, 66, 99};
    std::forward_list<int>::iterator iteratorOne = forwardNumberList.begin();
    while (iteratorOne != forwardNumberList.end()) {
        std::cout << *iteratorOne << " ";
        ++iteratorOne;
    }

    std::cout << std::endl << "------------------------" << std::endl;

    // REVERSE ITERATOR
    std::list<int> numberList = {11, 22, 66, 99};
    std::list<int>::reverse_iterator reverseIterator = numberList.rbegin();
    while (reverseIterator != numberList.rend()) {
        std::cout << *reverseIterator << " ";
        ++reverseIterator;
    }

    std::cout << std::endl << "------------------------" << std::endl;

    // BIDIRECTIONAL ITERATOR
    std::list<int> anotherNumberList = {33, 44, 55, 66, 77};
    std::list<int>::iterator iterator;
    for (iterator = anotherNumberList.begin(); iterator != anotherNumberList.end(); ++iterator) {
        std::cout << *iterator << " ";
    }

    std::cout << std::endl << "//////////////" << std::endl;

    for (--iterator; iterator != anotherNumberList.begin(); --iterator) {
        std::cout << *iterator << " ";
    }

    std::cout << std::endl << "------------------------" << std::endl;

    // RANDOM ACCESS ITERATOR
    std::vector<int> ohNumbersAgain = {1, 2, 3, 4};
    std::vector<int>::iterator justAnotherIterator;
    for (justAnotherIterator = ohNumbersAgain.begin();
         justAnotherIterator != ohNumbersAgain.end(); ++justAnotherIterator) {
        std::cout << *justAnotherIterator << " ";
    }

    std::cout << std::endl << "~~~~~~~~" << std::endl;

    for (justAnotherIterator -= 1; justAnotherIterator != ohNumbersAgain.begin() - 1; --justAnotherIterator) {
        std::cout << *justAnotherIterator << " ";
    }

    return 0;
}
