
# 📘 Chapter 4: Classes and Objects  
## 🧱 Organizing Code with Structure, Abstraction, and Reusability

---

### ✅ 1. What is a Class?  
**📌 What:**  
A **class** defines a **blueprint** or **template** for creating objects.  
It combines **data (attributes)** and **functions (behaviors)** that operate on that data.

**🎯 Why in embedded systems?**  
- Helps organize complex hardware behavior  
- Models real-world components (e.g., sensors, actuators)  
- Makes code modular, readable, and reusable

```cpp
class LED {
public:
    int pin;

    void turnOn() {
        digitalWrite(pin, HIGH);
    }

    void turnOff() {
        digitalWrite(pin, LOW);
    }
};
```

---

### ✅ 2. What is an Object?  
**📌 What:**  
An **object** is an **instance** of a class — it holds real data.

**🎯 Why use it?**  
- You can create multiple independent objects from the same class.

```cpp
LED led1;
led1.pin = 13;
led1.turnOn();
```

---

### ✅ 3. Access Specifiers: `public`, `private`, `protected`  
**📌 What:**  
Control which parts of the code can access members of a class.

| Specifier   | Access Scope                          |
|-------------|----------------------------------------|
| `public`    | Accessible from anywhere               |
| `private`   | Accessible only within the class       |
| `protected` | Accessible in class and subclasses     |

**🎯 Why:**  
- Protect sensitive data (like internal sensor state)  
- Only expose what is necessary

```cpp
class Button {
private:
    int pin;

public:
    void setPin(int p) { pin = p; }
    int getPin() { return pin; }
};
```

---

### ✅ 4. Member Functions  
**📌 What:**  
Functions that belong to a class and typically act on its data (variables).

**🎯 Why:**  
Encapsulates behavior, avoids global functions.

```cpp
class Timer {
private:
    int interval;

public:
    void setInterval(int ms) {
        interval = ms;
    }

    int getInterval() {
        return interval;
    }
};
```

---

### ✅ 5. The `this` Pointer  
**📌 What:**  
The this pointer is an implicit pointer available inside **all non-static member functions** of a class.

Inside a class, `this` is a pointer to the current object - the instance on which the method was called.

**🎯 Why:**  
- Disambiguates between member variables and parameters  
- Allows **chaining** methods (`return this;`)

```cpp
class Sensor {
private:
    int id;

public:
    void setId(int id) {
        this->id = id;  // clearly assign parameter to member
    }
};
```

---

### ✅ 6. Scope Resolution Operator `::`  
**📌 What:**  
Used to define member functions **outside** the class definition.

**🎯 Why:**  
- Keeps class declarations clean  
- Preferred for long function definitions

```cpp
class Fan {
public:
    void start();
};

// Defined outside
void Fan::start() {
    // Start the fan
}
```

---

### ✅ 7. Information Hiding & Encapsulation  
**📌 What:**  
Encapsulation means hiding internal data and exposing only safe interfaces.

**🎯 Why:**  
- Prevent misuse of internal state  
- Allows internal change without breaking code outside

```cpp
class Motor {
private:
    int speed;

public:
    void setSpeed(int s) {
        if (s >= 0 && s <= 100) speed = s;
    }

    int getSpeed() {
        return speed;
    }
};
```

---

### ✅ 8. Abstract Data Types (ADTs)  
**📌 What:**  
An ADT is a model where **only the interface is visible**, not the internal implementation.

**🎯 Why:**  
- Promotes **modularity** and **abstraction**  
- The user doesn't need to know how it works internally

```cpp
class TemperatureSensor {
public:
    float readCelsius();
    float readFahrenheit();
};
```

> You can use this to model any device in your embedded system — ADCs, UART drivers, I2C displays, etc.

---
