<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# Doxygen Guidelines

These rules describe how to document the code so the generated reference
(`make docs`) stays consistent. The build treats Doxygen warnings as errors, so
undocumented or malformed comments fail it.

## 1. General

* Document every public declaration in `.h` files. Do not put Doxygen comments
  in `.c` files.
* Start Doxygen blocks with `/**` and use `@` for commands, never `\`.
* Use `/**<` for a trailing comment on the same line as an enum member or
  struct field.
* Write the brief as one sentence ending with a period.

## 2. Where documentation lives

| What                              | Where                                   |
|-----------------------------------|-----------------------------------------|
| API of a module (functions, types)| The module's public header              |
| The module's own group            | The same header                         |
| Layer groups (`hal`, `util`, ...) | `doxygen/groups.dox`                    |
| Main page                         | `doxygen/mainpage.dox`                  |
| Long-form pages                   | `doxygen/<topic>.dox`, one `@page` each |

## 3. File block

Every header starts, after the license lines, with a file block that names its
group:

```c
/*******************************************************************************
 * @file
 * @ingroup hal_gpio
 * @brief Mockable GPIO HAL.
 ******************************************************************************/
```

## 4. Groups

* Layer groups are defined once in `doxygen/groups.dox`.
* A module defines its own group in its header, after the include guard, puts
  it in a layer with `@ingroup`, and wraps the declarations with `@{` and `@}`.
* Group ids are unique across the whole project and use the module name, for
  example `hal_gpio`.
* Give each module group `@since` and `@version`.

```c
/**
 * @brief Mockable GPIO HAL.
 * @defgroup hal_gpio GPIO
 * @ingroup hal
 * @since 1.0.0
 * @version 1.0.0
 * @{
 */

/* declarations */

/** @} */
```

## 5. Functions

Order the tags as shown and use only the ones that apply:

```c
/**
 * @brief One sentence summary.
 * @details Only when there is more to say than the brief.
 * @param[in]  pin   what it is
 * @param[out] value what it is
 * @return What the function returns in general.
 * @retval 0 a specific value and what it means
 * @retval 1 another specific value
 */
```

* `@brief` is always required.
* `@details` is optional. Add it only for information the brief cannot carry,
  such as preconditions or side effects.
* Document parameters in declaration order and always state the direction:
  `[in]`, `[out]` or `[in,out]`.
* Use `@return` for a general description of the result. Add `@retval` for
  each specific value when the function returns a small set of them.
* Omit `@return` for `void` functions.

## 6. Types

Give every `typedef`, `struct`, `union` and `enum` a `@brief`, and document each
member.

## 7. Examples

* Use `@par Example` with `@code` and `@endcode` for a short snippet in a
  group or function description.

## 8. Pages and sections

* Use a page (`@page`) for topics that do not belong to one module, such as the
  architecture or the workflow. Link pages from the main page with `@subpage`.
* Use `@section` and `@subsection` to structure long pages and long group
  descriptions.
* Section and page ids are unique across the whole project.
