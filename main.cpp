#include <iostream>
#include "stack.hpp"

int main    (void)
{
    ft::stack<int>  t, s;

    std::cout   << (t == s)
                << std::endl;
    
    t.push(3);
    t.push(5);
    t.push(9);

    std::cout << t.top() << std::endl;
    // std::vector<int>    v ({0,1,2}); = cpp 11
   
}