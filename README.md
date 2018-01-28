# Versión 2.3.1

## Características:

- **Botones**: Se pueden crear instancias del objeto **Button** mediante su contructor por defecto _**Button::** Button()_ y por su constructor  _**Button::** Button(int **id_button**)_: El primero permite crear una instancia de **Button** que "detecta" el estado de cualquiera de los 5 botones del *Robot Uzi*; mientras que el segundo nos permite interactuar únicamente con el boton especificado por *id_button*. En la sección de ejemplos está disponible un código de prueba. Están disponibles las siguientes funciones:
    - **init()** : Inicializa el Objeto **Button** para poder interactuar con él.
    - **isPressed()** : Retorna _true_ si el botón está presionado al momento de la consulta; retorna _false_ en caso contrario.
    - **isReleased()** : Retorna _true_ si el botón **NO** está presionado al momento de la consulta; retorna _false_ en caso contrario.
    - **isClicked()** : Retorna _true_ si el botón a sido pulsado al momento de la consulta; retorna _false_ en caso contrario.

- **Buzzer** : Se pueden crear instancias del objeto **Buzzer**, mediante su constructor por defecto _**Buzzer::** Buzzer()_, para poder utilizar el buzzer piezoeléctrico que tiene el _Robot Uzi_ y emitir sonidos entretenidos o de ayuda para verificar en qué etapa de la rutina se encuentra. En la sección de ejemplos se encuentra disponible un código de prueba. Están disponibleslas siguientes funciones:
    - **init()** : Emite un sonido de 440 [Hz] durante 500 [ms] que sirve para comprobar el correcto funcionamiento del mismo. Si se pone al final del _void **setup()**_ el _Robot Uzi_ nos avisará que se inicializó correctamente.
    - **r3d3()** : Emite un simpático sonido imitando al famoso Arturito.
    - **happy()** : Emite un simpático sonido de júbilo.
    - **scary()** : Emite un sonido imitando una expresión de _pavor_.
    - **tatan()** : Emite un simpático sonido, perfecto para anunciar la finalización exitosa de una rutina.
    - **sound(** _int **nota**, int **octava**, int **delay**_ **)** : Emite el sonido de la **nota** y **octava** especificada durante el tiempo especificado por **delay**.

- **Control Remoto y Monitoreo** : Está disponible un ejemplo **DEMO** que te permitirá interactuar con el _Robot Uzi_ usando nuestra aplicación móvil.

- **LEDs RGB** : Se pueden crear instancias del objeto **Lights**, mediante su constructor por defecto _**Lights::* Lights()_, para poder utilizar los LEDs RGB del _Robot Uzi_. En la sección _ejemplos_ se encuantra disponible un código de prueba. Están disponibles las siguientes funciones:
    - **init()** : Inicializa el objeto para poder interactuar con los LEDs RGB.
    - **demo()** : Muestra una secuencia de colores entre los distintos LEDs del _Robot Uzi_.
    - **setColor(** _int **i**, int **red**, int **green**, int **blue**_ **)** : Permite elegir el color en **Formato RGB** del LED **i**, donde **i** es el identificador del LED que va desde **0** a **3**. También están predefinidos los colores básicos usando _MACROS_ (i.e. **setColor(** 0, _AMARILLO_ **)**, etc). Las _MACROS_ definidas son las siguientes:
        - _NEGRO_
        - _AZUL_
        - _VERDE_
        - _CIAN_
        - _ROJO_
        - _MAGENTA_
        - _AMARILLO_
        - _BLANCO_
    - **getColor(** _int ***i**_ **)** : Retorna un número entero el color del LED con el identificador **i**.

    ... (coming soon) ...
