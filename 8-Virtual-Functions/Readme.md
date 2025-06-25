
# Chapter 8: Virtual Functions

Virtual functions enable **polymorphism** in C++, allowing derived classes to **override** behavior of base class methods and enabling **dynamic dispatch** at runtime.

---

## 📚 Topics Covered
- Inheriting common behavior
- Overriding methods
- Virtual functions
- Polymorphism
- Late binding
- Virtual destructors
- Vtable
- Cost of virtual functions
- Abstract base classes and pure virtual functions
- Interface classes

---

## 🔁 Virtual Functions

A **virtual function** is a member function you expect to override in derived classes.

```cpp
class Animal {
public:
    virtual void speak() {
        std::cout << "Some generic animal sound
";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof
";
    }
};
```

```cpp
Animal* a = new Dog();
a->speak(); // Output: Woof (not Animal::speak)
```

---

## 🔄 Overriding Methods

Derived classes **override** base virtual methods to customize behavior.

Use `override` keyword to enforce that the base class method exists.

```cpp
class Base {
public:
    virtual void show();
};

class Derived : public Base {
public:
    void show() override; // override required method
};
```

---

## ⏱ Polymorphism and Late Binding
Polymorphism means **“many forms”**. In C++, it enables objects of different classes to be treated as objects of a **common base class** while behaving differently at runtime.

---

### ✅ Why Use Polymorphism?

- Reuse a **common interface**
- Dynamically **switch behavior at runtime**
- Improve **extensibility** and code reusability

---

### 📌 Example: Polymorphism in Action

```cpp
class Animal {
public:
    virtual void speak() {
        std::cout << "Some generic animal sound\n";
    }
};

class Dog : public Animal {
public:
    void speak() override {
        std::cout << "Woof\n";
    }
};

class Cat : public Animal {
public:
    void speak() override {
        std::cout << "Meow\n";
    }
};

void makeItSpeak(Animal* a) {
    a->speak(); // Resolved at runtime
}
```

```cpp
int main() {
    Dog d;
    Cat c;
    makeItSpeak(&d); // Output: Woof
    makeItSpeak(&c); // Output: Meow
}
```

---

### ⏱ Static vs Dynamic Polymorphism

| Type                 | Description                              | Binding Time | Example                          |
|----------------------|------------------------------------------|---------------|-----------------------------------|
| Static Polymorphism  | Function overloading or templates         | Compile-time | `void func(int);` and `func(float);` |
| Dynamic Polymorphism | Virtual functions and base class pointers | Run-time     | `Animal* a = new Dog();`          |

---

### 🧠 How It Works: Under the Hood

- Each class with virtual functions has a **vtable** (virtual table)
- Each object has a hidden pointer to this table: the **vptr**
- When a virtual function is called, C++ uses the vptr to look up the right function in the vtable

---

### 🧱 Embedded Perspective

- **Use it** for device abstraction (e.g. `Sensor` as base, `TempSensor` and `LightSensor` as derived)
- **Costs**:
  - Small memory overhead due to vptr
  - Slight runtime overhead due to function pointer indirection

---

### 🧰 Embedded Example of polymorphism

```cpp
class Sensor {
public:
    virtual int readValue() = 0;
};

class TempSensor : public Sensor {
public:
    int readValue() override {
        return 42; // Simulate temperature reading
    }
};

class LightSensor : public Sensor {
public:
    int readValue() override {
        return 300; // Simulate light reading
    }
};

void logSensor(Sensor* s) {
    std::cout << "Sensor reading: " << s->readValue() << std::endl;
}
```
---

## 💣 Virtual Destructors

Always declare destructors **virtual** in base classes when using inheritance.

```cpp
class Base {
public:
    virtual ~Base() {
        std::cout << "Base destructor
";
    }
};

class Derived : public Base {
public:
    ~Derived() {
        std::cout << "Derived destructor
";
    }
};
```

> Without a virtual destructor, deleting a derived object via a base pointer causes **undefined behavior**.

---

## 🧠 Vtable (Virtual Table)

The **vtable** is a compiler-generated table holding function pointers for virtual methods. Each object with virtual functions carries a **vptr** pointing to its vtable.

> Allows fast lookup of the correct method at runtime.

---

## 💸 Cost of Virtual Functions

- Slightly more memory due to vtable/vptr
- Slightly slower due to indirection
- **Trade-off**: Acceptable in most embedded systems if needed

---

## 🧱 Abstract Base Classes and Pure Virtual Functions

In C++, abstract base classes and interface classes provide a way to define **common behaviors** without implementing them, allowing derived classes to define specific logic.

---

## 🧱 Abstract Base Class

An **abstract base class** is a class that contains at least **one pure virtual function** (i.e. function with = 0). You cannot create objects from it.

### ✅ Syntax

```cpp
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function
};
```

Shape is abstract because draw() has no body.

Any class that inherits from Shape must implement draw().



### 🔍 Key Points
- Cannot be instantiated
- Can contain implemented functions and member variables
- Used as a common base for multiple related classes

### ✅ Example

```cpp
class Shape {
public:
    virtual void draw() = 0; // pure virtual
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Circle
";
    }
};

class Square : public Shape {
public:
    void draw() override {
        std::cout << "Drawing Square
";
    }
};
```

---

## 🔌 Interface Class

An **interface class** is a special type of abstract class where **all functions are pure virtual**, and it contains **no data members or implementations**.

### ✅ Syntax

```cpp
class Printable {
public:
    virtual void print() = 0;
    virtual ~Printable() = default;
};
```

### ✅ Example

```cpp
class Document : public Printable {
public:
    void print() override {
        std::cout << "Printing Document
";
    }
};
```

---

## 🧠 Why Use These?

| Use Case                          | Abstract Base Class      | Interface Class              |
|----------------------------------|---------------------------|------------------------------|
| Provide default/shared behavior  | ✅ Yes                    | ❌ No                        |
| Define required functions only   | ✅ Yes                    | ✅ Yes                       |
| Enable polymorphic behavior      | ✅ Yes                    | ✅ Yes                       |
| Represent contract/API only      | 🚫 Not ideal              | ✅ Ideal                     |

---

## 🔁 Embedded System Use Case

- Define a `Sensor` interface:
```cpp
class Sensor {
public:
    virtual int read() = 0;
    virtual void calibrate() = 0;
    virtual ~Sensor() = default;
};
```

- Implement different sensors:
```cpp
class TempSensor : public Sensor {
public:
    int read() override { return 25; }
    void calibrate() override { /* do something */ }
};

class LightSensor : public Sensor {
public:
    int read() override { return 300; }
    void calibrate() override { /* do something else */ }
};
```

---
## ✅ Summary Table

| Feature                   | Description                                           |
|---------------------------|-------------------------------------------------------|
| Virtual Function          | Allows method override and polymorphism              |
| override Keyword          | Ensures base method exists for overriding            |
| Polymorphism              | Behavior changes depending on object type            |
| Late Binding              | Function resolved at runtime using vtable            |
| Virtual Destructor        | Ensures proper destruction of derived objects        |
| Vtable                    | Table of function pointers for virtual methods       |
| Abstract Class            | Cannot be instantiated, used as a base for interfaces|
| Pure Virtual Function     | Must be overridden by derived class                  |
| Interface Class           | A class with only pure virtual methods               |
