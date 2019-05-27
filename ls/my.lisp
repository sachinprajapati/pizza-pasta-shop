;(setq a (read))

(defvar *valid-menu* (list 1 2 3 4 5 6 7 8) )

(defvar pizza 0)

(defvar pasta 0)

;(cond ((> a 20)
;   (format t "~% a is greater than 20"))
;   (t (format t "~% value of a is ~d " a)))

(defun Select-Option (option)
	(if	(= option 1)
		(setq pizza 1)
		;(format T "pizza is : ~a~%" pizza)
	)
	(if	(= option 2)
		(setq pizza 2)
		;(format T "pizza is : ~a~%" pizza)
	)
	(if	(= option 3)
		(progn
			(print "Please Enter Quantity : ")
			(setq pizza (read)))
	)
)

(defun Menu ()
	(format T "Pizzas :- ~%1. 1 large Pizza = 12 AUD~%2. 2 large Pizzas = 22 AUD~%3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)~%")
    (format T "~%pastas :- ~%4. 4. 1 large pasta = 8 AUD~%5. 2 large pastas = 15 AUD~%6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)~%")
    (format T "~%For every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.~%7. Cart~%8. Payment Information~%9. Quit~%~%")	
)
   
(defun Main ()
	(loop
		(Menu) 
		(setq option (read))
		(if (not (find option *valid-menu* :test #'equalp))
			(format T "Invalid choice - please choose again.~%") ; THEN part
			(Select-Option option)                            ; ELSE part
		)
		(format T "pizza is : ~a~%" pizza)
	)
)   
   
(Main)
