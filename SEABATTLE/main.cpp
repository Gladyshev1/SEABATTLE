#include <SFML/Graphics.hpp>
#include "button.h"
#include<iostream>
#include <string>
#include"element.h"
#include"field.h"
#include"elementF.h"
#include"ship.h"
#include"MYfield.h"

#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <charconv>
#include<thread>
#include <windows.h>
#pragma warning(disable: 4996)




using namespace std;
SOCKET client;
SOCKET sListen;
SOCKET hostSock;
SOCKET sockz;
SOCKADDR_IN addr;
SOCKADDR_IN addrz;
string inputText;
int sum = 0;
int el = -9;
int el1 = 1;
int SLOM[10][10];
int SLOM3[10][10];
int SLOM33[10][10] = {0};
int SLOM2[10][10];
int MYsh[10][10];
char MYsh2[101];
char poluchH[101];
char zeroch[101] = {0};
char poluchC[101];
string buff;
string buff1;
Text text;
char myip[80]={0};
char nmyip[80] = {0};
int enemy[10][10] ;
bool flagH = true;

bool STAF = false;
bool STAF2 = false;
bool full = true;
bool full21 = true;
bool flagi= false;
bool rast = true;
bool rast2 = true;
MYfield a(250, 100);
field b(1030, 100);
MYfield aC(250, 100);
field bC(1030, 100);
ship S1(630, 220 + 10 * 64, 1);
ship S12(630 + 1 * 64, 220 + 10 * 64, 1);
ship S13(630 + 2 * 64, 220 + 10 * 64, 1);
ship S14(630 + 3 * 64, 220 + 10 * 64, 1);


ship S2(630 + 4 * 64, 220 + 9 * 64, 2);
ship S21(630 + 6 * 64, 220 + 9 * 64, 2);
ship S22(630 + 8 * 64, 220 + 9 * 64, 2);

ship S3(630 + 4 * 64, 220 + 10 * 64, 3);
ship S31(630 + 7 * 64, 220 + 10 * 64, 3);


ship S4(630, 220 + 9 * 64, 4);
ship S10(630, 220 + 10 * 64, 1);
ship S120(630 + 1 * 64, 220 + 10 * 64, 1);
ship S130(630 + 2 * 64, 220 + 10 * 64, 1);
ship S140(630 + 3 * 64, 220 + 10 * 64, 1);


ship S20(630 + 4 * 64, 220 + 9 * 64, 2);
ship S210(630 + 6 * 64, 220 + 9 * 64, 2);
ship S220(630 + 8 * 64, 220 + 9 * 64, 2);

ship S30(630 + 4 * 64, 220 + 10 * 64, 3);
ship S310(630 + 7 * 64, 220 + 10 * 64, 3);


ship S40(630, 220 + 9 * 64, 4);

ship* arrsh[10] = { &S1,&S12,&S13,&S14,&S2,&S21,&S22 ,&S3,&S31,&S4 };
ship* arrsh2[10] = { &S10,&S120,&S130,&S140,&S20,&S210,&S220 ,&S30,&S310,&S40 };
button ro(590, 200 + 9 * 64, 740, 220, "");
void agan(); 


void igra(RenderWindow& window, Event& event, Vector2f  pos);






void hostHandler();


