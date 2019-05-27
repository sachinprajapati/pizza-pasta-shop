; Function to print a line of text (substituted for '~a') followed by a newline character (~%)
(defun writeLine (msg)
	(format *query-io* "~a~%" msg)
	(force-output *query-io*)
)

; Function to print a prompt and read a line of input
(defun prompt-read (prompt)
	(format *query-io* "~a: " prompt)
	(force-output *query-io*)
	(read-line *query-io*)
)

; Global variable to hold a list of sports (note: global variables are surrounded by asterisks)
(defvar *valid-menu* (list "1" "2" "3" "4" "5" "6" "7" "8") )

; Global variable to hold a a list of favourite sports
(defvar *favourite-sport* nil)

(format T "~%----- Lisp Example Program -----~%~%") 

; Function to add a sport to the favourite-sports list
(defun addSportToList (sportToAdd)
	(push sportToAdd *favourite-sports*)
)

; Function to print out each item in a list on separate lines
(defun printList (list)
	(loop for item in list
		do ( writeLine(item) )
	)
)

; Function to add up the values in a list
(defun sumList (list)
	; This only runs the first time the function is called...
	(defvar sum)
	 ; ...so we need to reset the value to zero each time.
	(setf sum 0)
	
	; Use incf to increment our sum
	(loop for item in list
		do (incf sum item) 
	)
	
	; Return the sum
	sum
)

(defun Select-Option(input)
	(cond ((> input 20)
		(format t "~% a is greater than 20"))
		(t (format t "~% value of a is ~d " a))))

(defun main ()
	; Get the users name
	; Note: defvar defines a local variable
	; Note: setf sets the value of a variable, in this case we're setting it to be the return value of the prompt-read method
	; Note: ~% is a newline character, ~a substitutes a value, which in this case is the value of the user-name variable.

	; Print our list of valid sports

    (format T "Pizzas :- ~%1. 1 large Pizza = 12 AUD~%2. 2 large Pizzas = 22 AUD~%3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)~%")
    (format T "~%pastas :- ~%4. 4. 1 large pasta = 8 AUD~%5. 2 large pastas = 15 AUD~%6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)~%")
    (format T "~%For every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.~%7. Cart~%8. Payment Information~%9. Quit~%~%")	
    ; Get the user's favourite sport, and keep asking the until we get a valid response
	(loop 
		(setq favourite-sport (prompt-read "Enter Choice ") )
		(if (not (find favourite-sport *valid-menu* :test #'equalp))
			(format T "Invalid choice - please choose again.~%") ; THEN part
			(Select-Option favourite-sport)                            ; ELSE part
		)
	)
	
	(format T "Good choice! I like ~a too!~%" *favourite-sport*)  
	
	(defvar total 0)
	(defvar number-list (list 5 10 15 20 25) )
	
	(format T "Here's a list of numbers:~%")
	(loop for number in number-list 
		do ( writeLine number )
	)
	(writeLine "")
	
	(format T "Adding up the numbers gives us: ~a~%" (sumList number-list))
	
	(format T "The list reversed is: ~a~%" (reverse number-list))
	
	(format T "The first element in the list is: ~a~%" (car number-list))
	
	(format T "Everything except the first element in the list is: ~a~%" (cdr number-list))
	
	(format T "The sublist of everything after the 3rd element is: ~a~%" (nthcdr 3 number-list))
	
	( if ( not (y-or-n-p "Run program again?") ) (quit) )
)

(main)
	
	
