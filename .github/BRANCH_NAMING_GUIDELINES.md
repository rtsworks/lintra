<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# Branch Naming Guidelines

To keep the repository organized and maintain a clean Git history, please follow
these conventions when creating branches.

---

## Reserved Branches

| Branch Name | Description                                   |
| ----------- | --------------------------------------------- |
| `main`      | Stable branch. Only merged PRs should go here |
| `dev`       | Development branch for integrating features   |

---

## Work Branches

| Branch Prefix       | Purpose                     | Notes                                                                   |
| ------------------- | --------------------------- | ----------------------------------------------------------------------- |
| `feature/<name>`    | New features                | `<name>` should describe the feature clearly, e.g., `login-page`        |
| `bugfix/<issue>`    | Bug fixes                   | Use the related issue number & short description, e.g., `123-fix-login` |
| `docs/<topic>`      | Documentation changes       | `<topic>` describes the docs section updated                            |
| `chore/<task>`      | Maintenance or housekeeping | For tooling, dependency updates, etc...                                 |
| `refactor/<module>` | Refactoring code            | Module or component being refactored                                    |
| `test/<module>`     | Adding or updating tests    | Specify which module or feature is tested                               |
| `perf/<module>`     | Performance improvements    | Indicate what was optimized                                             |


---

## Guidelines

1. Use **lowercase letters** and **hyphens** (`-`) to separate words.
2. Do not use spaces or special characters (only letters, numbers, and hyphens).
3. Keep branch names **short and descriptive** (e.g., under 50 characters).
4. Include the **type of work** (`feature/`, `bugfix/`, etc.) as a prefix.
5. Reference the **issue number** if applicable, placing it before the description
   in the branch name (e.g., `bugfix/123-fix-login` or `feature/456-new-dashboard`).
