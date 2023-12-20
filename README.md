# CPP_Module3

>This document contains the exercises of Module 03 from C++ modules.

[Subject CPPModule3 Project 42](https://cdn.intra.42.fr/pdf/pdf/113975/en.subject.pdf)

## New Notion

### [Inheritance](https://en.cppreference.com/w/cpp/language/derived_class)(https://cplusplus.com/doc/tutorial/inheritance/)
- A class can inheritat from an other class
- The new class will have all the attributs and methods from the class parent
- There is a new keyword to define a new type of access : **protected**

|Access                    |public | protected| private|
|members of the same class |    yes|       yes|     yes|
|members of derived class  |    yes|       yes|      no|
|not members               |    yes|        no|      no|

```c++
class Polygon {
protected:		// don't work if private
	int width, height;
public:
	void set_values (int a, int b)
		{ width=a; height=b;}
 };

class Rectangle: public Polygon {
public:
	int area ()
		{ return width * height; }
 };

int main()
{
	Rectangle rect;

	rect.set_values(10, 56);
	std::cout << rect.area() << std::endl;
}
```