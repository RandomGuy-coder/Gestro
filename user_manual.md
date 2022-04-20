---
nav_order: 3
title: User Manual
---

# User Manual

| :------------------------------------------------------------------------------------------------------------------------------------------- |
| **IMPORTANT:** When using Gestro, no other body parts except for the gesture performing hand of the user should be within the yellow region so that hand gestures can be detected correctly. |
| It is recommended to use Gestro in a location with a stable camera which the background has a sufficiently different colour than your skin colour for optimum experience. |

## Getting Started
If you haven't done so, install Gestro following the instructions from our [installation guide](installation_guide).

## Launching Gestro
Firstly, launch a terminal and enter the following commands to cd into the Gestro directory:
```sh
cd ~/Gestro
```

Start the Gestro application by running the following commands:

```sh
./Gestro
```

## Main Menu

<div align="center">
    <img src="assets/screenshots/Main Menu.png" alt="Main Menu Screenshot" width="600"/>
</div>

After Gestro is successfully launched, users will be greeted with the main menu. At the main menu, there will be three buttons: _Start_, _Instructions_, and _About Us_, which starts using Gestro, shows instructions, and shows the about us page respectively.

## Main Program

<div align="center">
    <img src="assets/screenshots/Main Program.png" alt="Main Program Screenshot" width="600"/>
</div>

After clicking on the _Start_ button, the main program officially starts, displaying the main user interface to the user.

### 1. Feedback display

The first noticeable thing on the main user interface will be the feedback display where the selection of _Unprocessed Feed_ is selected by default to show the user what is being captured from their webcam without going through any processing.

To start using Gestro, the user should first press Calibrate Skin, followed by the Calibrate Background button, then select the functions that they want to use before they start performing hand gestures to call the functions. **If the _Skin Mask_ doesn't clearly show only the hand of the user, please adjust the sliders in _Calibrate Values_.**

- Calibrate Skin - Calibrates the feed to detect the skin color of the user. **_Note: The user has to first move one of their hands to cover the blue boxes shown in Unprocessed Feed before clicking Calibrate Skin_**

- Calibrate Background - Calibrates the feed to ignore the background of the user. **_Note: Before clicking Calibrate Background, the user should remove their hands from the camera feed to avoid it being detected as background._**

The instructions and description to the other buttons are:

- Skin Mask - Displays the skin mask to the user, will be available and is selected automatically after clicking Calibrate Skin.

- Detector - Displays the finger detection to the user, will be available after clicking Calibrate Skin.



### 2. Select Controls
Here users will be able to select and deselect the features that they would like to use through the corresponding checkboxes,

Here are the list of features which can be select or deselect:
* Enter Spacebar (used to control play or pause)
* Increase and Decrease Volume
* Minimise window.
* Move Window.
* Move mouse and perform mouse clicks.

### 3. Calibrate Values
There are four trackbars which can be manually adjusted to make sure the hand detection is working as intended in cases where either or both the automatic calibrate buttons does not give the best results.

### 4. Log
There is a log here which records details on the buttons that were selected on previously (Eg. Calibrate Skin, Skin Detector, etc).

## Instructions

<div align="center">
    <img src="assets/screenshots/Instructions Page.png" alt="Instructions Page Screenshot" width="600"/>
</div>

The button _Instructions_ from Main Menu shows the users instructions on how to use Gestro. Also, an image which shows the corresponding gestures for each functions is also displayed for the user to learn how to call the functions.

## About Us

<div align="center">
    <img src="assets/screenshots/About Us Page.png" alt="About Us Page Screenshot" width="600"/>
</div>

The last button _About Us_ in Main Menu brings up a page which introduces the team behind Gestro, along with the current version of Gestro.
