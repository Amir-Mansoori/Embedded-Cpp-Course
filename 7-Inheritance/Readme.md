
# Chapter 7: Inheritance

Inheritance is one of the core features of object-oriented programming in C++. It allows a class (derived class) to inherit properties and behaviors (members and functions) from another class (base class).

---

## 📚 Topics Covered
- Derived classes
- Inheritance types
- Protected members
- Pointer casting
- Order of initialization

---

## 🧬 Derived Classes

A derived class inherits members from a base class. It can reuse or extend base class functionality.

### ✅ Basic Inheritance Example

```cpp
class Animal {
public:
    void eat() {
        std::cout << "Eating...
";
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking...
";
    }
};
```

```cpp
Dog d;
d.eat();  // Inherited
d.bark(); // Own method
```

---

## 🔓 Access Specifiers

- `public`: Base members retain their access level
- `protected`: Base public and protected become protected in derived
- `private`: All base members become private in derived class

```cpp
class A {
public: int x;
protected: int y;
private: int z;
};

class B : public A {};      // x public, y protected
class C : protected A {};   // x protected, y protected
class D : private A {};     // x private, y private
```

---

## 🔒 Protected Members

`protected` members are like private members but accessible by derived classes.

```cpp
class Parent {
protected:
    int value;
};

class Child : public Parent {
public:
    void setValue(int v) {
        value = v; // allowed
    }
};
```

---

## 🔄 Constructor and Destructor Order

1. **Base class constructor** runs before derived constructor
2. **Derived class destructor** runs before base destructor

```cpp
class Base {
public:
    Base() { std::cout << "Base constructor
"; }
    ~Base() { std::cout << "Base destructor
"; }
};

class Derived : public Base {
public:
    Derived() { std::cout << "Derived constructor
"; }
    ~Derived() { std::cout << "Derived destructor
"; }
};
```

---

## 🔁 Pointer Casting and Object Slicing

### ✅ Base Pointer to Derived Object (Allowed)

```cpp
Dog dog;
Animal* ptr = &dog; // Upcasting
ptr->eat();         // OK
```

### ⚠️ Derived Pointer to Base Object (Not Allowed)

```cpp
Animal a;
Dog* dptr = (Dog*)&a; // Unsafe - slicing
```

> 🧠 **Object slicing** occurs when a derived object is assigned to a base object, losing derived data.

---

## 🔄 Overriding Methods (Preview for Next Chapter)

Derived classes can override base methods when using `virtual` keyword.

```cpp
class Animal {
public:
    virtual void sound() {
        std::cout << "Some sound
";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        std::cout << "Bark
";
    }
};
```

---

## ✅ Summary Table

| Feature                | Description                                        |
|------------------------|----------------------------------------------------|
| Inheritance            | Mechanism for reusing base class code              |
| Access Specifiers      | Control visibility in derived classes              |
| Protected Members      | Accessible in derived classes, not outside         |
| Constructor Order      | Base → Derived (constructors), Derived → Base (destructors) |
| Pointer Casting        | Upcasting is safe, downcasting is risky            |
| Object Slicing         | Loss of derived class data in base class assignment|

