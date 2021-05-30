# Arduino-Laser-Alarm
Laser alarm using Arduino UNO
### Demo link:
https://youtu.be/8l55dDpjTFM

### Things needed:
- Ardunio UNO
- Mini breadboard
- Piezo buzzer
- Light sensor (brick type in my case, but any type can be used)
- Laser module (ky-008 in this case)
- Touchpad 4 channels TTP224
- MF wires
- FF wires

### How it works:
The laser hits the light sensor, which registers a certain value. When something interrupts the laser, the value drops and the buzzer starts producing sounds. If key 1 is pressed three times on the touchpad, the laser turns back on and the buzzer stops (the key on the touchpad works as a security code; any key or combination can be used).
### How the code works:
The variables for buzzer, laser and button are declared. Also, the "sensorVal" and "code" integers are declared, the last one being incremented every time the first key on the touchpad is pressed.
In setup, the pins for input/output are declared.
Also, the bools "alarm" (which is false initially) and "button1_state" (which represents the state of the touchpad's key) are declared.
In loop, we read the sensor value in "valLight" and, if it drops under 300, it means the laser has been interrupted (300 is the value the sensor receives when the laser hits it; it can be changed, depending on the sensor). In this case, the laser stops and the buzzer starts emitting sounds. The program checks if the alarm is on and if the button is pressed, in which case "code" var is incremented. When "code" reaches a value of 30, the alarm resets.
### Other observations:
- Cable colors may be different in the diagram and my video.
- There is a possibility that an insect or a small object might trigger the alarm. In this case, another laser could be added, parallel with the firs one, at a small distance. The alarm is triggered only when both of them are interrupted (it means a large object blocks them, such as a human).
- In the video, I used lego pieces to stop the components from moving.
