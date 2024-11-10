# Project Introduction
1.Write a CLI program that reads scoring records of students and prints out a summary sheet in the same format as the last homework, Students I.

The user can input an arbitrary number of students. Each student can take an arbitrary number of courses. Each record consists of the course id/name and the score the student got. Please note that a student usually won't choose every available course.

2.Evaluation standard

C++ code quality (clean, compact, and reasonable)

Comments quality

3.Required Files

Please prepare a zip package including the following items：

The source code

A text file containing your test data


# directory structure
```
StudentProgram  
|   CMakeLists.txt  
|   README.md  
|  
+---images
|       data.png // the image of test result
|
+---data  
|       student_data.txt  // store the data of students
|  
+---include  
|       student.h  
|       utils.h  
|
\---src
        main.cpp
        student.cpp // Implemented the calculation of student record printing and statistical information and data reading
        utils.cpp // Implemented an auxiliary function
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
5. `student_program.exe` is the final file. you can choose to use the test data or input the data manually.
6. you can use proper command to remove directory `build`.

# Attention
If a student doesn't attend the course, the course's score will be shown as `-`.

The program can adjust the output format according to the length of the course name and the student name. The default length is 8 characters. 

The test result of the data `student_data.txt` is as follows.
```
no      name                     Art     Biology Chemistry English History Math    Music   PE      Philosophy Physics Science average 
1       Alice                    -       -       -         4       3       4       -       -       -          -       5       4
2       Isabella Marie Johnson   3       -       -         5       4       5       -       -       -          -       4       4.2
3       Bob                      -       -       -         4       5       4       -       -       -          -       3       4
4       Charlie                  5       -       -         2       3       3       -       -       -          -       2       3       
5       Diana                    -       -       -         -       4       4       5       3       -          -       5       4.2
6       Eva                      -       4       4         -       -       5       -       -       -          3       -       4
7       Alexander Jonathan Smith -       -       -         4       3       4       -       -       2          -       5       3.6
        average                  4       4       4         3.8     3.66667 4.14286 5       3       2          3       4
        min                      3       4       4         2       3       3       5       3       2          3       2
        max                      5       4       4         5       5       5       5       3       2          3       5
```
![alt text](.\images\data.png)