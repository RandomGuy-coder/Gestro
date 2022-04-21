<h1 align="center">Gestro</h1>
<p align="center">
  <a href="https://github.com/RandomGuy-coder/Gestro">
    <img src="/assets/gestro_logo.png" alt="Gestro Logo" width="200">
  </a>

  <p align="center">Controlling Linux system using hand gestures</p>
</p>

<div align="center">

  ![Contributors](https://img.shields.io/github/contributors/RandomGuy-coder/Gestro?color=9cf&style=flat-square)
  ![Issues](https://img.shields.io/github/issues/RandomGuy-coder/Gestro?color=orange&style=flat-square)
  ![License](https://img.shields.io/github/license/RandomGuy-coder/Gestro?color=skyblue&style=flat-square)
  ![Releases](https://img.shields.io/github/v/release/RandomGuy-coder/Gestro?color=blueviolet&include_prereleases&style=flat-square)
  ![LastCommit](https://img.shields.io/github/last-commit/RandomGuy-coder/Gestro?color=violet&style=flat-square)

</div>

<!-- CONTENTS -->
<details open="open">
  <summary>Contents</summary>
  <ol>
    <li>
      <a href="#About-Gestro">About Gestro</a>
      <ul>
        <li><a href="#Demonstration-Video">Demonstration Video</a></li>
        <li><a href="#Features">Features</a></li>
        <li><a href="#Built-With">Built With</a></li>
        <li><a href="#Built-On">Built On</a></li>
      </ul>
    </li>
    <li>
      <a href="#Getting-Started">Getting Started</a>
      <ul>
        <li><a href="#Prerequisites">Prerequisites</a></li>
        <li><a href="#Installation-Guide">Installation Guide</a></li>
      </ul>
    </li>
    <li>
      <a href="#Launching-Gestro">Launching Gestro</a>
      <ul>
        <li><a href="#Main-Program">Main Program</a></li>
        <li><a href="#Unit-Tests">Unit Tests</a></li>
      </ul>
    </li>
    <!-- <li><a href="#contributing">Contributing</a></li> -->
    <li><a href="#Contributors">Contributors</a></li>
    <li><a href="#Future-Enhancement">Future Enhancement</a></li>
    <li><a href="#Social-Media">Social Media</a></li>
    <li><a href="#Documentation">Documentation</a></li>
    <li><a href="#License">License</a></li>
  </ol>
</details>

## About Gestro

Gestro is developed by a group of students from The University of Glasgow currently undertaking the course of ENG5220 - Real-time Embedded Systems under Team 26.

Gestro is an application which allows users to control their Linux system using hand gestures so that users will be able to perform certains actions without the use of a keyboard and mouse. This is particularly useful in cases where users want to control their Linux PC while: being away from it, being unfamiliar with modern devices (such as Elderly people), et cetera.

By using a webcam and libraries such as OpenCV, X11, et cetera, Gestro is able to successfully translate hand gestures performed by users into commands that performs certain operations including, but not limited to, muting and unmuting the system's volume, move window, mouse move and clicks. Gestro is designed to be displayed using a Qt application on the users' Linux system running the Ubuntu distribution.

<!-- **enter more about functionalities here** -->

More details can be found below. However, for the complete information about Gestro, please visit our [website](https://randomguy-coder.github.io/Gestro/).

### Demonstration Video
Click to view our [demonstration video]()!

<div align="center">
  <img src="" alt="Screenshot of demonstration" width="600">
</div>


### Features
* Enter Spacebar (Used for Play and Pause).
* Track mouse.
* Perform mouse clicks.
* Mute and Unmute Volume.
* Move and Minimise window.

### Built With
* A PC running Ubuntu 18.04 LTS.
* A webcam.

### Built On
* Iir
* X11
* Qt 5
* C++
* CMake
* OpenCV
* Doxygen
* libasound2-dev
* Google Unit Test Framework

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
* Google Unit Test FrameWork

> These required tools and libraries will be installed if you follow step 2 of the [installation guide](#installation-guide) below.

### Installation Guide

> If permission is denied while trying to run any of the scripts, please enter the following Commands into the terminal and try running the script again, ``` sudo chmod +x <script_name>.sh```.

> For example, for the install_dependencies.sh, enter ``` sudo chmod +x install_dependencies.sh ``` into the terminal.

**1. Download the latest [release]() from our Github and extract the contents into the Home folder.**

> Note: Make sure the folder with the contents is named "Gestro". If not, rename it to "Gestro".

> Alternatively, launch a terminal and run:
> ```
> git clone https://github.com/RandomGuy-coder/Gestro.git
> ```

**2. Launch a terminal and enter the following commands into it to install the requirements:**
```sh
cd ~/Gestro && ./install_dependencies.sh
```
> Note: If CMake version is found to be too low, please follow instructions [here](https://askubuntu.com/a/829311) to update CMake. After updating CMake, make sure to close and reopen the terminal before starting from step 2 again.

**3. Enter the following commands into the terminal to run the build script.**
```sh
./build.sh
```

## Launching Gestro
Firstly, launch a terminal and enter the following commands to cd into the Gestro directory:
```sh
cd ~/Gestro/bin
```

### Main Program
Start the Gestro application by running the following commands:

```sh
./Gestro
```
**For instructions on how to use the Gestro application, please see [User Manual](https://randomguy-coder.github.io/Gestro/user_manual.html) on our [website](https://randomguy-coder.github.io/Gestro/)**.

### Unit Tests
Run the unit tests by running the following Commands:
```sh
./test_run
```

## Contributors:
ENG5220 - Real-time Embedded Systems - Team 26:
- [Tushar Anil Mittal, 2669699M](https://github.com/RandomGuy-coder)
- [Tian Jie Wong, 2702282W](https://github.com/terrsoshi)
- [Muhatasim Intisar, 2683935I](https://github.com/MuhatasimIntisar)
- [Ruoqi Sun, 2574212S](https://github.com/David2574)

## Future Enhancement:
Here are some of the planned features for this project:
* Enter other keys
* Close Window
* Change window size
* Play Next and Previous
* Zoom in and Zoom out
* Switch between applications
* Increase and Decrease Brightness

Propose for a new feature or report a bug [here](https://github.com/RandomGuy-coder/Gestro/issues)!

> Feel free to contribute to this project by forking it and submitting a pull request for the added changes.

## Social Media:
<nav>
    Follow us on:<br><br>
    <div class="sociallinks"><!--links to social pages, opened in new tabs-->
        <a href="https://www.facebook.com/GestroProject" target="_blank"><img src="assets/fb_logo.png" style="width: 40px; vertical-align: middle; margin-right: 5px;"></a>
        <a href="https://twitter.com/GestroProject" target="_blank"><img src="assets/twitter_logo.png" style="width: 40px; vertical-align: middle; margin-right: 5px;"></a>
        <a href="https://www.instagram.com/gestroproject/" target="_blank"><img src="assets/insta_logo.png" style="width: 40px; vertical-align: middle; margin-right: 5px;"></a>
        <a href="https://hackaday.io/project/184728-gestro" target="_blank"><img src="assets/hackaday_logo.png" style="width: 36px; vertical-align: middle; margin-right: 5px;"></a>
    </div>
</nav>

## Documentation
Check out [Gestro's documentation page](https://randomguy-coder.github.io/Gestro/docs/html/index.html)!

## License
Distributed under the GPL-3.0 License. See [`LICENSE`](https://github.com/RandomGuy-coder/Gestro/blob/main/LICENSE) for more information.

<!-- FOOTER -->
<br>
<small><i>Copyright &copy; 2022; ENG5220 - Real-Time-Embedded-Systems - Team 26</i></small><br>
<small><i>Distributed by a <a href="https://github.com/RandomGuy-coder/Gestro/blob/main/LICENSE" target="_blank">GNU GPL-3.0 License.</i></small></a>
