#include <iostream>
#include <concepts>

template <typename T>
concept ComplexConcept =  requires(T v)
{
	{v.toString()}
	->std::same_as<std::string>;
	{v.hash()}
	->std::convertible_to<long>;
	std::has_virtual_destructor <T>::value ;
};

class noname {
public:
		int val = 1;
		noname() {
			std::cout << "constructor\n";
		}
		std::string toString() {
			std::string text = "Concept toString\n";
			std::cout << text;
			return text;
		}
		int hash() {
			int number = 1000;
			std::cout << number << std::endl;
			
			return number;
		}
		 ~noname() {
			std::cout << "distructor\n";
		};
};

template <ComplexConcept T> void summer( T val) {
	val.toString();
	val.hash();
}

int main()
{
	noname d;
	//summer(-5);
	//summer("so");
	//summer('R');
	//summer(10L);
	//summer(10U);
	summer(d);
	return 0;
}
