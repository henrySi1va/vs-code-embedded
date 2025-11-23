# Escaping the Arduino IDE

## Introduction

The Arduino IDE is great for anyone starting out in embedded systems.
However, many people will quickly find its editor experience to be lackluster and may desire features present in the wildly popular VS Code.

VS Code is a modern, customizable code editor that can be extended into a full-featured development environment for a wide range of software applications.
In fact, it can even be used for embedded systems and replace the clunky, eclipse-based editors many engineers have faced in the past.
VS Code has AI Assistance through Copilot right in the editor which can be very helpful to those starting their journey in embedded systems.

This guide serves as a first step in going deeper into the world of embedded systems by leaving the Arduino IDE and getting familiar with Arduino's command line interface, the `arduino-cli`.
If you have never used the terminal before, don't worry.
There are only a few terminal commands to run in this guide and it will be a great way to get your feet wet.

Please note that this guide was written using a setup on Windows 11.
This guide can be followed on Linux or Mac without much trouble, but you may run into a few obstacles that should be easily overcome (hopefully).

## Step 1: Download the Arduino CLI (or IDE)

Go to [Arduino's downloads](https://www.arduino.cc/en/software/) page to get the installer.
If you already have the Arduino IDE downloaded, you already have the CLI installed.

If you would like to familiarize yourself with the CLI, view the CLI's [Getting Started](https://arduino.github.io/arduino-cli/1.3/getting-started/) page.

## Step 2: Download VS Code

If you do not have VS Code already downloaded, get it [here](https://code.visualstudio.com/download).

## Step 3: Clone this Repo.

Clone or download this repo.

In VS Code, you can press `Ctrl + Shift + P` to access the Command Palette and type in `Git: Clone` to clone the repo.
Just copy and paste the repo's URL when prompted.
Remember to check out the `p1-escaping-arduino-ide` branch.

VS Code has a very easy to use `Source Control` tab that can be accessed by clicking the branch icon the left side of the screen.

You can use this repo as a template for any future projects.

Upon opening the repo, you may recommended to install certain extension by VS Code.
Please install these as they are required for the project to work.
Only two extensions are required:

1. C/C++ for auto-complete and error matching
2. Serial Monitor for viewing console output

## Step 4: Find or Install Your Board's Core Package

The `arduino-cli` must know which board you are using.
In the Arduino IDE, this is done using the Boards Manager.
The CLI uses a unique identifier for each board called the FQBN.

You can search for your board's FQBN with the following command:

```
arduino-cli board listall BOARD_NAME
```

If you have your board plugged in, you may be able to find the FQBN using:

```
arduino-cli board list
```

This command will output the board name, FQBN, and port.
Note the port as it will be used in the next step.
If your board name shows up as `Unknown`, you must install your board's core package.

First, find your board's FQBN using the first command in this step.
If you are having trouble finding it, you can run `arduino-cli board listall` to display all the boards supported by the `arduino-cli` by default.
If your board is not in the list, your board requires a 3rd part core package.
Please see [these instructions](https://arduino.github.io/arduino-cli/1.3/getting-started/#adding-3rd-party-cores) on adding the core package URL to the `arduino-cli.yaml` file in this project.

Once you have your board's FQBN, you can install the necessary core package using the first two words of the FQBN.
For example, the core package for `esp32:esp32:nodemcu-32s` is `esp32:esp32`.
Run the following command to install the core package:

```
arduino-cli core install CORE_PACKAGE_NAME
```

Once installed, you can check if the output of `arduino-cli board list` is any different.
There is a chance that your board still shows up as unknown, but as long as you have the correct core package installed compilation and uploading should work.

## Step 5: Update The VS Code Project Settings File

VS Code allows for project specific configuration files to be placed in the `.vscode` directory.
There are a few settings that must be updated so that the `arduino-cli` can compile and upload your code.
Open the `settings.json` file in the `.vscode` directory of this project and find the settings under the `User Configuration` comment.

`arduino.project_name` is the name of project the `arduino-cli` uses too compile the code.
It must match the directory name and file name of the `.ino` file used for the project.
By default, it is set to `app`.
If you want to change the project name, you must also change the `app` directory and `app.ino` file names accordingly or else your code will not compile.

`arduino.fqbn` is the identification string for your board.
Please change it to the one you found in the previous step.

`arduino.port` is the port your board is connected to on your computer.
The port is displayed when running `arduino-cli board list`.
Note that this port stays the same most of the time, but may change if you plug your board in when other devices are plugged in to your computer.
Just update the setting in this file if the port every changes.

## Step 6: Compile and Upload the Code

The code for this project is located in `app/app.ino`.
This example uses a heartbeat library to blink the onboard LED in a heartbeat pattern and prints a message to the console from a custom library.

The `arduino-cli` also allows for downloading libraries similar to the Arduino IDE.
You can check out [this section of the Getting Started guide](https://arduino.github.io/arduino-cli/1.3/getting-started/#add-libraries) on how to do that.
I recommend using [Arduino's online library browser](https://docs.arduino.cc/libraries/) to look for libraries instead of using the CLI.

Any installed libraries will be placed in the `user/libraries` directory in this project.
In addition, any libraries you would like to make yourself can be placed in the same directory.
The `MyLibrary` library is an example I made that demonstrates how to do this.

Running the `arduino-cli`'s compile and upload commands is done using [VS Code's terminal tasks](https://code.visualstudio.com/docs/debugtest/tasks).
These tasks make it easy to run frequently used commands.
This project defines `arduino-cli compile` as the build task which can be run by pressing `Ctrl + Shift + B`.
The upload task can be accessed by opening the command palette and typing `Tasks: Run Task` and selecting `Upload Sketch`.

Any errors output by the compile or upload task will be highlighted in the editor.

## Step 7: Viewing Console Output

This project prints a message to console every second.
You can view the message by opening the Serial Monitor tab at the bottom of your screen.
Make sure to set the baud rate to `9600` to match the baud rate set in `app.ino`.

Press the `Start Monitoring` button to being reading data from your board.
Press `Stop Monitoring` to end the session.
Note that this may cause your board to halt or reset.

The serial monitor can also be used to send data, but I have not tried that yet.

## Conclusion

Now you can use VS Code to replace most of the functionality of the Arduino IDE.
You get the added benefit of a better, customizable editor experience along with the ability to use AI right in the editor with Copilot.
One critical feature that this guide did not cover is debugging, but I can cover that next.

Using VS Code for embedded systems does not stop with Arduino.
VS Code can be used to create a full development environment for almost any toolchain with containerization, static analysis, language servers (auto-completion, error checking, etc.), testing, and much more.
The concepts used for a full VS Code development environment also extend very well into automated testing in the cloud and hardware-in-the-loop testing.
