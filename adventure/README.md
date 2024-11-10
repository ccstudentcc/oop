# Project Introduction
The Story

Adventure is a CLI game. The player has to explore a castle, which consists of several levels and many rooms. The task of the player is to find the room where the princess is prisoned and take her to leave!

There are many types of rooms, and each type has distinct exits. Note that there is a monster in one of the rooms, whose exact location is unknown. But once the player meets the monster, the game is over.

The program always shows information about the room into which the player enters: the name of the room, how many exits are there, and the names of all the exits. For example, the player is in the 
lobby of the castle when the game starts, and the program outputs:
```
Welcome to the lobby. There are 3 exits: east, west and up.
Enter your command:
```
Then the player can input the command go followed by the name of the exit that he/she would like to pass through, e.g.,
```
go east
```
Consequently, the player goes into the room to the east. The program gives information about that room, like what is shown above for the lobby. This process repeats.

During this process, if the player enters a room with a monster, the program shows a message, and the game is over. Likewise, once the player enters the secret room where the princess is, the program shows 
the conversation between the role and the princess. After that, she is ready to leave with the player. Then 
the player has to find their way out. The only way to leave the castle is via the lobby.


# directory structure
```
adventure  
|   CMakeLists.txt  
|   README.md  
|   
+---googletest // necessary doc for ctest
|       
|
+---include 
|       init.h 
|       room.h  
|       player.h  
|
+---src
|       adventure.cpp // main 
|       room.cpp // Implemented the class room and its interface such as description and exits
|       player.cpp // Implemented the class player and its interface like status
|       init.cpp // Implemented the initialization of the game
|
+---test
|       test_adventure.cpp // test code for testing possible cases
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
5. `adventure.exe` is the final file. `test_adventure.exe` is the test file. Use `ctest --verbose` to run the test. 
6. you can use proper command to remove directory `build`.

# Attention
You can modify the number of the rooms and rooms'structure  in `void initializeGame(...)` of `adventure.cpp`.

The princess and the monster are randomly set in the rooms except the lobby.

The test suite covers key gameplay mechanics, including room connections, player movement, interactions with the princess and monster, and win/loss conditions:

1. **Room Exits Test**: Verifies correct connections between rooms (lobby to hall and back).
2. **Princess's Room And Monster's Room Test**: Confirms the princess and the monster can be correctly placed in the rooms.
3. **Winning Condition Test**: Simulates finding the princess and returning to the lobby to win.
4. **Player Movement Test**: Tests valid room movement between the lobby and hall.
5. **Invalid Move Test**: Ensures invalid moves (e.g., north from the lobby) leave the player in the same room.
6.  **Finding Princess Again Test**: Verifies that the player still recognizes the princess when revisiting the same room.
7.  **Monster Encounter Test**: Checks if encountering a monster leads to game termination.