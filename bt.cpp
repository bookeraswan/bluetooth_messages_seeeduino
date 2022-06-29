#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <bluetooth/bluetooth.h>
#include <bluetooth/rfcomm.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;


string eeee(int socket){
    string data;
    char buf[1];
    while(buf[0] != ']'){
        recv(socket, buf, 1, 0);
        data += buf[0];
    }
    return data;
}


void displayImage(string imageData){
    for(int i = 0; i < int(imageData.size()); i++){
        if(imageData[i] == '1'){
            cout << "#";
        }
        else{
            cout << " ";
        }

        if(i%128 == 0){
            cout << "\n";
        }
    }
}

vector<int> imageStrToVec(string strImage){
    vector<int> vecImage;
    string currentNum;
    for(int i = 0; i < (int)strImage.size(); i++){
        if(strImage[i] == '[') continue;
        else if(strImage[i] == ',' || strImage[i] == ']'){
            vecImage.push_back(stoi(currentNum));
            currentNum = "";
        }
        else{
            currentNum += strImage[i];
        }
    }
    return vecImage;
}

string decodeImage(vector<int> encodedImage){
    string decodedImage;
    int imageSize = 0;
    for(int i = 0; i < (int)encodedImage.size(); i+=2){
        for(int j = 0; j < encodedImage[i]; j++){
            if(imageSize%128 == 0){
                decodedImage += "\n";
            }
            if(encodedImage[i+1] == 1) decodedImage += "▅";
            else decodedImage += " ";

            imageSize++;
        }
    }
    for(int i = 0; i < 6144-imageSize; i++){
        if(encodedImage[encodedImage.size()-1] == 1) decodedImage += "▅";
        else decodedImage += " ";
    }
    return decodedImage;
}

int main(){
    struct sockaddr_rc addr = { 0 };
    int s, status;
    char *dest =  (char*)"98:D3:31:F7:3B:D0"; //  HC05 = "98:D3:31:F7:3B:D0"

    s = socket(AF_BLUETOOTH, SOCK_STREAM, BTPROTO_RFCOMM);

    addr.rc_family = AF_BLUETOOTH;
    addr.rc_channel = (uint8_t) 1;
    str2ba( dest, &addr.rc_bdaddr );
    int getImage = 0;
    int numPixels = 0;
    status = connect(s, (struct sockaddr *)&addr, sizeof(addr));
    if( status < 0 ) perror("uh oh");
    while(1){
        char buf[1];
        recv(s, buf, 1, 0);
        // if(getImage == 1){
        //     printf("%c", buf[0]);
            // if(buf[0] == '1'){
            //     printf("▅");
            // }else{
            //     printf(" ");
            // }
            // if(numPixels%128 == 0){
            //     printf("\n");
            // }
            // numPixels++;
        // }
        if(buf[0] == 'g'){
            system("google-chrome 'https://google.com' &");
        }
        else if(buf[0] == 'c'){
            system("cheese &");
        }
        else if(buf[0] == 'v'){
            system("code .");
        }
        else if(buf[0] == 'w'){
            system("whatsie &");
        }
        else if(buf[0] == 'n'){
            system("google-chrome 'https://www.netflix.com' &");
        }
        else if(buf[0] == '['){
            // getImage = 1;
            std::string str = eeee(s);
            // vector<int> q = imageStrToVec(str);
            // cout << str << endl;
            // std::cout << decodeImage(q) << std::endl;
            displayImage(str);
            // printf("%s", str);
        }
        // else if(buf[0] == ']'){
        //     getImage = 0;
        //     numPixels = 0;
        //     printf("\n\t%d\n", numPixels);
        // }
    }
    close(s);
    return 0;
}