int main()
{
  

    sf::Font font;
    font.loadFromFile("font/ObelixPro.ttf");


    text.setFont(font);
    text.setCharacterSize(24);
    text.setFillColor(sf::Color::Black);
    text.setPosition(480, 200);
    text.setString("conect to: " );




    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        std::cout << "Error" << std::endl;
        exit(1);
    }



    char ac[80];
   gethostname(ac, sizeof(ac));
        

    struct hostent* phe = gethostbyname(ac);
    

   
        struct in_addr addr1;
        memcpy(&addr1, phe->h_addr_list[1], sizeof(struct in_addr));
        buff=(string)inet_ntoa(addr1);
        strcpy(myip, buff.c_str());
        mytext ipd("your ip "+buff);
        ipd.setfontsize(30);
        ipd.setpos(480, 100);
        

    
    

    Texture t1;
    t1.loadFromFile("img/back.png");
    Sprite s1(t1);
    int y = 0;
    float HB = 220;
    float WB = 60;
    mytext liable("    Sea \n battle");
    liable.setfontsize(70);
    liable.setpos(780, 100);
    mytext win(" you win");
    win.setfontsize(70);
    win.setpos(780, 200);
    mytext lose(" you lose");
    lose.setfontsize(70);
    lose.setpos(780, 200);
    mytext ur(" your move   ");
    mytext opp("opponent's move");
    ur.setfontsize(50);
    opp.setfontsize(50);
    
        ur.setpos(760, 250 + 9 * 64);
    opp.setpos(690, 250 + 9 * 64);
    RenderWindow window(VideoMode(1920, 1080), "seabuble"/*, Style::Fullscreen **/);
    RectangleShape contour1(Vector2f(100, 100));
    button play(850, 340, HB, WB, "PLAY");
    play.setfontsize(40);
    button host(900, 410, 120, 50, "HOST");
    host.setfontsize(25);
    button join(900, 510, 120, 50, "JOIN");
    join.setfontsize(25);
    button save(250, 770, HB, WB, "SAVE");
    save.setfontsize(40);

    button exit(850, 440, HB, WB, "EXIT");
    exit.setfontsize(40);
    button ret(830, 340, HB+100, WB, "Main menu");
    ret.setfontsize(25);
    int indeceit = 0;
   
        thread wq(hostHandler);
        wq.detach();
   
    /*thread wqe(ClientHandler);

    wqe.detach();*/
    while (window.isOpen())



    {

        a.getarr((int*)MYsh);

        Vector2i mouse = Mouse::getPosition(window);
        Vector2f mousePos = window.mapPixelToCoords(mouse);
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.draw(s1);
        if (indeceit == 0) {

            play.mydraw(window);
            exit.mydraw(window);
            liable.mydraw(window);
            if (play.pressed(event, mousePos) == true&&indeceit==0)
            {
                indeceit = 1;
            }
            if (exit.pressed(event, mousePos) == true&&indeceit==0)
            {
                window.close();
            }
        }
        else if (indeceit == 1) {
            join.mydraw(window);
            host.mydraw(window);
            ipd.mydraw(window);
            window.draw(text);
            if (event.type == sf::Event::TextEntered)
            {
               
                if (event.text.unicode < 128)
                {
                    if (event.text.unicode == 8 && inputText.size() > 0) // Backspace
                        inputText.pop_back();
                    else if (event.text.unicode != 8) // Input characters
                        inputText += static_cast<char>(event.text.unicode);
                    text.setString("conect to: "+inputText);
                }
                Sleep(200);
            }
            
            if (join.pressed(event, mousePos) == true && indeceit == 1) {
                flagH = false;
                
                //////////////////////////////////////////////////////////


                buff1 = text.getString().toAnsiString();

                buff1.erase(0, 11);
               //out << buff1;
                strcpy(nmyip, buff1.c_str());
                
                int sizeofaddr = sizeof(addr);
                addr.sin_addr.s_addr = inet_addr(nmyip);
                addr.sin_port = htons(1111);
                addr.sin_family = AF_INET;

                client = socket(AF_INET, SOCK_STREAM, NULL);
                if (connect(client, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
                   
                }
                else {
                    std::cout << "Connected!\n";

                    indeceit = 3;
                }
               

                /////////////////////////////////////////////////////////////



            }
            if (host.pressed(event, mousePos) == true && indeceit == 1) {
                flagH = true;

                ////////////////////////////////////////////////////////


                
                int sizeofaddr = sizeof(addr);
                addr.sin_addr.s_addr = inet_addr(myip);
                addr.sin_port = htons(1111);
                addr.sin_family = AF_INET;

                 sListen = socket(AF_INET, SOCK_STREAM, NULL);
                bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
                listen(sListen, SOMAXCONN);


                hostSock = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

                if (hostSock == 0) {
                    std::cout << "Error #2\n";
                }
                else {
                    std::cout << "Client Connected!\n";



                }

                ////////////////////////////////////////////////////////////
                indeceit = 3;
            }
        }
        else if (indeceit == 3 && flagH == true) {

            if (rast) {
                for (int u = 0; u < 100; u++) {
                    MYsh2[u] = MYsh[u / 10][u % 10];
                }
                if (a.full() == 50) {
                    send(hostSock, MYsh2, sizeof(MYsh2), NULL);
                    Sleep(10);
                    
                }
                if (b.full() == 0) {

                }
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        enemy[i][j] = (int)poluchH[i * 10 + j];
                        sum += enemy[i][j];
                    }

                }
                if (full21 && sum != 0) {
                    b.setmass((int*)enemy);
                    full21 = false;
                }
                

                
                
                cout << "";
                if (a.full() == 50 && b.full() == 50) {
                    rast = false;
                    flagi = true;
                }
            }
            else {
                if (b.full() == -50 || a.full() == -50) {
                    indeceit = 4;

                }
                if (full == true) 
                    STAF = true;
                    full = false;
                

                b.getarr((int*)enemy);
                for (int u = 0; u < 100; u++) {
                    poluchC[u] = enemy[u / 10][u % 10];
                }
               
                poluchC[100] = (char)STAF;

                send(hostSock, poluchC, sizeof(poluchC), NULL);
                Sleep(10);

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        SLOM2[i][j] = poluchH[i * 10 + j];


                    }
                }


                
                    STAF = !(bool)poluchH[100];
                
               

               

                a.setmass((int*)SLOM2);

               

            }
           // cout << STAF;
            igra(window, event, mousePos);
            if (b.full() == -50) {
                win.mydraw(window);
            }
            else if (a.full() == -50) {
                lose.mydraw(window);
            }
            if (flagi == true) {
                if (STAF == 1 ) {
                    ur.mydraw(window);
                }
                else if (STAF == 0 ) {
                    opp.mydraw(window);
                }
            }
        }
        else if (indeceit == 3 && flagH != true) {

            if (rast2) {
                for (int u = 0; u < 100; u++) {
                    MYsh2[u] = MYsh[u / 10][u % 10];
                }


                if (a.full() == 50) {
                    send(client, MYsh2, sizeof(MYsh2), NULL);
                    Sleep(10);
                   
                }
                if (b.full() == 0) {

                }
                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        enemy[i][j] = (int)poluchC[i * 10 + j];
                        sum += enemy[i][j];
                    }

                }
                if (full21 && sum != 0) {
                    b.setmass((int*)enemy);
                    full21 = false;
                }
                cout << "";
                if (a.full() == 50 && b.full() == 50) {
                    rast2 = false;
                    flagi = true;
                }
            
            }
            else {
                full = false;
                //STAF = true;
                if (b.full() == -50 || a.full() == -50) {
                    indeceit = 4;

                }
               b.getarr((int*)enemy);
                for (int u = 0; u < 100; u++) {
                    poluchH[u] = enemy[u / 10][u % 10];
                }

                poluchH[100] = (char)STAF2;
                send(client, poluchH, sizeof(poluchH), NULL);
                Sleep(20);

                for (int i = 0; i < 10; i++) {
                    for (int j = 0; j < 10; j++) {
                        SLOM[i][j] = poluchC[i * 10 + j];


                    }
                }
                
                    STAF2 = !(bool)poluchC[100];
               
                
               
                a.setmass((int*)SLOM);
                //ut << STAF2;
                
            }
           
            
            igra(window, event, mousePos);
            
           
            if (flagi == true) {
                if (STAF2 == 1) {
                    ur.mydraw(window);
                }
                else if (STAF2 == 0 ) {
                    opp.mydraw(window);
                }
            }
            // cout << qw;

        }
        else if (indeceit == 4) {
            ret.mydraw(window);
            if (b.full() == -50) {
                win.mydraw(window);
                
            }
            else if (a.full() == -50) {
                lose.mydraw(window);
                
            }
        }
        if (ret.pressed(event,mousePos) == true && indeceit == 4) {
            agan();
            indeceit = 0;
        }
        window.display();
        window.clear();



    }

    return 0;
}
void agan(){
inputText.clear();
text.setString("conect to: ");
closesocket(sListen);
closesocket(client);
closesocket(hostSock);
client = sockz;
hostSock = sockz;
for (int i = 0; i < 10; i++) {

    (*arrsh[i]) = (*arrsh2[i]);

}

sum = 0;
el = -9;
el1 = 1;

a.setmass((int*)SLOM3);
b.setmass((int*)SLOM3);
a = aC;
b = bC;
for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
        enemy[i][j] = SLOM3[j][i];
        MYsh[i][j] = SLOM3[j][i];
        SLOM[i][j] = SLOM3[j][i];
    }

}
flagH = true;
for (int i = 0; i < 101; i++) {
    MYsh2[i] = zeroch[i];
    poluchH[i] = zeroch[i];

    poluchC[i] = zeroch[i];
}
STAF = false;
STAF2 = false;
full = true;
full21 = true;
flagi = false;
rast = true;
rast2 = true;
}

