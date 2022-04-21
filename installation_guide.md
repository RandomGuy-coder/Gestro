---
nav_order: 2
title: Installation Guide
---

# Installation Guide
Gestro is designed to be used on Linux PCs running the Ubuntu distribution. In particular, it was tested and found to be running perfectly on PCs running Ubuntu 18.04 LTS.

## Prerequisites
* A PC running Ubuntu.
* A webcam.

Gestro requires the following tools and libraries to run (other versions are not tested):
* X11
* Qt 5
* OpenCV 4.5.5
* libasound2-dev
* Google Unit Test FrameWork

> These required tools and libraries will be installed if you follow step 2 of the [installation instructions](#installation-instructions) below.

## Installation Instructions

> If permission is denied while trying to run any of the scripts, please enter the following Commands into the terminal and try running the script again, ``` sudo chmod +x <script_name>.sh```.

> For example, for the install_dependencies.sh, enter ``` sudo chmod +x install_dependencies.sh ``` into the terminal.

**1. Download the latest [release](https://github.com/RandomGuy-coder/Gestro/releases) from our Github and extract the contents into the _Home_ folder.**

> Note: Make sure the folder with the contents is named "Gestro". If not, rename it to "Gestro".

> Alternatively, launch a terminal and run:
> ```
> git clone https://github.com/RandomGuy-coder/Gestro.git
> ```

**2. Launch a terminal and enter the following commands into it to install the requirements:**
```sh
cd ~/Gestro && sudo ./install_dependencies.sh
```
> Note: If CMake version is found to be too low, please follow instructions [here](https://askubuntu.com/a/829311) to update CMake. After updating CMake, make sure to close and reopen the terminal before starting from step 2 again.

**3. Enter the following commands into the terminal to run the build script.**
```sh
sudo ./build.sh
```
