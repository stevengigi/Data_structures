#include<iostream>
#include<cmath>
using namespace std;

class Class{
    public:
        string title;
        string name;
        int nums;

        Class(string atitle,string aname,int anums){
            title=atitle;
            name=aname;
            nums=anums;
            cout << title<< "  " << name << "  "<< nums << endl;
        }
        bool honor(){
            if(nums>4){
                return true;
            }else{
                return false;
            }
        }
};

int main(){
    string name="steven";
    int charage=10;
    double five =5;
    cout << name << ":" << charage << endl;
    cout << "length :"<< name.length() << endl; //length() retrun length
    cout << "find e :" << name.find("v",0) << endl; //find("string",start index)
    cout << "substr : " << name.substr(2,3)<<endl; //substr(start index, len)
    cout << "pow" << pow(5,2) << endl;
    cout << "floor : "<< floor(4.6)<< endl ; // 無條件捨去
    cout << "ceil : " << ceil(4.1) << endl; //無條件進位
    Class one("classB","CHEN",54);
    cout << one.honor()<< endl;

    return 0;
}