/* osapi.c */
#define Library
#include "osapi.h"

private fd fds[256];

private bool isopen(fd file) {
    signed int posixfd;
    struct stat _;

    if (file < 2)
        return false;

    posixfd = getposixfd(file);
    if (posixfd == -1)
        return false;

    if (fstat(posixfd, &_) == -1)
        return false;

    return true;

}

public bool load(fd file, int8 c) {
    if (file > 1) // not stdin or stdout
        if (!isopen(file))
            reterr(ErrBadFD);
    return false;
}

public int8 store(fd file) {
    return 0;
}