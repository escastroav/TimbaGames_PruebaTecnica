# Aplicación para prueba técnica de TimbaGames

Por: Esteban Castro Ávila

## Instalación

Para compilar el proyecto, basta con tener instalado make o mingw32-make en la consola. Se debe colocar en la carpeta del proyecto
```bash
make
```
ó
```bash
mingw32-make
```
El proyecto generará los objetos y el ejecutable correspondiente

# Funcionamiento

Al ejecutar main.exe se abrirá una ventana de 800x600 de resolución. Puede cerrarla con la tecla Esc.

## Dibujar figuras
Para utilizar el software debe seleccionar la figura que se desea dibujar presionando una vez las siguientes teclas:

 * **Tecla Q** : Dibuja un cuadrado. Después de presionar Q de click izquierdo en algún lugar de la ventana para colocar el centro del cuadrado, luego arrastre (sin presionar el click) y arrastre para darle forma.
 * **Tecla W** : Dibuja un círculo. Después de presionar W de click izquierdo en algún lugar de la ventana para colocar el centro del círculo, luego arrastre (sin presionar el click) y arrastre para darle forma.
 * **Tecla E** : Dibuja un hexágono. Después de presionar E de click izquierdo en algún lugar de la ventana para colocar el centro del hexágono, luego arrastre (sin presionar el click) y arrastre para darle forma. 
 * **Tecla R** : Dibuja un triángulo. Después de presionar R de click izquierdo una vez para colocar el primer vértice. Arrastre y de click izquierdo nuevamente para colocar el siguiente vértice y a continuación coloque el último vértice dando click por tercera vez.
## Animar figuras
Antes de dibujar la figura que ha seleccionado con las teclas anteriormente selecionadas, debe presionar una vez alguna de las siguientes teclas:
* **Tecla A**: Movimiento de izquierda a derecha.
* **Tecla S**: Movimiento de arriba a abajo.
* **Tecla D**: Movimiento circular.
* **Tecla F**: Movimiento cuadro o caja.
* **Tecla G**: Sin movimiento.

Una vez seleccionado un tipo de animación, la próxima figura que dibuje se moverá con el patrón seleccionado. Puede ajustar la velocidad moviendo la rueda del ratón. 
## Cargar figuras en archivo de texto
El archivo "TestFile.txt" se utiliza para cargar figuras con una serie de parámetros. Para cargar el contenido del archivo, debe presionar Enter en cualquier momento y las figuras escritas aparecerán.

Para asignar los parámetros puede guiarse del siguiente ejemplo:
```Text
figure:<square, circle, hexagon, triangle>
animation:<left-right, up-down, circular, box>
speed:<valor de velocidad>
color_R:<valor de color de 0-255>
color_G:<valor de color de 0-255>
color_B:<valor de color de 0-255>
Xpos:<Valor de la posición inicial horizontal en pixeles>
Ypos:<Valor de la posición inicial vertical en pixeles>
size:<Valor del tamaño en pixeles>
X1:<posicion horizontal primer vértice>
X2:<posicion horizontal segundo vértice>
X3:<posicion horizontal tercer vértice>
Y1:<posicion vertical primer vértice>
Y2:<posicion vertical segundo vértice>
Y3:<posicion vertical tercer vértice>
Xcenter:<posicion horizontal centro de movimiento circular>
Ycenter:<posicion vertical centro de movimiento circular>
boxWidth:<ancho de la caja de movimiento> 
boxHeigth:<alto de la caja de movimiento>
END:
```   
Es muy importante que siga el formato mencionado. *