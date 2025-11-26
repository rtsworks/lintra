<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# Commit Message Guidelines

This project uses **[Conventional Commits]** and enforces the **50/72 rule** for
all commit messages. Follow these guidelines to ensure clear project history, 
better tooling support, and more readable logs.

## 1. Conventional Commits

All commits must follow the [Conventional Commits] specification.

### Format

```
<type>(optional scope): <short summary>

<detailed body>

<footer>
```

### Common Types

| Type       | Purpose                                           | Example commit title                            |
|------------|---------------------------------------------------|-------------------------------------------------|
| `feat`     | A new feature                                     | `feat(auth): add login page`                    |
| `fix`      | A bug fix                                         | `fix(api): handle null response`                |
| `docs`     | Documentation changes                             | `docs(readme): update installation section`     |
| `style`    | Code style changes (no logic changes)             | `style(ui): fix button indentation`             |
| `refactor` | Code refactoring without behavior changes         | `refactor(core): simplify config loader`        |
| `perf`     | Performance improvements                          | `perf(db): optimize query execution`            |
| `test`     | Adding or updating tests                          | `test(user-service): add missing unit tests`    |
| `chore`    | Maintenance tasks, tooling, dependencies, etc.    | `chore(deps): update eslint to latest version`  |
| `ci`       | Changes to CI configuration                       | `ci(github): update actions workflow`           |
| `build`    | Build system or dependency updates                | `build(webpack): enable prod optimizations`     |
| `revert`   | Reverts a previous commit                         | `revert: revert auth token validation change`   |

### Optional Scope

The scope is optional and should be a short identifier for the component or
module changed. Scopes should be concise and lowercase (e.g., `cmd`, `api`, `ui`).

### Simple Examples

```
feat(cmd): add command parser
```

```
fix(cmd): correct null parameter handling
```

## 2. The 50/72 Rule

To improve readability in command-line tools and Git logs, follow these
line-length rules:

### Subject Line (First Line)

* Must be **50 characters or fewer**.
* Use **imperative mood** (e.g., "add", "fix", "remove").
* Do **not** end with a period.
* Must be followed by one blank line before the body.

### Body Lines

* Wrap text at **72 characters per line**.
* Include a body **if the change is not trivial**.
* Explain the **what** and **why**, not necessarily the how.
* Must be followed by one blank line before the footer (if a footer exists).

### Footer

* Optional.
* Used for breaking changes or issue references.
* Footer lines should remain single-line directives and do not need to wrap 
  at 72 characters.

### Extended Examples

Breaking changes must always be marked with **BREAKING CHANGE** in the footer:

```
feat(cmd): add new AT command set

Add a new family of AT commands for configuration and diagnostics.
Provides improved tooling support for device control.

BREAKING CHANGE: Legacy AT command formats are no longer supported.
```

You may also use `!` after the type or scope to indicate a breaking change, in
addition to the required `BREAKING CHANGE:` footer.

```
feat(cmd)!: add new AT command set
```

When a commit closes an open issue, it must be referenced in the footer:

```
fix(cmd): correct AT+STATUS response formatting

Fix formatting of AT+STATUS key/value pairs.
Aligns results to match updated device specification.

Closes: #42
```

To reference an issue without closing it in the footer:

```
Refs: #42
```

To address multiple issues in the footer:

```
Closes: #23, #44, #55
```

or 

```
Refs: #23, #44, #55
```

Sometimes, a commit may close issues, reference others, and include a breaking
change:

```
feat(cmd)!: add new AT command set

Add a new family of AT commands for configuration and diagnostics.
Provides improved tooling support for device control.

BREAKING CHANGE: Legacy AT command formats are no longer supported.
Closes: #42, #55
Refs: #23
```

Although the Conventional Commits specification does not require a specific
footer order, the ordering above is recommended for tooling compatibility and
readability.

## 3. Additional Guidance

* A commit should represent a **single logical change**.
* If unsure, split changes into multiple commits.
* Ensure commit messages are meaningful for both humans and tooling.
* Avoid auto-generated commit messages from editors or hosting platforms; always
  write messages following these guidelines.

[Conventional Commits]: https://www.conventionalcommits.org/