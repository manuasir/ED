#!/bin/csh
@ inicio = 100000
@ fin = 128500
@ incremento = 500
set ejecutable = burbuja
set salida = peorcaso.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i 10000 2` >> $salida
  @ i += $incremento
end
