# Project Introduction
A program that asks you for 10 records of students. Each record consists of a name (w/o space) and scores for three courses (in integer, 1 to 5). Output a list as follows and calculate the average score (in float) of each student and each course. Output the lowest and highest score for each course.
```
no      name    score1  score2  score3  average
1       K.Weng  5       5       5       5
2       T.Dixon 4       3       2       3
3       V.Chu   3       4       5       4
4       L.Tson  4       3       4       3.66667
5       L.Lee   3       4       3       3.33333
6       I.Young 4       2       5       3.66667
7       K.Hiro  4       2       1       2.33333
8       G.Ping  4       4       4       4
9       H.Gu    2       3       4       3
10      J.Jon   5       4       3       4
        average 3.8     3.4     3.6
        min     2       2       1
        max     5       5       5
```

# directory structure
```
StudentProgram  
|   CMakeLists.txt  
|   README.md  
|  
+---data  
|       student_data.txt  // store the data of 10 students
|  
+---include  
|       student.h  
|       utils.h  
|
\---src
        main.cpp
        student.cpp // Implemented the calculation of student record printing and statistical information and data reading
        utils.cpp // Implemented universal template functions and an auxiliary function
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
5. `student_program.exe` is the final file.
6. you can use proper command to remove directory `build`.

# Attention
The student's name cannot exceed eight characters, otherwise the format is incorrect.