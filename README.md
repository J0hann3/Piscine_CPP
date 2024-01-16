# CPP_Module06

>This document contains the exercises of Module 06 from C++ modules.

## New Notion

#### Cast

```c++
double a;
int b = (int)a;
```

```c++
float a = 420.042f;

void *b = &a;

int *c = b; //when printing c the bits will be the same but interpret as an int instead of a float
```

- static_cast<type>value;
- dynamic_cast<type>value; // only on pointer and reference
- reinterpret_cast<type>value; //works on everything
- const_cast<type>value; //use to remove a const
- operator int() {return static_cast<int>(this->_nb)}  //overload cast in class
- explicit
