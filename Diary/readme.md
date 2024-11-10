# Programme Introduction
`pdadd` is used to add an entity to the diary for the date. If an entity of the same date is in the diary, the existing one will be replaced. pdadd reads lines of the diary from the stdin, line by line, until a line with a single . character or the EOF character (Ctrl-D in Unix and Ctrl-Z in Windows).

`pdlist` lists all entities in the diary ordered by date. If start and end dates are provided through command line parameters, it lists entities between the start and the end only. This program lists to the stdout.

`pdshow` prints the content of the entity specified by the date to the stdout.

`pdremove` removes one entity of the date. It returns 0 on success and -1 on failure.

# directory structure
```
Diary
├── data
│   ├── diary.txt \\ store diary's content
│   └── log.txt \\ store the record of the command and the output
├── readme.md
├── src
│   ├── diary.h
│   ├── pdadd.cpp
│   ├── pdlist.cpp
│   ├── pdremove.cpp
│   └── pdshow.cpp
├── CMakeLists.txt
└── test.sh

```

# instructions
Please use `CMakelists.txt` as follows  
1. `mkdir build`  
2. `cd build`
3. Please use 
    `cmake -G "MinGW Makefiles" ..` 
instead of 
    `cmake ..`
if you find this error:
```
-- Building for: NMake Makefiles
CMake Error at CMakeLists.txt:3 (project):
  Running

   'nmake' '-?'

  failed with:

   系统找不到指定的文件。
CMake Error: CMAKE_C_COMPILER not set, after EnableLanguage
CMake Error: CMAKE_CXX_COMPILER not set, after EnableLanguage
-- Configuring incomplete, errors occurred!
```
4. `make`
5. Use `bash test.sh` to test.

