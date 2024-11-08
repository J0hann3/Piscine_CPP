# CPP_Module0

>Ce document contient les exercices du Module 00 des C++ modules

[Subject CPP Module 0 Project 42](https://cdn.intra.42.fr/pdf/pdf/113963/en.subject.pdf)

## New Notion

### [Namespaces](https://en.cppreference.com/w/cpp/language/namespace)
- Namespace are blocks to prevent function's, method's, variable's, class's name conflicts in large projects
- Namespace block can have multiple namespaces inside them, ex: **std::ifstream::in**
- Acces method or function in ***standart*** namespace : **std::\<method>**
- Acces method or function in ***global*** namespace : **::\<method>**
- **using namespace std;** will always use function from the standart namespace -> ***forbidden at 42School***
- **using std::cout;** will specify to always use cout from the standart namespace

- Example :
```c++
namespace user
{
	void print();
}

namespace phone
{
	void print();
	int call(char *text);
}

int main()
{
	namespace p = phone;

	user::print();		//will use the function print of the user namespace
	print();			//will use the function print of the global namespace
	b::print();			//will use the function print of the phone namespace
}
```

### [Standart Stream input output](https://en.cppreference.com/w/cpp/io)
- write to the standart output : **std::cout <<**
- read from the standart input : **std::cin >>**
- return new line depending on the computer architecture : **std::endl;**

- Example :
```c++
#include <iostream>

int main()
{
	std::string name;
 
	std::cout << "Enter your name:" <<std::endl;
	std::cin >> name;
}
```

### [Class](https://en.cppreference.com/w/cpp/language/class)
- A class can contain variables and functions, which are call method
- Constructor : initialize the class
- Destructor : is call when the instance is not use anymore
- with the keyword **private** element are visible only in the class
- with the keyword **public** element are visible everywhere
- Each variable can have a getter and a setter to modify or get the member, that are private
- Each method have an invisible parameter, which is a pointer to the class instance 
that have call the metod. Its name is **this**
- Example :
```c++
#include <string>

class Animal
{
private :
	std::string	_name;
	int _nbPatte;
	std::string _sound;
public :
	Animal();			//Constructor
	~Animal();			//Destructor
	void makeSound();	//Method
	void print();
	void setName(std::string name);
}

Animal::Animal() : _name("Default") _nbPatte(4) _sound("Miaouu")		//Constructor initialize in list
{}

void setName(std::string name)
{
	_name = name;	//similar to this->_name = name;
}

Animal::~Animal()		//Destructor
{}

int main
{
	Animal dog;		//create an instance object

	dog.makeSound();	//But can't do pet._name; because it private
}
```

### [Static method and member](https://en.cppreference.com/w/cpp/language/static)
- static member of class is the same betweeen all the instance of this class
- static member is initialize directly in the cpp file : **int Class::_name = Value;**
- To acces a static member : **Class::_name**  
  
- static method don't require instance of the class to call it : **Class::method();**
- static method don't have the keyword **this**, because there is no instance to refer
- static method are initialize like the other method, without the keyword **static**

### [Const](https://en.cppreference.com/w/cpp/keyword/const)
- this keyword mean that this element will never change, it's constant

- Example :
```c++
int main
{
	int const a = 10;		//Similar to const int a = 10;
	//a = 2;	is an error

	int tmp = 30;
	int tmp1 = 50;

	int const *b = &tmp1;
	//*b = 13;	is an error. The content of the pointer is const
	b = &tmp;

	int * const b = &tmp1;
	*b = 13;
	//b = &tmp; is an error. Impossible to change the address of the pointer
}
```
- a method in a class can also be const. it's impossible to change the member of this function : **std::string getText() const;**

### [Pointers to members](https://en.cppreference.com/w/cpp/language/pointer)

- Example :

```c++
#include <string>
#include <iostream>

class Animal
{
public :
	std::string	name;
	int nbPatte;
	std::string sound;

	Animal();			//Constructor
	~Animal();			//Destructor
	void makeSound(void);	//Method
	void print();
	void setName(std::string name);
}

int main()
{
	Animal instance1;
	
	std::string	Animal::*pointer = NULL;
	void		(Animal::*function)(void);

	pointer = &Animal::name;
	function = &Animal::makeSound;

	std::cout << "Name :" << instance1.name << std::endl;
	instance1.*pointer = "Chien";
	std::cout << "Name :" << instance1.name << std::endl;

	(instance1.*function)();		// If instance1 was a pointeur it would be (instance1->*function)();
}

```

### Class vs Struct

- Class is private by default
- Struct is public by default
- It also true for the inheritance acces
