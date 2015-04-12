#include "AESstoreIO.h" 
  

AESstoreIO::AESstoreIO(unsigned char *input,int size,bool porc) 
{ 
  unsigned char *temp=input; 
  int block_num; 

  input_size=size; 
  block_num=input_size/BLOCKSIZE; 
  /*Divide the inputs to blocks*/
  for(int block=0;block<block_num;block++) 
  { 
    unsigned char *store=new unsigned char[BLOCKSIZE]; 
    for(int i = 0; i < BLOCKSIZE; i++) store[i]=temp[i]; 
    temp+=BLOCKSIZE; 
    if(porc) PlainText.push_back(store); 
    else CipherText.push_back(store); 
  } 
} 
 
/*To get the plain text block address by their index*/
unsigned char * AESstoreIO::PlainBlock(const int index) 
{ 
  if(index<=PlainText.size()) 
    return *(PlainText.begin()+(index-1));
  else
  { 
    cerr<<"Out Of Space in PlainBlock!!"<<endl; 
    return NULL; 
  } 
} 
 
/*To get the cipher text block address by their index*/
unsigned char * AESstoreIO::CipherBlock(const int index) 
{ 
  if(index<=CipherText.size()) 
    return *(CipherText.begin()+(index-1));
  else 
  { 
    cerr<<"Out Of Space in CipherBlock!!"<<endl; 
    return NULL; 
  } 
} 
 
/*Store the text deciphered by the decryption algorithm*/
void AESstoreIO::StorePlain(unsigned char *input) 
{ 
  if(!input) 
  { 
    cout<<"Error in StorePlain!"<<endl; 
  } 
  else 
  { 
    unsigned char *store=new unsigned char[16]; 
    for(int i=0;i<BLOCKSIZE;i++) store[i]=input[i]; 
    PlainText.push_back(store); 
  } 
} 

/*Store the text encrypted by encryption algorithm */
void AESstoreIO::StoreCipher(unsigned char *input) 
{ 
  if(!input) 
  { 
    cout<<"Error in StoreCipher!"<<endl; 
  } 
  else 
  { 
    unsigned char *store=new unsigned char[16]; 
    for(int i=0; i<BLOCKSIZE; i++) store[i] =input[i]; 
    CipherText.push_back(store); 
  } 
} 

/*Compute number of blocks*/ 
int AESstoreIO::size() 
{ 
  return PlainText.size(); 
} 
 
/*print out the block data*/
void AESstoreIO::printblock(unsigned char* state) 
{ 
  int i; 
  if(!state) 
  {
	cout<<"Error in printblock!"<<endl; 
  }
  else 
  { 
    for(i=0;i<BLOCKSIZE;i++) printf("%s%X ",state[i]>15?"":"0",state[i]); 
    printf("\n"); 
  } 
} 
/*print out the plain text data*/
 void AESstoreIO::printPlain() 
{ 
  for(vector<unsigned char *>::iterator iter=PlainText.begin(); 
    iter!=PlainText.end();iter++) printblock(*iter); 
} 
/*print out the cipher text data*/
void AESstoreIO::printCipher() 
{ 
  for(vector<unsigned char *>::iterator iter=CipherText.begin(); 
    iter!= CipherText.end(); iter++) printblock(*iter); 
}
