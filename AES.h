#ifndef __AES_H__ 
#define __AES_H__ 

class AES    
{ 
public: 
  AES(unsigned char* key); 
  /*define encryption process functions*/
  unsigned char* Encip(unsigned char* input); 
  unsigned char* Decip(unsigned char* input); 
 
private: 
  static unsigned char Sbox[256]; 
  static unsigned char InvSbox[256]; 
  unsigned char w[11][4][4]; //expanded keys
 
  /* expand keys: 128 bits -> 44*32 bits*/ 
  void KeyExp(unsigned char* key, unsigned char w[][4][4]); 
  /*  GF(2^8) */
  unsigned char GFmul(unsigned char a, unsigned char b); 
 
  /*define encryption operation functions*/
  void SubBytes(unsigned char state[][4]); // replacement
  void ShiftRows(unsigned char state[][4]); // shift rows
  void MixColumns(unsigned char state[][4]); // mix columns
  void AddRoundKey(unsigned char state[][4], unsigned char key[][4]); // addRound Keys
 
  /*define decryption process*/ 
  void InvSubBytes(unsigned char state[][4]); 
  void InvShiftRows(unsigned char state[][4]); 
  void InvMixColumns(unsigned char state[][4]); 
  /*reverse implement of encryption operation functions*/
}; 
 
#endif
