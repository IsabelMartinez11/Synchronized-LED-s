#include <msp430.h>
#include <driverlib.h>


/**
 * main.c
 */

int main(void)
{
    //PM5CTL0 &= ~LOCKLPM5;       // for FRAM devices
    PMM_unlockLPM5();

    //WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    WDT_A_hold(WDT_A_BASE);

    // input button S1


    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN5);



    // output LED1
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN7);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN5);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN4);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN3);
    GPIO_setAsOutputPin(GPIO_PORT_P3, GPIO_PIN0);
    GPIO_setAsOutputPin(GPIO_PORT_P2, GPIO_PIN5);
    GPIO_setAsOutputPin(GPIO_PORT_P1, GPIO_PIN0);
    int x = -1; // set P4.6 as output

    while(1)
    {
        // read pin P4.5, push button S1
        if ( GPIO_getInputPinValue(GPIO_PORT_P4, GPIO_PIN5)) {
            // if button is down, turn on LED1, pin P4.6
            GPIO_setOutputHighOnPin(GPIO_PORT_P1, GPIO_PIN0);
        }
        else {
            // if button is up, turn off LED1, pin P4.6
            GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN7);
            GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN5);
            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}
            _delay_cycles(100000);
            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}

            _delay_cycles(100000);
            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}


            _delay_cycles(100000);
            GPIO_toggleOutputOnPin(GPIO_PORT_P4, GPIO_PIN3);
            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}
            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}

            _delay_cycles(100000);
            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}
            _delay_cycles(100000);

            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}
            _delay_cycles(100000);
            if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN4);}
            _delay_cycles(100000);

            GPIO_toggleOutputOnPin(GPIO_PORT_P1, GPIO_PIN3);
                       GPIO_toggleOutputOnPin(GPIO_PORT_P3, GPIO_PIN0);
                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}
                       _delay_cycles(100000);
                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}

                       _delay_cycles(100000);
                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}


                       _delay_cycles(100000);
                       GPIO_toggleOutputOnPin(GPIO_PORT_P4, GPIO_PIN3);
                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}
                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}

                       _delay_cycles(100000);
                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}
                       _delay_cycles(100000);

                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}
                       _delay_cycles(100000);
                       if(x>5){GPIO_toggleOutputOnPin(GPIO_PORT_P2, GPIO_PIN5);}
                       _delay_cycles(100000);

            x++;

        }
    }
}
