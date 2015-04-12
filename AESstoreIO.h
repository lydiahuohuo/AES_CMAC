#ifndef __AESSTOREIO_H__ 
#define __AESSTOREIO_H__ 
#include <fstream> 
#include <vector> 
#include <iostream.h> 
#define BLOCKSIZE 16 
using namespace std; 
 
/*define I/O functions to implement AES*/ 
class AESstoreIO
{ 
  friend class AES; 
private: 
  vector<unsigned char *> PlainText, CipherText; 
  int input_size; 
public: 
  /**/
  AESstoreIO(unsigned char *input, int size, bool porc);
  /*Define functions of storaging input plain texts and output cipher texts*/
  unsigned char *PlainBlock(int); 
  unsigned char *CipherBlock(int); 
  void StorePlain(unsigned char *); 
  void StoreCipher(unsigned char *); 
  int size(); 
  /*print out the encryption and decryption results*/
  void printblock(unsigned char* state); 
  void printPlain(); 
  void printCipher(); 
 }; 
 #endif
