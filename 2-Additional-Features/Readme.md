
# 📘 From C to C++, C++11 and Beyond  
## 🔧 Key Features with Descriptions and Examples

---

### ✅ 1. `inline` Function  
**What:** Suggests compiler to replace a function call with its body.  
**Why:** Avoids call overhead, replaces unsafe macros.  
**When:** Use for small, frequent, or header-defined functions.

```cpp
inline int square(int x) {
    return x * x;
}
```

---

### ✅ 2. `const` Keyword  
**What:** Marks variables or parameters as read-only.  
**Why:** Prevents accidental changes and enables optimizations.  
**When:** Use for fixed configuration values or input parameters.

```cpp
const int ledPin = 13;

void printMessage(const char* msg) {
    Serial.print(msg);
}
```

---

### ✅ 3. `enum class`  
**What:** Type-safe scoped enumerations.  
**Why:** Avoids name clashes, enforces stricter type checks.  
**When:** Use for device states, modes, or commands.

```cpp
enum class State { Idle, Running, Error };

State current = State::Idle;
```

---

### ✅ 4. `constexpr`  
**What:** Compile-time evaluated constants or functions.  
**Why:** Safer than `#define`, avoids RAM usage.  
**When:** For buffer sizes, timing constants, or compile-time logic.

```cpp
constexpr int bufferSize = 64;
char buffer[bufferSize];
```

---

### ✅ 5. `auto` Type Deduction  
**What:** Compiler deduces variable type from initializer.  
**Why:** Cleaner syntax, reduces errors with complex types.  
**When:** Especially useful with templates or iterators.

```cpp
auto voltage = 3.3;

for (auto it = data.begin(); it != data.end(); ++it) {
    it->update();
}
```

---

### ✅ 6. Function Overloading  
**What:** Same function name with different parameter types.  
**Why:** Simplifies naming, improves readability.  
**When:** When similar operations are applied to different types.

```cpp
int add(int a, int b) { return a + b; }
float add(float a, float b) { return a + b; }
```

---

### ✅ 7. Default Function Arguments  
**What:** Provides default values for parameters.  
**Why:** Reduces overloads and improves usability.  
**When:** For optional configurations in drivers and helpers.

```cpp
void blink(int pin = 13, int duration = 500) {
    digitalWrite(pin, HIGH);
    delay(duration);
    digitalWrite(pin, LOW);
}
```

---

### ✅ 8. Pass-by-Reference (`&`)  
**What:** Function receives a reference instead of a copy.  
**Why:** Efficient for large data, allows in-place modification.  
**When:** Use when function should modify input or avoid copying.

```cpp
void increment(int& value) {
    value++;
}
```

---

### ✅ 9. Lambda Functions  
**What:** Anonymous inline functions.  
**Why:** Useful for short logic or callbacks.  
**When:** Use in event handlers, filters, or timers.

```cpp
int factor = 3;
auto multiply = [factor](int x) { return x * factor; };
```

---

### ✅ 10. User-Defined Literals  
**What:** Custom suffixes for values.  
**Why:** Improves code readability for units.  
**When:** In device drivers, timing configs, unit-safe code.

```cpp
constexpr unsigned long long operator"" _ms(unsigned long long ms) {
    return ms;
}

delay(500_ms);
```

---

### ✅ 11. `std::string` and Streams  
**What:** Modern C++ string and formatting support.  
**Why:** Easier than `char[]` and `sprintf`, safer for manipulation.  
**When:** Use only in resource-rich embedded systems or Linux targets.

```cpp
#include <string>
#include <sstream>

std::string name = "Sensor";
int value = 42;

std::ostringstream oss;
oss << name << ": " << value;
std::string msg = oss.str();
```

---
