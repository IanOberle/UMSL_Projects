#ifndef OBJECT_H
#define OBJECT_H

typedef struct
{
    char first[16];
    char middle[3];
    char last[16];
    int id;
    float bal;
}Account;

Account accounts[50];

#endif
