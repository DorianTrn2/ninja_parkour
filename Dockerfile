FROM debian:latest

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    qtbase5-dev \
    qtchooser \
    qt5-qmake \
    qtbase5-dev-tools \
    qtmultimedia5-dev \
    libqt5multimedia5-plugins \
    g++ \
    make \
    && rm -rf /var/lib/apt/lists/*
	
WORKDIR /usr/src/app

COPY . .

RUN qmake ninja_parkour.pro && make

CMD ["./game"]