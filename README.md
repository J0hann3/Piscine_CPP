# CPP_Module1

>Ce document contient les exercices du Module 01 des C++ modules.

[Subject CPP Module 1 Project 42](https://cdn.intra.42.fr/pdf/pdf/89227/en.subject.pdf)

## New Notion

### [New](https://en.cppreference.com/w/cpp/language/new)
- New create and initialize an object with dynamic memory (malloc in C)
- For a class, it will allocate the memory then call the constructor of the class

### [Delete](https://en.cppreference.com/w/cpp/language/delete)
- Delete free the memory alloacte by new, then call the destructor of the element if there is one
- Delete[] is use to free an array
- Example :
```c++
class Animal;

int main()
{
	int nb = 89;
	int *value = new int;
	int *tab = new int[nb];
	Animal *dog = new Animal("dog");

	*value = 42;

	delete value;
	delete[] tab;
	delete dog;
}
```

### [Reference](https://en.cppreference.com/w/cpp/language/reference)
- Reference is an alias to an alredy existing object or function
- Reference need to be initialize
- There are no arrays of references, no pointers to references, and no references to references

- Example :
```c++
#include <iostream>

int main()
{
	int a = 5;
	int &b = a;

	std::cout << "Address : " << &b << std::endl;
	std::cout << "Address : " << &a << std::endl;

	std::cout << "Value : " << b << std::endl;
	std::cout << "Value : " << a << std::endl;
}
```

### Filestream
#### Input File
- to open a input file : **std:ifstream ifs("name", std::ifstream::in);**
- **std::ifstream::in** is mode to open the file, here its in reading
- to check if the file is correctly open : **ifs.is_open()**
- to read in the file : **ifs >> word;** or **std::getline(ifs, line);**
- to find the end of file : **ifs.eof()**
- to close the file : **ifs.close()**
#### Output File
- to open a output file : **std:ofstream ofs("name", std::ofstream::out);**
- **std::ofstream::out** is mode to open the file, here its in writing
- to check if the file is correctly open : **ofs.is_open()**
- to write in the file : **ofs << line;**
- to close the file : **ofs.close()**