#ifndef ARRAY_TPP
# define ARRAY_TPP

# include "Array.hpp"

template <class T>
class Array
{
	private:

		int size_;
		T	*array_;

	public:
		Array():size_(0)
			{ array_ = new T[0]; };
		Array(int n):size_(n)
			{ array_ = new T[n]; };
		Array(Array const & src)
			{ array_ = new T[0]; *this = src; };

		Array &operator=(Array const & copy)
		{
			size_ = copy.size();
			delete[] array_;
			array_ = new T[size_];
			for (int i = 0; i < size_; i++)
				array_[i] = copy[i];
			return(*this);
		}

		T	&operator[](int n) const
		{
			if (n < 0 || n >= size_)
				throw std::out_of_range("out of range");
			return(array_[n]);
		}

		int size( void ) const { return(size_); };

		void setValue(T value, int n)
		{
			if (n < 0 || n >= size_)
				throw std::out_of_range("out of range");
			array_[n] = value;
		}

		~Array() { delete[] array_; };
};

#endif