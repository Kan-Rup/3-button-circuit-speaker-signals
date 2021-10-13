# 3-button-circuit-speaker-signals
Copyright (c) Kanishka Rupasinghe, 2021. The code is provided to you under MIT licence.


This is an Arduino program which has to be uploaded to the Arduino board of the relevant circuit, for the circuit to function.

The circuit has three buttons. Pressing one of these buttons triggers its specific sound signal. A custom sound signal for any
of the buttons can be added to the circuit by uploading new speaker power-supply instructions from the Arduino IDE to the 
Arduino board.

The program declares the pins that are to be used and their input or output role. In the setup section the pin modes are set,
and in the loop section, the board first reads the current value of the input pins, and if any button press is detected through
this, the board sends the sounding current signals to the speaker attached to the board.

The following article describes the circuit in detail :
https://techieartisans.com/2021/10/13/get-started-on-electronics-and-arduino-easy-3-button-sound-signaller-circuit/
