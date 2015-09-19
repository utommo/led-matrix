# led-matrix

I have built a 3x3x3 led matrix similar to ones found [here](https://www.youtube.com/watch?v=GLx6aA75CZY) and [here](http://www.instructables.com/id/LED-Cube-and-Arduino-Lib/).

The matrix consists of 27 leds, which are powered by 12 pins. 
9 pins connected to  common anodes, 3 pins connected to common cathodes.

```
   Physical Pins                  Declared as
|       |[ 8][5][2]          |       |[6][3][0]
|Arduino|[ 9][6][3]          |Arduino|[7][4][1]
|       |[10][7][4]          |       |[8][5][2]
```

The Arduino used to control the circuit is an Arduino Pro Mini.
And also:

3x 22k ohm Resistors
9x 220 ohm Resistors
3x 2N2222 NPN Transistors

![wiringdiagram](
http://i1.wp.com/randomnerdtutorials.com/wp-content/uploads/2013/08/Schematics-Led-Cube.png)

The wiring diagram is taking from [this](http://randomnerdtutorials.com/arduino-led-cube-3x3x3/) website.
