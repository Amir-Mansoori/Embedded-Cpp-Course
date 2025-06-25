
# Chapter 5: Constructors

This chapter explains how to ensure that objects are properly initialized and how to handle cleanup afterwards. It covers:
- Constructors
- Destructors
- Delegating constructors
- Copy constructors
- Pointers and objects
- Move semantics

---

## 🧱 What is a Constructor?

A **constructor** is a special member function that is automatically called when an object of a class is created. Its primary purpose is to initialize object members.

```cpp
class MyClass {
public:
    MyClass(); // Constructor declaration
};
```

---

## ✅ Types of Constructors

### 1. Default Constructor

A constructor that takes no parameters. It is used to initialize members with default values.

```cpp
class Sensor {
public:
    int id;
    Sensor() {
        id = 0;
    }
};
```

---

### 2. Parameterized Constructor

A constructor that takes parameters to initialize member variables.

```cpp
class Sensor {
public:
    int id;
    Sensor(int newId) {
        id = newId;
    }
};
```

---

### 3. Constructor with Initialization List

This approach is preferred for initializing `const`, reference, or performance-critical members.

```cpp
class Sensor {
    const int id;
public:
    Sensor(int newId) : id(newId) {}
};
```

> 🧠 Use initialization lists for better performance and to support const/reference members.

---

## 🔄 Copy Constructor

### ✅ Purpose

The **copy constructor** creates a new object as a copy of an existing one. It's essential for managing resources such as dynamic memory.

```cpp
class Buffer {
    int* data;
    int size;
public:
    Buffer(int size) : size(size) {
        data = new int[size];
    }

    // Deep copy constructor
    Buffer(const Buffer& other) : size(other.size) {
        data = new int[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    ~Buffer() {
        delete[] data;
    }
};
```

#### ⚠️ Without a copy constructor:

```cpp
Buffer b1(10);
Buffer b2 = b1; // Shallow copy - both share the same pointer
```

This can lead to double deletion or memory corruption.

> 📌 **Embedded tip**: Always define a deep copy constructor when working with peripheral buffers or hardware memory.

---

## 🔁 Delegating Constructor (C++11+)

Allows one constructor to call another constructor within the same class, promoting code reuse.

```cpp
class Sensor {
    int id;
    std::string type;

public:
    Sensor() : Sensor(0, "unknown") {}
    Sensor(int id) : Sensor(id, "temperature") {}
    Sensor(int id, std::string type) : id(id), type(type) {
        std::cout << "Sensor " << id << " of type " << type << " initialized\n";
    }
};
```

> ✅ Use this to avoid duplicating initialization logic for different constructor variants.

---

## 💣 Destructor

A **destructor** is a special member function that is automatically called when an object is destroyed. It's used to release resources like dynamic memory, files, or peripheral handles.

```cpp
class Sensor {
public:
    ~Sensor() {
        // Cleanup logic
    }
};
```

> Destructors:
- Cannot be overloaded
- Take no parameters
- Should always be `virtual` in polymorphic base classes

---

## 👥 Pointers and Objects

When using pointers to dynamically allocate objects, constructors and destructors must be managed manually.

```cpp
Sensor* s = new Sensor(5); // Constructor called
delete s;                  // Destructor must be called manually
```

> 🧠 Embedded systems often rely on dynamic allocation for device drivers or buffers — handle carefully!

---

## 🚀 Move Semantics (C++11+)

Move semantics allow **transfer of ownership** instead of deep copying, which is more efficient.

### ✅ Move Constructor

```cpp
class Buffer {
    int* data;
    int size;
public:
    Buffer(Buffer&& other) noexcept
        : data(other.data), size(other.size) {
        other.data = nullptr; // Transfer ownership
        other.size = 0;
    }
};
```

> 🧠 Use `std::move()` to enable move semantics and avoid expensive copies.

---

## 👣 Full Example: Constructor and Destructor Flow

```cpp
#include <iostream>
using namespace std;

class Sensor {
    int id;
public:
    Sensor(int newId) : id(newId) {
        cout << "Sensor " << id << " initialized\n";
    }

    ~Sensor() {
        cout << "Sensor " << id << " destroyed\n";
    }
};

int main() {
    Sensor s1(101); // Constructor called
    return 0;       // Destructor called automatically
}
```

---

## ✅ Best Practices

- Always initialize all members (prefer initialization lists)
- Follow the **Rule of Three/Five**:
  - Destructor
  - Copy constructor
  - Copy assignment operator
  - Move constructor (C++11+)
  - Move assignment operator (C++11+)
- Avoid complex logic in constructors — use them strictly for setup

---

## 📋 Summary Table

| Feature                | Purpose                              | Syntax Example                          |
|------------------------|--------------------------------------|------------------------------------------|
| Default Constructor    | Initialize with defaults             | `Sensor();`                              |
| Parameterized          | Initialize with user input           | `Sensor(int id);`                        |
| Initialization List    | Efficient member init                | `Sensor(int id) : id(id) {}`             |
| Copy Constructor       | Copy existing object                 | `Sensor(const Sensor& s);`              |
| Delegating Constructor | Reuse another constructor            | `Sensor() : Sensor(0) {}`                |
| Destructor             | Cleanup on destruction               | `~Sensor();`                             |
| Move Constructor       | Transfer ownership (no copy)         | `Sensor(Sensor&& s);`                    |
