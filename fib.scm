(define (fib n)
  (if (or (= n 0) (= n 1))
      1
      (+ (fib (- n 1)) (fib (- n 2)))))