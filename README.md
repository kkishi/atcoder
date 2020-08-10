# Setup

Install online-judge-tools (oj).

Install the Go commands.

```
go install github.com/kkishi/atcoder/cmd/...
```

For Emacs, add this to .emacs:

```
(defun atcoder (opts)
  "Run atcoder command with the commandline options given as OPTS."
  (save-buffer)
  (shell-command (concat "atcoder " opts " " (buffer-file-name (current-buffer)))))
(defun ojt ()
  "Run oj -t."
  (interactive) (atcoder "-t"))
(defun ojd ()
  "Run oj -t with dbg build."
  (interactive) (atcoder "-t -c dbg"))
(defun ojp ()
  "Run oj -t with prof build."
  (interactive) (atcoder "-t -c prof"))
(defun ojs ()
  "Run oj -t, then oj -submit if the test passes."
  (interactive) (atcoder "-t -s"))
(defun ojf ()
  "Run oj -submit without test."
  (interactive) (atcoder "-s"))
```

For VS Code, add this to keybindings.json:
```
[
    {
        "key": "ctrl+i t",
        "command": "workbench.action.tasks.runTask",
        "args": "t"
    },
    {
        "key": "ctrl+i d",
        "command": "workbench.action.tasks.runTask",
        "args": "d"
    },
    {
        "key": "ctrl+i s",
        "command": "workbench.action.tasks.runTask",
        "args": "s"
    },
    {
        "key": "ctrl+i f",
        "command": "workbench.action.tasks.runTask",
        "args": "f"
    }
]
```

# Solving problems

Run:

```
compete --contest=abc172 --start="2020/06/27 14:00:00"
```

# Testing with the judge inputs

Use `judge.sh` after downloading the inputs (in/ and out/ directories).
