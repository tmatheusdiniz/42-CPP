<h1 align="center">
  Common Core 42 - CPP
</h1>

<p align="center">
  <img src="assets/oop_banner.svg" width="700" height="400">
</p>

<p align="center">
    <b><i>This project is part of the fifth milestone of the 42 cursus</i></b>
</p>

<h3 align="center">
    <a href="#-about">About</a>
    <span> · </span>
    <a href="#-usage">Usage</a>
    <span> · </span>
    <a href="#-references">References</a>
</h3>

## 📖 About

The goal of CPP modules is to learning as most as possible about Object-oriented programming, diving deeper into subject such as:

### CPP00:

- **Classes and objects**

- **Namespaces**

- **Stdio streams**

- **Casting**

### CPP01:

- **Memory allocation**

- **Pointers and references**

- **Loop Statements**

### CPP02:

- **Polymorphism**

- **Operator overloading**

- **Orthodox canonical class form**

- **Fixed pointers**

### CPP03

- **Inheritance**

### CPP04:

- **Subtype polymorphism**

- **Abstract classes and interfaces**

## 🧱 Usage

First of all clone this repository

All exercises are compiled with:
```bash
cd CPP* && cd ex*
```
```bash
c++ -Wall -Wextra -Werror [-std=c++98] *.cpp -o <executable_name>
```

Each module has a Makefile with the following rules:
- `make` || `make all`: Compiles the program
- `make clean`: Removes object files
- `make fclean`: Removes object files and executable
- `make re`: Executes `fclean` and `all` rules

## 📚 References

- The C++ Programming Language (3rd Edition) by Bjarne Stroustrup
- Effective Modern C++ by Scott Meyers
- [C++ Docs](https://cplusplus.com/)
- [C++ Reference](https://en.cppreference.com/)
