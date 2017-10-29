(print "whats ur name")

(defvar *name* (read))

(defun hello-you(name)
	(format t "Hello ~a! ~%" name)
)

(setq *print-case* :capitalize)
;;;upcase or downcase
(hello-you *name*)