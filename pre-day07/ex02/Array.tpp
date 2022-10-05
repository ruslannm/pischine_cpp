#ifndef ARRAY_TPP
#define ARRAY_TPP

template<typename T>
Array<T>::Array(void): _array(NULL), _size(0) { 
	std::cout << "Default contrustor is called." << std::endl;};
template<typename T>
		Array<T>::Array (unsigned int size) {
			_size = size;
			if (_size){
				_array = new T[_size];
			} else {
				_array = NULL;
			}
			return;
		};
template<typename T>
		Array<T>::Array (const Array<T>& src) {
			
			std::cout << "Copy contrustor is called." << std::endl;
			_size = src._size;
			if (_size){
			_array = new T[_size];
			}
			else {
				_array = NULL;
			}

			for (unsigned int i = 0; i < _size; ++i)
			{
				_array[i] = src._array[i];
				}
				

			};
template<typename T>
		Array<T>::~Array (void) {delete [] _array;};
template<typename T>
		Array<T>&	 Array<T>::operator=(const Array<T>& rhs)
		{
			std::cout << "Copy Assignment operator is called." << std::endl;
			if (this != &rhs) {
                if (_array){
                    delete [] _array;
                }
			_size = rhs._size;
			_array = new T[_size];

			for (unsigned int i = 0; i < _size; ++i)
			{
				_array[i] = rhs._array[i];}
				}
			return *this;
		};
template<typename T>
		T&	Array<T>::operator[](int idx)
		{
			if (0 <= idx && static_cast<unsigned int>(idx) < _size)
				return _array[idx];
			else
				throw Array<T>::IndexOutOfBonds();
		};
template<typename T>
unsigned		int	Array<T>::size(void) const
		{
			return _size;
		};
template<typename T>
const char * Array<T>::IndexOutOfBonds::what (void) const throw() {
                    return "Index is out of bounds";};

template<typename T>
void	iter(Array<T>  arr, void (*fun)(T const &))
{
	for (unsigned int i = 0; i < arr.size(); ++i){
		fun(arr[i]);
    }
    return;
};

template<typename T>
void	printElement(T & element)
{
	std::cout << element << std::endl;
    return;
};

#endif
