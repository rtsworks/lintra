# Changelog

All notable changes to this project are documented in this file.

Changes are organized into the following categories:

- **Added:** New features or functionality introduced to the project.
- **Changed:** Modifications to existing functionality that do not add new features.
- **Fixed:** Bug fixes that resolve issues or correct unintended behavior.
- **Removed:** Features or components that have been removed from the project.

## v1.1.0 (2026-09-28)

### Added

- **workflows**: Permission update

### Changed

- **commitizen**: update bump commit message
- **bump**: manual version bump

## v1.0.1 (2026-09-27)

### Changed

- **CHANGELOG.md**: Adapt to commitizen

## v1.0.0 (2026-09-27)

### Added

- A `make`-based workflow with independent `format`, `format-check`, `lint`,
  `test`, `build`, `docs`, and `clean` targets, and debug/release build
  configurations.
- Strict GCC compiler warnings for the build target.
- MISRA C:2012 static analysis via cppcheck, with a thread-safety addon.
- Unit testing via Ceedling, with CMock-generated mocks and gcovr coverage,
  producing JUnit and Cobertura reports.
- A clang-format configuration for consistent source formatting.
- API documentation via Doxygen, with the doxygen-awesome-css theme, PlantUML
  diagram support, and grouped topic pages.
- Commit message linting via gitlint, installable as a local commit-msg hook,
  and guided commit authoring via Commitizen, both configured to match this
  project's Commit Message Guidelines.
- GitHub Actions workflows for the build/lint/test/docs pipeline and for
  commit message and pull request title checks.
- Project guidelines: C Style Guide, Doxygen Guidelines, Commit Message
  Guidelines, Branch Naming Guidelines, and Pull Request Guidelines.
- A fork-and-branch contribution workflow, documented in CONTRIBUTING.md.
- A Code of Conduct, a Security Policy, issue and pull request templates, and
  a CODEOWNERS file.
- Starting templates for new `.c` and `.h` files, matching the C Style Guide.
- Vendored third-party tools: Ceedling, doxygen-awesome-css, and PlantUML.
