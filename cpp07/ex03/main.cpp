#include "FalafelTester.hpp"
#include <typeinfo>

int main(void)
{
    std::cout << "\n=== 🌯 DURUM FALAFEL COMPILER DEPTH TESTER 🌯 ===" << std::endl;
    std::cout << "Testing how many ChickpeaBalls C++98 can handle!\n" << std::endl;
    
    FalafelPrinter::printSeparator();
    
    // Test 1: Small falafel (everyone should handle this)
    std::cout << "\n[TEST 1] Light Snack - Small Falafel" << std::endl;
    FalafelTester<10>::testWithMessage("10 ChickpeaBalls");
    FalafelPrinter::printSuccess(10);
    
    FalafelPrinter::printSeparator();
    
    // Test 2: Medium falafel
    std::cout << "\n[TEST 2] Regular Meal - Medium Falafel" << std::endl;
    FalafelTester<50>::testWithMessage("50 ChickpeaBalls");
    FalafelPrinter::printSuccess(50);
    
    FalafelPrinter::printSeparator();
    
    // Test 3: Large falafel
    std::cout << "\n[TEST 3] Hungry Mode - Large Falafel" << std::endl;
    FalafelTester<100>::testWithMessage("100 ChickpeaBalls");
    FalafelPrinter::printSuccess(100);
    
    FalafelPrinter::printSeparator();
    
    // Test 4: Extra large (compiler dependent)
    std::cout << "\n[TEST 4] Feast Mode - Extra Large Falafel" << std::endl;
    std::cout << "Attempting 200 ChickpeaBalls..." << std::endl;
    FalafelTester<200>::testDepth();
    FalafelPrinter::printSuccess(200);
    
    FalafelPrinter::printSeparator();
    
    // Test 5: Extreme (find your compiler's limit!)
    std::cout << "\n[TEST 5] CHALLENGE MODE - Extreme Falafel" << std::endl;
    std::cout << "Attempting 79000 ChickpeaBalls (-ftemplate-depth=)..." << std::endl;
    FalafelTester<79000>::testDepth();
    FalafelPrinter::printSuccess(79000);
    
    FalafelPrinter::printSeparator();
    
    // Demonstrate recursive unwrapping
    std::cout << "\n=== RECURSIVE UNWRAPPING DEMO ===" << std::endl;
    std::cout << "DurumFalafel<3>::Type resolves to: " 
              << typeid(DurumFalafel<3>::Type).name() << std::endl;
    
    std::cout << "\n=== FALAFEL STATISTICS ===" << std::endl;
    std::cout << "Base falafel depth: " << DurumFalafel<0>::depth << std::endl;
    std::cout << "Small falafel depth: " << DurumFalafel<10>::depth << std::endl;
    std::cout << "Medium falafel depth: " << DurumFalafel<50>::depth << std::endl;
    std::cout << "Large falafel depth: " << DurumFalafel<100>::depth << std::endl;
    std::cout << "Extra Large falafel depth: " << DurumFalafel<200>::depth << std::endl;
    std::cout << "Extreme falafel depth: " << DurumFalafel<79000>::depth << std::endl;
    std::cout << "\n=== TASTING NOTES ===" << std::endl;
    std::cout << DurumFalafel<0>::description() << std::endl;
    std::cout << "DurumFalafel<42> is a " 
              << DurumFalafel<42>::description() << std::endl;
    
    std::cout << "\n🎉 All tests completed successfully! 🎉" << std::endl;
    std::cout << "Your compiler passed the Falafel Test!\n" << std::endl;
    
    return 0;
}
