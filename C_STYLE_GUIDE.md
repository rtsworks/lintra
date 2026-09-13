<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# C Style Guide

This document defines the **coding style and naming conventions** for all C
source code in this project. It supplements—but does **not replace** - MISRA
C:2012. Formatting (indentation, braces, spacing, line length, alignment,
etc.) is handled separately by [clang-format](.clang-format) and is not
documented here.

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

All code **must comply with MISRA C:2012**. A deviation is only permitted as
an inline `/* cppcheck-suppress misra-c2012-<rule> */` comment placed directly
above the violating line, immediately followed by a comment justifying why
the deviation is necessary. Undocumented or unjustified suppressions are not
allowed.

MISRA governs:

* safe language features
* undefined/implementation-defined behavior
* restricted constructs
* safe type usage
* memory safety

This style guide governs:

* naming conventions
* header layout
* file organization
* project conventions

Formatting is governed by [clang-format](.clang-format), not this document.

**If a rule here conflicts with MISRA, MISRA takes precedence.**

## 3. File Organization

### 3.1 File Naming

* Source files: `module_name.c`
* Header files: `module_name.h`
* Private module headers: `module_name_priv.h`
* Additional internal source files: `module_name_<descriptor>.c`
* Test files: `test_<module_name>.c`

Names must be lowercase with underscores.

A module may consist of only a header file, with no corresponding `.c`
file, when it contains no implementation requiring compilation.

This is distinct from a configuration header shared across multiple
modules in a layer (e.g. hardware/board configuration used by several
drivers) — such a header is not a module itself and does not get a
dedicated directory.

### 3.2 File Structure

* Every `.c` file must follow the [C Template file](template.c)
* Every `.h` file must follow the [H Template file](template.h)

### 3.3 File Placement

A module's *source* and *test suite* each need their own dedicated
directory only once they grow beyond a single file — for source, a
private header or multiple source files; for tests, multiple test files
split by scenario for readability. A module's public header never does —
a module only ever has one. Until dedicated, small single-file modules
that belong to a common category sit flatly alongside each other inside
that category's shared directory. A typical module layout is:

- `src/<module_name>/` — C source files (once dedicated)
- `include/` — Public header file (always flat within its category, or
  directly under `include/` if standalone)
- `test/<module_name>/` — Unit test files (once dedicated;
  non-hardware-dependent only)

#### 3.3.1 Module File Names

Each module consists of the following files (see Section 3.1 for naming):

| Purpose       | Description                                        |
|---------------|-----------------------------------------------------|
| Source file   | Implementation of the module                       |
| Public header | Interface exposed to other modules                 |
| Test file     | Unit tests for logic not depending on hardware/OS  |

A module may omit the source file when it has no implementation requiring
compilation (see Section 3.1).

**Example: ADC module (needs a private header)**

`adc` realistically belongs inside a shared category like `bsp` alongside
other peripheral drivers. Its private header for calibration helpers
means its *source* graduates into its own subdirectory — but its public
header does not, since a module only ever has one and a dedicated
directory would hold nothing else:

- `src/bsp/adc/adc.c`
- `src/bsp/adc/adc_priv.h`
- `include/bsp/adc.h`
- `test/bsp/test_adc.c` — Only if the logic is testable without hardware

**Example: HAL layer (flat category directory)**

Each of these is a single source + single header pair, so none of them
need their own subdirectory — they sit flatly inside the shared `hal`
category:

- `src/hal/gpio.c`, `include/hal/gpio.h`
- `src/hal/uart.c`, `include/hal/uart.h`
- `src/hal/spi.c`, `include/hal/spi.h`
- `src/hal/timer.c`, `include/hal/timer.h`

The moment one of them needs a private header or splits into multiple
source files, that module alone graduates into its own subdirectory —
e.g. `src/hal/uart/uart.c` and `src/hal/uart/uart_isr.c` — while the
others stay flat.

