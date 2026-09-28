<!-- Copyright (c) 2025 Daniel Rossinsky (https://github.com/rtsworks) -->
<!-- SPDX-License-Identifier: MIT -->

# Pull Request Guidelines

These guidelines describe how to prepare, submit, and review Pull Requests (PRs)
for this project. Following them will help keep the repository clean and maintainable.

## Branching

- PRs **must** originate from a branch following our [Branch Naming Guidelines](BRANCH_NAMING_GUIDELINES.md).
- Always branch off from `dev` unless the PR is a hotfix that must go directly
  into `main`.
- A PR from `dev` into `main` is a **release**, a distinct category from the
  above — see [Releasing](#releasing) below.
- Each PR should address **one logical change** only. Avoid mixing refactors,
  fixes, and features in a single PR.

## PR Content

- The **PR title must follow the [Conventional Commits format]**. What it
  becomes at merge time depends on the target branch:
  - **Into `dev`**: the PR is merged with **squash and merge**. The title
    becomes the squash commit's subject line, and the individual commits from
    the branch are preserved as a list in the commit body (GitHub's "Pull
    request title and commit details" option).
  - **Into `main`** (a release): the PR is merged with **create a merge
    commit** — never squashed or rebased, so `dev`'s history stays a strict
    ancestor of `main`'s. The title becomes the merge commit's subject.

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

## Releasing

Releasing is done via a PR from `dev` into `main`:

1. Open the PR with a `chore(release)` title, e.g.
   `chore(release): promote dev to main`. It does **not** carry a version
   bump yet. Use this link to open it pre-filled with the `release.md`
   template:
   <https://github.com/rtsworks/lintra/compare/main...dev?template=release.md>
2. Merge it using **Create a merge commit** — never squash or rebase, so
   `dev` stays an ancestor of `main`.
3. On `main`, run `cz bump`. This computes the new version from the commits
   since the last tag, updates `CHANGELOG.md`, and creates the bump commit
   and tag — done *after* the merge so the release commit sits at the true
   tip of `main`, with nothing dangling past the tag to pollute the next
   changelog.
4. Push the bump commit and the tag: `git push && git push --tags`.
5. Fast-forward `dev` back up to `main` (a trivial fast-forward, since `dev`
   is still an ancestor of `main`):
   ```bash
   git checkout dev
   git pull
   git merge --ff-only origin/main
   git push origin dev
   ```
   `--ff-only` fails loudly instead of silently creating a merge commit if
   `dev` and `main` have unexpectedly diverged.
6. Create the GitHub Release from the pushed tag.

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