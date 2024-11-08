# CPP_Module2

>This document contains the exercises of Module 02 from C++ modules.

[Subject CPP module2 Project 42](https://cdn.intra.42.fr/pdf/pdf/113980/en.subject.pdf)

## New Notion

### Ad-hoc Polymophism / Function overload
- Multiple functions can have the same name, as long as they take or return different type from each other
- the definition of the function is normal
- Example :

```c++
class Sample
{
	int _nb;

public :
	void print(int nb);
	void print(float nb);
	void print(char c);
	void print(char *str);
}

```
### [Operator overload](https://en.cppreference.com/w/cpp/language/operators)
- operator in class can be overload
- Example :

```c++
struct Vector2
{
	int _x;
	int _y;

	void print(void);
	Vector2 & operator=(Vector2 const & vecteur)
	{
		_x = vecteur._x;
		_y = vecteur._y;
		return *this;
	}
	bool operator>(Vector2 const & vecteur) const;
	bool operator<(Vector2 const & vecteur) const;
	bool operator>=(Vector2 const & vecteur) const;
	bool operator<=(Vector2 const & vecteur) const;
	bool operator==(Vector2 const & vecteur) const
	{
		return (_x == vecteur._x && _y == vecteur._y);
	}
	bool operator!=(Vector2 const & vecteur) const;
	Vector2 operator+(Vector2 const & vecteur) const
	{
		Vector2 res;
		res._x = _x + vecteur._x;
		res._y = _y + vecteur._y;
		return res;
	}
	Vector2 operator-(Vector2 const & vecteur) const;
	Vector2 operator*(Vector2 const & vecteur) const;
	Vector2 operator/(Vector2 const & vecteur) const;
	Vector2& operator++()
	{
		_x++;
		_y++;
		return (*this);
	}
	Vector2& operator--();
	Vector2 operator++(int)
	{
		Vector2 res(*this);
		_x++;
		_y++;
		return (res);
	}
	Vector2 operator--(int);
}

std::ostream & operator<<(std::ostream & o, Vector2 const & number);

std::ostream & operator<<(std::ostream & o, Vector2 const & number)
{
	o << "x :" << number._x << "y :" << number._y;
	return o;
}
```

### Canonical form
- For 42School the norm in c++ is :
	- Default constructor
	- Copy constructor
	- Operator overload **=**
	- Destructor