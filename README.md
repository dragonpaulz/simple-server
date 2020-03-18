#TCP Server
==========

Takes a Type-length-value message.

##Requirements
------------
Uses bazel for package management, building, and testing. makefile contains up-to-date commands for building, running, and testing application.

##Command-line arguments
---
`--port` required, specifies a port number.

##Left to do
---
src/setup/setup_helper/connection.cpp has notes on what I want to do, but need to actually do it.

* Once a client connects, interpret the bytes to vector<char> so that TLVmessage can be created, and print to screen.
* How to get server address. Options include:
    * asio library may have something
    * client input (so if they're connection from outside, show ip address they used)
* Add deconstructors
* Allow connections through ipv6

###Room for improvement
* use iterators in src/handler to break apart vector<char> instead of hardcoding specific array items
* add lengths of TLV components in their respective classes, so that they can change
    * have TLVmessage refer to said values to determine the delimitation of where one section starts and another ends, that way each of those classes are responsible for their own message sections.