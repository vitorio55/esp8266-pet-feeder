# Radio controlled DIY Pet Feeder using ESP8266

A DIY pet food dispenser using ESP8266 microcontroller.  
An optional Blynk support is present (but commented out).  

As can be seen on the image below, it is controlled using a simple radio controller.  

~~~
Buttons A and B:  
  Release food of the corresponding compartments (one servo activation)  

Button D:
  Activates twice both sides at the same time
~~~

*TODO: An electric components diagram will be added here in the future.*  

### List of parts
* 1x dual cereal dispenser
* 2x MG996R metal-gear servos
* 2x Pringles tubes
* 2x beans cans (or any other type that fits the end of a Pringles tube)
* 2x 45º PVC pipe fittings
* 1x optional case for the ESP8266
* ~15x nylon cable ties
* 1x optional wooden front support
* 2x optional L shaped metal supports for the wooden front support
* 2x wood planks for the structure
* 1x DC power source compatible with L7805 regulator (I used a 9V DC)
* 2x female jumper cables for servo cable extension
* 2x shrink tube sections for the servo cable extensions
* screws for the structure

#### Electronical components
*TODO*


<img src="https://drive.google.com/uc?export=view&id=19s2OR-KXJEJIvmxjpx6WrXahWPca26rq" alt="drawing" width="500"/>

---

### Future improvements
* Sometimes the food gets stuck inside the tubes, and a little shaking is necessary => change release system from beans cans to a 3D printed rotating part.
* The reset button must be pressed to start the code after the power is connected => add capacitor connected to RST pin for auto-startup.
* Add support from Blynk side / add a webserver to control it via wifi.
* Add an (ultrasonic?) meter to check remotely the food level.
* It's ugly => paint the damn thing!