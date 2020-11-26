//
// Created by LaithB on 11/26/2020.
//

#include <iostream>
#include <fstream>
using namespace std;

void fileStreams() {
    // write to file
    fstream outputStream;
    outputStream.open("write.txt", fstream::out);


    outputStream << "Laith Budairi\n22";
    outputStream.close();

    // read from file
    fstream inputStream;
    inputStream.open("write.txt", fstream::in);
    string data;

    cout << "data from file: \n";

    while(!inputStream.eof()) {
        getline(inputStream, data);
        cout << data << "\n\n";
    }

    inputStream.close();

    // file pointer - write;
    fstream p_outputStream;
    p_outputStream.open("write.txt", fstream::in);

    p_outputStream.seekg(5);

    string d;

    p_outputStream >> d;
    cout << d;

}