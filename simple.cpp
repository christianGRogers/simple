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
//-->2023-03-11[organize classes and add for]{decleration order issue start fix at 324}
//-->2023-03-12[]
//-->2023-03-13[got for working with php integration]{error with code stack return at end of for loop}
//-->2023-03-14[fix one issue and discover another (start with currentLineG's use int the loop execute class)]
//-->2023-03-15[fix line return after loop and add hash map for memory]{logic error 372}
//-->2023-03-16[return line fixed]
//-->2023-03-17[]
//================
//Globals///////////////////////////
int pos[1143];
string pointer[1143];
string VAL[1143];
double VALopp[1143];
//make sure memSize and the size of pointer ==
int memSize = 1143;
int NAMECOUNT = 0;
//mode selector//
bool debugMode = false;
bool isWebMode = true;
//
string key = "@8901262g2h2jk21";
int Lines;
int currentLineG;
string dataRAW;
//for loop globlas that handel inderpreture distortion of code block
string forTemp;
string intermediateS;
bool intermediateB = false;
bool isLoop = false;
////////////////////////////////////
string getfile(string fileName){
    ifstream read(fileName);
    string dataS;
    string FOO;
    while(getline (read, dataS)){
        dataS.erase(dataS.find_last_not_of(" \n\r\t")+1);
        FOO += "&" + dataS + "|";
    }
    read.close();
    return FOO;
}
string splitCONSOL(){
    string input;
    string foo;
    while(true){
        getline(cin >> ws, foo);
        foo.erase(foo.find_last_not_of(" \n\r\t")+1);
        input += "&"+foo+"|";
        if(foo == "run"){
            break;
        }
    }
    return input;
}
string setUp(){
    string mode;
    string foo;
    if(!(debugMode) && !(isWebMode)){
    cout<<"Enter read mode(file, inline):";
    cin>>mode;
    }
    else if(isWebMode || debugMode){
        foo = getfile("temp.simple");
    }
    else if(mode =="file"){
        cout<<"Enter file name(.simple filetype auto fills):";
        cin>>foo;
        foo = getfile(foo+".simple");
    }
    else if(mode == "inline"){
        foo = splitCONSOL();
    }
    return foo;
}
int splice(string dataI){
    int BAR =0;
    char test1 = '|';
    char test2 = '&';
    for(int i =0; i<dataI.length(); i++){
        if(dataI[i] == test1 || dataI[i] == test2){
            pos[BAR] = i;
            BAR++;
        }
    }
    return BAR;
}
class memory{
    public:
        string key;
        int conversion(){
            int keyConversion;
            for(int i =0; i<3; i++){
                if(i>key.length()){ break;}
                keyConversion += (int)key[i];
            }
            return keyConversion*3;
        }
        int addItemToMem(){
            int keyConversion = conversion();
            for(int i = keyConversion; i<memSize-keyConversion;i++){
                if(pointer[i] == "" ||  pointer[i] == key){
                    pointer[i] = key;
                    cout<<i;
                    return i;
                }
            }
            return memSize+10;
        }
        int findItemInMem(){
            int keyConversion = conversion();
            for(int i = keyConversion; i<memSize-keyConversion;i++){
                if(pointer[i] == key){
                    return i;
                }
            }
            cout<<"{Element "+ key+" has not been declared}";
        }
};
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
    int modeDIFF = 0;
    //if(isLoop && isWebMode){ modeDIFF = 1;}
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
        while(true){
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
        int i =6;
        while(true){
            if(i>=(FOO.length()-modeDIFF)){//-modeDiff?
                break;
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
    string temp[2];
    int i =4;
    while(true){
        if(FOO[i]==test){
            break;
        }
        temp[0] += FOO[i];
        i++;
    }
    pointer[NAMECOUNT] =temp[0];
    i++;
    while(true){
        temp[1] += FOO[i];
        if(i>=FOO.length()-1){
            break;
        }
        i++;
    }
    memory add;
    add.key = temp[0];
    int index = add.addItemToMem();
    VAL[index] = temp[1];
    // VAL[NAMECOUNT] = temp;
    // NAMECOUNT ++;
    return 1;
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
        else if(a == pointer[i] && VAL[i] == key){
            temp[0] = VALopp[i];
        }
        if(b == pointer[i] && VAL[i] != key){
            if(VAL[i] == "")
            temp[1]= stod(VAL[i]);
            VARb = true;
        }
        else if(b == pointer[i] && VAL[i] == key){
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
    else if(opperation == 'n'){
        VALopp[store] = tempINT[0];
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
        if(i>functionLine.length()){
            opperation ='n';
            reactants[0] = temp;
            intergerO(product, reactants[0], "1", opperation);
            return 1;
        }
        else if(functionLine[i] == '+' || functionLine[i] == '-' || functionLine[i] == '*' || functionLine[i] == '/' || functionLine[i] == '%'){
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
    return 1;
}
bool fCheck(string data){
    string lineToString[3];
    for(int i = 0; i< 3; i++){
        string temp;
        lineToString[i] = data[i];
    }
    string temp = lineToString[0] + lineToString[1] + lineToString[2];
    if(temp == "for"){
        forTemp = data;
        return true;
    }
    return false;
}
bool iCheck(string data){
    string lineToString[2];
    for(int i = 0; i< 2; i++){
        string temp;
        lineToString[i] = data[i];
    }
    string temp = lineToString[0] + lineToString[1];
    if(temp == "if"){
        forTemp = data;
        return true;
    }
    return false;
}
int iExecute(string data){
    return 0;
}
//when calling lines(return line data) multiply numlines*2 and index at even integers starting at 0
class callLine {
    public:
        string blockReturn(int Line){
            string FOO;
            for(int x = pos[Line]+1; x<(pos[Line+1]);x++){
                FOO += dataRAW[x];
            }
            return FOO;
        }
};
class executeLine{
    public:
        void callBack(string currentData){
            intermediateS = currentData;
            //check all possible functions
            bool isPrint = pCheck(currentData);
            bool isVAR = vCheck(currentData);
            bool isFOR = fCheck(currentData);
            bool isIF = iCheck(currentData);
            //expresion check/execute
            int isM = mCU(currentData);
            //fuction execute
            if(isPrint){ int p = pExecute(currentData);}
            else if(isVAR){ int v = vExecute(currentData);}
            else if(isFOR){ intermediateB =true;}
            else if(isIF){int i = iExecute(currentData);}
        }
};
//brings all the parts together and interprets at "Line" when indexed 0-n
void callBlocks(int Line){
    callLine currentStack;
    string FOO = currentStack.blockReturn(Line);
    executeLine currentInstruction;
    currentInstruction.callBack(FOO); 
}
//fix logic so cuurentLineG is correct at end of loop
class loopExecute {
    public:
        void loop(int Start,int End,int step, string iName){
            isLoop = true;
            currentLineG+=2;
            int codeLineStart;
            int temp;
            temp = vExecute("VAR "+iName+" "+ to_string(Start));
            for(int a = Start; a<End; a+=step){
                temp = mCU(iName+"="+to_string(a));
                codeLineStart = currentLineG;
                while(true){
                    callLine testEnd;
                    string testE = testEnd.blockReturn(codeLineStart);
                    if(testE == "]"){
                        temp = codeLineStart;
                        break;
                    }
                    callBlocks(codeLineStart);
                    codeLineStart+=2;
                }
            }
            currentLineG = temp+2;
            intermediateB = false;
            isLoop = false;
        }
};
int fExecute(string data){
    int part = 0;
    string start;
    string stop;
    string increment;
    string iName;
    //newline is interpreted differently via php
    int modeDIFF = 2;
    //if(isWebMode){ modeDIFF = 3;}
    for(int i =4; i<forTemp.length()-modeDIFF; i++){
        if(forTemp[i] == '~' ||forTemp[i]== '>'|| forTemp[i]== '('){
            part++;
            i++;
        }
        switch (part){
            case 0:
                start +=forTemp[i];
                break;
            case 1:
                increment+=forTemp[i];
                break;
            case 2:
                stop +=forTemp[i];
                break;
            case 3:
                iName +=forTemp[i];
                break;
        }
    }
    loopExecute loopC;
    loopC.loop(stoi(start), stoi(stop), stoi(increment), iName);
    return 1;
}
int main(){
    dataRAW = setUp();
    Lines = splice(dataRAW);
    for(int i = 0; i<Lines; i+=2){
        callBlocks(i);
        if(intermediateB){ 
            currentLineG = i;
            int temp = fExecute(intermediateS);
            i = currentLineG-2;
        }
    }
    return 1;
}
