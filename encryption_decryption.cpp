//Name: Anastassiya Neznanova
//ID: 1093
//MAC281, Section 3013
//Project 1, Part 2
//This program encrypts and decrypts text messages using chift cipher method.
#include <iostream>
#include <string>
using namespace std;

string encrypt(string text, int key);
string decrypt(string text, int key2);

int main()
{
	string text;
	int key;
    int choice;
    
    cout << "Enter your text message with capital letters:" << endl;
	getline(cin, text);//takes user's message
    
	cout << "Enter your key (positive integer less than 26):" << endl;
	cin >> key;
    
    cout<<"Enter 1 to encrypt, 2 to decrypt";
    cin>>choice;
    
    if(choice==1){
     	cout << "Encrypted: " << encrypt(text, key) << endl;// choice one calls function encrypt
    }
    else if(choice==2){
        cout << "Decrypted: " << decrypt(text, key) << endl;//choice two calls function decrypt
    }
    system("pause");
	return 0;
}

 string encrypt(string text, int key){//function that encrypts the shift cipher
	
    for (int i = 0; i < text.length(); i++){
            if (text[i]!=' ') //if not equal the space then check
            if('A'>=text[i]||text[i]<='Z'){ // checks if text between char A to Z
                text[i] = toupper((text[i]-'A')+key)%26 +'A';// shifts each letter by key(int input from user)
            }
        }
    return text;//returns encrypted text
    }

 string decrypt(string text1, int key1){ //decryption function
	
    for (int i = 0; i < text1.length(); i++){
            if (text1[i]!=' ')  //if not equal the space then check
            if('A'>=text1[i]||text1[i]<='Z'){ // checks if text between char A to Z
                text1[i] = toupper((text1[i])-'Z'-key1)%26+'Z'; //shifts each letter by -key(int input from user)
            }
        }
     return text1;//returns decremented text
    }