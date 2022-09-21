// Ojo de Kit de 16 bits en C

// PIC16F84A Configuration Bit Settings
// CONFIG
#pragma config FOSC = XT        // Oscillator Selection bits (XT oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#include <xc.h>
#define _XTAL_FREQ 4000000      // Frecuencia del cristal a utilizar.

int main() {
    int n;      // Variable usada como contador.
    TRISB = 0;  // Configuro PORTB como salida
    TRISD=0;    //Configuro PORTC como salida
    ANSEL=0;    //Aseguro que PORTB sea entrada digital
    ANSELH=0;   //Aseguro que PORTB sea entrada digital
    PORTB = 128;  // Valor inicial del PORTB (enciende el LED mas sig.)
    PORTD=0;      //configuro PORTC como salida
    __delay_ms(1000); //Retardo para poder ver el primer bit
    while(1){   // Bucle infinito.
        
        for(n=7;n>0;--n){   // Hago 7 corrimientos a la derecha en PORTB.
            PORTB >>=1;     // Corrimiento de un bit y asignación. 
            __delay_ms(1000);
        } //Las dos instrucciones siguientes son necesarias ya que el ojo de kit es de 16 bits y 
            //un solo puerto no es suficiente tenemos que tomar 2
            PORTB=0;    //Pongo a cero PORTB
            PORTD = 128;//Inicializo la segunda parte del ojo de kit poniendo el valor en PORTD
            __delay_ms(1000);
            for(n=7;n>0;--n){   // Hago 7 corrimientos a la derecha.
                PORTD >>=1;     // Corrimiento de un bit y asignación. 
                __delay_ms(1000);
    
        }
        
    
              
        for(n=7;n>0;--n) {  // Hago 7 corrimientos a la izquierda,
            PORTD <<=1;     // Corrimiento de un bit y asignación.
            __delay_ms(1000);
        }   //Las dos instrucciones siguientes son necesarias ya que el ojo de kit es de 16 bits y 
            //un solo puerto no es suficiente tenemos que tomar 2
            PORTD=0;    //Pongo a cero PORTD
            PORTB = 1;  //Inicializo la segunda parte del ojo de kit poniendo el valor en PORTB
            __delay_ms(1000);
            for(n=7;n>0;--n){   // Hago 7 corrimientos a la derecha.
                PORTB <<=1;     // Corrimiento de un bit y asignación. 
                __delay_ms(1000);           
        }
    }
}