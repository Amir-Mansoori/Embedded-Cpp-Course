
# Chapter 6: Members and Friends

This chapter explores more features of C++ classes that improve flexibility and control over object behavior and memory handling.

## 📚 Topics Covered
- Friends
- Operator overloading
- Overloading assignment
- Move assignment
- Memory fragmentation
- Working with memory pools
- Static members
- Constant objects and members

---

## 👫 Friend Functions and Friend Classes

A **friend function** or **friend class** can access private and protected members of another class.

### ✅ Friend Function Example

```cpp
class Box {
    int width;
public:
    Box(int w) : width(w) {}

    friend void printWidth(Box b);
};

void printWidth(Box b) {
    std::cout << "Width: " << b.width << std::endl;
}
```

### ✅ Friend Class Example

```cpp
class Engine;

class Car {
    friend class Engine;
private:
    int speed;
public:
    Car() : speed(100) {}
};

class Engine {
public:
    void showSpeed(Car& c) {
        std::cout << "Car speed: " << c.speed << std::endl;
    }
};
```

---

## ➕ Operator Overloading

Operator overloading allows you to redefine the meaning of operators for your custom types.

```cpp
class Point {
public:
    int x, y;

    Point(int x, int y) : x(x), y(y) {}

    Point operator+(const Point& other) {
        return Point(x + other.x, y + other.y);
    }
};
```

---

## 🔁 Overloading Assignment Operator

You should overload the assignment operator when your class manages resources.

```cpp
class Buffer {
    int* data;
    int size;
public:
    Buffer(int s) : size(s) {
        data = new int[s];
    }

    ~Buffer() {
        delete[] data;
    }

    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new int[size];
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }
};
```

---

## 🚀 Move Assignment Operator (C++11+)

```cpp
Buffer& operator=(Buffer&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        size = other.size;
        other.data = nullptr;
        other.size = 0;
    }
    return *this;
}
```

> 🧠 Move assignment avoids deep copying and is useful for performance in embedded systems.

---

## 🧠 Memory Fragmentation

Occurs when dynamic allocations and deallocations leave unused memory gaps.

### Strategies:
- Use memory pools (fixed-size blocks)
- Avoid frequent `new`/`delete`
- Use `std::vector` instead of raw arrays

---

## 🏊 Working with Memory Pools

Use custom allocators to allocate from a pre-allocated block of memory.

```cpp
// Pseudo-code example
class MemoryPool {
    uint8_t* pool;
public:
    void* allocate();
    void deallocate(void* ptr);
};
```

> Useful in embedded systems with limited and deterministic memory requirements.

---

## 🧮 Static Members

Static members are shared across all objects of a class.

```cpp
class Counter {
public:
    static int count;

    Counter() { ++count; }
};

int Counter::count = 0;
```

---

## 🔒 Constant Members and Objects

### Constant Member Functions
Cannot modify the object state.

```cpp
class Sensor {
    int id;
public:
    Sensor(int i) : id(i) {}

    int getId() const {
        return id;
    }
};
```

### Constant Objects

```cpp
const Sensor s(10);
s.getId(); // OK
// s.setId(20); // Error: s is const
```

---

## ✅ Summary Table

| Feature                 | Purpose                                       | Notes                                     |
|-------------------------|-----------------------------------------------|-------------------------------------------|
| Friend Function/Class   | Access private members externally             | Use sparingly for tight coupling          |
| Operator Overloading    | Custom behavior for operators                 | e.g. `+`, `-`, `==`                       |
| Assignment Overload     | Deep copy of resources                        | Always check for self-assignment          |
| Move Assignment         | Transfer resources without copying            | Avoids performance issues                 |
| Memory Fragmentation    | Gaps in memory after dynamic usage            | Use pools or compacting strategies        |
| Static Members          | Shared by all instances                       | Declare in class, define outside          |
| Const Members/Objects   | Read-only functions or instances              | Ensure immutability when required         |
