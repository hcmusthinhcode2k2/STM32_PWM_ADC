#include <common.h>
//==============================================================================================================================================================
const __code BitArray_TypeDef BitArray = {
  .NonReverse = {
    .MSB = {0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x02, 0x01},
    .LSB = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80},
  },
  .Reverse = {
    .MSB = {0x7F, 0xBF, 0xDF, 0xEF, 0xF7, 0xFB, 0xFD, 0xFE},
    .LSB = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F},
  },
};
//==============================================================================================================================================================
const __code BitGroup_TypeDef BitGroup = {
  .NonReverse = {
    .MSB = {0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFF},
    .LSB = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF},
  },
  .Reverse = {
    .MSB = {0xFF, 0x7F, 0x3F, 0x1F, 0x0F, 0x07, 0x03, 0x01, 0x00},
    .LSB = {0xFF, 0xFE, 0xFC, 0xF8, 0xF0, 0xE0, 0xC0, 0x80, 0x00},
  },
};
//==============================================================================================================================================================
const __code unsigned char HighBitCount[256] = {
//0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15
  0,    1,    1,    2,    1,    2,    2,    3,    1,    2,    2,    3,    2,    3,    3,    4,
//16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31
  1,    2,    2,    3,    2,    3,    3,    4,    2,    3,    3,    4,    3,    4,    4,    5,
//32    33    34    35    36    37    38    39    40    41    42    43    44    45    46    47
  1,    2,    2,    3,    2,    3,    3,    4,    2,    3,    3,    4,    3,    4,    4,    5,
//48    49    50    51    52    53    54    55    56    57    58    59    60    61    62    63
  2,    3,    3,    4,    3,    4,    4,    5,    3,    4,    4,    5,    4,    5,    5,    6,
//64    65    66    67    68    69    70    71    72    73    74    75    76    77    78    79
  1,    2,    2,    3,    2,    3,    3,    4,    2,    3,    3,    4,    3,    4,    4,    5,
//80    81    82    83    84    85    86    87    88    89    90    91    92    93    94    95
  2,    3,    3,    4,    3,    4,    4,    5,    3,    4,    4,    5,    4,    5,    5,    6,
//96    97    98    99    100   101   102   103   104   105   106   107   108   109   110   111
  2,    3,    3,    4,    3,    4,    4,    5,    3,    4,    4,    5,    4,    5,    5,    6,
//112   113   114   115   116   117   118   119   120   121   122   123   124   125   126   127
  3,    4,    4,    5,    4,    5,    5,    6,    4,    5,    5,    6,    5,    6,    6,    7,
//128   129   130   131   132   133   134   135   136   137   138   139   140   141   142   143
  1,    2,    2,    3,    2,    3,    3,    4,    2,    3,    3,    4,    3,    4,    4,    5,
//144   145   146   147   148   149   150   151   152   153   154   155   156   157   158   159
  2,    3,    3,    4,    3,    4,    4,    5,    3,    4,    4,    5,    4,    5,    5,    6,
//160   161   162   163   164   165   166   167   168   169   170   171   172   173   174   175
  2,    3,    3,    4,    3,    4,    4,    5,    3,    4,    4,    5,    4,    5,    5,    6,
//176   177   178   179   180   181   182   183   184   185   186   187   188   189   190   191
  3,    4,    4,    5,    4,    5,    5,    6,    4,    5,    5,    6,    5,    6,    6,    7,
//192   193   194   195   196   197   198   199   200   201   202   203   204   205   206   207
  2,    3,    3,    4,    3,    4,    4,    5,    3,    4,    4,    5,    4,    5,    5,    6,
//208   209   210   211   212   213   214   215   216   217   218   219   220   221   222   223
  3,    4,    4,    5,    4,    5,    5,    6,    4,    5,    5,    6,    5,    6,    6,    7,
//224   225   226   227   228   229   230   231   232   233   234   235   236   237   238   239
  3,    4,    4,    5,    4,    5,    5,    6,    4,    5,    5,    6,    5,    6,    6,    7,
//240   241   242   243   244   245   246   247   248   249   250   251   252   253   254   255
  4,    5,    5,    6,    5,    6,    6,    7,    5,    6,    6,    7,    6,    7,    7,    8,
};
//==============================================================================================================================================================
const unsigned char __code ReverseByte[256] = {
//0x00  0x01  0x02  0x03  0x04  0x05  0x06  0x07  0x08  0x09  0x0A  0x0B  0x0C  0x0D  0x0E  0x0F  
  0x00, 0x80, 0x40, 0xC0, 0x20, 0xA0, 0x60, 0xE0, 0x10, 0x90, 0x50, 0xD0, 0x30, 0xB0, 0x70, 0xF0, 
//0x10  0x11  0x12  0x13  0x14  0x15  0x16  0x17  0x18  0x19  0x1A  0x1B  0x1C  0x1D  0x1E  0x1F  
  0x08, 0x88, 0x48, 0xC8, 0x28, 0xA8, 0x68, 0xE8, 0x18, 0x98, 0x58, 0xD8, 0x38, 0xB8, 0x78, 0xF8, 
//0x20  0x21  0x22  0x23  0x24  0x25  0x26  0x27  0x28  0x29  0x2A  0x2B  0x2C  0x2D  0x2E  0x2F  
  0x04, 0x84, 0x44, 0xC4, 0x24, 0xA4, 0x64, 0xE4, 0x14, 0x94, 0x54, 0xD4, 0x34, 0xB4, 0x74, 0xF4, 
//0x30  0x31  0x32  0x33  0x34  0x35  0x36  0x37  0x38  0x39  0x3A  0x3B  0x3C  0x3D  0x3E  0x3F  
  0x0C, 0x8C, 0x4C, 0xCC, 0x2C, 0xAC, 0x6C, 0xEC, 0x1C, 0x9C, 0x5C, 0xDC, 0x3C, 0xBC, 0x7C, 0xFC, 
//0x40  0x41  0x42  0x43  0x44  0x45  0x46  0x47  0x48  0x49  0x4A  0x4B  0x4C  0x4D  0x4E  0x4F  
  0x02, 0x82, 0x42, 0xC2, 0x22, 0xA2, 0x62, 0xE2, 0x12, 0x92, 0x52, 0xD2, 0x32, 0xB2, 0x72, 0xF2, 
//0x50  0x51  0x52  0x53  0x54  0x55  0x56  0x57  0x58  0x59  0x5A  0x5B  0x5C  0x5D  0x5E  0x5F  
  0x0A, 0x8A, 0x4A, 0xCA, 0x2A, 0xAA, 0x6A, 0xEA, 0x1A, 0x9A, 0x5A, 0xDA, 0x3A, 0xBA, 0x7A, 0xFA, 
//0x60  0x61  0x62  0x63  0x64  0x65  0x66  0x67  0x68  0x69  0x6A  0x6B  0x6C  0x6D  0x6E  0x6F  
  0x06, 0x86, 0x46, 0xC6, 0x26, 0xA6, 0x66, 0xE6, 0x16, 0x96, 0x56, 0xD6, 0x36, 0xB6, 0x76, 0xF6, 
//0x70  0x71  0x72  0x73  0x74  0x75  0x76  0x77  0x78  0x79  0x7A  0x7B  0x7C  0x7D  0x7E  0x7F  
  0x0E, 0x8E, 0x4E, 0xCE, 0x2E, 0xAE, 0x6E, 0xEE, 0x1E, 0x9E, 0x5E, 0xDE, 0x3E, 0xBE, 0x7E, 0xFE, 
//0x80  0x81  0x82  0x83  0x84  0x85  0x86  0x87  0x88  0x89  0x8A  0x8B  0x8C  0x8D  0x8E  0x8F  
  0x01, 0x81, 0x41, 0xC1, 0x21, 0xA1, 0x61, 0xE1, 0x11, 0x91, 0x51, 0xD1, 0x31, 0xB1, 0x71, 0xF1, 
//0x90  0x91  0x92  0x93  0x94  0x95  0x96  0x97  0x98  0x99  0x9A  0x9B  0x9C  0x9D  0x9E  0x9F  
  0x09, 0x89, 0x49, 0xC9, 0x29, 0xA9, 0x69, 0xE9, 0x19, 0x99, 0x59, 0xD9, 0x39, 0xB9, 0x79, 0xF9, 
//0xA0  0xA1  0xA2  0xA3  0xA4  0xA5  0xA6  0xA7  0xA8  0xA9  0xAA  0xAB  0xAC  0xAD  0xAE  0xAF  
  0x05, 0x85, 0x45, 0xC5, 0x25, 0xA5, 0x65, 0xE5, 0x15, 0x95, 0x55, 0xD5, 0x35, 0xB5, 0x75, 0xF5, 
//0xB0  0xB1  0xB2  0xB3  0xB4  0xB5  0xB6  0xB7  0xB8  0xB9  0xBA  0xBB  0xBC  0xBD  0xBE  0xBF  
  0x0D, 0x8D, 0x4D, 0xCD, 0x2D, 0xAD, 0x6D, 0xED, 0x1D, 0x9D, 0x5D, 0xDD, 0x3D, 0xBD, 0x7D, 0xFD, 
//0xC0  0xC1  0xC2  0xC3  0xC4  0xC5  0xC6  0xC7  0xC8  0xC9  0xCA  0xCB  0xCC  0xCD  0xCE  0xCF  
  0x03, 0x83, 0x43, 0xC3, 0x23, 0xA3, 0x63, 0xE3, 0x13, 0x93, 0x53, 0xD3, 0x33, 0xB3, 0x73, 0xF3, 
//0xD0  0xD1  0xD2  0xD3  0xD4  0xD5  0xD6  0xD7  0xD8  0xD9  0xDA  0xDB  0xDC  0xDD  0xDE  0xDF  
  0x0B, 0x8B, 0x4B, 0xCB, 0x2B, 0xAB, 0x6B, 0xEB, 0x1B, 0x9B, 0x5B, 0xDB, 0x3B, 0xBB, 0x7B, 0xFB, 
//0xE0  0xE1  0xE2  0xE3  0xE4  0xE5  0xE6  0xE7  0xE8  0xE9  0xEA  0xEB  0xEC  0xED  0xEE  0xEF  
  0x07, 0x87, 0x47, 0xC7, 0x27, 0xA7, 0x67, 0xE7, 0x17, 0x97, 0x57, 0xD7, 0x37, 0xB7, 0x77, 0xF7, 
//0xF0  0xF1  0xF2  0xF3  0xF4  0xF5  0xF6  0xF7  0xF8  0xF9  0xFA  0xFB  0xFC  0xFD  0xFE  0xFF  
  0x0F, 0x8F, 0x4F, 0xCF, 0x2F, 0xAF, 0x6F, 0xEF, 0x1F, 0x9F, 0x5F, 0xDF, 0x3F, 0xBF, 0x7F, 0xFF, 
};
//==============================================================================================================================================================
const __code unsigned char HighBitCompare5[32] = {
//0     1     2     3     4     5     6     7     8     9     10    11    12    13    14    15
  0,    0,    0,    0,    0,    0,    0,    1,    0,    0,    0,    1,    0,    1,    1,    1,
//16    17    18    19    20    21    22    23    24    25    26    27    28    29    30    31
  0,    0,    0,    1,    0,    1,    1,    1,    0,    1,    1,    1,    1,    1,    1,    1,
};
//==============================================================================================================================================================
void DelayLoop(reg16 Loop)
{
  reg16 i;
  for (i = 0; i < Loop; i++);
}
////==============================================================================================================================================================
//reg16 GetStringLength(const unsigned char __gptr* String, 
//#ifndef GetCharacerWidth
//                      reg8 GetCharacerWidth(reg8 Character), 
//#endif
//                      reg8 SpaceWidth)
//{
//  reg16 length = 0;
//  reg8 index = 0;
//  reg8 character = String[index];
//  while (character)
//  {
//    length += GetCharacerWidth(character) + SpaceWidth;
//    index++;
//    character = String[index];
//  }
//  return length;
//}
//==============================================================================================================================================================
reg8 CompareString(unsigned char __gptr* String1, unsigned char __gptr* String2)
{
  return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
reg8 CompareArray(unsigned char __gptr* Array1, unsigned char __gptr* Array2, reg8 Length)
{
  while (Length--)
  {
    if (*Array1++ != *Array2++)
      return 0;
  }
  return 1;
}
//--------------------------------------------------------------------------------------------------------------------------------------------------------------
void Storage(unsigned char* Destiny, unsigned char __gptr* Source, reg8 Length)
{
  while (Length--)
    *Destiny++ = *Source++;
}