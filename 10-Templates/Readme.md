
# Chapter 10: Templates

Templates allow writing **generic code** that works for any type without duplicating logic.

---

## 📚 Topics Covered
- Function templates
- Class templates
- Template arguments
- Template specialization
- Dependent name and type lookup
- Avoiding code bloat

---

## 🧪 Function Templates

```cpp
template <typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}
```

---

## 🏗️ Class Templates

```cpp
template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T get() { return value; }
};
```

---

## 🔠 Template Arguments

You can use both **type** and **non-type** arguments.

```cpp
template <typename T, int size>
class Array {
    T data[size];
};
```

---

## 🧩 Template Specialization

Customize behavior for specific types.

```cpp
template <typename T>
class Printer {
public:
    void print(T val) { std::cout << val << std::endl; }
};

template <>
class Printer<bool> {
public:
    void print(bool val) { std::cout << (val ? "true" : "false") << std::endl; }
};
```

---

## 🔍 Dependent Name and Type Lookup

Inside templates, be explicit when referring to types from dependent parameters using `typename`.

```cpp
template <typename T>
void func() {
    typename T::NestedType val;
}
```

---

## ⚖️ Avoiding Code Bloat

Templates can cause large binaries if overused with many types.
Tips:
- Use templates only where generic code makes sense
- Separate implementation in `.tpp` files to control duplication

---

## ✅ Summary

| Feature                | Description                                       |
|------------------------|---------------------------------------------------|
| Function Template       | Create type-independent functions                |
| Class Template          | Create reusable containers or data structures    |
| Specialization          | Customize logic for specific types               |
| Template Arguments      | Support both type and constant parameters         |
| Code Bloat Management   | Avoid excessive instantiations                   |
