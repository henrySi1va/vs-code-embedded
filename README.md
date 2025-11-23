# Part 1: Escaping the Arduino IDE

## Step 0: Download the Arduino CLI (or IDE)

https://www.arduino.cc/en/software/

https://github.com/arduino/arduino-cli

https://arduino.github.io/arduino-cli/1.3/getting-started/

## Step 1: Download VS Code

## Step 2: Create Project Directory

Download this repo.

## Step 3: Initialize Config File

All project settings are located in a configuration file.
Say something about using the terminal in VS Code.
Go ahead and run this command `arduino-cli config init --dest-dir .`
We need to add that `--dest-dir` flag so that the config file is created in the project directory.

I will already have this in the repo with all the necessary configuration options.

## Step 4: Create Sketch

Run `arduino-cli sketch new Appliction`.
This just creates a new directory with an ino file of the same name.
I do not think it does anything special.

I will just have the project files already made and explain the structure.
TODO: See if the directory and .ino file need to be the same name.

## Step 5: Install Board

First run this command to download the default boards:

`arduino-cli core update-index`

Connect the board to your PC and see if it comes up in the port list:

`arduino-cli board list`

If the Board Name is unknown, you will have to find and install the board core.
You can search using the board's name with the following command:

`arduino-cli board listall BOARD_NAME_HERE`

If you find the board in the list, you can install it using the FQBN with the command:

`arduino-cli core install FQBN_HERE`

Note that the FQBN for the install command should include one `:` with the first two words in the FQBN.
For example, if the search for your board says the FQBN is `arduino:esp32:node-mcu`.
The install command should only contain `arduino:esp32`.

If the board name still shows up as Unkown for `arduino-cli board list`, it is okay.

TODO: Add note for 3rd party boards in the config file.

## Step 6: Compile and Upload

You can compile the code by running the command:

`arduino-cli compile --fqbn BOARD_FQBN_HERE PROJECT_NAME_HERE`

arduino-cli compile --config-file .\arduino-cli.yaml --fqbn esp32:esp32:nodemcu-32s app

You can then upload the code by running:

`arduino-cli upload -p PORT_HERE --fqbn BOARD_FQBN_HERE PROJECT_NAME_HERE`

arduino-cli upload --config-file .\arduino-cli.yaml --fqbn esp32:esp32:nodemcu-32s -p COM8 app

If no errors are thrown, the upload should be a success.

THINGS TO PUT IN CONFIG FILES:
1. Board FQBN
2. Port
3. Project Name

## Step 7: Using Libraries

Libraries and manually installed platforms are placed in the `user` directory.

I recommend searching libraries using [Arduino's online library search tool](https://docs.arduino.cc/libraries/) instead of the command line.

Once you find the library you want, install it using:

`arduino-cli lib install LIBRARY_NAME_HERE`
