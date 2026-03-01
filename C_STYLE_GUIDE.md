<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# C Style Guide

This document defines the **coding style and formatting rules** for all C source
code in this project. It supplements—but does **not replace** - MISRA C:2012.

The goals of this style guide are:

* readability
* consistency across the codebase
* maintainability for long-term embedded projects
* strong compatibility with automated tooling
* clear expectations for contributors

## 1. Scope

This guide applies to:

* All C source (`.c`) and header (`.h`) files
* All new contributions and refactoring work

It does **not** cover build scripts, tests, or documentation unless they use C.

## 2. Relationship to MISRA C:2012

All code **must comply with MISRA C:2012**, except where explicitly deviated by
the project’s approved **MISRA Deviation Procedure**.

MISRA governs:

* safe language features
* undefined/implementation-defined behavior
* restricted constructs
* safe type usage
* memory safety

This style guide governs:

* naming conventions
* indentation and formatting
* header layout
* file organization
* project conventions

**If a rule here conflicts with MISRA, MISRA takes precedence.**

## 3. File Organization

### 3.1 File Naming

* Source files: `module_name.c`
* Header files: `module_name.h`
* Private module headers: `module_name_priv.h`

Names must be lowercase with underscores.

### 3.2 File Structure

* Every `.c` file must follow the [C Template file](template.c)
* Every `.h` file must follow the [H Template file](template.h)

### 3.3 File Placement

Each module must be organized in a dedicated directory under the project’s
standard structure. A typical module layout is:

- `src/<module_name>/` — C source files
- `include/<module_name>/` — Public header files
- `test/<module_name>/` — Unit tests (non-hardware-dependent only)

#### 3.3.1 Module File Names

Each module consists of the following files:

| Purpose       | Required Filename      | Description                                       |
|---------------|------------------------|---------------------------------------------------|
| Source file   | `module_name.c`        | Implementation of the module                      |
| Public header | `module_name.h`        | Interface exposed to other modules                |
| Test file     | `test_<module_name>.c` | Unit tests for logic not depending on hardware/OS |

**Example: ADC module**

- `src/adc/adc.c`
- `include/adc/adc.h`
- `test/adc/test_adc.c` — Only if the logic is testable without hardware

#### 3.3.2 Rules

- Each module must reside in its own directory.
- File names must match the module name exactly (lowercase, underscores allowed).
- Only the public header for a module belongs in `include/<module_name>/`.  
  All internal headers required by the module should remain inside 
  `src/<module_name>/` alongside the source files.
- Test files must not depend on hardware peripherals or drivers.
- Modules must not define source files outside their own directory.

### 3.4 Include Paths

* Use **full paths** for project headers: `#include "drivers/i2c/i2c.h"`
* Use `<...>` for standard and system headers: `#include <stdint.h>`
* **Never** include `.c` files
* Minimize dependencies: include only what is required.

Includes must follow this order:

1. Module's own header
2. Standard library headers
3. Other project headers

### 3.5 Header Guards

All header files must use traditional include guards:

```
    #ifndef DRIVERS_I2C_H
    #define DRIVERS_I2C_H

    ...

    #endif /* DRIVERS_I2C_H */
```

Guard macro must reflect the relative include path in uppercase with underscores.
The example above is for the file located in `include/drivers/i2c/i2c.h`

## 4. Formatting

### 4.1 Indentation

Use 4 spaces per indentation level, **never** use tabs.

### 4.2 Braces

Conditional branches and control flow statements must follow Allman style,
with the exception of do-while loops.

Allman style:

```
if (condition) 
{
    ...
} 
else 
{
    ...
}
```

```
switch (state)
{
case STATE_IDLE:
    ...
    break;
case STATE_BUSY:
    ...
    break;
default:
    ...
    break;
}
```

```
for (...) 
{
    ...
}
```

```
while (...) 
{
    ...
}
```

do-while loops must use the following format:

```
do {
    ...
} while (...);
```

Function definitions must follow allman style:

```
void func(void)
{
    ...
}
```

### 4.3 Line Length

* Maximum 80 characters per line.
* Comments may exceed this only for URLs or doxygen markdown tables.

### 4.4 Spacing Rules

* One space after if, for, while, switch: `while (...)`
* case and default labels inside switch statements are not indented and must
  align with the switch keyword.
* No space before parentheses in function calls: `func(...);`
* One space around operators: `a = b + c;`
* No trailing whitespace.

## 5. Naming Conventions

### 5.1 Variables

#### 5.1.1 General Rules

* Use **lowercase with underscores** for variable names: `uint32_t my_var;`.
* Never declare multiple variables in a single statement:
```
uint8_t a;    /* OK */
uint8_t a, b; /* Not allowed */
```

