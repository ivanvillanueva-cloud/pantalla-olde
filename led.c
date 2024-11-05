//en esta parte se encuentran las librerias
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "pico/stdlib.h"
#include "hardware/i2c.h"
#include "ssd1306.h"


const uint8_t num_chars_per_disp[]={7,7,7,5};

// definimos lo que es el tiempo de refresco
#define SLEEPTIME 25
//definimos las variables
void iniciar(void);
void pantalla(void);

int main() {
    stdio_init_all();

   //ponemos los pins que vamos a usar 
    iniciar();

    // lo que se va a imprimir
    pantalla();

    return 0;
}

//definimos lo que es los pines de entrada para acceder a la pioc
//en este caso lo que es el pin2 y 3
// al igual que habilitamos las resistencias
void iniciar(void) {
    i2c_init(i2c1, 400000);
    gpio_set_function(2, GPIO_FUNC_I2C);
    gpio_set_function(3, GPIO_FUNC_I2C);
    gpio_pull_up(2);
    gpio_pull_up(3);
}

// aqui ponermos lo que es el ancho, la resolucion de la pantalla
void pantalla(void) {

    ssd1306_t disp;
    disp.external_vcc=false;
    ssd1306_init(&disp, 128, 64, 0x3C, i2c1);
    ssd1306_clear(&disp);
    char buf[8];
// en este apartado ponemos lo que ira en la pantalla
//primer comando lo que es la dimension, en la primera variable corresponde a x
//segunda variable a y
//tercera a lo que es el tamaño de letra
//por ultimo entre comillas lo que es el mensaje
//despues se selecciona lo que es el tiempo de disparo
//por ultimo lo que es que muestre el mensaje
// se hace tres veces porque son tres lineas de mensajes
    for(;;) {
        
            ssd1306_draw_string(&disp, 8, 10, 2, "Ivan");
            sleep_ms(500);
            ssd1306_show(&disp);
                        

            ssd1306_draw_string(&disp, 8,30,2, "Villanueva");
                        sleep_ms(200);
            ssd1306_show(&disp);
            ssd1306_draw_string(&disp, 8, 50, 2, "Ramirez");
            sleep_ms(400);
            
            ssd1306_show(&disp);
            sleep_ms(500);
            ssd1306_clear(&disp);
        }        
    }

