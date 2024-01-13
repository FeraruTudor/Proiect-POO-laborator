#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <fstream>
#include <sstream>
#include <typeinfo>
#include <limits>
#include <stdexcept>
#include <chrono>
#include <ctime>
using namespace std;

class numar_si_index
{
public:
    float numar;
    int index;

    numar_si_index(float numar, int index)
    {
        this->numar = numar;
        this->index = index;
    }

    numar_si_index()
    {
        this->numar = 0;
        this->index = 0;
    }
};

class string_si_index
{
public:
    string string1;
    int index;

    string_si_index(string string1, int index)
    {
        this->string1 = string1;
        this->index = index;
    }

    string_si_index()
    {
        this->index = 0;
    }
};

class Flow
{
private:
    string TITLE_titlu, TITLE_subtitlu;
    string TEXT_titlu, TEXT_copy;
public:
    Flow(string titlu)
    {
        TITLE_titlu = titlu;
    }

    void set_TITLE_titlu(string titlu)
    {
        TITLE_titlu = titlu;
    }
    void set_TITLE_subtitlu(string subtitlu)
    {
        TITLE_subtitlu = subtitlu;
    }
    void set_Text_titlu(string text)
    {
        TEXT_titlu = text;
    }
    void set_Text_copy(string text)
    {
        TEXT_copy = text;
    }

    string get_TITLE_titlu()
    {
        return TITLE_titlu;
    }
    string get_TITLE_subtitlu()
    {
        return TITLE_subtitlu;
    }
    string get_Text_Titlu()
    {
        return TEXT_titlu;
    }
    string get_Text_Copy()
    {
        return TEXT_copy;
    }
    vector <int> steps;
    vector <numar_si_index> number_input_vector;
    vector <string_si_index> text_input_vector;

    int numar_start = 0 ;
    int erori_step1 = 0, erori_step2 = 0, erori_step3 = 0, erori_step4 = 0, erori_step5 = 0, erori_step6 = 0;
    int erori_step7 = 0, erori_step8 = 0, erori_step9 = 0, erori_step10 = 0, erori_total = 0;
    chrono::system_clock::time_point currentTime = chrono::system_clock::now();
    time_t currentTime_t = chrono::system_clock::to_time_t(currentTime);
    tm localTime = *localtime(&currentTime_t);
};

vector <Flow> vector_Flows;
int i = 0;


class Actiuni_Flows
{
public:

    void afisare_flows()
    {
        cout<<"\nToate flows disponibile:\n";
        for(Flow flow : vector_Flows){
            cout<< flow.get_TITLE_titlu() << "\n";
        }
        cout<<"\n";
    }

    void creare_flow()
    {

        string nume_flow = "Flow_" + to_string(i);
        Flow flow_nou(nume_flow);
        i++;

        int alegere;
        string a, b;

        while(1)
        {
            cout<<"\n--Alegeti tipul de STEP pe care doriti sa-l adaugati--\n";
            cout<<"1.TITLE step (schimbati titlul si subtitlul flow-ului)\n";
            cout<<"2.TEXT step (adaugati un titlu pentru text si o copie(string) )\n";
            cout<<"3.TEXT INPUT step (adaugati un text(string) )\n";
            cout<<"4.NUMBER INPUT step (adaugati un numar(float) )\n";
            cout<<"5.CALCULUS step (alegeti 2 pasi anteriori(NUMBER INPUT) si un operator(+, -, *, /, min, max) )\n";
            cout<<"6.DISPLAY step (alegeti un fisier introdus la un pas anterior(TEXT FILE step sau CSV FILE step) )\n";
            cout<<"7.TEXT FILE step (introduceti numele unui fisier de tip text si o descriere)\n";
            cout<<"8.CSV FILE step (introduceti numele unui fisier de tip csv si o descriere)\n";
            cout<<"9.OUTPUT step (va genera un fisier text)\n";
            cout<<"10.END step (finalul flow-ului)\n\n";

            cin>>alegere;

            switch(alegere)
            {
            case 1:
                flow_nou.steps.push_back(1);
                break;
            case 2:
                flow_nou.steps.push_back(2);
                break;
            case 3:
                flow_nou.steps.push_back(3);
                break;
            case 4:
                flow_nou.steps.push_back(4);
                break;
            case 5:
                flow_nou.steps.push_back(5);
                break;
            case 6:
                flow_nou.steps.push_back(6);
                break;
            case 7:
                flow_nou.steps.push_back(7);
                break;
            case 8:
                flow_nou.steps.push_back(8);
                break;
            case 9:
                flow_nou.steps.push_back(9);
                break;
            case 10:
                flow_nou.steps.push_back(10);
                break;
            }

            if(alegere == 10)
                break;
        }

        vector_Flows.push_back(flow_nou);
    }

