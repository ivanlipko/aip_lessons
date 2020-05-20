/*
 * Пример работы с бинарными файлами.
 * Считываем заголовки популярных форматов.
 * Использование seekg, tellg
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void readPdfHeader(const string fname){
    ifstream f;
    char c[8];

    f.open(fname.c_str());
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }
    f >> c;
    f.close();

    cout << "----------------- PDF file header reader ----------------- \n";
    cout << "Size of char type is " << sizeof(char) << " byte." << endl;
    cout << "PDF header is 8 bytes." << endl;
    cout << "PDF header of \"" << fname << "\" file is: " << c << endl;

    cout << endl;
}


typedef short int WORD;
typedef unsigned int DWORD;
typedef int LONG;

#pragma pack(push, 1)  // упаковка памяти, иначе структура будет занимать 16 байт, а не 14, как положено
struct BITMAPFILEHEADER {
    WORD    bfType;
    DWORD   bfSize;
    WORD    bfReserved1;
    WORD    bfReserved2;
    DWORD   bfOffBits;
};
#pragma pack(pop)

struct BITMAPINFOHEADER {
    DWORD  biSize;
    LONG   biWidth;
    LONG   biHeight;
    WORD   biPlanes;
    WORD   biBitCount;
    DWORD  biCompression;
    DWORD  biSizeImage;
    LONG   biXPelsPerMeter;
    LONG   biYPelsPerMeter;
    DWORD  biClrUsed;
    DWORD  biClrImportant;
};

void readBmpHeader(string fname){
    ifstream f;
    BITMAPFILEHEADER fHead;
    BITMAPINFOHEADER imHead;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }
    f.read((char*)&fHead, sizeof(fHead));
    f.read((char*)&imHead, sizeof(imHead));
    f.close();

    cout << "----------------- BMP file header reader ----------------- \n";
    cout << fname << endl;
    cout << "Size of types are (in bytes, / must be):" << endl;
    cout << "WORD  " << sizeof(WORD) << " /2" << endl;
    cout << "DWORD " << sizeof(DWORD) << " /4" << endl;
    cout << "LONG  " << sizeof(LONG) << " /4" << endl;
    cout << "BITMAPFILEHEADER " << sizeof(BITMAPFILEHEADER) << " /14"  << endl;
    cout << "BITMAPINFOHEADER " << sizeof(BITMAPINFOHEADER) << endl;

    cout << endl;

    cout << "File info: ["
         << fHead.bfType << " == 19778, "
         << fHead.bfSize << " bytes, "
         << fHead.bfReserved1 << ", "
         << fHead.bfReserved2 << ", "
         << fHead.bfOffBits << "] " << endl;

    cout << "Image info: ["
         << imHead.biSize << " bytes, ("
         << imHead.biWidth << "x"
         << imHead.biHeight << ") px, "
         << imHead.biBitCount<< " bits] "<< endl;

    cout << endl;
}


void readBmpImageHeader(string fname){
    ifstream f;
    BITMAPINFOHEADER imHead;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }

    cout << "----------------- BMP file Image header reader via seek----------------- \n";
    cout << fname << endl;
    cout << "BITMAPFILEHEADER size is 14 bytes"  << endl;
    cout << "BITMAPINFOHEADER " << sizeof(BITMAPINFOHEADER) << endl;

    cout << "Current position in file " << f.tellg() << endl;
    cout << "Seek 14 bytes" << endl;
    f.seekg(14);  // смещаемся на 14 байт вперёд
    cout << "Current position in file " << f.tellg() << endl;

    f.read((char*)&imHead, sizeof(imHead));
    f.close();

    cout << endl;

    cout << "Image info: ["
         << imHead.biSize << " bytes, ("
         << imHead.biWidth << "x"
         << imHead.biHeight << ") px, "
         << imHead.biBitCount<< " bits] "<< endl;

    cout << endl;
}

void seekOverFile(string fname){
    ifstream f;
    BITMAPINFOHEADER imHead;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }

    cout << "----------------- Seek file example ----------------- \n";
    cout << fname << endl;
    cout << "Current position in file " << f.tellg() << endl;
    f.seekg(14);
    cout << "Current position in file " << f.tellg() << endl;

    // Как узнать размер файла
    f.seekg (0, f.end);  // двигаемся в конец
    int length = f.tellg();  // где мы?
    cout << "Current position in file " << f.tellg() << endl;
    cout << "File size is " << length << " bytes" << endl;

    f.seekg (34, f.beg);  // возврат в начало
    cout << "Current position in file " << f.tellg() << endl;

    DWORD biSizeImage;
    f.read((char*)&biSizeImage, sizeof(DWORD));
    cout << "biSizeImage (This is the size of the raw bitmap data: HxWx3 ) = " << biSizeImage << endl;

    f.read((char*)&imHead, sizeof(imHead));
    f.close();

    cout << endl;
}


void readMp3Header(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }

    unsigned char b2[2];
    unsigned char b3;
    unsigned char b4;

    cout << "----------------- Read First MP3 Header in file without ID3v2----------------- \n";
    f.read((char*)b2, sizeof(b2));
    f.read((char*)&b3, sizeof(char));
    f.read((char*)&b4, sizeof(char));
    f.close();

    cout << fname << endl << "Signature: " << hex << showbase << endl
         << (int) b2[0] << endl
         << (int) b2[1] << endl
         << (int) b3 << endl
         << (int) b4 << endl;

    cout << endl;
}

void readMp3Id3v1(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }


    cout << "----------------- Read First MP3 Header in file without ID3v2----------------- \n";

    f.close();

    cout << endl;
}

void readIcoHeader(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }

    struct ICONDIR {
        short int reserved;
        short int type;
        short int count;
    };

    struct ICONDIRENTRY {
        char width;
        char height;
        char colors;
        char reserved;
        short int planes;
        short int bpp;
        long size;
        long offset;
    };

    ICONDIR id;
    ICONDIRENTRY ide;

    cout << "----------------- Read ICO Header ----------------- \n";
    f.read((char*) &id, sizeof(id));
    f.read((char*) &ide, sizeof(ide));
    f.close();

    cout << fname << endl;
    cout << "ICONDIR: " << endl << dec
         << "reserved " << (int) id.reserved << endl
         << "type " << (int) id.type << endl
         << "count " << (int) id.count << endl <<endl;

    cout << "ICONDIRENTRY: " << endl << dec
         << "width " << (int) ide.width << endl
         << "height " << (int) ide.height << endl
         << "colors " << (int) ide.colors << endl
         << "reserved " << (int) ide.reserved << endl
         << "planes " << (unsigned int) ide.planes<< endl
         << "bpp " << (unsigned int) ide.bpp << endl
         << "size " << (int) ide.size << endl
         << "offset " << (int) ide.offset;
    cout << endl;
}

void readZipHeader(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }

    //    #pragma pack(push, 1)  // упаковка памяти, иначе структура будет занимать 16 байт, а не 14, как положено
    struct ZIPLOCALFILEHEADER {
        unsigned int sign;
        short int version;
        short int flag;
        short int comp;
        short int lastTime;
        short int lastDate;
        unsigned int crc;
        unsigned int sizec;
        unsigned int sized;
        short int lenName;
        short int lenEf;
        //        char * fName;
        //        char * ef;
    };
    //    #pragma pack(pop)

    ZIPLOCALFILEHEADER lfh;

    cout << "----------------- Read ZIP ----------------- \n";
    f.read((char*) &lfh, sizeof(ZIPLOCALFILEHEADER));
    f.close();

    unsigned short int ud = lfh.lastDate;
    unsigned short int ut = lfh.lastTime;

    cout << fname << endl;
    cout << "Local File Header: " << endl << dec
         << "sign     " << (unsigned int) lfh.sign << endl //<< dec
         << "version  " << (short int) lfh.version << endl
         << "flag     " << (short int) lfh.flag << endl
         << "comp     " << (unsigned short int) lfh.comp << endl
         << "lastTime " << (unsigned short int) lfh.lastTime
         << " (" << ((ut&0xF800) >> 11) << ":"
         << ((((ut)&0x7E0) >> 6)) << ":"
         << 2*(ut&0x1f)<< ")"  << endl
         << "lastDate " << (unsigned short int) lfh.lastDate
         << " (" << (ud&0b11111) << "/"
         << ((((ud)&0x1E0)/0x20)) << "/"
         << (((ud&0x0FE00)/0x0200)+1980) << ")" << endl
         << "crc      " << (unsigned int) lfh.crc << endl
         << "sizec    " << (unsigned int) lfh.sizec << endl
         << "sized    " << (unsigned int) lfh.sized << endl
         << "lenName  " << (short int) lfh.lenName << endl
         << "lenEf    " << (short int) lfh.lenEf << endl;

    cout << endl;
}

void readPNG(string fname){
    ifstream f;

    f.open(fname);
    if (!f.is_open()) {
        cout << "Error open: " << fname << ". (" << strerror(errno) << ")." << endl;
        f.close();
        return;
    }

    #pragma pack(push, 1)  // упаковка памяти
    struct PNGCHUNK_IHDR{
        unsigned int len_raw;
        unsigned int type;
        unsigned int width;
        unsigned int height;
        unsigned char depth;
        unsigned char cType;
        unsigned char compr;
        unsigned char filter;
        unsigned char interl;
        unsigned int crc;
    };
    #pragma pack(pop)

    unsigned char sign[8];
    PNGCHUNK_IHDR ihdr;

    f.read((char*) &sign, sizeof(sign));
    f.read((char*) &ihdr, sizeof(ihdr));
    f.close();

    cout << "----------------- Read PNG ----------------- \n";
    cout << fname << endl;

    cout << "Signature (hex): " << showbase << hex
         << +sign[0] << " "
         << +sign[1] << " "
         << +sign[2] << " "
         << +sign[3] << " "
         << +sign[4] << " "
         << +sign[5] << " "
         << +sign[6] << " "
         << +sign[7] << " " << endl;

    cout << "Chunk IHDR (" << dec << sizeof(ihdr) << " bytes)"<< endl
    << "len " << ihdr.len_raw << " (true = " << __builtin_bswap32(ihdr.len_raw) << ")" << endl
    << "type    " << ihdr.type <<  " [(char) "
                << (char)(ihdr.type)
                << (char)(ihdr.type >> 8)
                << (char)(ihdr.type >> 16)
                << (char)(ihdr.type >> 24) << "]" << endl
    << "width   " << (int) ihdr.width << " (true = " << __builtin_bswap32(ihdr.width) << ")" << endl
    << "height  " << (int) ihdr.height << " (true = " << __builtin_bswap32(ihdr.height) << ")" << endl
    << "depth   " << (int) ihdr.depth << endl
    << "cType   " << (int) ihdr.cType << endl
    << "compr   " << (int) ihdr.compr << endl
    << "filter  " << (int) ihdr.filter << endl
    << "interl  " << (int) ihdr.interl << endl
    << "crc     " << (int) ihdr.crc;

    cout << endl << endl;

    // без упаковки памяти
    struct PNGCHUNK_IHDR_NONPACKED{
        unsigned int len_raw;
        unsigned int type;
        unsigned int width;
        unsigned int height;
        unsigned char depth;
        unsigned char cType;
        unsigned char compr;
        unsigned char filter;
        unsigned char interl;
        unsigned int crc;
    };

    PNGCHUNK_IHDR_NONPACKED ihdrn;

    f.open(fname);
    f.read((char*) &sign, sizeof(sign));
    f.read((char*) &ihdrn, sizeof(ihdrn));
    f.close();

    cout << "Chunk IHDR_NONPACKED (" << dec << sizeof(ihdrn) << " bytes)"<< endl
    << "len " << ihdrn.len_raw << " (true = " << __builtin_bswap32(ihdrn.len_raw) << ")" << endl
    << "type    " << ihdrn.type <<  " [(char) "
                << (char)(ihdrn.type)
                << (char)(ihdrn.type >> 8)
                << (char)(ihdrn.type >> 16)
                << (char)(ihdrn.type >> 24) << "]" << endl
    << "width   " << (int) ihdrn.width << " (true = " << __builtin_bswap32(ihdrn.width) << ")" << endl
    << "height  " << (int) ihdrn.height << " (true = " << __builtin_bswap32(ihdrn.height) << ")" << endl
    << "depth   " << (int) ihdrn.depth << endl
    << "cType   " << (int) ihdrn.cType << endl
    << "compr   " << (int) ihdrn.compr << endl
    << "filter  " << (int) ihdrn.filter << endl
    << "interl  " << (int) ihdrn.interl << endl
    << "crc     " << (int) ihdrn.crc;

    cout << endl << endl;

}



int main()
{
    /* Unix-style пути к файлу: слеши / и \ */
    readPdfHeader("./data_samples/file.pdf");
    readBmpHeader("./data_samples/microsoft.bmp");
    readBmpImageHeader("./data_samples/microsoft.bmp");
    seekOverFile("./data_samples/microsoft.bmp");
    readMp3Header("./data_samples/1.mp3");
    readMp3Header("./data_samples/2.mp3");
    readMp3Header("./data_samples/3.mp3");

    readIcoHeader("./data_samples/books.ico");
    readIcoHeader("./data_samples/rotation.ico");
    readIcoHeader("./data_samples/tennis.ico");

    readZipHeader("./data_samples/ezyzip.zip");
    readZipHeader("./data_samples/files.zip");
    readZipHeader("./data_samples/tennis.zip");

    readPNG("./data_samples/sevgu1.png");
    readPNG("./data_samples/sevgu2.png");

    return 0;
}
