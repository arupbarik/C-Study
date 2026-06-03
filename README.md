# 📘 C Programming – Study Notes & Reference

> A structured guide based on the [`C-Study`](https://github.com/arupbarik/C-Study) repository.  
> Covers everything from "Hello World" to algorithms and data structures — with code examples drawn directly from the source files.

---

## 📑 Table of Contents

1. [Getting Started](#1-getting-started)
2. [Variables & Data Types](#2-variables--data-types)
3. [Operators](#3-operators)
4. [Conditional Statements](#4-conditional-statements)
5. [Loops](#5-loops)
6. [Functions & Recursion](#6-functions--recursion)
7. [Arrays](#7-arrays)
8. [Strings](#8-strings)
9. [Pointers](#9-pointers)
10. [Structures](#10-structures)
11. [Algorithms](#11-algorithms)
12. [Practice Problems & Labs](#12-practice-problems--labs)
13. [Mini Projects](#13-mini-projects)
14. [Quick Reference – Format Specifiers](#14-quick-reference--format-specifiers)
15. [Common Mistakes to Avoid](#15-common-mistakes-to-avoid)

---

## 1. Getting Started

**File:** `First.c`

Every C program needs:
- `#include <stdio.h>` — standard input/output library
- A `main()` function — the entry point
- `return 0;` — signals successful execution

```c
#include <stdio.h>

int main() {
    printf("Hello World\n");  // \n = newline
    return 0;
}
```

> **Tip:** `printf` prints to the console. `\n` moves to the next line.

---

## 2. Variables & Data Types

**File:** `varq.c`, `First.c`

### Declaring Variables

```c
int   a = 10;        // whole numbers
float b = 58.0;      // decimal numbers
char  c = 'A';       // single character
```

### Printing with Format Specifiers

```c
printf("%d\n",  a);     // integer
printf("%.2f\n", b);    // float, 2 decimal places
printf("%c\n",  c);     // character
```

### Checking Data Type Sizes

```c
printf("Size of int:   %zu bytes\n", sizeof(int));    // usually 4
printf("Size of char:  %zu bytes\n", sizeof(char));   // always 1
printf("Size of float: %zu bytes\n", sizeof(float));  // usually 4
```

### Swapping Two Numbers

**With a temp variable:**
```c
int temp = i;
i = j;
j = temp;
```

**Without a temp variable (arithmetic trick):**
```c
k = l + k;
l = k - l;
k = k - l;
```

### Type Conversion (Casting)

```c
int y = 1, z = 10;
printf("%d\n",   y / z);        // Wrong: prints 0 (integer division)
printf("%.2f\n", (float)y / z); // Correct: prints 0.10
```

### Global vs Local Variables

```c
int x = 0;          // global — accessible everywhere, lives for the whole program

int main() {
    int x = 5;      // local — shadows the global, exists only inside main()
}
```

### Finding INT_MAX / INT_MIN (without `limits.h`)

```c
unsigned int u = ~0u;      // all bits set to 1
int max_int =  u >> 1;     // 2147483647
int min_int = ~max_int;    // -2147483648
```

### Endianness Check

```c
int n = 1;
char *ptr = (char *)&n;
if (*ptr == 1)
    printf("Little-endian\n");
else
    printf("Big-endian\n");
```

---

## 3. Operators

**File:** `Second.c`, `incrementand_decrement.c`

### Arithmetic Operators

| Operator | Meaning      | Example     |
|----------|--------------|-------------|
| `+`      | Addition     | `a + b`     |
| `-`      | Subtraction  | `a - b`     |
| `*`      | Multiply     | `a * b`     |
| `/`      | Divide       | `a / b`     |
| `%`      | Modulus      | `a % b`     |

### Logical Operators

```c
int e = 0, g = 1;
printf("%d\n", e && g);   // AND → 0 (both must be true)
printf("%d\n", e || g);   // OR  → 1 (at least one true)
printf("%d\n", !e);       // NOT → 1 (flips the value)
```

### Increment & Decrement

```c
i++;   // post-increment: use value THEN add 1
++i;   // pre-increment:  add 1 THEN use value
i--;   // post-decrement
--i;   // pre-decrement
```

---

## 4. Conditional Statements

**Files:** `Second.c`, `project3.c`, `conditionalq.c`, `ques.c`

### if / else if / else

```c
int age;
scanf("%d", &age);

if (age > 60)
    printf("Senior citizen, can drive\n");
else if (age > 18)
    printf("Can drive\n");
else
    printf("Cannot drive\n");
```

> ⚠️ **Never write** `90 < a <= 100` in C. C evaluates left-to-right:
> `90 < a` → gives `0` or `1` → then `0 <= 100` is **always true**.  
> Always write `a > 90 && a <= 100`.

### switch / case

```c
int A;
scanf("%d", &A);
switch (A) {
    case 1:  printf("You entered 1\n"); break;
    case 2:  printf("You entered 2\n"); break;
    default: printf("Unknown\n");
}
```

> `break` stops execution from "falling through" to the next case.

### Grade System (Real Example)

```c
if      (a > 90 && a <= 100) printf("A");
else if (a > 80 && a <= 90)  printf("B");
else if (a > 70 && a <= 80)  printf("C");
else if (a > 60 && a <= 70)  printf("D");
else if (a > 50 && a <= 60)  printf("E");
else if (a > 0  && a <= 50)  printf("Fail");
else                          printf("Invalid");
```

### Leap Year Check

```c
if (year % 4 == 0 && year % 100 != 0 && year % 400 == 0)
    printf("Leap year\n");
```

---

## 5. Loops

**Files:** `Loops.c`, `incrementand_decrement.c`, `lab1.c`, `lab2.c`

### while Loop

```c
int i = 0;
while (i < 4) {
    printf("hi\n");
    i++;
}
```

### for Loop

```c
for (int b = 0; b < 15; b++) {
    printf("%d\n", b);
}
```

### Loop Control

```c
if (b == 12) break;     // exits the loop immediately
if (b == 12) continue;  // skips to the next iteration
```

### Nested Loops (Multiplication Table)

```c
for (int i = 1; i <= 10; i++) {
    printf("%d * %d = %d\n", mul, i, mul * i);
}
```

### Infinite Loop with Exit

```c
while (1) {
    // runs forever until break
    if (op == 5) break;
}
```

---

## 6. Functions & Recursion

**Files:** `FUNCTIONS_AND_RECURSION.c`, `sp.c`

### Defining and Calling Functions

```c
// Declaration (prototype) — before main
int add(int a, int b);

int main() {
    int result = add(10, 20);   // call
    printf("%d\n", result);     // 30
    return 0;
}

// Definition — after main
int add(int a, int b) {
    return a + b;
}
```

### Recursion (Factorial)

A function that calls itself with a **base case** to stop:

```c
int factorial(int n) {
    if (n == 0)
        return 1;               // base case
    else
        return n * factorial(n - 1);  // recursive call
}
```

| n  | Calls                              | Result |
|----|-------------------------------------|--------|
| 0  | returns 1                           | 1      |
| 3  | 3 × factorial(2) → 3 × 2 × 1 × 1  | 6      |
| 5  | 5 × 4 × 3 × 2 × 1 × 1             | 120    |

### Permutation P(n, r) — Recursive

```c
int p(int n, int r) {
    if (r == 0) return 1;
    return n * p(n - 1, r - 1);
}
```

---

## 7. Arrays

**Files:** `array.c`, `array_problem.c`, `arrray_function.c`, `temp.c`

### 1D Array Basics

```c
int arr[5] = {3, 2, 1, 2, 10};
printf("%d\n", arr[2]);           // index 2 → value 1
printf("%d\n", sizeof(arr));      // total bytes (5 × 4 = 20)
```

### Reading Array Input with a Loop

```c
int marks[5];
for (int i = 0; i < 5; i++)
    scanf("%d", &marks[i]);        // & = address-of operator
```

### 2D Arrays (Matrix)

```c
int m[2][3] = {{2,3,8}, {5,8,9}};
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++)
        printf("%d ", m[i][j]);
    printf("\n");
}
```

### Passing Arrays to Functions

```c
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
// Arrays are always passed by reference (no copy is made)
```

### Key Array Algorithms

**Find Sum & Average:**
```c
int sum = 0;
for (int i = 0; i < 5; i++) sum += arr[i];
float avg = sum / 5.0;
```

**Find Max & Min:**
```c
int max = arr[0], min = arr[0];
for (int i = 1; i < n; i++) {
    if (arr[i] > max) max = arr[i];
    if (arr[i] < min) min = arr[i];
}
```

**Reverse an Array:**
```c
for (int i = 0; i < n / 2; i++) {
    int temp    = arr[i];
    arr[i]      = arr[n - 1 - i];
    arr[n-1-i]  = temp;
}
```

**Merge Two Sorted Arrays:**
```c
int i = 0, j = 0, k = 0;
while (i < n1 && j < n2)
    merged[k++] = (a[i] <= b[j]) ? a[i++] : b[j++];
while (i < n1) merged[k++] = a[i++];
while (j < n2) merged[k++] = b[j++];
```

**Matrix Transpose:**
```c
for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
        trans[j][i] = mat[i][j];
```

**Matrix Multiplication:**
```c
for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
        for (int k = 0; k < 3; k++)
            C[i][j] += A[i][k] * B[k][j];
```

**Sparse Matrix Representation:**
```c
// Only store non-zero elements as (row, col, value)
for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        if (mat[i][j] != 0)
            printf("(%d, %d, %d)\n", i, j, mat[i][j]);
```

---

## 8. Strings

**Files:** `strings.c`, `temp.c`

### String Basics

```c
char greeting[] = "hello world";
printf("%s\n", greeting);            // print string
```

### Reading String Input

```c
char input[20];
fgets(input, sizeof(input), stdin);  // safe — won't overflow the buffer
```

### 2D Array of Strings

```c
char fruits[3][20] = {"Apple", "Banana", "Cherry"};
for (int i = 0; i < 3; i++)
    printf("%s\n", fruits[i]);
```

### String Operations Without Library Functions

**Length:**
```c
int len = 0;
while (name[len] != '\0') len++;
```

**Reverse:**
```c
for (int i = 0; i < len; i++)
    rev[i] = str[len - 1 - i];
rev[len] = '\0';
```

**Palindrome Check (two-pointer):**
```c
int l = 0, r = strlen(str) - 1;
while (l < r) {
    if (str[l] != str[r]) { isPalin = 0; break; }
    l++; r--;
}
```

**Compare Strings:**
```c
int i = 0, result = 0;
while (s1[i] != '\0' && s2[i] != '\0') {
    if (s1[i] != s2[i]) { result = s1[i] - s2[i]; break; }
    i++;
}
```

**To Lowercase (manual):**
```c
for (int i = 0; str[i] != '\0'; i++)
    if (str[i] >= 'A' && str[i] <= 'Z')
        str[i] += 32;    // ASCII: 'A'=65, 'a'=97 → difference is 32
```

**Character Frequency:**
```c
int freq[256] = {0};
for (int i = 0; name[i] != '\0'; i++)
    freq[(unsigned char)name[i]]++;
```

---

## 9. Pointers

**File:** `pointers.c`

```c
int x = 25;
int* ptr = &x;       // ptr holds the address of x
printf("%d", *ptr);  // *ptr dereferences → prints 25
```

| Syntax  | Meaning                        |
|---------|--------------------------------|
| `&x`    | Address of variable x          |
| `*ptr`  | Value at the address ptr holds |
| `int*`  | Declares a pointer to int      |

> Arrays are automatically passed as pointers to functions.

---

## 10. Structures

**Files:** `structure.c`, `temp.c`

### Defining a Structure

```c
struct Student {
    char name[50];
    int  age;
    int  class;
};
```

### Creating and Using Struct Instances

```c
struct Student s1;
strcpy(s1.name, "Arup");   // use strcpy for strings in structs
s1.age   = 19;
s1.class = 1;
printf("%s %d %d\n", s1.name, s1.age, s1.class);
```

### Array of Structures

```c
struct Student students[3] = {
    {"CSE", "Alice",   101, {85, 90, 78, 92, 88}},
    {"ECE", "Bob",     102, {70, 65, 80, 75, 60}},
    {"ME",  "Charlie", 103, {55, 60, 72, 68, 74}}
};
```

### Finding Maximum in Struct Array

```c
int maxIdx = 0;
for (int i = 1; i < n; i++)
    if (players[i].battingAverage > players[maxIdx].battingAverage)
        maxIdx = i;
```

---

## 11. Algorithms

**File:** `algorithm.c`

### Linear Search

Scans every element one by one. Works on **unsorted** arrays.

```c
int linearsearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++)
        if (arr[i] == target) return i;
    return -1;    // not found
}
```

- **Time Complexity:** O(n)

### Binary Search

Repeatedly halves the search space. Requires a **sorted** array.

```c
int binarysearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if      (arr[mid] == target) return mid;
        else if (target  >  arr[mid]) low  = mid + 1;
        else                          high = mid - 1;
    }
    return -1;
}
```

- **Time Complexity:** O(log n)

### Bubble Sort

Repeatedly compares adjacent elements and swaps if out of order.

```c
void bubblesort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int swap = 0;                           // optimization flag
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp  = arr[j];
                arr[j]    = arr[j+1];
                arr[j+1]  = temp;
                swap = 1;
            }
        }
        if (swap == 0) break;                   // already sorted — stop early
    }
}
```

- **Time Complexity:** O(n²) worst case, O(n) best case (with flag)

### Algorithm Comparison Table

| Algorithm     | Best     | Worst  | Requires Sorting? |
|---------------|----------|--------|-------------------|
| Linear Search | O(1)     | O(n)   | No                |
| Binary Search | O(1)     | O(log n)| Yes              |
| Bubble Sort   | O(n)     | O(n²)  | —                 |

---

## 12. Practice Problems & Labs

### Lab 1 – Series Sums (`lab1.c`)

| Series | Formula |
|--------|---------|
| a | S = 1 + 3 + 5 + 7 + … (N odd numbers) |
| b | S = 1 + 1/2 + 1/3 + 1/4 + … |
| c | S = 1×3 + 3×5 + 5×7 + … |
| d | S = 1 + 1/2² + 1/3³ + … + 1/nⁿ |
| e | S = 1 + 1/3 + 1/5 + 1/7 + … |

### Lab 2 – Classic Problems (`lab2.c`)

| # | Problem |
|---|---------|
| a | Factorial |
| b | X^Y without `pow()` |
| c | Even & Odd numbers up to N |
| d | Multiplication table (nested loops) |
| e | Count digits in a number |
| f | Product of digits |
| g | Reverse a number |
| h | Palindrome check |
| i | Prime number check |
| j | Menu-driven calculator (switch + infinite loop) |
| k | HCF (GCD) of two numbers |
| l | LCM of two numbers |
| m | Read N positive integers; reject zero, stop on negative |
| n | Keep taking input until sum exceeds 100 |

**Key snippets:**

Reverse a number:
```c
int rev = 0;
while (num != 0) {
    rev = rev * 10 + (num % 10);
    num /= 10;
}
```

Prime check (efficient):
```c
int isPrime = 1;
for (int k = 2; k * k <= inp; k++) {
    if (inp % k == 0) { isPrime = 0; break; }
}
```

Digital Root:
> Keep summing the digits of a number until only one digit remains.  
> Example: 456 → 4+5+6 = 15 → 1+5 = **6**

### Lab 3 – Patterns & Special Numbers (`lab3.c`)

```
Pattern 1 (sequential):    Pattern 2 (repeat digit):  Pattern 3 (triangle):
1                          1                          1
2  3                       2  2                       1  2
4  5  6                    3  3  3                    1  2  3
7  8  9  10                4  4  4  4                 1  2  3  4
```

```
Pattern 4 (chars):
A
B  B
C  C  C
D  D  D  D
E  E  E  E  E
```

Special numbers to explore:
- **Armstrong:** sum of digits each raised to the power of digit count equals the number (e.g., 153 = 1³ + 5³ + 3³)
- **Krishnamurti / Strong:** sum of factorials of digits equals the number (e.g., 145 = 1! + 4! + 5!)
- **Perfect:** sum of proper divisors equals the number (e.g., 6 = 1 + 2 + 3)
- **Pascal's Triangle:** each element is the sum of the two elements above it

### Conditional Questions (`conditionalq.c`)

- Positive / Negative / Zero check
- Larger of two numbers
- Leap year validation
- Vowel or consonant
- Sort 3 numbers without an array

### Advanced Conditional Exercises (`ques.c`)

| Problem | Concept |
|---------|---------|
| Smart Traffic Signal | Nested if-else with priority |
| Electricity Billing | Slab-rate calculation |
| Game Score Analyzer | Range-based conditions |
| ATM Withdrawal Logic | Multiple validation checks |
| Triangle Type Detector | Angle sum + type classification |
| Magic Number | Palindrome + digit sum combined |
| Scholarship Eligibility | Marks + income conditions |
| FizzBuzz variant | Modulus conditions |

---

## 13. Mini Projects

### Project 1 – Math Calculator (`Project1.c`)

| Calculation | Formula |
|-------------|---------|
| Rectangle Area | `length × width` |
| Circle Area | `π × r²` |
| Cylinder Volume | `π × R² × h` |
| Simple Interest | `(P × N × T) / 100` |

### Project 2 – Modulus (`Project2.c`)

```c
int a = 25454543;
printf("%d", a % 97);   // remainder when dividing by 97
```

### Project 3 – Grade System (`project3.c`)

Converts a score (0–100) into letter grades A–E or Fail.

### Project – Number Guessing Game (`project_1.c`)

```c
srand(time(NULL));                        // seed with current time
int random_number = (rand() % 100) + 1;  // 1 to 100
```

The player guesses until they find the number. The program counts attempts and gives "Higher" / "Lower" hints.

---

## 14. Quick Reference – Format Specifiers

| Specifier | Type             | Example                       |
|-----------|------------------|-------------------------------|
| `%d`      | int              | `printf("%d", 42)`            |
| `%f`      | float            | `printf("%f", 3.14)`          |
| `%.2f`    | float (2 dp)     | `printf("%.2f", 3.14159)`     |
| `%c`      | char             | `printf("%c", 'A')`           |
| `%s`      | string           | `printf("%s", "hello")`       |
| `%zu`     | size_t (sizeof)  | `printf("%zu", sizeof(int))`  |
| `%lf`     | double           | `printf("%lf", 3.14)`         |

---

## 15. Common Mistakes to Avoid

| Mistake | Why it's wrong | Fix |
|---------|---------------|-----|
| `90 < a <= 100` | C evaluates left-to-right; always evaluates as true | `a > 90 && a <= 100` |
| `int / int` for decimal | Integer division truncates | Cast: `(float)a / b` |
| Missing `&` in `scanf` | Reads into wrong memory | `scanf("%d", &a)` |
| `gets()` for strings | Buffer overflow risk | Use `fgets()` |
| No `break` in switch | Falls through to next case | Add `break` after each case |
| `=` instead of `==` in condition | Assignment, not comparison | Use `==` for comparison |
| Comparing strings with `==` | Compares pointers, not content | Use `strcmp()` or manual loop |
| Using `strcpy` vs `=` for char arrays | `=` doesn't work on arrays | Always use `strcpy()` |

---

## 📂 Repository File Map

| File | Topic |
|------|-------|
| `First.c` | Hello World, variables, nested loops |
| `Second.c` | if-else, logical operators, switch |
| `Loops.c` | while, for, break, continue |
| `incrementand_decrement.c` | `++` / `--` operators |
| `varq.c` | Variable exercises (10 questions) |
| `conditionalq.c` | Conditional exercises |
| `ques.c` | Advanced conditional problems |
| `FUNCTIONS_AND_RECURSION.c` | Functions, factorial recursion |
| `sp.c` | Permutation P(n,r) — recursion |
| `array.c` | 1D & 2D arrays |
| `array_problem.c` | Sum, max/min, reverse |
| `arrray_function.c` | Passing arrays to functions |
| `strings.c` | String basics, fgets, 2D strings |
| `pointers.c` | Pointer basics |
| `structure.c` | Struct definition & usage |
| `algorithm.c` | Linear search, binary search, bubble sort |
| `lab1.c` | Series sum problems |
| `lab2.c` | Classic loop problems |
| `lab3.c` | Patterns & special numbers |
| `Project1.c` | Area & interest calculator |
| `project3.c` | Grade system |
| `project_1.c` | Number guessing game |
| `temp.c` | Arrays, strings, structures — complete set |

---

*Happy coding! Practice each concept, then try modifying the examples — that's the fastest way to learn C.* 🚀