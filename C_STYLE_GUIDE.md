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

| Purpose       | Required Filename      | Description                                               |
|---------------|------------------------|-----------------------------------------------------------|
| Source file   | `module_name.c`        | Implementation of the module                              |
| Public header | `module_name.h`        | Interface exposed to other modules                        |
| Test file     | `test_<module_name>.c` | Unit tests for logic not depending on hardware (optional) |

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

## 4. Formatting

### 4.1 Indentation

Use 4 spaces per indentation level, **never** use tabs.

### 4.2 Braces

Conditional branches must follow K&R style:

```
if (condition) {
    ...
} else {
    ...
}
```

Control flow must follow K&R style:

```
for (...) {
    ...
}

while (...) {
    ...
}

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
* No space before parentheses in function calls: `func(...);`
* One space around operators: `a = b + c;`
* No trailing whitespace.

## 5. Naming Conventions

### 5.1 Variables

#### 5.1.1 General Rules

* Use **lowercase with underscores** for variable names: `uint32_t my_var;`.

#### 5.1.2 Pointer Variables

* Prefix pointers with `p_`: `uint8_t **p_data;`.
* Prefix pointer-to-pointer with `pp_`: `uint8_t **pp_data;`.
* Prefix function pointers with `fp_`: `void (*fp_handler)(int);`.

#### 5.1.3 Boolean Variables

Prefix boolean variables with `is_` or `has_`: `is_enabled`, `has_error`.

### 5.2 Functions

Use **lowercase with underscores** for function names: `uint32_t my_foo(void);`.

### 5.3 Types

#### 5.3.1 Enums

Postfix enum types with `_e`: `enum adc_e`.

#### 5.3.2 Structs

Postfix struct types with `_s`: `struct adc_s`.

#### 5.3.3 Unions

Postfix union types with `_u`: `union adc_u`.

### 5.4 Macros

Macros must be all uppercase with module name prefix:

```
/* The module name is ADC */
#define ADC_CHANNELS (16U)
```

### 5.5 Abbreviations

* Only use well-known abbreviations (`cfg` → `config`, `tmp` → `temporary`).
* Avoid ambiguous or cryptic abbreviations.

## 6. Comments

* Use `/* */` for normal comments.
* Keep comments concise.

## 7. Documentation

Use Doxygen to document only `.h` files. see [doxygen guidelines](DOXYGEN_GUIDELINES.md)
for more details.

## 8. Functions

Functions must be limited to < 100 lines.

## 9. Minimize scope

Only expose what is necessary. Use `static` for private file-scope functions and
variables.

## 10 Preprocessor Usage

* Avoid macros where inline functions suffice.
* Parenthesize macro parameters:

```
#define MAX(a,b) ((a) > (b) ? (a) : (b))
```