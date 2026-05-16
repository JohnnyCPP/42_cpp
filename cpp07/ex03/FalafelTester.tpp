#ifndef FALAFEL_TESTER_TPP
# define FALAFEL_TESTER_TPP

# include "FalafelTester.hpp"
# include <cstdlib>

template <int TestDepth>
void FalafelTester<TestDepth>::testDepth(void)
{
    // this will cause compilation error if depth is too high
    typename DurumFalafel<TestDepth>::Type value = 42;
    std::cout << "  - Stored value: " << value << std::endl;
    std::cout << "  - Depth reached: " << DurumFalafel<TestDepth>::depth 
              << " ChickpeaBalls" << std::endl;
}

template <int TestDepth>
void FalafelTester<TestDepth>::testWithMessage(const char* message)
{
    std::cout << "Testing: " << message << std::endl;
    testDepth();
    std::cout << "  ✓ Success!" << std::endl;
}

inline void FalafelPrinter::printSeparator(void)
{
    std::cout << "\n========================================" << std::endl;
}

inline void FalafelPrinter::printSuccess(int depth)
{
    std::cout << "✓ COMPILER HANDLED " << depth 
              << " CHICKPEABALLS! ✓" << std::endl;
}

inline void FalafelPrinter::printFailure(int depth)
{
    std::cout << "✗ Compiler limit reached at " << depth 
              << " ChickpeaBalls ✗" << std::endl;
}

#endif
