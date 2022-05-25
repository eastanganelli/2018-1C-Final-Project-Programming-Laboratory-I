# TP FINAL - Laboratorio de Programación I
    UF-FICEN 2018 1er Cuatrimestre
> ##### Desarrollado por
> -   Ezequiel Augusto Stanganelli
---

## INDICE
#### [El diseño del programa](#el-diseño-del-programa)
* [Main](#main-programa-de-simulación-debe-realizar-una-simulación-del-programa-pedido-debe)
* [Listado Obligatorio](#dentro-de-los-atributos-y-parámetros-obligatorios-se-debe-contar-con-al-menos)
#### [Enunciado](#enunciado)
#### [UML](#uml)

---
## El diseño del programa
### Main: Programa de simulación debe realizar una simulación del programa pedido. Debe
* Instanciar todas las clases diseñadas (siempre que se pueda…).
* Utilizar todas las funciones / métodos que se hayan diseñado.
* Mostrar la herencia efectuada.
* Mostrar el polimorfismo diseñado.
* Mostrar Sobrecarga efectuada.
* Control de excepciones
* El main, puede tener una parte que requiera entrada del usuario.
    * Debe tener una simulación autónoma.

### Dentro de los atributos y parámetros obligatorios se debe contar con al menos
* 1 Atributo Constante
* 1 Atributo static
* 1 Atributo puntero doble y su buena utilización de memoria (new y delete)
* Control de excepciones
* Utilización del algoritmo random
* Al menos una función y una clase friend
* Sobrecarga de cin y cout para clase base y e hijas
* Sobrecarga de (al menos 1 vez… no es necesario repetir… aunque pueden hacerlo)
    * <, >, ==, !=, ++ (pre y/o post), =, [], +,-.
* Herencia
* Al menos 1 método polimórfico

## Enunciado
### Tienda de electrodomésticos 
> La cadena de electrodomésticos Musimundo quiere realizar una actualización de su sistema que se programó en los años 70 y no contempla ciertas opciones.
> 
> Los productos están diferenciados por tipo / marca/ y es necesario que el comprador, conozca sus dimensiones y peso y por supuesto precio. De manera de simplificar la programación del nuevo sistema. La Versión V0.1 solo utilizara productos del tipo microonda, televisor, y heladera.
> 
> El sistema debe permitirle al vendedor buscar dentro de la lista de artículos por código / marca / tipo y nombre y desplegar una lista de los productos encontrados que coincidan con la búsqueda.
> 
> Una vez finalizada la compra, el vendedor remite el producto al
> despachante.
> 
> El despachante, como es uno solo para toda la tienda, tiene una lista de productos a entregar, y a quién debe entregárselos. Mediante un Código de operación se le puede pedir al despachante que despache (valga la redundancia) el producto. Antes de entregárselo al cliente, el despachante debe asegurarse del correcto
> funcionamiento de los productos y para ello debe probarlos. Para las heladeras, las enchufa, espera 10 minutos, y verifica que la luz de la heladera se prenda al abrir la puerta, y se apague al cerrarse, verifica además que la temperatura sea la configurada en el climatizador interno. A los televisores los enchufa, enciende, y conecta el cable de video, y realiza una prueba de aumentar y disminuir el sonido, cambiar de canal y que se visualice la programación. Para los microondas, verifica la luz al abrir/cerrar la puerta, prueba los distintos modos de calentamiento, configura la potencia al máximo y enciende el microondas por 1 minuto para verificar que funcione correctamente. En general, la prueba del control de televisor falla 1/10 veces que se aprieta el botón. Las heladeras tienen una tasa de falla de 1/20 al verificar la temperatura y los microondas una tasa de falla de 1/15 en la prueba de 1 minuto.
> 
> Al final del día se debe conocer la lista de los equipos que se vendieron, y el monto total recaudado. Por último, si hay equipo stock menor al stock mínimo (mínima cantidad de artículos que se quiere tener) se debe realizar una lista con ellos, donde la cantidad es la necesaria para que el stock final supere el stock mínimo en
> 5 unidades y se debe saber el costo de esa lista. Si el costo total no supera los $20.000 o si la cantidad total de ítems es menor a 15 la lista es rechazada (se borra), de lo contrario es Aprobarla (se agregan las cantidades a stock).
> 
> **Modele. Los distintos tipos de empleados, tipos de artículos y listas de artículos con las que se trabajan. Además de la funcionalidad requerida. Genere un Simulador (main) de manera de verificar el correcto funcionamiento de Compu Mundo Hiper Mega Red. El sistema simulador genera un cliente por minuto, este puede realizar una compra de un artículo al azar, o puede no comprar nada.**

## UML
![UML]([%20UML%20]%20TP%20Final.png)
