#include "pxt.h"

extern int ROW[5];
extern int COL[5];

//% color=#8169E6 weight=85 icon="\uf205"
namespace basic {

    /**
     * Draws an image on the LED screen.
     * @param leds the pattern of LED to turn on/off
     * @param interval time in milliseconds to pause after drawing
     */
    //% help=basic/show-leds
    //% weight=85 blockGap=8
    //% imageLiteral=1 async
    //% blockId=device_show_leds
    //% block="show leds" icon="\uf00a"
    //% parts="ledmatrix"
    void showLeds(String leds, int interval = 400) {
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
          sleep_us(100);

          for ( int row = 0; row < 5; row++ )
          {
              auto led1 = pxt::lookupPin(getConfig( ROW[row], -1));
              led1->setDigitalValue(0);
          }
          
          led->setDigitalValue(1);
      }
    }

    /**
     * Display text on the display, one character at a time. If the string fits on the screen (i.e. is one letter), does not scroll.
     * @param text the text to scroll on the screen, eg: "hi!"
     * @param interval how fast to shift characters; eg: 50, 100, 150, 200
     */
    //% help=basic/show-string
    //% weight=100 blockGap=16
    //% block="show|string %text || in an interval of %interval ms"
    //% async
    //% blockId=device_print_message
    //% parts="ledmatrix"
    //% text.shadowOptions.toString=true
    //% expandableArgumentMode="toggle"
    //% interval.defl=80
    void showString(String text, int interval = 80) {
      int matrix[5][5] = { 
                          {0,0,0,0,1},
                          {0,0,0,0,1},
                          {0,0,0,0,1},
                          {0,0,0,0,1},
                          {0,0,0,0,1}
                          };

      //matrix[x][y] = 1;

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
          sleep_us(100);

          for ( int row = 0; row < 5; row++ )
          {
              auto led1 = pxt::lookupPin(getConfig( ROW[row], -1));
              led1->setDigitalValue(0);
          }
          
          led->setDigitalValue(1);
      }
    }

    /**
     * Turn off all LEDs
     */
    //% help=basic/clear-screen weight=75
    //% blockId=device_clear_display block="clear screen"
    //% parts="ledmatrix"
    void clearScreen() {
      for(int x =0; x <= 4; x++)
      {
        auto led = pxt::lookupPin(getConfig( ROW[x], -1));
        led->setDigitalValue(0);

        led = pxt::lookupPin(getConfig( COL[x], -1));
        led->setDigitalValue(1);
      }
    }

    /**
     * Repeats the code forever in the background. On each iteration, allows other codes to run.
     * @param body code to execute
     */
    //% help=basic/forever weight=55 blockGap=16 blockAllowMultiple=1 afterOnStart=true
    //% blockId=device_runforever block="runforever" icon="\uf01e"
    void runforever(Action a) {
      runForever(a);
    }

    /**
     * Pause for the specified time in milliseconds
     * @param ms how long to pause for, eg: 100, 200, 500, 1000, 2000
     */
    //% help=basic/KeepWait weight=50 blockGap=16 blockAllowMultiple=1
    //% async block="KeepWait (ms) %KeepWait"
    //% blockId=device_KeepWait icon="\uf110"
    //% pause.shadow=timePicker
    void KeepWait(int ms) {
        if (ms < 0) return;
        sleep_ms(ms);
    }
}