# BlueRobotics_KellerLD_Library

Nvidia Jetson Nano library for the Keller 4LD - 9LD I2C pressure and temperature sensors; used in the Bar100 Sensor from Blue Robotics.

See the [Keller Communication Protocol 4LD-9LD](http://www.keller-druck2.ch/swupdate/InstallerD-LineAddressManager/manual/Communication_Protocol_4LD-9LD_en.pdf) document for more details on the I<sup>2</sup>C communication protocol, and the [Keller 4LD-9LD Datasheet](https://download.keller-druck.com/api/download/2LfcGMzMbeHdjFbyUd5DWA/en/latest) for sensor specification details.

## Usage
- Clone the repository
```
git clone -b jetsonNano https://github.com/bluerobotics/BlueRobotics_KellerLD_Library.git
```
- Compile and run it using CMake
```
cd ~/BlueRobotics_KellerLD_Library/build
cmake ..
make
./BlueRobotics_KellerLD
```