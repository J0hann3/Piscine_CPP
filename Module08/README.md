# CPP_Module8

>This document contains the exercises of Module 08 from C++ modules

[Subject CPP Module 08 42 School](https://cdn.intra.42.fr/pdf/pdf/89245/en.subject.pdf)

## New Notion

### Containers (STL)

#### Iterator

```c++
std::vector<int> values = {1, 2, 3, 4, 5};


// 1
for (int i = 0; i < values.size(); i++) // Can use this method for an unorderedmap or a tree
{
	std::cout << values[i] << std::endl;
}

// 2
for (int value : values)
{
	std::cout << value << std::endl;
}

// 3
for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++)
{
	std::cout << *it << std::endl;
}

```

#### Array (C++11)

- static array = do not grow
- store on the stack

```c++
itn main()
{
	std::array<int, 10> tab;

	tab[0] = 1;
	tab[20] = 3; //will throw an error 

	for (int i = 0; i < tab.size(); i++) // use ref to avoid copying the data
	{
		std::cout << value << std::endl;
	}

}
```

#### Vector

- dynamic arrays
- can resize a vector
- pass vector to function by const ref or ref
- store in the heap

```c++
itn main()
{
	std::vector<float> tab;
	std::vector<float*> tab1;
	tab.push_back(23.06);

	for (float& value : tab) // use ref to avoid copying the data
	{
		std::cout << value << std::endl;
	}

	//optimization for Object
	std::vector<float> test;
	test.reserve(3); //reserve 3 places in the vector at the beginning
	test.emplace_back(23.06); // avoid to copy the object to construct a new one in the vector, instead we give the argument to call the construtor at the right place
}
```

#### Deque

- Double Ended Queue(vector = dynamic array)
- easy to add somthing to the end or begin
- hard to add an element in the middle
- support random acces to element

```c++

int main()
{
	std::deque<string> res = {"coucou", "hey", "hello"};
	res.push_back("name");
	res.push_front("age");
}
```

#### List

- double linked list

```c++
int main()
{
	std::list<int> lst;
	lst.push_back(1);
	lst.push_back(2);
	lst.push_back(3);
	lst.push_back(4);
}

```

### Stack
- last-in, first-out(LIFO)

```c++
int main()
{
	std::stack<int> c1;
	c1.push(5);
}
```

### Queue
- first-in, first-out(FIFO)

```c++
int main()
{
	std::queue<float> q;

	q.push(3.20);
}
```

### Map
- key value pair to an unique value

```c++
int main()
{
	std::map<std::string, int> m{{"CPU", 10}, {"GPU", 15}, {"RAM", 20}};

	m["CPU"] = 25; //update
	m["SSD"] = 30; //insert
}
```
