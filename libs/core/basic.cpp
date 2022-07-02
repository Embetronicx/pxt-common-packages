#include "pxt.h"


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
    }

    /**
     * Turn off all LEDs
     */
    //% help=basic/clear-screen weight=75
    //% blockId=device_clear_display block="clear screen"
    //% parts="ledmatrix"
    void clearScreen() {
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
    }
}