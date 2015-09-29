
(set 'x 42)  ; Define una variable regular X, cuyo scope es estatic
(defvar *y* 42) ; Define una variable especial *Y* cuyo scope es dinamico 

(defun add1x()
    "Suma 1 a X"
    (+ x 1) 
)

(defun add1y()
    "Suma 1 a Y"
    (+ *y* 1)
)

(defun static()
    "Funcion que prueba el scope estatico de X"
    (add1x) ;  Llamar add1x retorna 43 
    (let ((x 99)) (add1x)) 
    ; Como el scope de x es estatico, retorna 43 igual
    ; ya que x vale 99 en este bloque, pero en add1x vale 42
)

(defun dynamic()
    (add1y); Aqui el valor de Y es 42 por lo que add1y retorna 43
    (let ((*y* 99)) (add1y))
    ; Como *y* es dinamica, va a tomar el valor de 99 en add1y tambien
    ; y va a retornar 100
)
