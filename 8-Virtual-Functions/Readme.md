
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

### Static binding:
```cpp
Dog d;
d.speak(); // Determined at compile-time
```

### Dynamic binding:
```cpp
Animal* a = new Dog();
a->speak(); // Determined at run-time via vtable
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

An abstract class **cannot be instantiated** and is used to define a common interface.

```cpp
class Shape {
public:
    virtual void draw() = 0; // pure virtual
};
```

Derived classes **must** implement `draw()`.

```cpp
class Circle : public Shape {
public:
    void draw() override {
        std::cout << "Drawing a circle
";
    }
};
```

---

## 🔌 Interface Classes

An interface class is a class with **only pure virtual functions**.

```cpp
class Printable {
public:
    virtual void print() = 0;
    virtual ~Printable() = default;
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
