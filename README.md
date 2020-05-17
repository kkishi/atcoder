Install online-judge-tools (oj).

Add this to .emacs:

```
(defun ojt ()
  (interactive)
  (shell-command (concat "g++ " (buffer-file-name (current-buffer)) " && oj t")))

(defun ojs ()
  (interactive)
  (shell-command (concat "oj submit -y --no-open " (buffer-file-name (current-buffer)))))
```

To download, do:

```bash
./download.sh abc168
```
