#include<iostream>
#include<fstream>
#include<string>
#include <typeinfo>
#include <cmath>
using namespace std;
//created :2023-02-17 by Christian Rogers

//Globals///////////////////////////
int pos[1143];
string pointer[1143];
string VAL[1143];
double VALopp[1143];
//make sure memSize and the size of pointer ==
int memSize = 1143;
int NAMECOUNT = 0;
//mode selector//
bool debugMode = true;
bool isWebMode = false;
//
string key = "@8901262g2h2jk21";
int Lines;
int currentLineG;
string dataRAW;
//for loop globlas that handel inderpreture distortion of code block
string forTemp;
string intermediateS;
bool intermediateB = false;
bool intermediateB1 = false;
bool intermediateB2 = false;
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
        string keyV;
        int conversion(){
            int keyConversion =0;
            for(int i =0; i<3; i++){
                if(i>keyV.length()){ break;}
                keyConversion += (int)keyV[i];
            }
            return keyConversion*3;
        }
        int addItemToMem(){
            int keyConversion = conversion();
            for(int i = keyConversion; i<memSize;i++){
                if(pointer[i] == "" ||  pointer[i] == keyV){
                    pointer[i] = keyV;
                    return i;
                }
            }
            return -1;
        }
        int findItemInMem(){
            int keyConversion = conversion();
            for(int i = keyConversion; i<memSize;i++){
                if(pointer[i] == keyV){
                    return i;
                }
            }
            
            return -1;
        }
};
class intToString{
    public:
        string splice[1000];
        string foo;
        string ctos(char a){
            string temp;
            switch (a){
                case '0': temp = "0";break;
                case '1': temp = "1";break;
                case '2': temp = "2";break;
                case '3': temp = "3";break;
                case '4': temp = "4";break;
                case '5': temp = "5";break;
                case '6': temp = "6";break;
                case '7': temp = "7";break;
                case '8': temp = "8";break;
                case '9': temp = "9";break;
            }
            return temp;

        }
        string nameSplice(string in){
            static string base[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
            static string teen[] = {"eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eighteen", "nineteen"};
            static string base10[] = {"", "ten", "twenty", "thirty", "fourty", "fivety", "sixty", "seventy", "eighty", "ninety"};
            string p[3] = {ctos(in[0]), ctos(in[1]), ctos(in[2])};
            string out = "";
            string teenS = "";
            if(p[1] == "1" && p[2] != "0"){
                teenS = teen[stoi(p[2])-1];
            }
            string hundred = "";
            //set up hundred join
            if(p[0] != "0"){
                hundred =" hundred ";
                if(p[1] != "" || p[2] != ""){
                    hundred = " hundred and ";
                }
            }
            //base ten dash
            string dash ="";
            if(p[1] != "0" && p[2] != "0"){
                dash = "-";
            }
            string foo = base10[stoi(p[1])]+ dash+ base[stoi(p[2])];
            if(teenS != ""){
                foo = teenS;
            }
            out = base[stoi(p[0])]+hundred+foo;
            return out;
            
        }
        string returnS(string Num){
            int count = 0;
            if(Num.length()%3!=0){
                Num = "0"+Num;
                if(Num.length()%3!=0){Num = "0"+Num;}
            }
            for(int i =(Num.length()/3)-1; i>-1;i-=1){

                splice[i] = ctos(Num[count])+ctos(Num[count+1])+ctos(Num[count+2]);
                count+=3;
            }
            return Num;
        }
        string joinbigBois(int num){
            static string bigBois[] ={"", "thousand", "million", "billion", "trillion", "Quadrillion", "Quintillion", "Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion", "Undecillion", "Duodecillion", "Tredecillion", "Quattuordecillion", "Quindecillion", "Sedecillion", "Septendecillion", "Octodecillion", "Novendecillion", "Vigintillion", "Unvigintillion", "Duovigintillion", "Tresvigintillion", "Quattuor­vigint­illion", "Quinvigintillion", "Sesvigintillion", "Septemvigintillion", "Octovigintillion", "Novemvigintillion", "Trigintillion", "Untrigintillion", "Duotrigintillion", "Trestrigintillion", "Quattuor­trigint­illion", "Quintrigintillion", "Sestrigintillion", "Septentrigintillion", "Octotrigintillion", "Noventrigintillion", "Quadragintillion"};
            static string prefixbase1[] = {"", "un", "duo", "tre", "quattuor", "quinqua", "se", "septe", "octo", "nove"};
            static string prefixvaseten[] = {"", "Deci", "viginti", "vriginta", "quadraginta", "quinquaginta", "sexaginta", "septuaginta", "octoginta", "nonaginta"};
            static string prefixbasehun[] = {"", "centi",  "ducenti", "trecenti", "quadringenti", "quingenti", "sescenti", "septingenti", "octingenti", "nongenti"};
            int o =num%10;
            int t = ((num%100)-o)/10;
            int h = (num-o-t)/100;
            int thou = (num-(num%1000))/1000;
            string biggestBoi = "";
            if(thou>0){
                int one =thou%10;
                int ten = ((thou%100)-o)/10;
                int hund = (thou-o-t)/100;
                biggestBoi = prefixbasehun[hund]+prefixvaseten[ten]+prefixbase1[one]+" millinillion ";
            }
            string out = biggestBoi+ prefixbasehun[h]+prefixvaseten[t]+prefixbase1[o]+"illion";
            return out;
        }
        string Starrt(){
            static string bigBois[] ={"", "thousand", "million", "billion", "trillion", "Quadrillion", "Quintillion", "Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion", "Undecillion", "Duodecillion", "Tredecillion", "Quattuordecillion", "Quindecillion", "Sedecillion", "Septendecillion", "Octodecillion", "Novendecillion", "Vigintillion", "Unvigintillion", "Duovigintillion", "Tresvigintillion", "Quattuor­vigint­illion", "Quinvigintillion", "Sesvigintillion", "Septemvigintillion", "Octovigintillion", "Novemvigintillion", "Trigintillion", "Untrigintillion", "Duotrigintillion", "Trestrigintillion", "Quattuor­trigint­illion", "Quintrigintillion", "Sestrigintillion", "Septentrigintillion", "Octotrigintillion", "Noventrigintillion", "Quadragintillion"};
            foo = returnS(foo);
            string out ="";
            string endTemp;
            for(int i = 0; i<foo.length()/3; i++){
                if(i >=41){
                    out = " "+nameSplice(splice[i]) +" "+joinbigBois(i)+out;
                }
                else{
                    out = " "+nameSplice(splice[i]) +" "+bigBois[i]+out;
                }
            }
            return out;
        }
};
void itosCheck(string functionLine){
    //isaacIsBad()
    string lineToString[10];
    for(int i = 0; i< 10; i++){
        string temp;
        lineToString[i] = functionLine[i];
    }
    string temp = lineToString[0] + lineToString[1] + lineToString[2] + lineToString[3] + lineToString[4]+ lineToString[5]+lineToString[6]+lineToString[7]+lineToString[8]+lineToString[9];
    if(temp == "isaacIsBad"){
        string temp="";
        for(int i = 11; i< functionLine.length()-2; i++){
            temp+=functionLine[i];
        }
        intToString isaac;
        isaac.foo = temp;
        string print = isaac.Starrt();
        cout<<print+"\n";
    }
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
        memory print;
        print.keyV = temp; 
        int index = print.findItemInMem();
        if(VAL[index] == key){ cout<<VALopp[index];}
        else{ cout<<VAL[index];}
        cout<<newLine;    
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
    i++;
    while(true){
        temp[1] += FOO[i];
        if(i>=FOO.length()-1){
            break;
        }
        i++;
    }
    //memory add
    memory add;
    add.keyV = temp[0];
    int index = add.addItemToMem();
    VAL[index] = temp[1];
    pointer[index] =temp[0];
    // {old implemetation VAL[NAMECOUNT] = temp;
    // NAMECOUNT ++;
    //
    return 1;
}
void intergerO(string c, string a, string b, char opperation){
    double temp[] = {0, 0};
    int store = 0;
    bool nonVARa = false;
    bool nonVARb = false;
    ///memory call
    memory findA;
    findA.keyV = a;
    int index = findA.findItemInMem();
    if(index == -1){ nonVARa = true;}
    else if(VAL[index] == key){ temp[0] = VALopp[index];}
    else{ temp[0] = stod(VAL[index]);}
    if(b != ""){ 
        memory findB;
        findB.keyV = b;
        index = findB.findItemInMem();
        if(index == -1){ nonVARb =true;}
        else if(VAL[index] == key){ temp[1] = VALopp[index];}
        else{ temp[1] = stod(VAL[index]);}

    }
    memory findC;
    findC.keyV = c;
    index = findC.findItemInMem();
    ////
    if(nonVARa){temp[0] = stod(a);}
    if(nonVARb && opperation != 'n'){temp[1] = stod(b);}
    int tempINT[2];
    if(opperation != 'n'){
        tempINT[0] = (int)temp[0];
        tempINT[1] = (int)temp[1];
    }
    if(opperation == '+'){
        double BAR  = round((temp[0]+temp[1]));
        VALopp[index] = BAR;
        VAL[index] = key;
    }
    else if(opperation == '-'){
        double BAR  = round((temp[0]-temp[1])*100)/100.0;
        VALopp[index] = BAR;
        VAL[index] = key;
    }
    else if(opperation == '*'){
        double BAR = round((temp[0]*temp[1])*100)/100.0;
        VALopp[index] = BAR;
        VAL[index] = key;
    }
    else if(opperation == '%'){
        VALopp[index] = tempINT[0]%tempINT[1];
        VAL[index] = key;
    }
    else if(opperation == 'n'){
        VALopp[index] = temp[0];
        VAL[index] = key;
    }
    else{
        double BAR = round((temp[0]/temp[1])*100)/100.0;
        VALopp[index] = BAR;
        VAL[index] = key;
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
        if(i>=functionLine.length()){
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
bool booleanTest(string data){
    int i = 0;
    string a ="";
    string b ="";
    if(data == "true"){return true;}
    if(data == "false"){return false;}
    memory find;
    find.keyV = data;
    int indexFind = find.findItemInMem();
    if(indexFind != -1){
        if(VAL[indexFind] == "true"){return true;}
        if(VAL[indexFind] == "false"){return false;}   
    }
    while(true){
        if(data[i] == '='){i+=2; break;}
        a+=data[i];
        i++;
    }
    while(true){
        if(i >= data.length()){ break;}
        b+=data[i];
        i++;
    }
    memory findA;
    findA.keyV = a;
    int indexA = findA.findItemInMem();
    memory findB;
    findB.keyV = b;
    int indexB = findB.findItemInMem();
    string val[2];
    if(indexA == -1){val[0] = a;}
    else{
        if(VAL[indexA] == key){
            val[0] = VALopp[indexA];
        }
        else{
            val[0] = VAL[indexA];
        }
    }
    if(indexB == -1){val[1] = b;}
    else{
        if(VAL[indexB] == key){
            val[1] = VALopp[indexB];
        }
        else{
            val[1] = VAL[indexB];
        }
    }
    if(val[0] == val[1]){
        return true;
    }
    return false;
}
int iExecute(string data){
    //if(true){
        string temp;
    for(int i=3; i<data.length()-2; i++){
        temp += data[i];
    }
    bool isTrue = booleanTest(temp);
    if(isTrue){
        intermediateB1 =true;
    }
    else{
        intermediateB2 = true;
    }
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
            //
            if(currentData[0] != '$'){
                //check all possible functions
                bool isPrint = pCheck(currentData);
                bool isVAR = vCheck(currentData);
                bool isFOR = fCheck(currentData);
                bool isIF = iCheck(currentData);
                //expresion check/execute
                itosCheck(currentData);
                //fuction execute
                if(isPrint){ int p = pExecute(currentData);}
                else if(isVAR){ int v = vExecute(currentData);}
                else if(isFOR){ intermediateB =true;}
                else if(isIF){int i = iExecute(currentData);}
                //arithmitic last to avoid exeption
                else{
                    int isM = mCU(currentData);
                }
            }
        }
};
//brings all the parts together and interprets at "Line" when indexed 0-n
void callBlocks(int Line){
    callLine currentStack;
    string FOO = currentStack.blockReturn(Line);
    executeLine currentInstruction;
    currentInstruction.callBack(FOO); 
}
class ifExeptiom {
    public:
        void loop(bool isIFpass){
            string endTest = "}";
            int codeLineStart = currentLineG;
            int temp;
            currentLineG+=2;
            if(isIFpass){
                while(true){
                    callLine testEnd0;
                    string testE = testEnd0.blockReturn(codeLineStart);
                    if(testE == endTest){
                        temp = codeLineStart;
                        break;
                    }
                    codeLineStart+=2;
                }
                currentLineG = temp+2;
                return;
            }
            codeLineStart = currentLineG;
            while(true){
                callLine testEnd;
                string testE = testEnd.blockReturn(codeLineStart);
                if(testE == endTest){
                    temp = codeLineStart;
                    break;
                }
                callBlocks(codeLineStart);
                codeLineStart+=2;
            }
            currentLineG = temp+2;
        }
};
//fix logic so cuurentLineG is correct at end of loop
class loopExecute {
    public:
        void loop(int Start,int End,int step, string iName, bool isIF, bool isIFpass){

            string endTest = "]";
            if(isIF){
                endTest = "}";
            }
            int codeLineStart = currentLineG;
            int temp;
            currentLineG+=2;
            if(isIFpass){
                endTest = "}";
                while(true){
                    callLine testEnd0;
                    string testE = testEnd0.blockReturn(codeLineStart);
                    if(testE == endTest){
                        temp = codeLineStart;
                        break;
                    }
                    codeLineStart+=2;
                }
                currentLineG = temp+2;
                return;
            }
            isLoop = true;
            temp = vExecute("VAR "+iName+" "+ to_string(Start));
            for(int a = Start; a<End; a+=step){
                temp = mCU(iName+"="+to_string(a));
                codeLineStart = currentLineG;
                while(true){
                    callLine testEnd;
                    string testE = testEnd.blockReturn(codeLineStart);
                    if(testE == endTest){
                        temp = codeLineStart;
                        break;
                    }
                    if(testE[testE.length()-1] == '{'){
                        iExecute(testE);
                        ifExeptiom forIf;
                        forIf.loop(intermediateB2);
                        intermediateB1 =false;
                        intermediateB2 =false;
                        codeLineStart = currentLineG;
                        cout<<codeLineStart;
                        continue;
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
    loopC.loop(stoi(start), stoi(stop), stoi(increment), iName, false, false);
    return 1;
}

int main(){
    dataRAW = setUp();
    Lines = splice(dataRAW);
    for(int i = 0; i<Lines; i+=2){
        callBlocks(i);
        //the following cases create a seperate execute object for their specific use
        if(intermediateB){ 
            currentLineG = i;
            int temp = fExecute(intermediateS);
            i = currentLineG-2;
        }
        if(intermediateB1){ 
            currentLineG = i;
            loopExecute loopif;
            loopif.loop(0, 1, 1, "oiuoiuoiuhhh", true, false);
            i = currentLineG-2;
            intermediateB1 =false;
        }
        if(intermediateB2){ 
            currentLineG = i;
            loopExecute loopnIF;
            loopnIF.loop(0, 1, 1, "", false, true);
            i = currentLineG-2;
            intermediateB2 =false;
        }

    }
    return 1;
}
