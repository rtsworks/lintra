<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

<div align="center">

  ![Lintra Banner](images/lintra-banner.png)

  # C project starter & CI/CD-friendly toolkit

  ![OS: Windows / Linux](https://img.shields.io/badge/OS-Windows%20%7C%20Linux-blue)
  [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE.md)
  ![Status: Active](https://img.shields.io/badge/status-active-brightgreen)

</div>

**Lintra** is a C project template with a built-in, CI/CD-friendly toolkit designed
to streamline the development workflow of C projects. It automates formatting,
linting, testing, building, and documenting C projects with minimal setup.

<a id="toolkit"></a>

Lintra gives you one `make` target per tool:

| Command             | What it does                                                |
|---------------------|-------------------------------------------------------------|
| `make format`       | Formats all sources in place with [clang-format].           |
| `make format-check` | Checks the formatting without changing any file, for CI.    |
| `make lint`         | Enforces MISRA C:2012 guidelines via [cppcheck].            |
| `make test`         | Runs unit tests with [ceedling] and collects coverage.      |
| `make build`        | Builds the project with [make] using strict compiler flags. |
| `make docs`         | Generates HTML API documentation with [doxygen].            |
| `make clean`        | Removes all build, test, and documentation output.          |

The targets are independent, so you can run them in any order and wire them into
CI however you like. Running `make` with no arguments runs `build`.

[clang-format]: https://clang.llvm.org/docs/ClangFormat.html
[cppcheck]: https://cppcheck.sourceforge.io/
[ceedling]: https://github.com/ThrowTheSwitch/Ceedling
[make]: https://www.gnu.org/software/make/
[doxygen]: https://www.doxygen.nl/

Alongside the toolkit, Lintra ships the conventions to go with it: a
[C style guide](C_STYLE_GUIDE.md), [Doxygen guidelines](DOXYGEN_GUIDELINES.md),
file [templates](templates/), and a set of GitHub issue, pull request, and
contribution templates.

## Getting Started

Start by obtaining a local copy of `lintra` (e.g., via Git):

```bash
git clone https://github.com/rtsworks/lintra.git
```

Alternatively, you can download the repository as a ZIP file from [this page]
and extract it manually.

[this page]: https://github.com/rtsworks/lintra/tree/main

Once you have a local copy of `lintra`, follow the instructions below to
complete the setup and get `lintra` up and running.

### MISRA Guidelines

This project uses the file `misra_c_2012__headlines_for_cppcheck - AMD1+AMD2.txt`
by **The MISRA Consortium Limited**, available [here].

Licensed under [CC BY-NC-ND 4.0](https://creativecommons.org/licenses/by-nc-nd/4.0/).

To use it here, download the file from the link above, rename it to
`misra_c_2012_rules.txt`, and move it to the `cppcheck/` folder. No modifications
are made to the file contents.

**NOTE:** This file is deliberately listed in `.gitignore` to avoid redistributing
it here, ensuring that the rest of the project remains entirely under the MIT license.

[here]: https://gitlab.com/MISRA/MISRA-C/MISRA-C-2012/tools/-/blob/main/misra_c_2012__headlines_for_cppcheck%20-%20AMD1+AMD2.txt?ref_type=heads

### Tool versions

The versions below are the ones `lintra` is currently developed and tested
against. Newer versions generally work, but these are the known-good ones.

#### Windows

| Tool           | Version   | Needed for                          |
|----------------|-----------|-------------------------------------|
| GCC            | 11.2.0    | Compiling the project and the tests |
| GNU Make       | 4.3       | Running the toolkit                 |
| Git            | 2.51.0    | Obtaining and versioning the code   |
| Ruby           | 3.4.5     | Running Ceedling                    |
| Ceedling       | 1.0.1     | Unit tests, mocks, coverage         |
| Python         | 3.14.3    | Installing and running `gcovr`      |
| gcovr          | 8.6       | Coverage reports                    |
| Cppcheck       | 2.20.0    | MISRA C:2012 static analysis        |
| clang-format   | 21.1.0    | Formatting the sources              |
| Doxygen        | 1.18.0    | Generating the documentation        |

#### Linux Mint

| Tool           | Version   | Needed for                          |
|----------------|-----------|-------------------------------------|
| GCC            | 11.4.0    | Compiling the project and the tests |
| GNU Make       | 4.3       | Running the toolkit                 |
| Git            | 2.34.1    | Obtaining and versioning the code   |
| Ruby           | 3.0.2     | Running Ceedling                    |
| Ceedling       | 1.0.1     | Unit tests, mocks, coverage         |
| Python         | 3.10.12   | Installing and running `gcovr`      |
| gcovr          | 8.6       | Coverage reports                    |
| Cppcheck       | 2.20.0    | MISRA C:2012 static analysis        |
| clang-format   | 21.1.0    | Formatting the sources              |
| Doxygen        | 1.18.0    | Generating the documentation        |

The Ceedling version must match `:ceedling_version:` in `project.yml`.

### Windows Setup

Windows users should install the following tools to run `lintra`:

- [MinGW] — Provides the GCC compiler and [make] utility for building the project.
- [MSYS2] — Offers a Unix-like shell environment required for the Makefile to run
            properly.
- [python3] — Comes with pip3 on Windows, used to install `gcovr` for coverage
              reports.
- [Ruby] — Required for running [Ceedling], the unit testing framework.
- [Cppcheck] — Used to enforce MISRA C:2012 guidelines.
- [LLVM] — Provides `clang-format`, used to format the sources.
- [Doxygen] — Used to generate the API documentation.

Once the tools are installed, make sure each tool’s executable directory is added
to your system’s **PATH**. The Python and Ruby installers offer an "Add to PATH"
option that does this for you. Then open a **new** terminal, so that it picks up
the updated **PATH**.

Install `gcovr` via command line:

```bash
pip3 install gcovr
```

Install [Ceedling] via command line:

```bash
gem install ceedling -v 1.0.1
```

`lintra` runs the copy of Ceedling vendored in `vendor/ceedling`, but the gem
still has to be installed so that the Ruby gems it depends on are available.

[MinGW]: https://nuwen.net/mingw.html
[MSYS2]: https://www.msys2.org/
[python3]: https://www.python.org/downloads/windows/
[Ruby]: https://rubyinstaller.org/
[Cppcheck]: https://cppcheck.sourceforge.io/
[LLVM]: https://releases.llvm.org/
[Doxygen]: https://www.doxygen.nl/download.html

### Linux Setup

**NOTE:** The instructions below were tested on Linux Mint. The versions they
produce are listed under [Tool versions](#tool-versions).

Linux users should install the following tools to run `lintra`:

- Install build essentials, Ruby, and pip:

```bash
sudo apt install -y build-essential ruby-full python3-pip
```

- Install [Doxygen]:

```bash
curl -sLO https://github.com/doxygen/doxygen/releases/download/Release_1_18_0/doxygen-1.18.0.linux.bin.tar.gz
sudo tar xzf doxygen-1.18.0.linux.bin.tar.gz -C /opt
sudo ln -sf /opt/doxygen-1.18.0/bin/doxygen /usr/local/bin/doxygen
rm doxygen-1.18.0.linux.bin.tar.gz
```

- Install `gcovr` and `clang-format`:

```bash
sudo pip3 install gcovr==8.6
sudo pip3 install clang-format==21.1.0
```

- Install [Ceedling]:

```bash
sudo gem install ceedling -v 1.0.1
```

- Install cppcheck:

```bash
git clone https://github.com/danmar/cppcheck.git /tmp/cppcheck && \
cd /tmp/cppcheck && \
git checkout 2.20.x && \
sudo make FILESDIR=/usr/share/cppcheck install
```

### Verifying the Setup

Verify that all required tools are installed:

```bash
gcc --version && \
make --version && \
git --version && \
ruby --version && \
cppcheck --version && \
gcovr --version && \
clang-format --version && \
doxygen --version
```

Then, run every `lintra` target once to verify the whole toolchain, and
finish with `make clean`:

```bash
cd lintra
make format lint test build docs
```

An executable should be created at `bin/debug/prog.bin`. Running it will print:

```bash
$ ./bin/debug/prog.bin
add: 20
sub: 15
mul: 10
state: 0
```

Finally, remove the generated output:

```bash
make clean
```

If you’ve reached this point, your setup is complete and ready to use.

## Howto

This section explains how to use `lintra` after the setup is complete. If you
haven’t set up `lintra` yet, see [Getting Started](#getting-started).

### Project layout

```
lintra/
├── include/     Public headers, grouped by layer or category
├── src/         Sources and private headers
├── test/        Unit tests (test/support/ holds generated mocks)
├── cppcheck/    Linter configuration (MISRA, thread safety, type sizes)
├── doxygen/     Doxyfile, HTML header, and documentation pages (.dox)
├── templates/   Starting point for new .c and .h files
├── vendor/      Third-party tools (see License)
├── images/      Images used by the documentation
├── .github/     Issue and PR templates, contribution and security policies
├── .clang-format
├── Makefile
├── project.yml  Ceedling configuration
└── *.md         README, C_STYLE_GUIDE, DOXYGEN_GUIDELINES, CONTRIBUTING,
                 CHANGELOG, and LICENSE
```

### Where to put your code

By default, `lintra` expects your project to be organized into three directories:

1. **Source files** — `.c` files and private headers in `src/`
2. **Header files** — public `.h` files in `include/`
3. **Test files** — `.c` files in `test/`

You can also create subfolders inside each directory to organize modules. See
the [C style guide](C_STYLE_GUIDE.md) for how modules are named and when they
get a directory of their own. An example project is included with `lintra`,
which uses all three directories and can be deleted after completing the setup.

New files should start from [templates/template.c](templates/template.c) and
[templates/template.h](templates/template.h), which carry the section layout and
documentation blocks the guides expect.

> **WARNING:**
> The `test/support` folder is reserved for mock files generated by **CMock**
> and should **not** be used by the developer. Its contents are also excluded
> from version control via `.gitignore`.

### How to run `lintra`

In your `lintra` project directory, run any of the targets described in the
[toolkit](#toolkit) section:

```bash
make format         # Format the sources
make format-check   # Check the formatting without changing any file (for CI)
make lint           # Static analysis (MISRA C:2012)
make test           # Unit tests + coverage
make build          # Build the executable (debug by default)
make docs           # Generate the HTML documentation
make clean          # Remove all generated output
```

`build` accepts a build type, which selects the compiler flags and the output
directory:

```bash
# For debug build
make build
# For release build
make build BUILD=release
```

### Where to find `lintra` output

The build output is organized by build type:

- **Debug build** — `bin/debug/` contains the executable and map file,
                    while `build/debug/` contains the build artifacts.
- **Release build** — `bin/release/` contains the executable and map file,
                      while `build/release/` contains the build artifacts.

For both builds:

- Test reports are located in `build/ceedling/artifacts/gcov`
- Coverage reports are located in `build/ceedling/artifacts/gcov/gcovr`
- API documentation is located in `build/doxygen/html` (open `index.html`)

Both the test and coverage reports are generated in XML and HTML formats.

### How to configure `lintra`

You can configure `lintra`’s toolkit as needed.

#### Configuring the formatter

`lintra` uses clang-format to format the sources, configured in
[.clang-format](.clang-format). The [C style guide](C_STYLE_GUIDE.md)
deliberately documents no formatting rules — the `.clang-format` file is the
single source of truth for them. The set of files that gets formatted is the
`FMT_FILES` variable in the [Makefile].

#### Configuring the linter

`lintra` uses CPPCheck as its linter. CPPCheck is configurable from the
[Makefile]'s `CPPCheck config` section. The following files are used by CPPCheck
for static analysis:
- `cppcheck/type_sizes.xml` - specifies the platform-specific variable sizes.
- `cppcheck/misra.json` - Enforces MISRA C:2012 Guidelines.
- `cppcheck/threadsafety.json` - Static thread safety analysis.

There are additional flags apart from the files above which you may choose
to keep, modify, or remove.

#### Configuring the test framework

`lintra` uses Ceedling for testing. You can configure the framework in the
`project.yml` file. This allows you to:

- Add or remove test files
- Configure mock generation
- Customize test report outputs
- Customize coverage report outputs

Editing this file allows you to tailor the test framework to your project.

#### Configuring the build process

The build process is configurable from the [Makefile] using the following
sections:
- `GENERAL` - Choose the target name and default build (debug/release).
- `Directory paths` - Decide the directory paths.
- `Files` - Set the sources to be used for the build.
- `Compiler config` - Decide what compiler, and compiler flags are used
                      for release and debug builds.
- `Make targets` - The **build** target controls how the executable will
                   be created.

#### Configuring the documentation

`lintra` uses Doxygen, configured in `doxygen/Doxyfile`. The API reference is
built from the public headers, while the main page, topic pages, and group
definitions live in the `.dox` files next to the Doxyfile. See the
[Doxygen guidelines](DOXYGEN_GUIDELINES.md) for how code is documented and where
each kind of documentation belongs.

[Makefile]: https://github.com/rtsworks/lintra/blob/main/Makefile

## CI/CD integration

TODO: Work in progress

## Contributing

We welcome contributions! Please see [CONTRIBUTING.md](CONTRIBUTING.md) for
details on our code of conduct and instructions for submitting pull requests.
Code is expected to follow the [C style guide](C_STYLE_GUIDE.md) and the
[Doxygen guidelines](DOXYGEN_GUIDELINES.md).

## Versioning

We use [SemVer](http://semver.org/) for versioning. For the versions available,
see the [tags on this repository](https://github.com/rtsworks/lintra/tags).
Notable changes are recorded in the [changelog](CHANGELOG.md).

## License

Most of this project is licensed under the MIT License — see the [LICENSE.md](LICENSE.md)
file for details.

The Code of Conduct is adapted from the Contributor Covenant, version 3.0,
which is licensed under the CC-BY-SA-4.0 License — see the [CODE_OF_CONDUCT.md](.github/CODE_OF_CONDUCT.md)
file for details.

The `vendor/` directory contains third-party software. Each component is MIT
licensed, so the whole repository stays under compatible terms:

| Component             | Used for                        |
|-----------------------|---------------------------------|
| [Ceedling]            | Unit testing, mocking, coverage |
| [doxygen-awesome-css] | Documentation theme             |
| [PlantUML]            | Diagrams in the documentation   |

[Ceedling]: https://github.com/ThrowTheSwitch/Ceedling
[doxygen-awesome-css]: https://github.com/jothepro/doxygen-awesome-css
[PlantUML]: https://plantuml.com/
