#include <iostream>
#include "Serializer.hpp"
#include "Data.hpp"

void printData(const Data& data, const std::string& label)
{
	std::cout << label << " -> ID: " << data.id 
	          << ", Name: " << data.name 
	          << ", Value: " << data.value << std::endl;
}

int main(void)
{
	std::cout << "========== SERIALIZATION TEST ==========" << std::endl;
	Data* original = new Data(42, "Test Object", 3.14159);
	
	std::cout << "\nOriginal data:" << std::endl;
	printData(*original, "Original");
	std::cout << "Original pointer address: " << original << std::endl;
	
	std::cout << "\n--- Serializing ---" << std::endl;
	uintptr_t raw = Serializer::serialize(original);
	std::cout << "Serialized value (uintptr_t): " << raw << std::endl;
	
	std::cout << "\n--- Deserializing ---" << std::endl;
	Data* deserialized = Serializer::deserialize(raw);
	std::cout << "Deserialized pointer address: " << deserialized << std::endl;
	
	std::cout << "\n--- Verification ---" << std::endl;
	if (deserialized == original)
		std::cout << "SUCCESS: Pointers are equal!" << std::endl;
	else
		std::cout << "FAIL: Pointers are different!" << std::endl;
	
	std::cout << "\nDeserialized data:" << std::endl;
	printData(*deserialized, "Deserialized");
	
	std::cout << "\n--- Modifying deserialized data ---" << std::endl;
	deserialized->id = 100;
	deserialized->name = "Modified Object";
	deserialized->value = 2.71828;
	
	std::cout << "After modification:" << std::endl;
	printData(*original, "Original (should be changed)");
	printData(*deserialized, "Deserialized");
	
	if (original->id == 100 && original->name == "Modified Object" && original->value == 2.71828)
		std::cout << "\nSUCCESS: Both pointers point to the SAME object!" << std::endl;
	else
		std::cout << "\nFAIL: Objects are different copies!" << std::endl;
	
	delete original;
	
	std::cout << "\n========== TEST COMPLETED ==========" << std::endl;
	
	return 0;
}
