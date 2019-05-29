;(setq a (read))

(defvar *valid-menu* (list 1 2 3 4 5 6 7 8 9) )

(defvar pizza 0)

(defvar pasta 0)


(defvar name)

(defvar email)

(defvar address)

(setq alist-of-colors
           '((rose . red) (lily . white) (buttercup . yellow)))
;(cond ((> a 20)
;   (format t "~% a is greater than 20"))
;   (t (format t "~% value of a is ~d " a)))

(defun getPaymentInfo ()
	(setq pz 0)
	(setq ps 0)
	(format T "~%--------------------Payment Option--------------------~%1. Payment For Pizza~%2. Payment For Pasta~%3. Total Payments~%")
	(format T "Enter your chice : ")
	(setq choice (read))
	(cond ((= choice 1) (setq pz 1))
      ((= choice 2) (setq ps 1))
      (t
      	(progn
      		(setq pz 1)
      		(setq ps 2)
      	) 
      ))
	(PaymentHistory pz ps)
)

(defun PaymentHistory (pz ps)
	(setq gtotal 0)
	(progn
        (format T "~%------------------------------Payment History-----------------------------~%")
        (format T "~%Item            Quantity    Total")
        (if (= pz 1)
            (progn
                (format T "~%Pizza           ~a           ~a~%" pizza (getPzPrice pizza))
                (setq gtotal (+ gtotal (getPzPrice pizza)))
            )
        )
        (if (= ps 1)
            (progn
                (format T "~%Pasta           ~a          ~a~%" pasta (getPsPrice pasta))
                (setq gtotal (+ gtotal (getPsPrice pasta)))
            )
        )
        (if (> pizza 2)
            (format T "~%Garlic Bread    ~a           0~%" (getGB pizza))
        )
        (if (> pasta 2)
            (format T "~%Soft Drink      ~a           0~%" (getGB pasta))
        )
        (if (and (> pizza 8)
                 (> pasta 8))
            (format T "~%Baklava         ~a           0" (getBK (floor pizza 3) (floor pasta 3)))
        )
        (format T "~%                       ----------------------")
        (format T "~%Grand Total is               ~a~%" gtotal)
	)
)


(defun getPzPrice(qty)
    (if (= qty 1)
      (return-from getPzPrice 12)
    )
    (if (= qty 2)
		(return-from getPzPrice 22)
    )
    (if (> qty 2)
      (return-from getPzPrice (* qty 10))
    )
)


(defun getPsPrice(qty)
    (if (= qty 1)
      (return-from getPsPrice 8)
      12
    )
    (if (= qty 2)
      (return-from getPsPrice 15)
      22
    )
    (if (> qty 2)
      (return-from getPsPrice (* qty 7))
    )
)

(defun getGB (qty)
    (return-from getGB (floor qty 3))
)

(defun getBK (gb drink)
    (setq gb (floor gb 3)) 
    (setq drink (floor drink 3))
    (if (> gb drink)
        drink
        gb
    )
)


(defun getCart ()
    (defvar gtotal 0)
    (defvar gb 0)
    (defvar drink 0)
    (defvar choice)
    (progn
        (format T "~%------------------------------Cart-----------------------------~%")
        (format T "~%Item            Quantity    Total")
        (if (> pizza 0)
            (progn
                (format T "~%Pizza           ~a           ~a~%" pizza (getPzPrice pizza))
                (setq gtotal (+ gtotal (getPzPrice pizza)))
            )
        )
        (if (> pasta 0)
            (progn
                (format T "~%Pasta           ~a          ~a~%" pasta (getPsPrice pasta))
                (setq gtotal (+ gtotal (getPsPrice pasta)))
            )
        )
        (if (> pizza 2)
            (format T "~%Garlic Bread    ~a           0~%" (getGB pizza))
        )
        (if (> pasta 2)
            (format T "~%Soft Drink      ~a           0~%" (getGB pasta))
        )
        (if (and (> pizza 8)
                 (> pasta 8))
            (format T "~%Baklava         ~a           0" (getBK (floor pizza 3) (floor pasta 3)))
        )
        (format T "~%                       ----------------------")
        (format T "~%Grand Total is               ~a~%" gtotal)
        (format T "~%~%1. Checkout~%2. Menu")
        (format T "~%Enter Choice : ")
        (setq choice (read))
        (if (= choice 1)
            (progn
                (princ "Enter Name: ")
                (setq name (read))
                (princ "Enter Email: ")
                (setq email (read))
                (princ "Enter Address: ")
                (setq address  (read))
                (format T "~%You order confirmed~%")
            )
        )
    ) 
)


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
    (if (= option 4)
        (setq pasta 1)
        ;(format T "pizza is : ~a~%" pizza)
    )
    (if (= option 5)
        (setq pasta 5)
        ;(format T "pizza is : ~a~%" pizza)
    )
    (if (= option 6)
        (progn
            (print "Please Enter Quantity : ")
            (setq pasta (read)))
    )
    (if (= option 7)
        (getCart)
    )
    (if (= option 8)
        (getPaymentInfo)
    )
    (if (= option 9)
        (progn
        	(format T "~%Thank for using~%")
        	(quit)
        )
    )
)

(defun Menu ()
	(format T "~%Pizzas :- ~%1. 1 large Pizza = 12 AUD~%2. 2 large Pizzas = 22 AUD~%3. 3 or more large pizzas = 10 AUD each (garlic bread for every 3 large pizzas)~%")
    (format T "~%pastas :- ~%4. 4. 1 large pasta = 8 AUD~%5. 2 large pastas = 15 AUD~%6. 3 or more large pastas = 7 AUD each (1.25 liter soft drinks for every 3 large pastas)~%")
    (format T "~%For every 3 pizzas AND 3 pastas, Sab will give a small box of Baklava (a famous dessert item) in addition to garlic-bread and 1.5-liter soft drinks.~%7. Cart~%8. Payment Information~%9. Quit~%~%")	
)
   
(defun Main ()
	(loop
		(Menu) 
		(setq option (read))
		(if (not (find option *valid-menu* :test #'equalp))
			(progn
				(format T "Invalid choice - please choose again.~%") ; THEN part
				(Main)
			)
			(Select-Option option)                            ; ELSE part
		)
	)
)   
   
(Main)
