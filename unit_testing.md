---
nav_order: 4
title: Unit Testing
---

# Unit Testing

Code that is covered by unit tests is more dependable than code that is not. That being said, unit tests were created to allow us to validate the functionality of each function with ease. This is so that if the programme didn't perform as planned, it would be simple to pinpoint the source of the problem rather than having to sift through a large codebase. Although unit testing may appear to be a time-consuming process initially, but the benefits are evident in the long term.

 Unit tests for Gestro were built using the Google Unit Test Framework, which are all located in the **tests** directory.

In order to run the unit tests, first install Gestro following the instructions from our [installation guide](installation_guide). Then, run the following command in a terminal:
```sh
cd ~/Gestro && sudo make test
```