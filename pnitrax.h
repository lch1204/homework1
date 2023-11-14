#ifndef PNITRAX_H
#define PNITRAX_H
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

union ufl
{
    unsigned long ul;
    float f;
    char ch;
    bool bl;
    uint16_t ut;
};

struct DataPNITrax
{
    float kHeading = 0;
    float kPitch = 0;
    float kRoll = 0;
    uint16_t  kHeadingStatus = 0;
    float kQuaternion[4];
    float kTemperature = 0;
    bool  kDistortion = 0;
    bool  kCalStatus = 0;
    float kAccelX = 0;
    float kAccelY = 0;
    float kAccelZ = 0;
    float kMagX = 0;
    float kMagY = 0;
    float kMagZ = 0;
    float kGyroX = 0;
    float kGyroY = 0;
    float kGyroZ = 0;
};

struct IdPNITrax
{
    unsigned char  kHeading = 5;
    unsigned char  kPitch = 24;
    unsigned char  kRoll = 25;
    unsigned char  kHeadingStatus = 79;
    unsigned char  kQuaternion = 77;
    unsigned char  kTemperature = 7;
    unsigned char  kDistortion = 8;
    unsigned char  kCalStatus = 9;
    unsigned char  kAccelX = 21;
    unsigned char  kAccelY = 22;
    unsigned char  kAccelZ = 23;
    unsigned char  kMagX = 27;
    unsigned char  kMagY = 28;
    unsigned char  kMagZ = 29;
    unsigned char  kGyroX = 74;
    unsigned char  kGyroY = 75;
    unsigned char  kGyroZ = 76;

};

struct Point
{
    bool kHeading = 0;
    bool kPitch = 0;
    bool kRoll = 0;
    bool kHeadingStatus = 0;
    bool kQuaternion = 0;
    bool kTemperature = 0;
    bool kDistortion = 0;
    bool kCalStatus = 0;
    bool kAccelX = 0;
    bool kAccelY = 0;
    bool kAccelZ = 0;
    bool kMagX = 0;
    bool kMagY = 0;
    bool kMagZ = 0;
    bool kGyroX = 0;
    bool kGyroY = 0;
    bool kGyroZ = 0;
};

class PNItrax
{
public:
    PNItrax();
    ufl u;
    DataPNITrax dataPNITrax;
    IdPNITrax idPNITrax;
    Point point;
    unsigned int sizeStr;
    void parser (string str);
    float float_parser (string str);
    bool bool_parser (string str);
};

#endif // PNITRAX_H
