#include "Serializer.hpp"
#include <iostream>

int main(void)
{
	Data text;
	text.data = "moiii";
	std::cout << "Original data: " << text.data << std::endl;

	uintptr_t ptr = Serializer::serialize(&text);
	std::cout << "Pointer: " << ptr << std::endl;

	Data* unserializedText = Serializer::deserialize(ptr);
	std::cout << "Deserialized data: " << unserializedText->data << std::endl;
	return (0);
}
