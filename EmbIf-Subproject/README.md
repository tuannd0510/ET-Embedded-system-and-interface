## boot config
```
sudo nano /boot/config.txt
```
add new lines
```
# SERVO
dtoverlay=pwm,pin=12,func=2
# rc522
dtoverlay=spidev_disabler
```
```
echo 1000000 > /dev/sg...
echo 2000000 > /dev/sg...
```
## LCD

```
echo '1' > /sys/devices/virtual/alphalcd/lcdi2c/clear 
echo '11' > /sys/devices/virtual/alphalcd/lcdi2c/position 
echo "abc" > /dev/lcdi2c 
```

## enable SPI Interface:
```
sudo raspi-config
```
->Interface Options -> SPI -> Enable -> Finish
```
sudo cp spidev_disabler.dtbo /boot/overlays/
```

## load modules on boot (bashrc)
```
sudo nano .bashrc
```
add new lines
```
sudo insmod /hopme/pi/HTN/src/*/*.ko 
```

## Reference
https://opensource.com/article/19/5/how-write-good-c-main-function
### rpi
### lcd
### ir-sensor
### pwm 
https://learn.sparkfun.com/tutorials/pulse-width-modulation/all

https://www.teachmemicro.com/raspberry-pi-pwm-servo-tutorial/#:~:text=A%201.5%20ms%20PWM%20signal,for%20controlling%20the%20servo%20motor!

https://www.allaboutcircuits.com/technical-articles/introduction-to-microcontroller-timers-pwm-timers/#:~:text=PWM%20Duty%20Cycle,a%20duty%20cycle%20of%2050%25

http://arduino.vn/tutorial/1423-avr-dieu-khien-dong-co-servo-sieu-chuan-voi-bien-do-goc-cuc-nho

https://github.com/dotnet/iot/blob/main/Documentation/raspi-pwm.md

https://github.com/raspberrypi/linux/blob/04c8e47067d4873c584395e5cb260b4f170a99ea/arch/arm/boot/dts/overlays/README#L925
