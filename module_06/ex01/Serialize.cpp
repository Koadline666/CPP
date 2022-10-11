
# include "Serialize.hpp"

uintptr_t serialize(Data* ptr)
{
	uintptr_t ret = reinterpret_cast<std::uintptr_t>(ptr);
	return(ret);
}

Data* deserialize(uintptr_t raw)
{
	
	return(data);
}