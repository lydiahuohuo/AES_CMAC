#include "CMAC.H" 


 unsigned char *CMAC::AES_CMAC(AESstoreIO &Msg,AESstoreIO &calkey1,AES &cryptor, int Tlen) 
{ 
  int return_size; 
  int byte_size=8*sizeof(unsigned char); 

  return_size=Tlen/byte_size; 

  unsigned char *cmac_curr,*cmac_next,*key1; 
  int i=1; 
  if(Msg.size()>=1) 
  { 
    cmac_curr=Msg.PlainBlock(i++); 
    cmac_next=cryptor.Encip(cmac_curr);
    for(;i<Msg.size();i++) 
    { 
      for(int j=0;j<BLOCKSIZE;j++) 
        cmac_curr[j]=Msg.PlainBlock(i)[j]^cmac_next[j];
      cmac_next=cryptor.Encip(cmac_curr);
    } 
  
    key1=cryptor.Encip(calkey1.PlainBlock(1));
	
	for(int j=BLOCKSIZE-1;j>=0;j--)
	{
	  static int temp=0;
	  key1[j]=key1[j]*2+temp;
	  if (key1[j]>0xff) temp=1;
	  key1[j]=key1[j]&0xff;
	}
    if (key1[0]>=8) 
	{
	  key1[14]=key1[14]^0x08;
	  key1[15]=key1[15]^0x07;
	}
    
	unsigned char *result=new unsigned char[return_size]; 
    for(j=0;j<BLOCKSIZE;j++) 
        cmac_curr[j]=Msg.PlainBlock(Msg.size())[j]^cmac_next[j]^key1[j];
    cmac_next=cryptor.Encip(cmac_curr);
	for(i=0;i<return_size;i++) result[i] = cmac_next[i]; 

	return result;
  } 
  else 
  { 
      return NULL; 
  } 
}