void igra(RenderWindow& window, Event& event, Vector2f  pos) {

    a.mydraw(window);
    b.mydraw(window);
    ro.mydraw(window);
    if (full) {
        for (int i = 0; i < 10; i++) {
            a.setka(arrsh[i]);
            (*arrsh[i]).arrangement(event, pos);
            (*arrsh[i]).mydraw(window);
        }
    }
    if (flagH) {
        if (STAF) {

            if (b.pressed11(event, pos) == true) {
                el = b.poluchel(event, pos);
                //cout << STAF;

            }
            if (el == 0) {

                STAF = false;
               
            }

        }
        el = -9;
    }
    else
    {
        if (STAF2) {

            if (b.pressed11(event, pos) == true) {
                el = b.poluchel(event, pos);
                //out << STAF2;

            }
            if (el == 0) {

                STAF2 = false;
               
            }
            
        }
        el = -9;
    }

    a.infield(event, pos);
    a.pressed11(event, pos);

}








void hostHandler()
{

    while (true)
    {
        if (flagH == false) {
            recv(hostSock, poluchH, sizeof(poluchH), NULL);
            recv(client, poluchC, sizeof(poluchC), NULL);
           
            //Sleep(12);
        }
        else if (flagH) {
           
            recv(client, poluchC, sizeof(poluchC), NULL);
            recv(hostSock, poluchH, sizeof(poluchH), NULL);

            //Sleep(12);
        }
    }


}