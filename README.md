#**Serial communication** 

##**System requirements**:    

Firstable, you have to install several modules:

* $ *npm* install --save serialport
* $ *npm* install express
* $ *npm* install socket.io

 It will install all the necessary assets for the serialport library.   
 `Express` and `socket.io` would be usefull if you want to remotely control your robot with your phone or from a dedicated webpage.
 
 to upload the code on the **Arietta**, just type:
 
 > $ node ariettaTalks.js **LEDON#** 
 
 To switch on the led 13 on the **Teensy**.
 
 > $ node ariettaTalks.js **LEDOFF#**
 
 To switch off the led 13 on the **Teensy**.
 
 Of course, you have also toupload the code on the Arietta : `teensyLed.c`
 
 
 > $ node readdatas.js 
 
 To read datas coming from the Teensy
 
 Watch what is happening with a little:
 > $ screen /dev/ttyS1 -b 9600
 
 On the Arietta
 

