---
nav_order: 2
title: Getting Started
---

## Getting Started
Gestro is designed to be used on Linux PCs running the Ubuntu distribution. In particular, it was tested and found to be running perfectly on PCs running Ubuntu 18.04 LTS.

### Prerequisites
* A PC running Ubuntu.
* A webcam.

Gestro requires the following tools and libraries to run (other versions are not tested):
* X11
* Qt 5
* OpenCV 4.5.5
* libasound2-dev
* Boost Unit Test Framework

> These required tools and libraries will be installed if you follow step 2 of the [installation guide](#installation-guide) below.

### Installation Guide

> If permission is denied while trying to run any of the scripts, please enter the following command into the terminal and try running the script again, ``` sudo chmod +x <script_name>.sh```.

>For example, for the install_dependencies.sh, enter ``` sudo chmod +x install_dependencies.sh ``` into the terminal.

**1. Download the latest [release]() from our Github and extract the contents into the Home folder.**

**2. Launch a terminal and enter the following commands into it to install the requirements:**
```sh
cd Gestro && ./install_dependencies.sh
```

**3. Enter the following commands into the terminal to run the build script.**
```sh
./build.sh
```
