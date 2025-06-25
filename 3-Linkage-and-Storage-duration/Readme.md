
# 📘 Chapter 3: Linkage and Storage Duration  
## 🔧 Key Concepts, Descriptions, and Embedded-Friendly Examples

---

### ✅ 1. Scope  
**What:** The region of code where a variable or function is visible.  
**Why:** Understanding scope prevents naming conflicts and bugs.  
**When:** Always—especially in embedded systems where memory is tight.

#### Types:
- **Local scope:** Inside a block or function
- **Global scope:** Defined outside any function

```cpp
int globalCounter = 0;  // Global scope

void loop() {
    int localValue = 5;  // Local scope
}
```

---

### ✅ 2. Storage Classes: `auto`, `static`, `extern`, `register`  

#### 🔹 `auto`  
**What:**  
- Default for local variables (C-style)  
- In C++11+, it refers to type deduction

```cpp
auto x = 42;  // Type deduction (int)
```

---

#### 🔹 `static`  
**What:**  
- Keeps value between function calls  
- Limits visibility to file (when used at global scope)

```cpp
#include <stdio.h>
#include <iostream>
using namespace std;

void countCalls() {
    static int count = 0;
    count++;
    printf("count = %d\n",count);
}

int main(){

    countCalls();
    countCalls();
    countCalls();
    return 0;
}
// Output is:
// count = 1
// count = 2
// count = 3
```

---

#### 🔹 `extern`  
**What:** Declares a variable or function defined in another file.

```cpp
// file1.cpp
int systemState = 0;

// file2.cpp
extern int systemState;
```

---

#### 🔹 `register`  
**What:** Suggests storing the variable in a CPU register (mostly obsolete today).

```cpp
register int counter = 0;
```

---

### ✅ 3. Linkage (Internal vs External)  
**What:** Controls visibility of symbols across translation units (source files).

#### Types:
- **Internal linkage:** Use `static` to restrict symbol to one file.
- **External linkage:** Use `extern` to reference symbols across files.

```cpp
// Internal
static void reset() { ... }

// External
extern void start();  // Defined elsewhere
```

---

### ✅ 4. Linking C and C++  
**What:** Ensures C functions can be called from C++ code without name mangling.

```cpp
extern "C" {
    void my_c_function();  // C function
}
```

---

### ✅ 5. Storage Duration  

#### 🔹 Automatic (stack):
```cpp
void loop() {
    int temp = 25;  // Lives only during this function call
}
```

#### 🔹 Static:
```cpp
static int counter = 0;  // Lives throughout program
```

#### 🔹 Dynamic (heap):
```cpp
int* ptr = new int(10);  // Must be deleted manually
delete ptr;
```

> ⚠️ In embedded systems, prefer static or stack memory. Avoid dynamic (`new/delete`) on small microcontrollers.

---
