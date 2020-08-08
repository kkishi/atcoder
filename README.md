# Setup

Install online-judge-tools (oj).

Install the Go commands.

```
go install github.com/kkishi/atcoder/cmd/atcoder
go install github.com/kkishi/atcoder/cmd/compete
```

For Emacs, add this to .emacs:

```
(defun ojt ()
  (interactive)
  (save-buffer)
  (shell-command (concat "atcoder -t --file=" (buffer-file-name (current-buffer)))))
(defun ojd ()
  (interactive)
  (save-buffer)
  (shell-command (concat "atcoder -t -dbg --file=" (buffer-file-name (current-buffer)))))
(defun ojs ()
  (interactive)
  (save-buffer)
  (shell-command (concat "atcoder -t -s --file=" (buffer-file-name (current-buffer)))))
(defun ojf ()
  (interactive)
  (save-buffer)
  (shell-command (concat "atcoder -s --file=" (buffer-file-name (current-buffer)))))
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
