var SerialPort = require("serialport").SerialPort;
var serialport = new SerialPort("/dev/ttyS2");
serialport.on('open', function(){
  console.log('Serial Port Open');
  serialport.on('data', function(data){
      console.log(data[0]);
  });
});
