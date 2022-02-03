# ENG5220 - Real-Time-Embedded-Systems - Team 26

## To control the Ubuntu system using hand gestures
**Functions:**
* Increase or Decrease Volume and Brightness.
* Switch between applications.
* Zoom in and Zoom out.
* Track mouse.
* Mute and Unmute.
* Play and Pause.
* Next and previous.

**Methodologies:**
* A PC running Ubuntu.
* A webcam.
* Using OpenCV and TensorFlow.

**Problems Being Solved:**
* Additional everyday functionalities for one that is sitting away from their PC (Eg. When giving a presentation).
* To aid users with poor fine motor control (Eg. Parkinson's patients).
* To make controlling the system more user friendly for people that are unfamiliar with modern devices (Eg. Elderly people)

"Steps to Configure OpenCV 4.5.5"
* Need Ubuntu 18.04

1. Python version should be above 3.6
```
sudo apt update
sudo apt install software-properties-common
sudo add-apt-repository ppa:deadsnakes/ppa
sudo apt update
sudo apt install python3.7
```

2. Check the python version, if shows 3.7 then skip step 3.
```
python --version
```

3. If some other version of python then you can configure the versions and switch between them. The current command will set 3.7 to highest priority.
```
sudo update-alternatives --install /usr/bin/python python /usr/bin/python3.7 1
```

4. Installing OpenCV just follow the following commands, skipping any command will result in failure.
```
# update the repositories
sudo apt-get update

# install important packages
sudo apt install build-essential cmake git pkg-config libgtk-3-dev \
    libavcodec-dev libavformat-dev libswscale-dev libv4l-dev \
    libxvidcore-dev libx264-dev libjpeg-dev libpng-dev libtiff-dev \
    gfortran openexr libatlas-base-dev python3-dev python3-numpy \
    libtbb2 libtbb-dev libdc1394-22-dev
    
# make directory to download and build opencv
mkdir ~/opencv_build && cd ~/opencv_build

# download and unpack the repositories
wget -O opencv.zip https://github.com/opencv/opencv/archive/4.x.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/4.x.zip
unzip opencv.zip
unzip opencv_contrib.zip

# cd into opencv-4.x 
cd opencv-4.x

# build the opencv
mkdir build && cd build

cmake -D CMAKE_BUILD_TYPE=RELEASE \
    -D CMAKE_INSTALL_PREFIX=/usr/local \
    -D INSTALL_C_EXAMPLES=ON \
    -D INSTALL_PYTHON_EXAMPLES=ON \
    -D OPENCV_GENERATE_PKGCONFIG=ON \
    -D OPENCV_EXTRA_MODULES_PATH=~/opencv_build/opencv_contrib-4.x/modules \
    -D BUILD_EXAMPLES=ON ..
    
# jX the X depends on your number of cores. I ran on 4 cores.
make -j4

# If the following error occurs: "recipe for target "all" failed", just rerun the make command again:
make -j4

# when opencv is successfully built, run the following command:
sudo make install            
```



