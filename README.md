# Ninja Parkour - A QT Video Game (C++)

## Overview

You are a Ninja looking to restore the piece in your nation. Go through the level, slashing enemies without falling into the abyss.

## Install
Install required packages
```sh
sudo apt-get install qtbase5-dev qtchooser qt5-qmake qtbase5-dev-tools qtmultimedia5-dev libqt5multimedia5-plugins -y
```

Compile
```sh
cd ninja_parkour
qmake
make
```

Play
```sh
./game
```

## Aspects
For implementing Aspect methods & Metrics, execute the `aspect.py` file:
```sh
python aspect.py
```
Then in the folder `new_project/src`, you have the new source code.
```sh
cp -i ./new_project/src/* ./src
```
Then you can re-compile and execute.

## Container (for Windows)
### Requirements
* Docker Desktop
* MobaXterm
### Build the image
Start Docker daemon
In cmd:
```sh
docker build -t ninja_game .
```
### Run container
You must have MobaXterm open and be sure X server is running
Then in cmd:
```sh
docker run -it --rm -e DISPLAY=<YOUR_WINDOWS_IPV4_ADRESS>:0.0 -v /tmp/.X11-unix:/tmp/.X11-unix ninja_game
```


