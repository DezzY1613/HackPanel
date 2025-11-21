#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include <iostream>
#include <windows.h>
#include <String>
#include <fstream>
using namespace std;

string folder = string(getenv("USERPROFILE")) + "\\Documents";
string path = folder + "\\save.dezz";

bool Save = false;
string macFind[6];

const string DataCreateOS = "19.11.2025";
bool IpGenerated;
bool HackLevel = false;
bool ActiveSystem;

const string Controller[] = { "DezzOS@user ~$ ", "\x1b[36mDezzOS@root ~$ \x1b[0m", "\x1b[31mDezzOS@hack ~$ \x1b[0m" };
const string controllerName = "\t\t\t\t\t\tController v1.0";
const string MacList[]{ "C7","47", "AE", "K5", "49", "JM", "ED", "A8", "C2", "C4","A6",
                     "DE", "ZZ", "26", "7L", "3M", "0X", "4O", "9G", "G6", "7Q","AU" };
int Ips[3];

int rights = 0; //права контроллера
int IpUser[3];



//Цвета
string DefaultColor = "\x1b[0m";

string ColorRed = "\x1b[31m";
string ColorGreen = "\x1b[32m";
string ColorYellow = "\x1b[33m";

string ColorError = "\x1b[41m";
string ColorSuccess = "\x1b[42m";


int SaveFiles() {

    ofstream savefile(path);
    savefile << rights << endl;
    savefile << HackLevel << endl;
    savefile << IpGenerated << endl;
    savefile << IpUser[0] << "." << IpUser[1] << "." << IpUser[2] << "." << IpUser[3] << endl;
    savefile << Ips[0] << "." << Ips[1] << "." << Ips[2] << "." << Ips[3] << endl;
    savefile << macFind[0] << ":" << macFind[1] << ":" << macFind[2] << ":"
        << macFind[3] << ":" << macFind[4] << ":" << macFind[5] << endl;
    savefile.close();
    return 0;
}
int LoadFiles() {
    ifstream loadfile(path);
    if (loadfile.good()) {
        loadfile >> rights >> HackLevel >> IpGenerated;
        char dummy;
        loadfile >> IpUser[0] >> dummy >> IpUser[1] >> dummy >> IpUser[2] >> dummy >> IpUser[3];
        loadfile >> Ips[0] >> dummy >> Ips[1] >> dummy >> Ips[2] >> dummy >> Ips[3];
        loadfile >> macFind[0] >> dummy >> macFind[1] >> dummy >> macFind[2] >> dummy
            >> macFind[3] >> dummy >> macFind[4] >> dummy >> macFind[5];
    }

    return 0;
}


