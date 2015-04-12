#ifndef __CMAC_H__ 
#define __CMAC_H__ 
#include "AES.h" 
#include "AESstoreIO.h"

class CMAC 
{ 
public: 
  unsigned char *AES_CMAC(AESstoreIO &,AESstoreIO &,AES &,int); 
};
#endif