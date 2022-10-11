 #ifndef DATA_HPP
 # define DATA_HPP

# include <iostream>

class Data
{
	private:
		int 		data_;
		std::string	info_;
	public:
		Data();
		Data(int data, std::string info);
		Data(Data const & copy);

		Data &operator=(Data const & src);

		int get_data( void ) const;
		std::string get_info( void ) const;

		~Data();
};

 #endif