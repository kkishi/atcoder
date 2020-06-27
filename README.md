Install online-judge-tools (oj).

Add this to .emacs:

```
(defun ojt ()
  (interactive)
  (shell-command (concat "g++ -O2 -std=c++17 -DDEBUG " (buffer-file-name (current-buffer)) " && oj t -t 2 --mle 1024")))

(defun ojs ()
  (interactive)
  (shell-command (concat "oj submit -y --no-open " (buffer-file-name (current-buffer)))))

(defun ojts ()
  (interactive)
  (shell-command (concat "../../submit.sh " (buffer-file-name (current-buffer)))))
```

To download samples, run:

```
go run compete.go --contest=abc172 --start="2020/06/27 14:00:00"
```

To run a judge test, use judge.sh.