**Example: shared configuration header (not a module)**

- `include/board_config.h` — configures several drivers in a layer; no
  dedicated directory, no corresponding `.c` file

#### 3.3.2 Rules

- A module's source graduates into its own dedicated directory once it
  needs more than one source file or a private header. Until then, it may
  sit flatly inside its category's shared `src/` directory alongside
  sibling modules.
- A module's test suite graduates into its own dedicated directory the
  same way — once it needs more than one test file (e.g. split by
  scenario for readability). Until then, it sits flatly in its category's
  shared `test/` directory alongside sibling modules.
- A module's public header never gets a dedicated directory of its own —
  a module only ever has one, so there is nothing else to put in such a
  directory regardless of how complex its source becomes. It always sits
  flatly in its category's shared `include/` directory (or directly under
  `include/` for a standalone module).
- File names must match the module name exactly.
- Internal headers belong in `src/`, next to the module's source file(s),
  never in `include/`.
- Test files must not depend on hardware peripherals or drivers.
- A module's source and test files must live in their own directory once
  they have one, or in their shared category directory while flat — never
  scattered elsewhere.

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
The example above is for the file located in `include/drivers/i2c/i2c.h`. This
header guard can also be prefixed by the projects name to reduce the chance of
name collisions.

## 4. Naming Conventions

### 4.1 Variables

#### 4.1.1 General Rules

* Use **lowercase with underscores** for variable names: `uint32_t my_var;`.
* Never declare multiple variables in a single statement:
```
uint8_t a;    /* OK */
uint8_t a, b; /* Not allowed */
```

#### 4.1.2 Pointer Variables

* Suffix pointer variables with `_p`: `uint8_t *data_p;`
* Suffix pointer-to-pointer variables with `_pp`: `uint8_t **data_pp;`
* Suffix function-pointer variables with `_fp`: `void (*handler_fp)(int);`

#### 4.1.3 Boolean Variables

Boolean variables must use `bool` from `<stdbool.h>`.

Integer types (`uint8_t`, `int`) must not be used to represent logical 
true/false values, except when:

- Representing hardware registers or memory-mapped I/O
- Representing bitmask flag fields
- Required by protocol or ABI layout

Prefix boolean variables with `is_` or `has_`: `is_enabled`, `has_error`.

#### 4.1.4 File-Static Objects

Global variables with external linkage (plain globals) are **not allowed**.
Every object at file scope must be declared `static`, giving it internal
linkage.

Prefix file-static objects with `s_`:

```
static uint32_t s_counter;
```

The static prefix and a pointer suffix combine when both apply, prefix
first and suffix last:

```
static uint8_t *s_buffer_p;
```

### 4.2 Functions

Use **lowercase with underscores** for function names: `uint32_t my_foo(void);`.

### 4.3 Types

#### 4.3.1 Enums

Postfix enum typedefs with `_e`:

```
typedef enum {
    ADC_A,
    ADC_B
} adc_e;
```

Enum entries must not end with a trailing comma after the final element.

#### 4.3.2 Ordinary Types

Postfix ordinary typedefs (e.g. structs) with `_t`:

```
typedef struct {
    ...
} adc_t;
```

#### 4.3.3 Unions

Postfix union typedefs with `_u`:

```
typedef union {
    ...
} adc_u;
```

#### 4.3.4 Function-Pointer Typedefs

Postfix function-pointer typedefs with `_fp_t`:

```
typedef void (*adc_callback_fp_t)(int);
```

### 4.4 Macros

Macros must be all uppercase with module name prefix:

```
/* The module name is ADC */
#define ADC_CHANNELS (16U)
```

Configuration macros (e.g. in a shared configuration header — see Section
3.1) use a `CONFIG_` prefix, in addition to the module name when the value
configures one specific module:

```
#define CONFIG_TIMER_SERVER_SLOTS (8U) /* configures the timer server module */
#define CONFIG_BOARD_CLOCK_HZ (16000000UL) /* shared across the layer */
```