#### 5.1.2 Pointer Variables

* Pointer stars must be written next to the type: `uint8_t* p_data;`
* Prefix pointers with `p_`: `uint8_t* p_data;`.
* Prefix pointer-to-pointer with `pp_`: `uint8_t** pp_data;`.
* Prefix function pointers with `fp_`: `void (*fp_handler)(int);`.

#### 5.1.3 Boolean Variables

Boolean variables must use `bool` from `<stdbool.h>`.

Integer types (`uint8_t`, `int`) must not be used to represent logical 
true/false values, except when:

- Representing hardware registers or memory-mapped I/O
- Representing bitmask flag fields
- Required by protocol or ABI layout

Prefix boolean variables with `is_` or `has_`: `is_enabled`, `has_error`.

### 5.2 Functions

Use **lowercase with underscores** for function names: `uint32_t my_foo(void);`.

### 5.3 Types

#### 5.3.1 Enums

Postfix enum typedefs with `_e`:

```
typedef enum
{
    ADC_A,
    ADC_B
} adc_e;
```

Enum entries must not end with a trailing comma after the final element.

#### 5.3.2 Structs

Postfix struct typedefs with `_t`:

```
typedef struct
{
    ...
} adc_t;
```

#### 5.3.3 Unions

Postfix union typedefs with `_u`:

```
typedef union
{
    ...
} adc_u;
```

### 5.4 Macros

Macros must be all uppercase with module name prefix:

```
/* The module name is ADC */
#define ADC_CHANNELS (16U)
```

### 5.5 Abbreviations

* Avoid abbreviations unless they are universally understood (e.g., id, crc).
* Avoid ambiguous or cryptic abbreviations.

## 6. Declarations and Object Rules

### 6.1 Const Correctness

The `const` qualifier must be used wherever possible to enforce immutability
and improve code safety:

* All objects that are not modified after initialization must be declared `const`.
* File-scope objects that are not modified must be declared `static const`.
* Function parameters that are not modified must be declared `const`.
* Pointers to read-only data must declare the pointed-to data as `const`.
* Never cast away `const`.

### 6.2 Initialization

* All variables must be initialized at the point of declaration. This includes
  static storage duration objects.
* Integer literals must use appropriate suffixes (e.g., U, UL).

```
static uint32_t value = 0U;
uint32_t counter = 0U;
bool is_ready = false;
```

### 6.3 Magic Numbers

Numeric literals must not appear directly in code except in the following cases:

* 0, 1, and -1 when semantically clear.
* Bit shifts (e.g., 1U << 3).
* Loop counters in for-statements when the literal is 0 or 1.

All other numeric values must be defined as named constants or macros.

* Named constants must use uppercase with module prefix.
* Literal suffixes must match the intended type (e.g., U, UL).
* Floating-point literals must use explicit suffixes (e.g., 1.0F).

## 7. Comments

* Use `/* */` for normal comments.
* `//` single-line comments are not permitted.
* Doxygen comments (`/** */`) are allowed only in `.h` files.
* Keep comments concise.

## 8. Documentation

Use Doxygen to document only `.h` files. See [Doxygen guidelines](DOXYGEN_GUIDELINES.md)
for more details.

## 9. Functions

* Functions must not exceed 100 lines of executable code.
* Function length excludes blank lines and comments.
* Functions must not exceed 5 parameters.
* Avoid nesting control structures deeper than 3 levels.
* Prefer early returns to reduce nesting.
* Each function must have a single, clearly defined responsibility.
* Functions must be declared at file scope unless required in a header.

## 10. Minimize scope

Only expose what is necessary. Use `static` for private file-scope functions and
variables.

## 11. Preprocessor Usage

* Avoid macros where inline functions suffice.
* Parenthesize macro parameters:

```
#define MAX(a,b) ((a) > (b) ? (a) : (b))
```

## 12. Error Handling

* Functions that may fail must return a status code.
* The success value must be explicitly defined as 0.
* Status codes must use a module/system-specific enum type:

```
typedef enum
{
    ADC_STATUS_OK = 0,
    ADC_STATUS_INVALID_PARAM,
    ADC_STATUS_TIMEOUT,
    ADC_STATUS_HW_FAILURE
} adc_status_e;
```

* Boolean return types must not be used to represent detailed error conditions.
* Input parameters must be validated at the beginning of the function.
* Functions that cannot fail must return `void`.

## 13. Tooling

All formatting must be compatible with the project's formatter 
[configuration](.clang-format). Contributors must not manually reformat code in
ways that conflict with the formatter.