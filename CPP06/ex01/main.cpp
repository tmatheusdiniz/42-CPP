#include "Serializer.hpp"
#include <iostream>

int main()
{
	Data data;
	data.name = "Testing";
	data.value = 42;
	Data* p = &data;
	Data* p2 = nullptr;

	uintptr_t serializedData = Serializer::serialize(p);
	uintptr_t serializedData2 = Serializer::serialize(p2);
	std::cout << "Serialized Data: " << serializedData << std::endl;
	std::cout << "Serialized Data: " << serializedData2 << std::endl;
	Data* deserializedData = Serializer::deserialize(serializedData);
	std::cout << "Deserialized Data: " << deserializedData->name << ", "<< deserializedData->value << std::endl;

	std::cout << "Original Data Adress: " << &data << std::endl;
	if (&data == reinterpret_cast<Data*>(serializedData))
		std::cout << "Serialized data is the same as original data." << std::endl;
	else
		std::cout << "Serialized data is NOT the same as original data." << std::endl;
	if (deserializedData == p)
		std::cout << "Deserialized data is the same as original data." << std::endl;
	else
		std::cout << "Deserialized data is NOT the same as original data." << std::endl;
}
