# Taller2EDatos
--------------------------------------------
Taller de estructura 2: Conect 4
Nombre: Bruno Toro Elgueta - 20864066-6
--------------------------------------------
Linea de compilación:
g++ -o main main.cpp
--------------------------------------------
# Diseño del juego
--------------------------------------------
El conecta 4 está representado en una matriz de 6x7, las cuales serán rellenadas por "X" (ficha del jugador)  y "O" (ficha de la maquina). Siempre el primer movimiento será del jugador. En este juego, se pedirá por pantalla la columna deseada para insertar la ficha, en el caso de que esta columna esté totalmente llena (desde la fila 1 a la 6) se aplicará control de errores e insertará la ficha en otra columna deseada, la maquina hará lo mismo, pero sin necesidad de escojer columna (claramente).

Cada "estado" del tablero será mostrado por pantalla. Un estado corresponde al ingreso de fichas al tablero, el estado 1 del tablero es vacío, el estado 2 es con la ficha ingresada por el jugador, el estado 3 por la maquina, y así continuamente hasta encontrar un ganador. Esto nos permite visualizar de forma precisa qué estado corresponde a qué jugador:

Inicio:         Jugador:            Maquina:
<-------------->;<--------------->;<--------------->
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | | | | | | | |
| | | | | | | | ; | | | | | | | | ; | |O| | | | | |
| | | | | | | | ; | |X| | | | | | ; | |X| | | | | |
<-------------->;<--------------->;<--------------->

El ganador se definirá cuando hayan 4 fichas iguales:
- Horizontales consecutivas
- Verticales consecutivas
- Diagonal derecha consecutivas
- Diagonal izquierda consecutivas

Opciones:
El jugador tendrá la posibilidad de esoger entre 3 dificultades:
-Facil: La maquina hará movimientos al azar.
-Media: La maquina intentará ganar realizando movimientos consecutivos.
-Dificil: La maquina buscará la mejor estrategia para ganar.

Cada vez que sea el turno del jugador, este tendrá la opción de "guardar partida", para posteriormente cargarla, o de lo contrario, realizar otro movimiento si así lo desea.
--------------------------------------------
# Implementación
--------------------------------------------
El programa tendrá 2 clases: Nodo y main

La clase Nodo, se utilizará para diseñar el arbol de posibilidades, la lógica que se siguio para esto, fue ir creando hijos del nodo raiz, y eliminandolos de la memoria, de esta forma no se utilizan tantos recursos. Es decir, en primera instancia, el tablero está vacío, entonces el nodo raiz del arbol será este, y cuando sea el turno de la maquina, este utilizará el metodo miniMax, el cuál generará los hijos de este tablero