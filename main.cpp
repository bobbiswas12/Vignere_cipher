#include <iostream>
#include <string>
using namespace std;

string encrypt(string deciphered, string key){
  int k = deciphered.size();
  string newkey = "";
  while (newkey.size()<=k){
    newkey+=key;
  }
  newkey = newkey.substr(0,k);

  string ciphered = "";
  for (int i = 0; i < k; i++){
    char current = deciphered[i];
    char key_char = toupper(newkey[i]);  
    int shift = key_char - 'A';
    
    if ((int) current <= 90 and (int) current >= 65){
      char new1 = (char) ((current - 'A' + (newkey[i] - 'A'))%26 + 'A');
      ciphered+=new1;
    }
    else if((int) current <=122 and (int) current >= 97){
      char upper_current = toupper(current); 
      char new1 = (char)((upper_current - 'A' + shift) % 26 + 'A');  
      ciphered += tolower(new1);
    }
    else{
      ciphered+=current;
    }
  }
  return ciphered;
}


string decrypt(string ciphered, string key){
    int k = ciphered.size();      
    string newkey = "";

    while (newkey.size() < k){
        newkey += key;
    }
    newkey = newkey.substr(0, k);

    string deciphered = "";
    for (int i = 0; i < k; i++){
        char current = ciphered[i];
        char key_char = toupper(newkey[i]);  
        int shift = key_char - 'A';

        if (current >= 'A' && current <= 'Z'){
            char new1 = (char)((current - 'A' - shift + 26) % 26 + 'A');  
            deciphered += new1;
        }
        else if (current >= 'a' && current <= 'z'){
            char upper_current = toupper(current);
            char new1 = (char)((upper_current - 'A' - shift + 26) % 26 + 'A');  
            deciphered += tolower(new1);
        }
        else {
            deciphered += current; 
        }
    }
    return deciphered;
}

int main(){
  int what;
  cout<<"Enter 0 for encryption and 1 for decryption"<<endl;
  cin>>what;
  string key;
  cout<<"Enter your key"<<endl;
  cin>>key;
  
  if (what == 0){
    string deciphered;
    cout<<"Enter the deciphered string"<<endl;
    cin>>deciphered;
    cout<<"Ciphered string"<<endl;
    cout<<encrypt(deciphered,key)<<endl;
  }
  else{
    string ciphered;
    cout<<"Enter the ciphered string"<<endl;
    cin>>ciphered;
    cout<<"Deciphered string"<<endl;
    cout<<decrypt(ciphered,key)<<endl;
  }
  return 0;
}