### 4.5 Abbreviations

* Avoid abbreviations unless they are universally understood (e.g., id, crc).
* Avoid ambiguous or cryptic abbreviations.

## 5. Declarations and Object Rules

### 5.1 Const Correctness

The `const` qualifier must be used wherever possible to enforce immutability
and improve code safety:

* All objects that are not modified after initialization must be declared `const`.
* File-scope objects that are not modified must be declared `static const`.
* Function parameters that are not modified must be declared `const`.
* Pointers to read-only data must declare the pointed-to data as `const`.
* Never cast away `const`.

### 5.2 Initialization

* All variables must be initialized at the point of declaration. This includes
  static storage duration objects.
* Integer literals must use appropriate suffixes (e.g., U, UL).

```
static uint32_t s_value = 0U;
uint32_t counter = 0U;
bool is_ready = false;
```

### 5.3 Magic Numbers

Numeric literals must not appear directly in code except in the following cases:

* 0, 1, and -1 when semantically clear.
* Bit shifts (e.g., 1U << BIT_POSITION).
* Loop counters in for-statements when the literal is 0 or 1.

All other numeric values must be defined as named constants or macros.

* Named constants must use uppercase with module prefix.
* Literal suffixes must match the intended type (e.g., U, UL).
* Floating-point literals must use explicit suffixes (e.g., 1.0F).

#### 5.3.1 Enum vs. Macro

Use an **enum** when the value is one of a related, mutually-exclusive set
of symbolic options (states, error codes, pin identifiers, modes).

Use a **macro** for a standalone numeric constant, or whenever the value
must be visible to the preprocessor (`#if`). A macro is also required
whenever an exact literal suffix must be enforced (e.g., `U`, `UL`, `F`),
since an enum member's underlying type is implementation-defined and
cannot carry one.

## 6. Comments

* Use `/* */` for normal comments.
* `//` single-line comments are not permitted.
* Doxygen comments (`/** */`) are allowed only in `.h` files.
* Keep comments concise.

## 7. Documentation

Use Doxygen to document only `.h` files. See [Doxygen guidelines](DOXYGEN_GUIDELINES.md)
for more details.

## 8. Functions

* Functions must not exceed 100 lines of executable code.
* Function length excludes blank lines and comments.
* Functions must not exceed 5 parameters.
* Avoid nesting control structures deeper than 3 levels.
* Functions must have a single point of exit: one `return`, at the end of
  the function (MISRA C:2012 Rule 15.5). Do not use early returns.
* Each function must have a single, clearly defined responsibility.
* Functions must be declared at file scope unless required in a header.

## 9. Minimize Scope

Only expose what is necessary. Use `static` for private file-scope functions and
variables — see Section 4.1.4 for the required naming and the rule against
plain (non-static) global variables.

## 10. Preprocessor Usage

* Avoid macros where inline functions suffice.
* Parenthesize macro parameters:

```
#define MAX(a,b) ((a) > (b) ? (a) : (b))
```

## 11. Error Handling

* Functions that may fail must return a status code.
* The success value must be explicitly defined as 0.
* Status codes must use a module/system-specific enum type:

```
typedef enum {
    ADC_STATUS_OK = 0,
    ADC_STATUS_INVALID_PARAM,
    ADC_STATUS_TIMEOUT,
    ADC_STATUS_HW_FAILURE
} adc_status_e;
```

* Boolean return types must not be used to represent detailed error conditions.
* Input parameters must be validated at the beginning of the function.
* Functions that cannot fail must return `void`.

## 12. Tooling

All formatting (indentation, braces, spacing, line length, alignment, include
ordering, etc.) is fully delegated to [clang-format](.clang-format). This
guide does not document formatting rules directly — the `.clang-format`
configuration is the single source of truth. Run `make format` before
committing. Contributors must not manually reformat code in ways that
conflict with the formatter's output.
