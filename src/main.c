// NOTES:
//      Sif operates on the local network.
//
//      Sif essentially makes your computer say to other computers on the network that it's sharing a file or files.
//      When another computer asks for it, your computer will send it.
//
//      output:
//          0  10.0.2.9   example.txt  4M
//          1  10.0.2.11  my_notes.md  16M
//          3  10.0.2.7   my_notes.md  9M
//
//      commands:
//          $ sif             (prints available files)
//          $ sif l/list      (prints available files)
//
//          the *d/down/download* commands download files
//          $ sif d 0
//          $ sif down example.txt
//          $ sif download 10.0.2.1-255
//
//          the *u/up/upload* commands upload files
//          $ sif u image.png message.txt
//          $ sif up example.txt
//          $ sif upload 10.0.2.1-255    (or with ipv6)

#include <stdio.h>

int main(void)
{
    return 0;
}
