### What is a socket?
Socket is a way to speak to other programs using std Unix file descriptors.

Everything in unix is a file so whatever i/o operations happen, they happen
through these file descriptors. File descriptor is an integer associated
with an open file. That file can by anything: network connection, FIFO, pipe,
terminal, etc.

To get this descriptor, we call `socket()` (a system routine/ a function
provided by the operating system itself) which returns a socket descriptor.
Now that we will be having a socket descriptor, we can communicate to it
through `send()` and `recv()`.

You can even use `read()` and `write()` as you would use in normal files but that
would still not offer as much control as `send()` and `recv()`. There are many
types of sockets but we will only deal with internet sockets.

### Internet Sockets
TODO

> Remeber that maximum text I will be putting in this file will be less than
> 78. I have to follow this for nice readability
