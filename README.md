<div align="center">

  <!-- Banner placeholder -->
  ![Lintra Banner](images/lintra-banner.png)
  
  # C project starter & CI/CD-friendly toolkit
  
  <!-- Badge placeholder -->
  ![OS: Windows / Linux](https://img.shields.io/badge/OS-Windows%20%7C%20Linux-blue)
  [![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](LICENSE)
  ![Status: Active](https://img.shields.io/badge/status-active-brightgreen)
  
</div>

**Lintra** is a C project template with a built-in, CI/CD-friendly toolkit designed
to streamline the development workflow of C projects. It automates linting, testing,
and building C projects with minimal setup.

Lintra enforces a strict, fail-fast workflow composed of three stages:

1. **Lint** — Enforces MISRA C:2012 guidelines via [cppcheck].  
2. **Test** — Executes unit tests using [ceedling], automatically generating:
   - Cobertura and HTML code coverage reports  
   - JUnit and HTML test reports  
   - Test runners and mocks  
3. **Build** — Uses [make] to build the project with strict compilation flags.

[cppcheck]: https://cppcheck.sourceforge.io/
[ceedling]: https://github.com/ThrowTheSwitch/Ceedling
[make]: https://www.gnu.org/software/make/

If any stage fails, Lintra immediately halts the process.

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
`misra_c_2012_rules.txt`, and move it to the `scripts/` folder. No modifications
are made to the file contents.

**NOTE:** This file is deliberately listed in `.gitignore` to avoid redistributing
it here, ensuring that the rest of the project remains entirely under the MIT license.

[here]: https://gitlab.com/MISRA/MISRA-C/MISRA-C-2012/tools/-/blob/main/misra_c_2012__headlines_for_cppcheck%20-%20AMD1+AMD2.txt?ref_type=heads

### Windows Setup

Windows users should install the following tools to run `lintra`:

- [MinGW] — Provides the GCC compiler and [make] utility for building the project.  
- [MSYS2] — Offers a Unix-like shell environment required for the Makefile to run
            properly.  
- [python3] — Comes with pip3 on Windows, used to install gcovr for coverage
              reports.  
- [Ruby] — Required for running [Ceedling], the unit testing framework.  
- [Cppcheck] — Used to enforce MISRA C:2012 guidelines.

Install gcovr via command line:

```bash
pip3 install gcovr
```

After installation, ensure that each tool’s executable directory is added to your
system’s **PATH**.  

[MinGW]: https://nuwen.net/mingw.html  
[MSYS2]: https://www.msys2.org/  
[python3]: https://www.python.org/downloads/windows/  
[Ruby]: https://rubyinstaller.org/  
[Cppcheck]: https://cppcheck.sourceforge.io/  

### Linux Setup

**NOTE:** The instructions below were tested on mint/ubuntu.

Linux users should install the following tools to run `lintra`:

- Install build essentials, Git, Ruby, Python, and pip:

```bash
sudo apt update && sudo apt install build-essential git ruby-full python3 python3-pip
```

- Install gcovr:

```bash
sudo pip3 install gcovr
```

- Install cppcheck:

```bash
git clone https://github.com/danmar/cppcheck.git && \
cd cppcheck && \
git checkout 2.18.x && \
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
gcovr --version
```

Then, run `lintra` as follows:

```bash
cd lintra
make
```

An executable should be created at `bin/debug/prog.out`. Running it will print:

```bash
$ ./bin/debug/prog.out 
add: 20
sub: 15
mul: 10
state: 0
```

If you’ve reached this point, your setup is complete and ready to use.

## Howto

**TODO**
