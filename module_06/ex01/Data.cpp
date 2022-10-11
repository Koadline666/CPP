# include "Data.hpp"

Data::Data(): data_(0), info_("empty") {}

Data::Data(int data, std::string info): data_(data), info_(info) {}

Data::Data(Data const & copy)
{
	*this = copy;
}

Data &Data::operator=(Data const & src)
{
	data_ = src.get_data();
	info_ = src.get_info();
	return (*this);
}

int Data::get_data( void ) const { return(data_); }

std::string Data::get_info( void ) const { return(info_); }

Data::~Data() {}