#include "AES.h" 
#include "AESstoreIO.h" 
#include "CMAC.h" 
 
void main() 
{ 
  
	unsigned char input[]=   
  { 
   0x00, 0x23, 0x45, 0x67,   
    0x89, 0xab, 0xcd, 0xef,   
    0xfe, 0xdc, 0xba, 0x98,   
    0x76, 0x54, 0x32, 0x10, 
  }; 
  
    unsigned char key[]=   
  { 
    0x0f, 0x15, 0x71, 0xc9,   
    0x47, 0xd9, 0xe8, 0x59,   
    0x0c, 0xb7, 0xad, 0xd6,   
    0xaf, 0x7f, 0x67, 0x98 
  }; 
 
    unsigned char zeros[]=   
  { 
    0x00, 0x00, 0x00, 0x00,   
    0x00, 0x00, 0x00, 0x00,   
    0x00, 0x00, 0x00, 0x00,   
    0x00, 0x00, 0x00, 0x00, 
  }; 
  AES aes(key); 
  CMAC cmac; 
  AESstoreIO store(input,sizeof(input),true),calkey1(zeros,sizeof(zeros),true); 
 
  printf("Input: %d bytes\n",sizeof(input)); 
  store.printPlain(); 
  
  int i; 
  for(i=1;i<=store.size();i++) 
    store.StoreCipher(aes.Encip(store.PlainBlock(i))); 
  cout<<"Ciphertext as follows:"<<endl; 
  store.printCipher(); 

  cout<<endl<<"After Decipher:"<<endl; 
  for(i=1;i<=store.size();i++) 
    store.printblock(aes.Decip(store.CipherBlock(i))); 
 
  cout<<endl<<"CMAC value:"<<endl; 
  store.printblock(cmac.AES_CMAC(store,calkey1,aes,8*BLOCKSIZE)); 
}