    void run_flow()
    {
        cout<<"Numele flow-ului caruia vreti sa-i dati run:\n";
        string nume, a, b, c, d, f, g, h, l, n, o, p;
        int contor, j, k, m, q;
        float e;
        cin>> nume;
        int ok = 0, alegere_step1, alegere_step2, alegere_step3, alegere_step4, alegere_step5;
        int alegere_step6, alegere_step7, alegere_step8, alegere_step9, alegere_step10;
        for(Flow flow : vector_Flows)
        {
            if(flow.get_TITLE_titlu() == nume)
            {
                ok = 1;
                contor = 1;
                flow.numar_start++;
                for(int i : flow.steps)
                {
                    cout << "Pasul numarul " << contor << endl;
                    switch(i)
                    {
                    case 1:
                    {
                        cout<<"Step TITLE.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";

                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step TITLE: ";

                            try
                            {
                                if (!(cin >> alegere_step1))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step1++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }
                        if(alegere_step1 == 1)
                            break;

                        vector_Flows.erase(remove_if(vector_Flows.begin(), vector_Flows.end(), [&](Flow obj)
                        {
                            return obj.get_TITLE_titlu() == flow.get_TITLE_titlu();
                        }), vector_Flows.end());

                        cout<<"Introduceti un titlu:\n";
                        cin>>a;
                        if(typeid(a) != typeid(string))
                        {
                            throw 10;
                        }
                        flow.set_TITLE_titlu(a);
                        cout<<"Introduceti un subtitlu:\n";
                        cin>>b;
                        if(typeid(b) != typeid(string))
                        {
                            throw 10.1;
                        }
                        flow.set_TITLE_subtitlu(b);

                        vector_Flows.push_back(flow);

                        break;
                    }

                    case 2:
                    {
                        cout<<"Step TEXT.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";

                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step TEXT: ";

                            try
                            {
                                if (!(cin >> alegere_step2))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step2++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }


                        if(alegere_step2 == 1)
                            break;

                        cout<<"Introduceti un Titlu:\n";
                        cin>>c;
                        flow.set_Text_titlu(c);
                        cout<<"Introduceti un Copy:\n";
                        cin >> d;
                        flow.set_Text_copy(d);



                        break;
                    }

                    case 3:
                    {
                        cout<<"Step TEXT INPUT.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";

                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step TEXT INPUT: ";

                            try
                            {
                                if (!(cin >> alegere_step3))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step3++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }
                        if(alegere_step3 == 1)
                            break;

                        vector_Flows.erase(remove_if(vector_Flows.begin(), vector_Flows.end(), [&](Flow obj)
                        {
                            return obj.get_TITLE_titlu() == flow.get_TITLE_titlu();
                        }), vector_Flows.end());

                        cout<<"Introduceti un string:\n";
                        cin >> f;
                        string_si_index text_input(f, contor);
                        flow.text_input_vector.push_back(text_input);

                        vector_Flows.push_back(flow);

                        break;
                    }

                    case 4:
                    {
                        cout<<"Step NUMBER INPUT.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";
                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step NUMBER INPUT: ";

                            try
                            {
                                if (!(cin >> alegere_step4))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step4++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }


                        if(alegere_step4 == 1)
                            break;

                        vector_Flows.erase(remove_if(vector_Flows.begin(), vector_Flows.end(), [&](Flow obj)
                        {
                            return obj.get_TITLE_titlu() == flow.get_TITLE_titlu();
                        }), vector_Flows.end());


                        while (true)
                        {
                            cout << "Introduceti un numar ";

                            try
                            {
                                if (!(cin >> e))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step4++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }



                        numar_si_index number_input(e, contor);
                        flow.number_input_vector.push_back(number_input);

                        vector_Flows.push_back(flow);

                        break;
                    }

                    case 5:
                    {
                        cout<<"Step CALCULUS.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";
                        int ok_pas_calculus = 0;
                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step CALCULUS: ";

                            try
                            {
                                if (!(cin >> alegere_step5))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step5++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }
                        if(alegere_step5 == 1)
                            break;
                        // face operatii cu chestiile de la step-uri NUMBER INPUT
                        cout << "Operatia dintre pasi:(+, -, *, /, min, max)\n";

                        cin >> l;

                        while (true)
                        {
                            cout << "Introduceti alegerea pentru primul pas:  ";

                            try
                            {
                                if (!(cin >> j))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step5++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }

                        while (true)
                        {
                            cout << "Introduceti alegerea pentru al doilea pas:  ";

                            try
                            {
                                if (!(cin >> k))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step5++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }

                        for(numar_si_index parcurgere1 : flow.number_input_vector)
                        {
                            if(parcurgere1.index == j)
                            {
                                for(numar_si_index parcurgere2 : flow.number_input_vector)
                                {
                                    if(parcurgere2.index == k)
                                    {

                                        cout<<"rezultatul operatiei este: ";

                                        if(l == "+")
                                            cout << parcurgere1.numar + parcurgere2.numar;
                                        else if(l == "-")
                                            cout << parcurgere1.numar - parcurgere2.numar;
                                        else if(l == "*")
                                            cout << parcurgere1.numar * parcurgere2.numar;
                                        else if(l == "/")
                                            cout << parcurgere1.numar / parcurgere2.numar;
                                        else if(l == "min")
                                            cout << (parcurgere1.numar>parcurgere2.numar)?parcurgere2.numar:parcurgere1.numar;
                                        else if(l == "max")
                                            cout << (parcurgere1.numar<parcurgere2.numar)?parcurgere2.numar:parcurgere1.numar;
                                        ok_pas_calculus = 1;
                                        cout<<"\n";
                                    }
                                }
                            }
                        }

                        try
                        {
                            if(ok_pas_calculus == 0)
                                throw 10;
                        }
                        catch(int x)
                        {
                            flow.erori_step5++;
                            flow.erori_total++;
                            cout <<"Cel putin unul dintre pasii alesi nu este de tip NUMBER INPUT\n";
                        }

                        break;
                    }

                    case 6:
                    {
                        int ok_pas_display = 0;
                        cout<<"Step DISPLAY.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";
                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step DISPLAY: ";

                            try
                            {
                                if (!(cin >> alegere_step6))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step6++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }
                        if(alegere_step6 == 1)
                            break;

                        cout<<"Alegeti un pas fisier text sau csv, adaugat anterior:\n";
                        cin >> m;

                        for(string_si_index parcurgere3 : flow.text_input_vector)
                        {

                            if(parcurgere3.index == m)
                            {
                                ok_pas_display = 1;
                                if(parcurgere3.string1.find(".txt") != string::npos)
                                {
                                    ifstream file(parcurgere3.string1);//deschiderea fisierului in modul de citire

                                    string line;

                                    while(getline(file, line))
                                    {
                                        cout << line << endl;
                                    }

                                    file.close();
                                }
                                else
                                {
                                    ifstream file(parcurgere3.string1);

                                    if (file.is_open())   // Verificare dacă fișierul s-a deschis cu succes
                                    {
                                        string line;

                                        // Citirea și afișarea conținutului fișierului CSV linie cu linie
                                        while (getline(file, line))
                                        {
                                            vector<string> tokens; // Vector pentru stocarea valorilor separate

                                            istringstream iss(line);
                                            string token;

                                            // Separarea valorilor în funcție de separator (virgulă)
                                            while (getline(iss, token, ','))
                                            {
                                                tokens.push_back(token);
                                            }

                                            // Afișarea valorilor separate din fiecare linie
                                            for (const auto& value : tokens)
                                            {
                                                cout << value << " ";
                                            }
                                            cout << endl;
                                        }

                                        file.close(); // Închiderea fișierului după utilizare
                                    }
                                }
                            }

                        }
                        try
                        {
                            if(ok_pas_display == 0)
                                throw 10;
                        }
                        catch(int x)
                        {
                            flow.erori_step6++;
                            flow.erori_total++;
                            cout <<"Pasul ales nu este un pas de tip TEXT FILE sau CSV FILE\n";
                        }

                        break;
                    }

                    case 7:
                    {
                        cout<<"Step TEXT FILE.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";
                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step TEXT FILE: ";

                            try
                            {
                                if (!(cin >> alegere_step7))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step7++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }
                        if(alegere_step7 == 1)
                            break;
                        //primeste ca input un fisier text

                        vector_Flows.erase(remove_if(vector_Flows.begin(), vector_Flows.end(), [&](Flow obj)
                        {
                            return obj.get_TITLE_titlu() == flow.get_TITLE_titlu();
                        }), vector_Flows.end());

                        while (true)
                        {
                            cout << "Introduceti numele fisierului (.txt): ";

                            try
                            {
                                if (!(cin >> g) || g.substr(g.size() - 4) != ".txt")
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un string care se termina cu '.txt'.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {
                                flow.erori_step7++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }



                        string_si_index text_input(g, contor);
                        flow.text_input_vector.push_back(text_input);

                        vector_Flows.push_back(flow);
                        break;
                    }

                    case 8:
                    {
                        cout<<"Step CSV FILE.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";
                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step CSV FILE: ";

                            try
                            {
                                if (!(cin >> alegere_step8))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step8++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }
                        if(alegere_step8 == 1)
                            break;
                        //primeste ca input un fisier csv
                        vector_Flows.erase(remove_if(vector_Flows.begin(), vector_Flows.end(), [&](Flow obj)
                        {
                            return obj.get_TITLE_titlu() == flow.get_TITLE_titlu();
                        }), vector_Flows.end());

                        while (true)
                        {
                            cout << "Introduceti numele fisierului (.csv): ";

                            try
                            {
                                if (!(cin >> h) || h.substr(h.size() - 4) != ".csv")
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un string care se termina cu '.csv'.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {
                                flow.erori_step8++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }


                        string_si_index text_input(h, contor);
                        flow.text_input_vector.push_back(text_input);

                        vector_Flows.push_back(flow);

                        break;
                    }

                    case 9:
                    {
                        cout<<"Step OUTPUT.Apasati 1 pentru skip, apasati alt numar pentru a continua\n";
                        while (true)
                        {
                            cout << "Introduceti alegerea pentru step OUTPUT: ";

                            try
                            {
                                if (!(cin >> alegere_step9))
                                {
                                    throw invalid_argument("Input invalid! Va rugam sa introduceti un numar intreg.");
                                }

                                // Ieșirea din ciclu dacă input-ul este corect
                                break;
                            }
                            catch (const invalid_argument& e)
                            {

                                flow.erori_step9++;
                                flow.erori_total++;
                                cout << "Eroare: " << e.what() << endl;
                                cin.clear(); // Curățarea stării erorii
                                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorarea input-ului invalid
                            }
                        }
                        if(alegere_step9 == 1)
                            break;
                        //genereaza un fisier txt
                        //primeste: numele fisierului, titlu, descriere, info din ceilalti steps
                        int ok100 = 1;
                        cout<< "Nume pentru fisierul ce va fi creat:\n";
                        cin >> n;
                        cout << "Titlu pentru fisier:\n";
                        cin >> o;
                        cout << "Descriere pentru fisier:\n";
                        cin >> p;
                        
        cout << "Pas de la care doresti sa adaugi informatii:\n";

        // Verifica daca input-ul este de tip int
        while (!(cin >> q) || cin.peek() != '\n') {
            cin.clear(); // Clear erorile de input
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignora input-ul invalid
            cout << "Va rugam introduceti un numar valid.\n";
        }


                        ofstream outputFile(n);

                        try
                        {
                            if(outputFile.is_open())
                            {
                                outputFile << o << endl;
                                outputFile << p << endl;

                                for(string_si_index parcurgere4 : flow.text_input_vector)
                                {
                                    if(parcurgere4.index == q){
                                        outputFile << parcurgere4.string1 << endl;
                                        ok100 = 0;
                                    }
                                }
                                for(numar_si_index parcurgere5 : flow.number_input_vector)
                                {
                                    if(parcurgere5.index == q){
                                        outputFile << parcurgere5.numar << endl;
                                        ok100 = 0;
                                    }
                                }
                                if( ok100 == 1){
                                    cout << "Step-ul cu numarul introdus nu este TEXT INPUT sau NUMBER INPUT";
                                }
                                cout<< "S a scris in fisierul: " << n << endl;
                            }
                            else
                            {
                                throw 10;
                            }
                        }
                        catch(int x)
                        {
                            flow.erori_step9++;
                            flow.erori_total++;
                            cout<<"Fisierul nu a putut fi deschis!\n";
                        }

                        break;
                    }

                    case 10:
                    {
                        cout <<"Step END. Sfarsitul flow-ului.\n";

                        // Exemplu de afișare a orei și datei curente
                        cout << "Ora si data la care a fost creat flow-ul: " << (flow.localTime.tm_hour < 10 ? "0" : "") << flow.localTime.tm_hour
                        << ":" << (flow.localTime.tm_min < 10 ? "0" : "") << flow.localTime.tm_min
                        << ":" << (flow.localTime.tm_sec < 10 ? "0" : "") << flow.localTime.tm_sec
                        << " " << (flow.localTime.tm_mday < 10 ? "0" : "") << flow.localTime.tm_mday
                        << "/" << (flow.localTime.tm_mon + 1 < 10 ? "0" : "") << flow.localTime.tm_mon + 1
                        << "/" << flow.localTime.tm_year + 1900 << endl;
                        break;
                        //semnaleaza sfarsitul unui flow
                    }

                    }
                    contor++;
                }

            }
        }
        if(ok == 0)
            cout<<"Flow-ul nu exista\n";
    }


    void sterge_flow()
    {
        cout<<"Numele flow-ului pe care doriti sa-l stergeti:\n";
        string a;
        cin >> a;
        int ok = 1, index;

        auto it = find_if(vector_Flows.begin(), vector_Flows.end(), [&](Flow flow)
        {
            return flow.get_TITLE_titlu() == a;
        });

        if (it != vector_Flows.end())
        {
            ok = 0;
            vector_Flows.erase(it);
            std::cout << "Flow-ul a fost sters cu succes din vector_Flows.\n";
        }

        if (ok == 1)
        {
            std::cout << "Flow-ul nu a fost gasit in vector_Flows.\n";
        }
    }

    void analitics_flow()
    {
        string r;
        int ok = 1;
        cout<<"Numele flow-ului pentru care vreti sa afisati analitics.\n";
        cin >> r;
        for(Flow flow : vector_Flows)
        {
            if( flow.get_TITLE_titlu() == r)
            {
                cout << "Flow-ul a fost rulat de " <<flow.numar_start<<" ori\n";
                cout << "\n--Erori afisate pentru fiecare step--\n";
                cout << "Erori Step TITLE:" << flow.erori_step1 << endl;
                cout << "Erori Step TEXT:" << flow.erori_step2 << endl;
                cout << "Erori Step TEXT INPUT:" << flow.erori_step3 << endl;
                cout << "Erori Step NUMBER INPUT:" << flow.erori_step4 << endl;
                cout << "Erori Step CALCULUS:" << flow.erori_step5 << endl;
                cout << "Erori Step DISPLAY:" << flow.erori_step6 << endl;
                cout << "Erori Step TEXT FILE:" << flow.erori_step7 << endl;
                cout << "Erori Step CSV FILE:" << flow.erori_step8 << endl;
                cout << "Erori Step OUTPUT:" << flow.erori_step9 << endl;
                cout << "Erori Step END:" << flow.erori_step10 << endl;
                cout << "Numarul average de erori pentru flow: " << (flow.erori_total / 10) << endl ;
                ok = 0;
            }
        }

        if(ok == 1){
            cout << "Flow-ul nu exista\n";
        }

    }

};

class Meniu
{
public:
    Meniu(Actiuni_Flows Obiect)
    {
        int alegere;
        while(1)
        {
            cout << "\nAlegeti optiunea:\n";
            cout << "1.Creare flow now\n";
            cout << "2.Run la flow existent\n";
            cout << "3.Sterge un flow din sistem\n";
            cout << "4.Analitics pentru un flow existent\n";
            cout << "5.Afisare flows\n";
            cout << "6.Incheiere program\n\n";

            cin >> alegere;

            switch(alegere)
            {
            case 1:
                Obiect.creare_flow();
                break;
            case 2:
                Obiect.afisare_flows();
                Obiect.run_flow();
                break;
            case 3:
                Obiect.afisare_flows();
                Obiect.sterge_flow();
                break;
            case 4:
                Obiect.afisare_flows();
                Obiect.analitics_flow();
                break;
            case 5:
                Obiect.afisare_flows();
                break;
            }
            if(alegere == 6)
            {
                break;
            }
        }
    }
};

int main(){
    Actiuni_Flows actiuni_flows;
    Meniu meniu(actiuni_flows);
}