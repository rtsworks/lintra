<div align="center">

  <!-- Banner placeholder -->
  ![Lintra Banner](images/lintra-banner.png)
  
  # C project starter & CI/CD-friendly toolkit
  
  <!-- Badge placeholder -->
  [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
  ![OS: Windows](https://img.shields.io/badge/OS-Windows-blue)
  ![Status: Active](https://img.shields.io/badge/status-active-brightgreen)
  
</div>

**Lintra** is a C project template with a built-in, CI/CD-friendly toolkit designed to
streamline the development workflow of C projects. It provides an automated process
for linting, testing, and building a C project with minimal setup.

Lintra enforces a strict, fail-fast policy composed of three stages:

1. **Lint** — Enforces MISRA C:2012 guidelines via [cppcheck].  
2. **Test** — Executes unit tests using [ceedling], automatically generating:
   - Cobertura and HTML code coverage reports  
   - JUnit and HTML test reports  
   - Test runners and mocks  
3. **Build** — Uses [make] to build the project with strict compilation flags.

[cppcheck]: https://github.com/danmar/cppcheck
[ceedling]: https://github.com/ThrowTheSwitch/Ceedling
[make]: https://www.gnu.org/software/make/

If any stage fails, Lintra immediately halts the process.
