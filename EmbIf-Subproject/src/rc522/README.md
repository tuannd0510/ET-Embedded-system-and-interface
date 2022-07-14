**Step by step:**
## 
```
sudo raspi-config
```
->Interface Options -> SPI -> Enable -> Finish

## 

```
make
dtc spidev_disabler.dts -O dtb >spidev_disabler.dtbo
sudo cp spidev_disabler.dtbo /boot/overlays/
```

## 

```
sudo nano /boot/config.txt
# add new line:
dtoverlay=spidev_disabler
```

## Run file test
