# Git basics with a tiny C project

Git records the history of a project. Each commit gives you a snapshot you can inspect later. Branches let you work on a change while the main branch stays where it is. Git runs on your computer, and GitHub hosts a copy of the repository that people can share.

## Run the example

You’ll need Git, `make`, and a C compiler. If you already have the project folder, start with `make` inside it. To get your own copy, clone the repository. To push changes yourself, use a clone of a repository you can write to. You can fork this repository on GitHub and clone your fork to practise on your own.

```sh
git clone https://github.com/ShlokK04/Demo.git
cd Demo
make
./temperatures
```

The program prints a Celsius-to-Fahrenheit table. `main.c` holds the sample values and prints the table. `temperature.c` does the conversion, and `temperature.h` declares the function so `main.c` can call it. The `Makefile` builds the two `.c` files together. `.gitignore` keeps the compiled program out of Git.

```text
 Celsius Fahrenheit
     0.0       32.0
    20.0       68.0
    37.0       98.6
   100.0      212.0
```

## Make and share one change

1. **Create a branch.** Start from `main` and switch to a new branch named `add-cold-sample`.

   ```sh
   git switch main
   git switch -c add-cold-sample
   ```

2. **Edit and check.** Open `main.c` and add `-40.0` before `0.0` in the `samples` array. Run the program again. The new row should show `-40.0` in both columns. `git diff` shows what you changed since staging or, if you haven’t staged anything yet, since your last commit.

   ```sh
   make
   ./temperatures
   git status
   git diff
   ```

3. **Stage.** Use `git add` to copy the current version of `main.c` into the staging area, where Git prepares the next commit. `git diff --staged` lets you review what will go into that commit. If you edit again, run `git add` again to include the new edit.

   ```sh
   git add main.c
   git diff --staged
   ```

4. **Commit.** Save a snapshot locally with a message explaining the change. Your current branch advances to the new commit. `git log` shows the history.

   ```sh
   git commit -m "Add a minus forty temperature sample"
   git log --oneline --max-count=5
   ```

5. **Push.** Send your commits to `origin`, the name Git usually gives the server you cloned from. `-u` links the local branch to its remote counterpart so subsequent pushes from this branch can use `git push` on its own.

   ```sh
   git push -u origin add-cold-sample
   ```

## Pull a change from GitHub

On GitHub, open a pull request from `add-cold-sample` into `main` in the repository or fork you’re using for practice. A pull request is a proposal to merge a branch. Once it has been merged, switch back to your local `main` and pull. `git pull` fetches the latest commits and brings them into your current branch. `--ff-only` updates `main` when its history can move straight forward to match the remote.

```sh
git switch main
git pull --ff-only
git log --oneline --max-count=5
make
./temperatures
```

The `-40.0` row should now appear when you run the program from `main`.
