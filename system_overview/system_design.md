---
nav_order: 1
title: System Design
parent: System Overview
---

# System Design

## System Diagram

<div align="center">
    <img src="../assets/diagrams/System Diagram.png" alt="System Diagram" width="600"/>
</div>

### Webcam
The webcam captures and sends the input video feed to the Ubuntu system of the user. Although Gestro is developed using a webcam, an external camera should work the same. However, the camera should be placed in a similar setting as a webcam would be.

### Ubuntu System
The Ubuntu system is the Linux PC of the user running the Ubuntu distribution. Gestro is designed and tested to work on Ubuntu, especially Ubuntu 18.04 LTS. Receiving the input video feed from the webcam, the Ubuntu system processes the feed and detect the hand gesture being performed by the user. If the Ubuntu system identifies a command being called by the user performing a certain gestures, the corresponding command will be sent back to itself in order to execute the command.

### Display
The GUI of Gestro is displayed on the display of the Ubuntu machine. Other than the GUI, the input video feed and processed feed are also shown on the display in real-time.

## System Interaction
