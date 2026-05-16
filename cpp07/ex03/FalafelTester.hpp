#ifndef FALAFEL_TESTER_HPP
# define FALAFEL_TESTER_HPP

# include <iostream>
# include "DurumFalafel.hpp"

// compile-time depth tester
template <int TestDepth>
struct FalafelTester
{
    static void testDepth(void);
    static void testWithMessage(const char* message);
};

struct FalafelPrinter
{
    static void printSeparator(void);
    static void printSuccess(int depth);
    static void printFailure(int depth);
};

# include "FalafelTester.tpp"

#endif
