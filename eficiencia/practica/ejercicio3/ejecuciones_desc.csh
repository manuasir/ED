#!/bin/csh
@ inicio = 10
@ fin = 100000000
@ incremento = 500
@ incremento1 = 500
set ejecutable = ejercicio_desc
set salida = tiempos_desc.dat

@ i = $inicio
echo > $salida
while ( $i <= $fin )
  echo Ejecución tam = $i
  echo `./{$ejecutable} $i` >> $salida
  @ i += $incremento
end


