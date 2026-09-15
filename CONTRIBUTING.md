<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# Contributing to Lintra

Thank you for considering contributing! We welcome contributions of all kinds:
code, documentation, bug reports, or ideas.

## One-Time Setup

This needs to be done only once.

1. **Fork the repository** — go to the
   [lintra repository](https://github.com/rtsworks/lintra) on GitHub and
   click **Fork**. This creates a copy in your own GitHub account that you
   can push to.
2. **Clone your fork and configure the upstream remote:**

```bash
# Clone your fork (replace <your-username>)
git clone git@github.com:<your-username>/lintra.git
cd lintra

# Add the original repository as upstream
git remote add upstream git@github.com:rtsworks/lintra.git

# Create a local dev branch tracking upstream/dev
git fetch upstream
git checkout -b dev upstream/dev
git push origin dev
```

## Start a New Feature

Repeat this for every feature or fix, starting from an up-to-date `dev`:

```bash
# Sync your local dev with upstream first
git checkout dev
git fetch upstream
git rebase upstream/dev
git push origin dev

# Then branch off it
git checkout -b feature/my-feature
```

Follow the [Branch Naming Guidelines](.github/BRANCH_NAMING_GUIDELINES.md)
for the prefix (`feature/`, `bugfix/`, `docs/`, `chore/`, `refactor/`,
`test/`, `perf/`) and naming.

## Work on Your Branch

```bash
git add .
git commit -m "feat(scope): describe your change"
git push origin feature/my-feature
```

- Follow the project [C Style Guide](C_STYLE_GUIDE.md).
- Follow the [Commit Message Guidelines](.github/COMMIT_MESSAGE_GUIDELINES.md)
  (Conventional Commits, 50/72 rule).
- Run `make format` before committing.

## Keep Your Branch Up to Date

If `dev` moves upstream while your branch is still open:

```bash
git fetch upstream
git checkout feature/my-feature
git rebase upstream/dev
git push origin feature/my-feature --force-with-lease
```

## Open a Pull Request

Once your feature is ready:

1. Go to your fork on GitHub and click **Compare & pull request**.
2. Confirm the base is `dev` on `rtsworks/lintra`, and compare is your branch.
3. Give the PR title a [Conventional Commits] type — it becomes the merge
   commit message. See the [Pull Request Guidelines](.github/PULL_REQUEST_GUIDELINES.md).
4. Fill out the Pull Request template and click **Create pull request**.

[Conventional Commits]: https://www.conventionalcommits.org/

## Reporting Issues

1. Search existing issues before creating a new one.
2. Go to the [Issue](https://github.com/rtsworks/lintra/issues) tab and click
   **New issue**.
3. Choose one of the existing templates:
    - **Bug Report**
    - **Feature Request**
    - **Documentation**
    - **Feedback**
    - **Other**
4. Fill in the blanks and click **Create**.

## Code of Conduct

By contributing, you agree to abide by our [Code of Conduct](.github/CODE_OF_CONDUCT.md).
Be respectful and collaborative.

## Contact

For questions or sensitive inquiries, email: **danielrossinsky@gmail.com**
