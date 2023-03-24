#include<iostream>
#include<string>
using namespace std;
class intToString{
    public:
        string base[] = {"", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        string teen[] = {"eleven", "twelve", "thirteen", "fourteen", "fiveteen", "sixteen", "seventeen", "eighteen", "nineteen"};
        string base10[] = {"", "ten", "twenty", "thirty", "fourty", "fivety", "sixty", "seventy", "eighty", "ninety"};
        //42index or 40 pre-made prefic 
        string bigBois[] ={"", "thousand", "million", "billion", "trillion", "Quadrillion", "Quintillion", "Sextillion", "Septillion", "Octillion", "Nonillion", "Decillion", "Undecillion", "Duodecillion", "Tredecillion", "Quattuordecillion", "Quindecillion", "Sedecillion", "Septendecillion", "Octodecillion", "Novendecillion", "Vigintillion", "Unvigintillion", "Duovigintillion", "Tresvigintillion", "Quattuor­vigint­illion", "Quinvigintillion", "Sesvigintillion", "Septemvigintillion", "Octovigintillion", "Novemvigintillion", "Trigintillion", "Untrigintillion", "Duotrigintillion", "Trestrigintillion", "Quattuor­trigint­illion", "Quintrigintillion", "Sestrigintillion", "Septentrigintillion", "Octotrigintillion", "Noventrigintillion", "Quadragintillion"};
        string prefixbase1[] = {"", "un", "duo", "tre", "quattuor", "quinqua", "se", "septe", "octo", "nove"};
        string prefixvaseten[] = {"", "Deci", "viginti", "vriginta", "quadraginta", "quinquaginta", "sexaginta", "septuaginta", "octoginta", "nonaginta"};
        string prefixbasehun[] = {"", "centi",  "ducenti", "trecenti", "quadringenti", "quingenti", "sescenti", "septingenti", "octingenti", "nongenti"};
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
        int Starrt(){
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
            cout<<out;
        }
};
