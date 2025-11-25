<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# Pull Request Guidelines

These guidelines describe how to prepare, submit, and review Pull Requests (PRs)
for this project. Following them will help keep the repository clean and maintainable.

## Branching

- PRs **must** originate from a branch following our [Branch Naming Guidelines](BRANCH_NAMING_GUIDELINES.md).
- Always branch off from `dev` unless the PR is a hotfix that must go directly
  into `main`.
- Each PR should address **one logical change** only. Avoid mixing refactors,
  fixes, and features in a single PR.

## PR Content

- The **PR title must follow the [Conventional Commits format]**, since it will be
  used as the commit message when the PR is merged.

[Conventional Commits format]: https://www.conventionalcommits.org/en/v1.0.0/

### Allowed PR Title Types

| Type       | Purpose                                           | Example PR Title                                |
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

### PR Description Formatting

The **PR description does not need to follow Conventional Commits**.  
Simply fill in the provided Pull Request template with a clear explanation of:
- what the change does,
- why it is needed,
- and any relevant implementation notes.

## Testing

Before submitting a PR:

- Run the linting tool locally before opening a PR.
- Ensure **all existing tests pass**.
- Add tests for:
  - new features,
  - bug fixes,
  - or behavioral changes.
- Include steps in the PR for how others can verify the change
  (see the PR template’s *How to Test / Verify* section).

## Review Process

- PRs will be reviewed by at least one maintainer or team member.
- Reviewers may request changes or clarifications — please respond promptly.
- If requested changes are made, mark the comments as resolved when appropriate.
- Do **not** force-push changes that rewrite history during the review unless requested.
- A PR will be merged once:
  - all required checks pass.
  - reviewers approve.
  - and the branch is up to date with `dev` (rebased or fast-forward merged).

---

Following these guidelines will make your PR easier to review and increase the
likelihood of faster integration.