void Commands(string EnteredCommand) {
    //--------------------------------------------------------------------------------- 
    if (!IpGenerated) // генерация айпи адреса (я просто не знаю как по другому сделать ^_^)
    {
        srand(time(NULL));
        IpUser[0] = {rand() % 199}; IpUser[1] = {rand() % 199}; IpUser[2] = { rand() % 199 }; IpUser[3] = { rand() % 199 };
        IpGenerated = true;
    }
    //---------------------------------------------------------------------------------



    // Комманды 0
    if (EnteredCommand == "quit") // user (nonRoot)
    {
        cout << ColorGreen << "Подготовка системы..." << DefaultColor;
        SaveFiles();
        Sleep(100);
        system("cls");
        cout << ColorGreen << "Выключение системы..." << DefaultColor;
        Sleep(1500);
        system("cls");
        exit(0);
    }

    else if (EnteredCommand == "help") {
        cout << ColorYellow << "Список комманд: \nhelp - для просмотра комманд \nquit - для выключения системы \nclear | clr | cl | cls - отчистить контроллер \nsudo - комманды для полных прав \ninfo - информация о системе" << DefaultColor << endl;
    }

    else if (EnteredCommand == "clear" or EnteredCommand == "cl" or EnteredCommand == "clr" or EnteredCommand == "cls") {
        system("cls");
        cout << controllerName << endl;
    }

    else if (EnteredCommand == "Dezz") {
        cout << ColorGreen << "[!] Пасхалочка ^_^\n" << DefaultColor;
    }

    else if (EnteredCommand == "info") {
        


        cout << ColorGreen << "Название системы: DezzOS" << 
                              "\nВерсия контроллера: v1.0" << 
                              "\nIp адрес: " << IpUser[0] << "." << IpUser[1] << "." << IpUser[2] << "." << IpUser[3] <<
                              "\nДата создания сборки: " << DataCreateOS <<
                              "\nРут права: " << rights << 
                DefaultColor << endl;
    }

    // SUDO                                        ROOT 1
    else if (EnteredCommand == "sudo") {

        switch (rights) {
        case 0:
            cout << ColorRed << "[!] У вас нет необходимых прав!\n" << ColorYellow << "Чтобы их включить попробуйте: sudo root\n" << DefaultColor;
            break;    
        case 1:
            cout << ColorYellow << "[?] Используйте: sudo help\n" << DefaultColor;
            break;
        case 2:
            cout << ColorYellow << "[?] Используйте: sudo help\n" << DefaultColor;
            break;
        }

    }
    //Включение прав админа
    else if (EnteredCommand == "sudo root DezzOS on")
    {
        switch (rights) {
        case 0:
            cout << ColorGreen << "[+] Права включены!\n" << DefaultColor;
            rights = 1;
            break;
        case 1:
            cout << ColorYellow << "[!] Права и так включены!\n" << DefaultColor;
            break;
        case 2:
            cout << ColorYellow << "[!] Права и так включены!\n" << DefaultColor;
            break;
        }
    }
    else if (EnteredCommand == "sudo root DezzOS hack" && HackLevel)
    {
        switch (rights) {
        case 0:
            cout << ColorGreen << "[+] Права включены!\n" << DefaultColor;
            rights = 2;
            break;
        case 1:
            cout << ColorGreen << "[+] Права включены!\n" << DefaultColor;
            rights = 2;
            break;
        case 2:
            cout << ColorYellow << "[!] Права и так включены!\n" << DefaultColor;
            break;
        }
    }
    else if (EnteredCommand == "sudo root DezzOS off") {
        switch (rights) {
        case 0:
            cout << ColorYellow << "[!] Права и так выключены!\n" << DefaultColor;
            break;
        case 1:
            cout << ColorGreen << "[+] Права выключены!\n" << DefaultColor;
            rights = 0;
            break;
        case 2:
            cout << ColorGreen << "[+] Права выключены!\n" << DefaultColor;
            rights = 0;
            break;
        }
    }
    else if (EnteredCommand == "sudo root") {
        cout << ColorYellow << "[!] Укажите название ПК и что нужно сделать! \nДля hack режима нужно хоть 1 раз взломать чью-то систему!\n" << DefaultColor;
    }


    // Комманды с правами админа
    else if (EnteredCommand == "sudo help" && rights > 0) {
        cout << ColorYellow << "[?] Список комманд: \nhelp - для просмотра комманд \nroot - для включения или выключения прав админа \nsearch - поиск чужих ip сетей и MAC адрессов \nhack - для взлома жертвы \nconnect - для подключения к жертве" << DefaultColor << endl;
    }

    // Поиск айпи и мак адрессов                           Search ip and Mac
    else if (EnteredCommand == "sudo search ip" && rights > 0) {
        cout << "Ищу IP жертвы...\n";
        Sleep(1500);
        Ips[0] = { rand() % 199 }; Ips[1] = { rand() % 199 }; Ips[2] = { rand() % 199 }; Ips[3] = { rand() % 199 };
        cout << ColorGreen << "[+] " << DefaultColor << ColorSuccess << "Жертва найдена!" << DefaultColor << ColorGreen << "\nЕё ip адрес: "
        << Ips[0] << "." << Ips[1] << "." << Ips[2] << "." << Ips[3] << DefaultColor << endl;
    }
    else if (EnteredCommand == "sudo search mac" && rights > 0) {
        cout << "Ищу MAC жертвы...\n";
        Sleep(2000);
        cout << ColorGreen << "[+] " << DefaultColor << ColorSuccess << "Жертва найдена!" << DefaultColor << ColorGreen << "\nЕё MAC адрес: ";
        srand(time(NULL));
        int MacRand = rand() % 21;
        cout << MacList[MacRand] ;
        macFind[0] = MacList[MacRand];
        Sleep(1000);

        srand(time(NULL));
        MacRand = rand() % 21;
        cout << ":" << MacList[MacRand];
        macFind[1] = MacList[MacRand];
        Sleep(1000);

        srand(time(NULL));
        MacRand = rand() % 21;
        cout << ":" << MacList[MacRand];
        macFind[2] = MacList[MacRand];
        Sleep(1000);

        srand(time(NULL));
        MacRand = rand() % 21;
        cout << ":" << MacList[MacRand];
        macFind[3] = MacList[MacRand];
        Sleep(1000);

        srand(time(NULL));
        MacRand = rand() % 21;
        cout << ":" << MacList[MacRand];
        macFind[4] = MacList[MacRand];
        Sleep(1000);

        srand(time(NULL));
        MacRand = rand() % 21;
        cout << ":" << MacList[MacRand] << DefaultColor << endl;
        macFind[5] = MacList[MacRand];
    }
    else if (EnteredCommand == "sudo search" && rights > 0) {
        cout << ColorGreen << "[?] Укажите что именно вы хотите найти:\n1) ip аддрес\n2) mac аддрес\n" << DefaultColor;
    }


    // Эксплоит

    else if (EnteredCommand == "sudo hack" && rights > 0)
    {
        cout << ColorGreen << "[?] Укажите ip адрес жертвы и mac адрес жертвы которую нашли" << DefaultColor;
    }
    else if (EnteredCommand.substr(0, 9) == "sudo hack" && rights > 0)
    {
        string rest = EnteredCommand.substr(9);

        size_t start = rest.find_first_not_of(" ");
        if (start != string::npos) rest = rest.substr(start);
        else rest = "";

        size_t spacePos = rest.find(' ');
        if (spacePos == string::npos) {
            cout << ColorRed << "[!] Укажите IP и MAC через пробел!\nПример: sudo hack 192.168.1.23 00:11:22:33:44:55" << DefaultColor << endl;
            return;
        }

        string ip = rest.substr(0, spacePos);
        string mac = rest.substr(spacePos + 1);

        mac.erase(remove(mac.begin(), mac.end(), ' '), mac.end());

        // проверка та ли эта жертва или нет
        string realIp = to_string(Ips[0]) + "." + to_string(Ips[1]) + "." + to_string(Ips[2]) + "." + to_string(Ips[3]);
        string realMac = macFind[0] + ":" + macFind[1] + ":" + macFind[2] + ":" + macFind[3] + ":" + macFind[4] + ":" + macFind[5];

        if (ip == realIp && mac == realMac)
        {
            cout << ColorGreen << "[+] Цель подтверждена!\n";
            cout << "[+] Получение данных..." << endl;
            Sleep(2000);
            cout << "[+] Получены данные!\n" << DefaultColor;
            cout << ColorSuccess << "[SUCCESS] Взом завершен " << DefaultColor << endl;
            rights = 2; // hack-режим
            HackLevel = true;
            ActiveSystem = true;
        }
        else
        {
            cout << ColorRed << "[-] Неверный IP или MAC. Попробуйте снова." << DefaultColor << endl;
        }
        }
    

    //----------------------------------------------------------------------- Hack 2

    else if (EnteredCommand == "sudo connect" && rights == 2)
    {
        cout << ColorGreen << "[?] Укажите номер жертвы \n[?] Для просмотра информации используйте list\n" << DefaultColor;
    }
    else if (EnteredCommand == "sudo connect 0" && rights == 2 && ActiveSystem)
    {
        char DeleteSystemVictim;
        string temp;

        cout << ColorGreen << "[!] Удалять жертве систему (y/n): " << DefaultColor;
        getline(cin, temp);
        DeleteSystemVictim = tolower(temp[0]);

        switch (DeleteSystemVictim) {
        case 'y':
            cout << ColorYellow << "Подготовка к удалении системы жертве!" << DefaultColor << endl;
            Sleep(1600);
            cout << ColorSuccess << "[+] Система жертвы успешна удалена!" << DefaultColor << endl;
            ActiveSystem = false;
            break;
        case 'n':
            cout << ColorGreen << "[+] Отмена удалении системы жертве!" << DefaultColor << endl;
            break;
        default:
            cout << ColorError << "[!] Ошибка ответа!" << DefaultColor << endl;
            break;
        }
        
    }
    else if (EnteredCommand == "sudo connect 0" && rights == 2 && !ActiveSystem)
    {
        cout << ColorError << "[!] Ошибка при подключении!" << DefaultColor << endl;
    }

    else if (EnteredCommand == "sudo connect list" && rights == 2)
    {
        cout << ColorSuccess << "Вот данные о вашей последний жертве" << DefaultColor << endl;
        cout << ColorGreen << "Система: Windows 10 \nНомер: 0 \nIP: " << Ips[0] << "." << Ips[1] << "." << Ips[2] << "." << Ips[3] << endl <<
                              "MAC: " << macFind[0] << ":" << macFind[1] << ":" << macFind[2] << ":" << macFind[3] << ":" << macFind[4] << ":" << macFind[5] << endl <<
                              "Состояние: " << ActiveSystem << DefaultColor << endl;
    }

    //-----------------------------------------------------------------------
    else {
        cout << ColorRed << "[!] Неизвестная комманда! Проверте правильность написания!\n" << DefaultColor;
    }
}

