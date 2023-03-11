#include<iostream>
#include<fstream>
#include<string>
#include <typeinfo>
#include <cmath>
using namespace std;

//================
//MASTER REPO
//created :2023-02-17[read file with print functonality]{error pCheck(43) non congruent value(should == print) but  == !┐÷ char to string conversion error suspected}
//Revisions:
//-->2023-02-18[print function works]{error only executes one line}
//-->2023-02-19[line read fixed start on varible system]
//-->2023-02-21[check var causing issues]
//-->2023-02-27[add arithmatic functonality and intergrate php]
//-->2023-03-01[car trip lol continue with inline entry functonlity]
//-->2023-03-07[arithmatic and git repo created]
//-->2023-03-08[add run --/--continue integration(webMode)]
//-->2023-03-09[fix webmode inf]
//-->2023-03-10[locked out(core dump issues)]
//================

//Globals
int pos[1000];
string pointer[1000];
string VAL[1000];
double VALopp[1000];
//make sure memSize and the size of pointer ==
int memSize = 1000;
int NAMECOUNT = 0;
bool debugMode = false;
bool isWebMode = false;
string key = "@8901262g2h2jk21";
//
string getfile(string fileName){
    ifstream read(fileName);
    string dataS;
    string FOO;
    while(getline (read, dataS)){
        FOO += "-" + dataS + "|";
    }
    read.close();
    return FOO;
}
string splitCONSOL(){
    string input;
    string foo;
    while(true){
        getline(cin >> ws, foo);
        input += "-"+foo+"|";
        if(foo == "run"){
            break;
        }
    }
    return input;
}
string setUp(){
    string mode;
    if(!(debugMode) && !(isWebMode)){
    cout<<"Enter read mode(file, inline):";
    cin>>mode;
    }
    string foo;
    if(isWebMode){
        foo = getfile("temp.simple");
    }
    else if(mode =="file" && !(debugMode)){
        cout<<"Enter file name(.simple filetype auto fills):";
        cin>>foo;
        foo = getfile(foo+".simple");
    }
    else if(mode == "inline" || debugMode){
        foo = splitCONSOL();
    }
    return foo;
}
int splice(string dataI){
    int BAR =0;
    char test1 = '|';
    char test2 = '-';
    for(int i =0; i<dataI.length(); i++){
        if(dataI[i] == test1 || dataI[i] == test2){
            pos[BAR] = i;
            BAR++;
        }
    }
    return BAR;
}
bool pCheck(string functionLine){
    string lineToString[5];
    for(int i = 0; i< 5; i++){
        string temp;
        lineToString[i] = functionLine[i];
    }
    string temp = lineToString[0] + lineToString[1] + lineToString[2] + lineToString[3] + lineToString[4];
    if(temp == "print"){
        return true;
    }
    return false;
}
int pExecute(string FOO){
    string newLine;
    if(isWebMode){
        newLine = "<br>";
    }
    else{
        newLine ="\n";
    }

    char test = '"';
    char test2 = ' ';
    if(FOO[5] == test){
        int temp=0;
        string print;
        bool element = true;
        while(element){
            if(FOO[6+temp] == test){
                print += newLine;
                cout<<print;
                return 0;
            }
            print += FOO[6+temp];
            temp++;
        }
    }
    else if(FOO[5] == test2){
        string temp;
        bool isNAME = true;
        int i =6;
        while(isNAME){
            if(i==(FOO.length()-1)){
                isNAME = false;
            }
            temp += FOO[i];
            i++;
        }
        for(int i =0; i< 1000; i++){
            string out;
            if(pointer[i] == temp){
                if(VAL[i] == key){
                    cout<<VALopp[i];
                }
                else{
                    cout<<VAL[i];
                }
                cout<<newLine;
                return 0;
            }
        }
    }
    return 1;    
}
bool vCheck(string functionLine){
    string lineToString[3];
    for(int i = 0; i< 3; i++){
        string temp;
        lineToString[i] = functionLine[i];
    }
    string temp = lineToString[0] + lineToString[1] + lineToString[2];
    if(temp == "VAR"){
        return true;
    }
    return false;
}
int vExecute(string FOO){
    char test = ' ';
    string temp;
    int i =4;
    while(true){
        if(FOO[i]==test){
            break;
        }
        temp += FOO[i];
        i++;
    }
    pointer[NAMECOUNT] =temp;
    temp = "";
    i++;
    while(true){
        temp += FOO[i];
        if(i>=FOO.length()-1){
            break;
        }
        i++;
    }
    VAL[NAMECOUNT] = temp;
    NAMECOUNT ++;
    return 0;
}
void intergerO(string c, string a, string b, char opperation){
    double temp[2];
    int store;
    bool VARa = false;
    bool VARb = false;
    for(int i =0; i<memSize; i++){
        if(a == pointer[i] && VAL[i] != key){
            temp[0] = stod(VAL[i]);
            VARa = true;
        }
        else{
            temp[0] = VALopp[i];
        }
        if(b == pointer[i] && VAL[i] != key){
            if(VAL[i] == "")
            temp[1]= stod(VAL[i]);
            VARb = true;
        }
        else{
            temp[1] = VALopp[i];
        }
        if(c == pointer[i]){
            store = i;
        }
    }
    if(!(VARa)){temp[0] = stod(a);}
    if(!(VARb)){temp[1] = stod(b);}
    int tempINT[2] = {(int)temp[0], (int)temp[1]};

    if(opperation == '+'){
        double BAR  = round((temp[0]+temp[1]));
        VALopp[store] = BAR;
        VAL[store] = key;
    }
    else if(opperation == '-'){
        double BAR  = round((temp[0]*temp[1])*100)/100.0;
        VALopp[store] = BAR;
        VAL[store] = key;
    }
    else if(opperation == '*'){
        double BAR = round((temp[0]*temp[1])*100)/100.0;
        VALopp[store] = BAR;
        VAL[store] = key;
    }
    else if(opperation == '%'){
        VALopp[store] = tempINT[0]%tempINT[1];
        VAL[store] = key;
    }
    else{
        double BAR = round((temp[0]/temp[1])*100)/100.0;
        VALopp[store] = BAR;
        VAL[store] = key;
    }
}
int mCU(string functionLine){
    string temp;
    string product;
    string reactants[2];
    int i =0;
    while(true){
        if(functionLine[i] == '='){
            break;
        }
        temp += functionLine[i];
        i++;
        if(i>functionLine.length()){
            return 0;
        }
    }
    product = temp;
    temp ="";
    i++;
    char opperation;
    while(true){
        if(functionLine[i] == '+' || functionLine[i] == '-' || functionLine[i] == '*' || functionLine[i] == '/' || functionLine[i] == '%' || i>functionLine.length()){
            opperation = functionLine[i];
            break;
        }
        temp += functionLine[i];
        i++;
    }
    reactants[0] = temp;
    temp ="";
    i++;
    while(true){
        temp += functionLine[i];
        if(i>=functionLine.length()-1){
            break;
        }
        i++;
    }
    reactants[1] = temp;
    intergerO(product, reactants[0], reactants[1], opperation);
    return 0;
}
bool fCheck(string data){
    string lineToString[3];
    for(int i = 0; i< 3; i++){
        string temp;
        lineToString[i] = data[i];
    }
    string temp = lineToString[0] + lineToString[1] + lineToString[2];
    if(temp == "for"){
        return true;
    }
    return false;
}
int fExecute(string data){
    return 0;
}
class loopExecute {
    public:
        string data;
        int Start;
        int End;
        int step;
        string iName;
        loopExecute(){
            for(int i = Start; i<End; i+=step){
                
            }
        }
};
class callLine {
    public:
        string blockReturn(int currentLine, string dataI){
            string FOO;
            for(int x = pos[currentLine]+1; x<(pos[currentLine+1]);x++){
                FOO += dataI[x];
            }
            return FOO;
        }
};
class executeLine{
    public:
        void callBack(string currentData){
            //check all possible functions
            bool isPrint = pCheck(currentData);
            bool isVAR = vCheck(currentData);
            bool isFOR = fCheck(currentData);
            //expresion check/execute
            int isM = mCU(currentData);
            //fuction execute
            if(isPrint){ int p = pExecute(currentData);}
            else if(isVAR){ int v = vExecute(currentData);}
            else if(isFOR){ 
                int f = fExecute(currentData);
            }
        }
};
void callBlocks(string dataI, int numLines){
    for(int i = 0; i<numLines; i+=2){
        //current data splice
        callLine currentStack;
        string FOO = currentStack.blockReturn(i, dataI);
        executeLine currentInstruction;
        currentInstruction.callBack(FOO);
        
    }
}
int main(){
    string data = setUp();
    int Lines = splice(data);
    callBlocks(data, Lines);
    return 0;
}
