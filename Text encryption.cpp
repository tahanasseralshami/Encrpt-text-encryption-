#include<iostream>
 #include <istream>
#include <ostream>
#include <fstream>
#include <cstdlib>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
using namespace std;
string encryptionMessage(string Msg)
{
    string CTxt = "";
    int a = 3;
    int b = 6;
    for (int i = 0; i < Msg.length(); i++)
    {
        CTxt = CTxt + (char) ((((a * Msg[i]) + b) % 26) + 65);
    }
    return CTxt;
}
 
string decryptionMessage(string CTxt)
{
    string Msg = "";
    int a = 3;
    int b = 6;
    int a_inv = 0;
    int flag = 0;
    for (int i = 0; i < 26; i++)
    {
        flag = (a * i) % 26;
        if (flag == 1)
        {
            a_inv = i;
        }
    }
    for (int i = 0; i < CTxt.length(); i++)
    {
        Msg = Msg + (char) (((a_inv * ((CTxt[i] - b)) % 26)) + 65);
    }
    return Msg;
}
//call affint function
//call affint function
int affinn()
{
    cout << "Enter the message: ";
    string message;
    cin >> message;
    cout << "Message is :" << message;
    cout << "\nEncrypted Message is : " << encryptionMessage(message);
 
    cout << "\nDecrypted Message is: " << decryptionMessage(
            encryptionMessage(message));
}
 int caeser()
 {
 	char message[100], ch;
	int i, key;
	
	cout << "Enter a message to encrypt: ";
	cin.getline(message, 100);
	cin>>message;
	cout << "Enter key: ";
	cin >> key;
	
	for(i = 0; message[i] != '\0'; ++i){
		ch = message[i];
		
		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;
			
			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;
			
			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}
			
			message[i] = ch;
		}
	}
	
	cout << "Encrypted message: " << message;
	
	return 0;
 }
 
 
 
  // the rot13 function
std::string rot13(std::string s)
{
  static std::string const
    lcalph = "abcdefghijklmnopqrstuvwxyz",
    ucalph = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
 
  std::string result;
  std::string::size_type pos;
 
  result.reserve(s.length());
 
  for (std::string::iterator it = s.begin(); it != s.end(); ++it)
  {
    if ( (pos = lcalph.find(*it)) != std::string::npos )
      result.push_back(lcalph[(pos+13) % 26]);
    else if ( (pos = ucalph.find(*it)) != std::string::npos )
      result.push_back(ucalph[(pos+13) % 26]);
    else
      result.push_back(*it);
  }
 
  return result;
}
 
// function to output the rot13 of a file on std::cout
// returns false if an error occurred processing the file, true otherwise
// on entry, the argument is must be open for reading
int rot13_stream(std::istream& is)
{
  std::string line;
  while (std::getline(is, line))
  {
    if (!(std::cout << rot13(line) << "\n"))
      return false;
  }
  return is.eof();
}

 
int main(int argc, char* argv[])
{
		int haz;
	printf("the choices are :\n1-caeser\n2-affin\n3-root13\n");//this messege to explain to the users the choices
   scanf("%d",&haz);//here I see the chosen of the user
   switch(haz)
{
   case 1:
	printf("the choices are caeser\n ");
	caeser();
	break;
	case 2:
		printf("the choices are affin\n ");
	affinn();break;
   //////
   /////
   ////
   ////
   case 3:
   		printf("the choices are root13\n ");
   if (argc == 1) // no arguments given
    return rot13_stream(std::cin)? EXIT_SUCCESS : EXIT_FAILURE;
 
  std::ifstream file;
  for (int i = 1; i < argc; ++i)
  {
    file.open(argv[i], std::ios::in);
    if (!file)
    {
      std::cerr << argv[0] << ": could not open for reading: " << argv[i] << "\n";
      return EXIT_FAILURE;
    }
    if (!rot13_stream(file))
    {
      if (file.eof())
        // no error occurred for file, so the error must have been in output
        std::cerr << argv[0] << ": error writing to stdout\n";
      else
        std::cerr << argv[0] << ": error reading from " << argv[i] << "\n";
      return EXIT_FAILURE;
    }
    file.clear();
    file.close();
    if (!file)
      std::cerr << argv[0] << ": warning: closing failed for " << argv[i] << "\n";
  }
  return EXIT_SUCCESS;
   ;break;
		
		
}

}