void StartOS() {
    setlocale(LC_ALL, "en_US.UTF-8");


    const wstring loadingWelcome[]{L"▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 0%",L"█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 5%", L"██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 10%", L"███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 15%", L"████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 20%", 
    L"█████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 25%", L"██████▒▒▒▒▒▒▒▒▒▒▒▒▒▒ 30%", L"███████▒▒▒▒▒▒▒▒▒▒▒▒▒ 35%", L"████████▒▒▒▒▒▒▒▒▒▒▒▒ 40%", L"█████████▒▒▒▒▒▒▒▒▒▒▒ 45%", 
    L"██████████▒▒▒▒▒▒▒▒▒▒ 50%", L"███████████▒▒▒▒▒▒▒▒▒ 55%", L"████████████▒▒▒▒▒▒▒▒ 60%", L"█████████████▒▒▒▒▒▒▒ 65%", L"██████████████▒▒▒▒▒▒ 70%", 
    L"███████████████▒▒▒▒▒ 75%", L"████████████████▒▒▒▒ 80%", L"█████████████████▒▒▒ 85%", L"██████████████████▒▒ 90%", L"███████████████████▒ 95%", L"████████████████████ 100%", };
  
    const wstring DezzOS = LR"(
                       ██████████                                        ███████     █████████ 
                      ░░███░░░░███                                     ███░░░░░███  ███░░░░░███
                       ░███   ░░███  ██████   █████████  █████████    ███     ░░███░███    ░░░ 
                       ░███    ░███ ███░░███ ░█░░░░███  ░█░░░░███    ░███      ░███░░█████████ 
                       ░███    ░███░███████  ░   ███░   ░   ███░     ░███      ░███ ░░░░░░░░███
                       ░███    ███ ░███░░░     ███░   █   ███░   █   ░░███     ███  ███    ░███
                       ██████████  ░░██████   █████████  █████████    ░░░███████░  ░░█████████ 
                      ░░░░░░░░░░    ░░░░░░   ░░░░░░░░░  ░░░░░░░░░       ░░░░░░░     ░░░░░░░░░                                                                                                                                                                                                                                                    
)";
    for (int i = 0; i <= 20; i++)
    {
        system("cls");
        cout << "\n\n\n\n\n\n\n";
        wcout << DezzOS;
        wcout << L"\n\n\n\n\n\t\t\t\t\tLoading  " << loadingWelcome[i];
        cout << "\n\n\n\n\n\n";
        Sleep(200); // тракторист)
    }
    Sleep(500);
    system("cls");

}
void OS() {
    setlocale(LC_ALL, "Ru");
    
    string EnteredCommand;
    bool quit = false;

    LoadFiles();
    cout << controllerName << endl;
    while (!quit) {
        cout << Controller[rights];
        getline(cin, EnteredCommand);
        Commands(EnteredCommand);
    }

}


int main() {
	StartOS();
    OS();
    return 0;
}