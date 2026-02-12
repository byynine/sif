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
//
// When calling $ sif up ... the file gets cached and on request from a different computer a tcp connection
// will be established and the file will be transferred.
//
// A simple scan request can also be made, like a "anyone got files?", the computer that's uploaded will be awaiting
// for such a request and reply accordingly.

#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

// Command definitions.
#define CMD_UPLOAD0 "u"
#define CMD_UPLOAD1 "up"
#define CMD_UPLOAD2 "upload"

typedef struct {
    size_t idx;
    char filepath[PATH_MAX];
} upload_metadata;

int main(int argc, char **argv)
{
    if (argc != 3) { printf("error: invalid argument count\n"); return 1; }

    // Upload command.
    if (strcmp(argv[1], CMD_UPLOAD0) == 0 ||
        strcmp(argv[1], CMD_UPLOAD1) == 0 ||
        strcmp(argv[1], CMD_UPLOAD2) == 0)
    {
        if (access(argv[2], F_OK) == 0)
        {
            char fullpath[PATH_MAX];
            if (realpath(argv[2], fullpath) != NULL)
            {
                printf("full path: %s\n", fullpath);
            }
            else
            {
                printf("error: couldn't get full path\n");
                return 1;
            }
        }
        else
        {
            printf("error: file %s does not exist\n", argv[2]);
            return 1;
        }
    }
    else
    {
        printf("error: invalid command\n");
        return 1;
    }


    return 0;
}
