
# MNXB01-ProjectNPT
MNXB01 Project by Nikolei, Pinar, and Tilde

## Project Directory

- `project.cpp`       : This is our main source code file
- `rootlogon.C`       : Start ROOT in the project directory, ROOT will execute and run `project()` method from `project.cpp`
- `clean_datafile.sh` : Processes raw data file by removing unwanted text lines, unexpected data and formating of data, ready to be used in the program
- `README.md`
- `ChangeLog`
- `License`

## Directories within Project
- `doc`     : contains documentation files
- `in`      : contains input files
- `include` : contains header files
- `out`     : contains output files
- `src`     : contains source code files

## How to execute
(1) Start `ROOT` and wait for ROOT interpreter to complete compilation steps
(2) Call `project()` method

## Clarification regarding the input datafile
Our code works well with the selected `Uppsala datafile` and produces the expected results. It is not recommended to test with any other datafile than Uppsala, as the code will fail to execute. For this reason, `the path to the Uppsala datafile` is hardcoded in our source code.


