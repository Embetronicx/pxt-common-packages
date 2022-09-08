#include "pxt.h"

int ROW[5] = { CFG_PIN_P0, CFG_PIN_P1, CFG_PIN_P2, CFG_PIN_P3, CFG_PIN_P4 };
int COL[5] = { CFG_PIN_P5, CFG_PIN_P6, CFG_PIN_P7, CFG_PIN_P8, CFG_PIN_P9 };

//% color=#8169E6 weight=85 icon="\uf205"
namespace led {

    CODAL_LEDMATRIX ledMtrix;

    //CODAL_TEST test;

    /**
     * Turn on the specified LED using x, y coordinates (x is horizontal, y is vertical). (0,0) is upper left.
     * @param x the horizontal coordinate of the LED starting at 0
     * @param y the vertical coordinate of the LED starting at 0
     */
    //% help=led/plot weight=78
    //% blockId=device_plot block="plot|x %x|y %y" blockGap=8
    //% parts="ledmatrix"
    //% x.min=0 x.max=4 y.min=0 y.max=4
    //% x.fieldOptions.precision=1 y.fieldOptions.precision=1
    void plot(int x, int y) {
        ledMtrix.etx_plot(*pxt::lookupPin(getConfig( ROW[x], -1)),*pxt::lookupPin(getConfig( COL[y], -1)));
#if 0
#if 1
        if( ( x <= 4 ) || ( y <= 4 ) )
        {
            int var = getConfig( ROW[x], -1);
            auto led = pxt::lookupPin( var );
            led->setDigitalValue(1);

            led = pxt::lookupPin(getConfig( COL[y], -1));
            led->setDigitalValue(0);
        }
#else
        int matrix[5][5] = { 
                            {0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,0,0,0,0},
                            {0,0,0,0,0}
                           };

        matrix[x][y] = 1;

        for ( int col = 0; col < 5; col++ )
        {
            auto led = pxt::lookupPin(getConfig( COL[col], -1));
            led->setDigitalValue(0);

            for ( int row = 0; row < 5; row++ )
            {
                auto led1 = pxt::lookupPin(getConfig( ROW[row], -1));
                led1->setDigitalValue(matrix[row][col]);
            }

            //TODO - SLR : Remove this delay
            sleep_us(500);

            for ( int row = 0; row < 5; row++ )
            {
                auto led1 = pxt::lookupPin(getConfig( ROW[row], -1));
                led1->setDigitalValue(0);
            }

            led->setDigitalValue(1);
        }
#endif
#endif
    }

    /**
     * Turn on the specified LED with specific brightness using x, y coordinates (x is horizontal, y is vertical). (0,0) is upper left.
     * @param x the horizontal coordinate of the LED starting at 0
     * @param y the vertical coordinate of the LED starting at 0
     * @param brightness the brightness from 0 (off) to 255 (bright), eg:255
     */
    //% help=led/plot-brightness weight=78
    //% blockId=device_plot_brightness block="plot|x %x|y %y|brightness %brightness" blockGap=8
    //% parts="ledmatrix"
    //% x.min=0 x.max=4 y.min=0 y.max=4 brightness.min=0 brightness.max=255
    //% x.fieldOptions.precision=1 y.fieldOptions.precision=1
    //% advanced=true
    void plotBrightness(int x, int y, int brightness) {
    }

    /**
     * Turn off the specified LED using x, y coordinates (x is horizontal, y is vertical). (0,0) is upper left.
     * @param x the horizontal coordinate of the LED
     * @param y the vertical coordinate of the LED
     */
    //% help=led/unplot weight=77
    //% blockId=device_unplot block="unplot|x %x|y %y" blockGap=8
    //% parts="ledmatrix"
    //% x.min=0 x.max=4 y.min=0 y.max=4
    //% x.fieldOptions.precision=1 y.fieldOptions.precision=1
    void unplot(int x, int y) {
        ledMtrix.etx_unplot(*pxt::lookupPin(getConfig( ROW[x], -1)),*pxt::lookupPin(getConfig( COL[y], -1)));
#if 0
        if( ( x <= 4 ) || ( y <= 4 ) )
        {
            auto led = pxt::lookupPin(getConfig( ROW[x], -1));
            led->setDigitalValue(0);

            led = pxt::lookupPin(getConfig( COL[y], -1));
            led->setDigitalValue(0);
        }
#endif
    }
    /**
     * Draws an image on the LED screen.
     * @param leds the pattern of LED to turn on/off
     * @param interval time in milliseconds to pause after drawing
     */
    //% help=basic/show-leds
    //% weight=85 blockGap=8
    //% imageLiteral=1 async
    //% blockId=device_show_leds_show_led_pattern
    //% block="Led Pattern" icon="\uf00a"
    //% parts="ledmatrix"
    void showLedPattern(String leds, int interval = 400) {
      int matrix[5][5] = { 
                          {1,0,0,0,0},
                          {1,0,0,0,0},
                          {1,0,0,0,0},
                          {1,0,0,0,0},
                          {1,0,0,0,0}
                          };

      //matrix[x][y] = 1;

      for ( int col = 0; col < 5; col++ )
      {
        auto led = pxt::lookupPin(getConfig( COL[col], -1));
        led->setDigitalValue(0);

        for ( int row = 0; row < 5; row++ )
        {
            auto led1 = pxt::lookupPin(getConfig( ROW[row], -1));
            led1->setDigitalValue(matrix[col][row]);
        }
        
        //TODO - SLR : Remove this delay
        sleep_us(500);

        for ( int row = 0; row < 5; row++ )
        {
            auto led1 = pxt::lookupPin(getConfig( ROW[row], -1));
            led1->setDigitalValue(0);
        }
        
        led->setDigitalValue(1);
      }
    }

    /**
     * Get the brightness state of the specified LED using x, y coordinates. (0,0) is upper left.
     * @param x the horizontal coordinate of the LED
     * @param y the vertical coordinate of the LED
     */
    //% help=led/point-brightness weight=76
    //% blockId=device_point_brightness block="point|x %x|y %y brightness"
    //% parts="ledmatrix"
    //% x.min=0 x.max=4 y.min=0 y.max=4
    //% x.fieldOptions.precision=1 y.fieldOptions.precision=1
    //% advanced=true
    int pointBrightness(int x, int y) {

        return 0;
    }

    /**
     * Get the screen brightness from 0 (off) to 255 (full bright).
     */
    //% help=led/brightness weight=60
    //% blockId=device_get_brightness block="brightness" blockGap=8
    //% parts="ledmatrix"
    //% advanced=true
    int brightness() {

        return 0;
    }

    /**
     * Set the screen brightness from 0 (off) to 255 (full bright).
     * @param value the brightness value, eg:255, 127, 0
     */
    //% help=led/set-brightness weight=59
    //% blockId=device_set_brightness block="set brightness %value"
    //% parts="ledmatrix"
    //% advanced=true
    //% value.min=0 value.max=255
    void setBrightness(int value) {
    }

    /**
     * Cancels the current animation and clears other pending animations.
     */
    //% weight=50 help=led/stop-animation
    //% blockId=device_stop_animation block="stop animation"
    //% parts="ledmatrix"
    //% advanced=true
    void stopAnimation() {
    }

    /**
    * Turns on or off the display
    */
    //% help=led/enable blockId=device_led_enable block="led enable %on"
    //% advanced=true parts="ledmatrix"
    void enable(bool on) {
    }
}
