#include <iostream>
#include "stack.hpp"
#include <stack>

#ifndef NAMESPACE
# define NAMESPACE ft
#endif

int main    (void)
{
    NAMESPACE::stack<int>  stack1;
    NAMESPACE::stack<int>  stack2;
    
    std::cout << "******* FT::STACK_1 *******" << std::endl;
    std::cout << std::endl;
    std::cout << "stack1.push(): filling the container" << std::endl;
    for (size_t i = 0; i < 10; i++)
        stack1.push(i);
    std::cout << std::endl;

    std::cout << "stack1.empty(): " << std::boolalpha << stack1.empty() << std::endl;
    std::cout << "stack2.empty(): " << std::boolalpha << stack2.empty() << std::endl;
    std::cout << std::endl;
    std::cout << "-+-Copying stack1 into stack2-+-" << std::endl;
    std::cout << std::endl;
    stack2 = stack1;

    for (size_t i = 0; i < 10; i++)
    {   
        std::cout << "stack1.size(): " << stack1.size() << std::endl;
        std::cout << std::endl;
        std::cout << "stack1.top(): " << stack1.top() << std::endl;
        std::cout << std::endl;
        std::cout << "stack1.pop(): removing the element" << std::endl;
        stack1.pop();
        std::cout << std::endl;
    }

    std::cout << "******* FT::STACK_2 *******" << std::endl;
    std::cout << std::endl;
    std::cout << "stack2.push(): filling the second container" << std::endl;
    for (size_t i = 10; i < 20; i++)
        stack1.push(i);

    std::cout << std::endl;
    std::cout << "-+-Comparing two stacks-+-" << std::endl;
    std::cout << std::endl;

    std::cout << "------- ft::operator == -------" << std::endl;
    std::cout << std::boolalpha << (stack1 == stack2) << std::endl;

    std::cout << "------- ft::operator != -------" << std::endl;
    std::cout << std::boolalpha << (stack1 != stack2) << std::endl;

    std::cout << "------- ft::operator < -------" << std::endl;
    std::cout << std::boolalpha << (stack1 < stack2) << std::endl;

    std::cout << "------- ft::operator <= -------" << std::endl;
    std::cout << std::boolalpha << (stack1 <= stack2) << std::endl;

    std::cout << "------- ft::operator > -------" << std::endl;
    std::cout << std::boolalpha << (stack1 > stack2) << std::endl;

    std::cout << "------- ft::operator >= -------" << std::endl;
    std::cout << std::boolalpha << (stack1 >= stack2) << std::endl;

}