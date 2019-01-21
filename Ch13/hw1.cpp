#include <string>
#include <iostream>

using namespace std;
void input_name_by_pointer(string *p_first, string *p_last){
    cout << "input name by pointer." << endl << "성" << endl;
    cin >> *p_first;
    cout << "이름" << endl;
    cin >> *p_last;
}
void input_name_by_ref(string& f_name, string& l_name){
    cout << "input name by reference." << endl << "성" << endl;
    cin >> f_name;
    cout << "이름" << endl;
    cin >> l_name;
}

int main(){
    string first_name;
    string last_name;

    input_name_by_pointer(&first_name, &last_name);
    cout << first_name<< endl;
    cout << last_name << endl;

    first_name = "";
    last_name = "";

    string& ref_first = first_name;
    string& ref_last = last_name;
    input_name_by_ref(ref_first, ref_last);

    cout << first_name << endl;
    cout << last_name << endl;

}
