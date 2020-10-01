## Dependencies

This project requires:

1. C++17 or newer
2. Boost >= 1.72
3. CMake >= 3.12
4. NCurses (only tested with 6.1)

## Building with CMake

1. Create a new directory for building.

        mkdir build

2. Change into the new directory.

        cd networkbuild

3. Run CMake with the path to the source.

        cmake ../Social Gaming/

4. Run make inside the build directory:

        make

## Running the Chat Server

5. Run the chat server

    bin/chatserver 4000 ../web-socket-networking/webchat.html

## Visiting the Chat Server

6. Visit the chat server by visiting the following link in a web browser
	
	http://localhost:4000/index.html

6.5 It is also possible to visit the chat client by running

    bin/chatclient localhost 4000


