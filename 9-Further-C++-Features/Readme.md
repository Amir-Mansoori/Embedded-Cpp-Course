
# Chapter 9: Further C++ Features

This chapter introduces additional features of modern C++ that improve expressiveness, safety, and flexibility.

---

## 📚 Topics Covered
- User-defined conversions
- `explicit` functions
- `default` and `delete` behavior
- Run-Time Type Identification (RTTI)
- Type casts: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`
- Nested classes
- Multiple inheritance
- Pointer-to-member
- Function wrappers (`std::function`, `std::bind`)

---

## 🔁 User-defined Conversions

```cpp
class Angle {
    double radians;
public:
    Angle(double r) : radians(r) {}
    operator double() const { return radians; }
};
```

Allows implicit conversion to double. Use `explicit` to prevent this if undesired.

---

## 🚫 `explicit` Keyword

Prevents **implicit conversions** by requiring the constructor to be called explicitly.

```cpp
class Meter {
public:
    explicit Meter(double m) { /* ... */ }
};
```

---

## ✅ `default` and `delete`

```cpp
class Example {
public:
    Example() = default;          // Compiler generates constructor
    Example(const Example&) = delete; // Disallow copy
};
```

---

## 🔎 Run-Time Type Identification (RTTI)

Allows checking or casting object types at runtime using `typeid` and `dynamic_cast`.

```cpp
Base* b = new Derived();
if (Derived* d = dynamic_cast<Derived*>(b)) {
    // Safe to use d
}
```

---

## 🌀 Type Casts in C++

| Cast             | Use Case                                 |
|------------------|-------------------------------------------|
| `static_cast`    | Safe conversions (int to float, etc.)     |
| `dynamic_cast`   | Downcasting in class hierarchies          |
| `const_cast`     | Add/remove const                          |
| `reinterpret_cast` | Dangerous, low-level cast (e.g., int to ptr) |

---

## 🧱 Nested Classes

```cpp
class Outer {
public:
    class Inner {
        void sayHi() {}
    };
};
```

---

## 🔗 Multiple Inheritance

```cpp
class A {};
class B {};
class C : public A, public B {};
```

> Use carefully due to ambiguity (e.g., diamond problem)

---

## 👉 Pointer-to-member

```cpp
class MyClass {
public:
    int value;
};

int MyClass::*ptr = &MyClass::value;
MyClass obj;
obj.*ptr = 10;
```

---

## 🧰 Function Wrappers

Use `std::function`, `std::bind`, or lambdas to store callable entities.

```cpp
std::function<void(int)> f = [](int x) { std::cout << x << std::endl; };
f(42);
```

---

## ✅ Summary

| Feature              | Purpose                                           |
|----------------------|---------------------------------------------------|
| `explicit`           | Prevent unintended implicit conversions           |
| `default/delete`     | Customize compiler-generated special members      |
| RTTI                 | Type checking and safe downcasting at runtime     |
| Type Casts           | Safe or low-level type conversions                |
| Nested Classes       | Structure helper types inside outer classes       |
| Multiple Inheritance | Inherit from more than one base class             |
| Function Wrappers    | Generic storage of functions or callables         |
