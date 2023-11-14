#include "pnitrax.h"
#include "sstream"

PNItrax::PNItrax()
{

}

void PNItrax::parser(string str)
{
    cout << str << endl;
    sizeStr = str.size();
    cout << "sizeStr: " << sizeStr << endl;
    while (str.size() >1)
    {
        stringstream stream;
//        cout << str.substr(0, 2) << endl;
//        int header = stoi(str.substr(0, 2));
//        stream <<header;
//        stream >> hex >>header;
//        cout <<"hader: " << header <<endl;
        int header;
        stream <<str.substr(0, 2);
        stream >> hex >>header;
        cout <<"hader: " << header <<endl;
        if (header == idPNITrax.kHeading)
        {
            cout << "Парсинг kHeading "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kHeading = f;
            str.erase(0,10);
            point.kHeading = 1;
        }
        else if (header == idPNITrax.kPitch)
        {
            cout << "Парсинг kPitch "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kPitch = f;
            str.erase(0,10);
            point.kPitch = 1;
        }
        else if (header == idPNITrax.kRoll)
        {
            cout << "Парсинг kRoll "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kRoll = f;
            str.erase(0,10);
            point.kRoll = 1;
        }
        else if (header == idPNITrax.kHeadingStatus)
        {
            //
            cout << "Парсинг kHeadingStatus "<< endl;
            cout << "str.substr(2,2) " << str.substr(2,2) << endl;
            stringstream ss(str.substr(2,2));
            ss >> hex >> u.ut;
            char ch = static_cast<char>(u.ut);
            cout << "kHeadingStatus u.ch: " << u.ut << endl;
            dataPNITrax.kHeadingStatus = u.ut;
            str.erase(0, 4);
            point.kHeadingStatus = 1;
        }
        else if (header == idPNITrax.kQuaternion)
        {
            cout << "Парсинг kQuaternion "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kQuaternion[0] = f;
            float g = float_parser(str.substr(10,8));
            dataPNITrax.kQuaternion[1] = g;
            float h = float_parser(str.substr(18,8));
            dataPNITrax.kQuaternion[2] = h;
            float j = float_parser(str.substr(26,8));
            dataPNITrax.kQuaternion[3] = j;
            str.erase(0,34);
            point.kQuaternion = 1;
        }
        else if (header == idPNITrax.kTemperature)
        {
            cout << "Парсинг kTemperature "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kTemperature = f;
            str.erase(0,10);
            point.kTemperature = 1;
        }
        else if (header == idPNITrax.kDistortion)
        {
            cout << "Парсинг kDistortion "<< endl;
            cout << "str.substr(2,2) " << str.substr(2,2) << endl;
            bool bl = bool_parser(str.substr(2,2));
            cout << "dataPNITrax.kTemperature: " << bl << endl;
            dataPNITrax.kTemperature = bl;
            str.erase(0,4);
            point.kDistortion = 1;
        }
        else if (header == idPNITrax.kCalStatus)
        {
            cout << "Парсинг kCalStatus "<< endl;
            cout << "str.substr(2,2) " << str.substr(2,2) << endl;
            bool bl = bool_parser(str.substr(2,2));
            cout << "dataPNITrax.kCalStatus: " << bl << endl;
            dataPNITrax.kCalStatus = bl;
            str.erase(0,4);
            point.kCalStatus =1;
        }
        else if (header == idPNITrax.kAccelX)
        {
            cout << "Парсинг kAccelX "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kAccelX = f;
            str.erase(0,10);
            point.kAccelX =1;
        }
        else if (header == idPNITrax.kAccelY)
        {
            cout << "Парсинг kAccelY "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kAccelY = f;
            str.erase(0,10);
            point.kAccelY = 1;
        }
        else if (header == idPNITrax.kAccelZ)
        {
            cout << "Парсинг kAccelZ "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kAccelZ = f;
            str.erase(0,10);
            point.kAccelZ = 1;
        }
        else if (header == idPNITrax.kMagX)
        {
            cout << "Парсинг kMagX "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kMagX = f;
            str.erase(0,10);
            point.kMagX =1;
        }
        else if (header == idPNITrax.kMagY)
        {
            cout << "Парсинг kMagY "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kMagY = f;
            str.erase(0,10);
            point.kMagY = 1;
        }
        else if (header == idPNITrax.kMagZ)
        {
            cout << "Парсинг kMagZ "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kMagZ = f;
            str.erase(0,10);
            point.kMagZ =1;
        }
        else if (header == idPNITrax.kGyroX)
        {
            cout << "Парсинг kGyroX "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kGyroX = f;
            str.erase(0,10);
            point.kGyroX = 1;
        }
        else if (header == idPNITrax.kGyroY)
        {
            cout << "Парсинг kGyroY "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kGyroY = f;
            str.erase(0,10);
            point.kGyroY = 1;
        }
        else if (header == idPNITrax.kGyroZ)
        {
            cout << "Парсинг kGyroZ "<< endl;
            cout << "str.substr(2,8) " << str.substr(2,8) << endl;
            float f = float_parser(str.substr(2,8));
            dataPNITrax.kGyroZ = f;
            str.erase(0,10);
            point.kGyroZ = 1;
        }
        else {
            cout << "Такого хедера нет" << endl;
            str.erase(0,1);
        }
    }
    //вывод всей посылки, которая была распарсена
    if (point.kHeading == 1) cout << "kHeading: " << dataPNITrax.kHeading << endl;
    if (point.kPitch == 1) cout << "kPitch: " << dataPNITrax.kPitch << endl;
    if (point.kRoll == 1) cout << "kRoll: " << dataPNITrax.kRoll << endl;
    if (point.kHeadingStatus == 1) cout << "kHeadingStatus: " << dataPNITrax.kHeadingStatus << endl;
    if (point.kQuaternion == 1)
    {
        cout << "kQuaternion[0]: " << dataPNITrax.kQuaternion[0] << endl;
        cout << "kQuaternion[1]: " << dataPNITrax.kQuaternion[1] << endl;
        cout << "kQuaternion[2]: " << dataPNITrax.kQuaternion[2] << endl;
        cout << "kQuaternion[3]: " << dataPNITrax.kQuaternion[3] << endl;
    }
    if (point.kTemperature == 1) cout << "kTemperature: " << dataPNITrax.kTemperature << endl;
    if (point.kDistortion == 1)
    {
        if (dataPNITrax.kDistortion == 1) cout << "kDistortion: " << "true"<< endl;
        else cout << "kDistortion: " << "folse"<< endl;
    }
    if (point.kCalStatus == 1)
    {
        if (dataPNITrax.kCalStatus == 1) cout << "kCalStatus: " << "true"<< endl;
        else cout << "kCalStatus: " << "folse"<< endl;
    }
    if (point.kAccelX == 1) cout << "kAccelX: " << dataPNITrax.kAccelX << endl;
    if (point.kAccelY == 1) cout << "kAccelY: " << dataPNITrax.kAccelY << endl;
    if (point.kAccelZ == 1) cout << "kAccelZ: " << dataPNITrax.kAccelZ << endl;
    if (point.kMagX == 1) cout << "kMagX: " << dataPNITrax.kMagX << endl;
    if (point.kMagY == 1) cout << "kMagY: " << dataPNITrax.kMagY << endl;
    if (point.kMagZ == 1) cout << "kMagZ: " << dataPNITrax.kMagZ << endl;
    if (point.kGyroX == 1) cout << "kGyroX: " << dataPNITrax.kGyroX << endl;
    if (point.kGyroY == 1) cout << "kGyroY: " << dataPNITrax.kGyroY << endl;
    if (point.kGyroZ == 1) cout << "kGyroZ: " << dataPNITrax.kGyroZ << endl;
    point.kHeading = 0;
    point.kPitch = 0;
    point.kRoll = 0;
    point.kHeadingStatus = 0;
    point.kQuaternion = 0;
    point.kTemperature = 0;
    point.kDistortion = 0;
    point.kCalStatus = 0;
    point.kAccelX = 0;
    point.kAccelY = 0;
    point.kAccelZ = 0;
    point.kMagX = 0;
    point.kMagY = 0;
    point.kMagZ = 0;
    point.kGyroX = 0;
    point.kGyroY = 0;
    point.kGyroZ = 0;
}

float PNItrax::float_parser(string str)
{
    stringstream ss(str);
    ss >> hex >> u.ul;
    float f = u.f;
    cout << f << endl;
    return f;
}

bool PNItrax::bool_parser(string str)
{
    stringstream ss(str);
    ss >> hex >> u.ut;
    u.bl = static_cast<bool>(u.ut);
    cout << u.bl << endl;
    return u.bl;
}
