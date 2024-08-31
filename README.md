# TKMap

An educational product designed to help people with visual impairments learn Karnaugh maps.

## Getting Started

To compile the project, you'll need to follow these steps:

1. **Download the Arduino CLI:**
   - Get the latest release from the official repository: [Arduino CLI Releases](https://github.com/arduino/arduino-cli)
   - For example, you can download `arduino-cli_1.0.4_Windows_64bit.zip`.
   - Extract the `.exe` file and place it in a directory. (e.g., `C:\Program Files\Arduino`)

2. **Install the Arduino Extension for VS Code:**
   - Download the extension: `vscode-arduino.vscode-arduino-community`
   - Update the `arduino.path` setting in VS Code to point to the folder where you placed the `arduino-cli.exe`.
   - Reload your VScode.

3. **Compile the Project:**
   - You will now see a "Verify" button at the top right corner of your VS Code window. Use it to compile your project.
   - The compilation will generate a file named `main.ino.hex` inside the `build` folder.
   - This `.hex` file can be used on Proteus for simulation.