#include "../inc/Serializer.hpp"

int main() {
	Data *data = new Data;
	Data *deserial;
	uintptr_t serial;

	data->content = "Bananinha";
	serial = Serializer::serialize(data);
	deserial = Serializer::deserialize(serial);
	std::cout << "Serialized: " << serial << std::endl;
	std::cout << "Original: " << data->content << std::endl;
	std::cout << "Deserialized: " << deserial->content << std::endl;
	std::cout << "Memory address check:\n    Original: " << data << "\n    Deserial: " << deserial << std::endl;
	delete data;
}