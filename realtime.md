---
nav_order: 7
title: Realtime Responsiveness Analysis
---

# Realtime Responsiveness Analysis

## Relevance to System
The design of the system is to be able to control the following aspects of an Ubuntu system:
-	Mouse movement and clicking action
-	Keyboard Inputs sent to focused windows
-	Control system features such as volume


 For all of these interactions, the user will desire very low latency or they may encounter a feeling that the system is behaving sluggishly and thus they would choose to return to using mouse and keyboard.

## Mouse Input
The mouse is the most common input device that people use when interacting with their computer. The latency of an average mouse can range from 1ms to 20ms. Using the tick counter in OpenCV, we were able to calculate the time between the user making the gesture for mouse movement and then the mouse completing desired action is 8ms.

Accuracy of analysis may have been improved through the use of high-speed camera equipment to detect to a much greater level of accuracy exactly when user has shifted to the desired gesture and mouse has begun to move, or click. However, without access to such equipment, the accuracy of testing is limited.

## Keyboard Input
When using the keyboard to send commands to the focused window, there will be an inherent lag due to the transmission speed of the USB connection (fully wired connections though rare, would have less latency). However, the delay is nearly imperceptible to the average person.

For Gestro, the average time to detect a change in finger count is 5ms. However, upon detecting the change in gesture the transmission of the command to the display is near instantaneous.
