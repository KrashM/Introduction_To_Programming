# Installation guide for VS Code on Windows

## 1) VS Code [Download](https://code.visualstudio.com/download)

## 2) Add the [C/C++ extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) for code formatting and intellisense

press **Ctrl + Shift + x** in VSCode to open the extension tab and download the extensions from there

**Shortcut for formatting page: Ctrl + Alt + F**

[optional]: enable auto formatting  - Open the Settings tab (Ctrl + ,) and search for `format on type` and check the option

## 3) Set up [GCC](https://winlibs.com/)

**!!!Important!!!**
Download an UCRT version of GCC.

1. You can download a Win32 or Win64 in respect to your operating system. Also you should probably download the version without LLVM/Clang/LLD/LLDB.

2. After you have downloaded the zip file, you can extract the content. It should contain a single folder named mingw[32/64].

3. Place that folder wherever you choose in your system.

4. Then you should copy the full path to the folder for later.

## 4) Set up environmental variable(For Windows users)
1. Open your search tab
2. Search for `edit environment variables for your account`
3. Click on `PATH` in the user variables tab and then `Edit`
![](http://i.imgur.com/gHPOIh5.png)
4. Add a new path by clicking on `New`
5. Paste the path which we copied in the last step and add *'\bin'* at the end
6. You are all set!

## 5) [Optional] If you don't want to run programs via terminal

Install [the Code Runner extension](https://marketplace.visualstudio.com/items?itemName=formulahendry.code-runner).

Open the Settings tab (Ctrl + ,).
Open the Code Runner settings.json file:
![](https://i.ibb.co/1J1H25p/1.png)
add these lines in order to compile with the button and save all files before run:
```json
"code-runner.executorMap": {
        "cpp": "g++ $fileName -o $fileNameWithoutExt && $fileNameWithoutExt"
    },
"code-runner.saveAllFilesBeforeRun": true
```

Now you can compile with the triangle run button!
![](https://i.ibb.co/xJJdLTH/2.png)

You're ready to go :)

## Commands for compiling via terminal

1. Compiling
    - g++ "filename" - compiles the code and creates executable with name `a`
    - g++ "filename" -o "exefilename" - compiles the code and creates executable with name `exefilename`
        - We need to compile our program every time we do changes to it!!!

2. Running the program
    - "exefilename" - runs the exe compiled from the previous command

## 6) Setting up a debugger

1. Open the debugger window on the left navigation bar.
2. Click on **create a launch.json file**.
3. After opening the launch.json file, click on the **Add configuration...** button in the bottom right.
4. Search for C/C++: (gdb) launch. This will generate a template for us to fill.
5. On program add the following: "\${fileDirname}/${fileBasenameNoExtension}.exe".
6. Then on miDebuggerPath add the path to yout gdb.exe (it should be contained in the same folder as g++.exe)

Your launch.json file should look something like this:
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/Program Files/mingw64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ]
        }
    ]
}
```

Now we have the following problem. If we want to debug a program we have to compile it first (e.g. make an exe before debugging). We have two options:

1. Leave it at this and just run the program once before debugging it.
2. Set up additional tasks that will compile the program for us before the debugger is launched.

If you want to continue with the second option follow the instructions below.

1. Create another file named **tasks.json** in the same folder as **launch.json**.
2. Paste the following code inside of **tasks.json**. And specify the path to your compiler.
```json
{
    "tasks": [
        {
            "type": "cppbuild",
            "label": "C/C++: Build file",
            "command": "path/to/mingw64/bin/g++.exe",
            "args": [
                "-fdiagnostics-color=always",
                "-g",
                "${file}",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        }
    ],
    "version": "2.0.0"
}
```
3. In your **launch.json** file we will add a prelaunch task right after your **setupCommands**:

```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "C:/Program Files/mingw64/bin/gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "C/C++: Build file"
        }
    ]
}
```

### You are all set! 