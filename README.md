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

* Client blocks when making a call.
* Getting printout requires SIGINT on client-side.
    * when doing call again, getting error `nc: bind failed: Address already in use`
* I am getting the number of bytes, but not the actual bytes themselves into connection class. I don't know how to get around this yet.
* How to get server address. Options include:
    * asio library may have something
    * client input (so if they're connection from outside, show ip address they used)
* Add deconstructors
* Allow connections through ipv6

###Room for improvement
* use iterators in src/handler to break apart vector<char> instead of hardcoding specific array items
* add lengths of TLV components in their respective classes, so that they can change
    * have TLVmessage refer to said values to determine the delimitation of where one section starts and another ends, that way each of those classes are responsible for their own message sections.