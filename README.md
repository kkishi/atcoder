# Setup

Install online-judge-tools (oj).

For Emacs, add this to .emacs:

```
(defun ojt ()
  (interactive)
  (save-buffer)
  (shell-command (concat "go run ../../../oj/oj.go -t --file=" (buffer-file-name (current-buffer)))))
(defun ojd ()
  (interactive)
  (save-buffer)
  (shell-command (concat "go run ../../../oj/oj.go -t -dbg --file=" (buffer-file-name (current-buffer)))))
(defun ojs ()
  (interactive)
  (save-buffer)
  (shell-command (concat "go run ../../../oj/oj.go -t -s --file=" (buffer-file-name (current-buffer)))))
(defun ojf ()
  (interactive)
  (save-buffer)
  (shell-command (concat "go run ../../../oj/oj.go -s --file=" (buffer-file-name (current-buffer)))))
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
go run compete.go --contest=abc172 --start="2020/06/27 14:00:00"
```

# Testing with the judge inputs

Use `judge.sh` after downloading the inputs (in/ and out/ directories).
