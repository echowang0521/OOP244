//name: mengjiao Wang
//id 137144192
//email:mwang154@myseneca.ca
//date:2021-03-10
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strLen(lineValue) + 1];
      strCpy(m_value, lineValue);
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }

   void TextFile::setFilename(const char* fname, bool isCopy) {
     if (!isCopy) {
         delete[] m_filename;
         if (fname != nullptr) {
           m_filename = new char[strLen(fname) + 1];
         } else {
           m_filename = new char[0];
         }
        strCpy(m_filename, fname);
     } else {
       delete[] m_filename;
       if (fname != nullptr) {
         m_filename = new char[strLen(fname) + 3];
       } else {
         m_filename = new char[0];
       }
       string copy_name = "C_";
       for(int i = 0; i < (int)strLen(fname); i++) {
           copy_name += fname[i];
         }
       strCpy(m_filename,copy_name.c_str());
     }
   }

   void TextFile::setNoOfLines() {
     m_noOfLines = 0;
     ifstream myfile (m_filename);
     if (myfile.is_open()) {
       string l;
       while(getline(myfile, l)) {
         m_noOfLines++;
       }
       myfile.close();
     }
     if (m_noOfLines == 0) {
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
     }
   }

   void TextFile::loadText() {
     if (m_filename == nullptr) return;
     delete [] m_textLines;
     setNoOfLines();
     if (m_noOfLines != 0) {
       m_textLines = new Line[m_noOfLines];
       ifstream myfile (m_filename);
       if (myfile.is_open()) {
         string line;
         for(int i = 0; i < (int)m_noOfLines; i++) {
              getline(myfile, line);
              m_textLines[i] = line.c_str();
          }
       }
       myfile.close();
     }
   }

   void TextFile::saveAs(const char *fileName)const {
     if (fileName != nullptr) {
       ofstream newFile;
       newFile.open(fileName);
       if (newFile.is_open()) {
         for (int i = 0; i < (int)m_noOfLines; i++) {
           newFile << m_textLines[i] << endl;
         }
        newFile.close();
      }
    }
   }

   TextFile::TextFile(const TextFile& newText) {
     m_pageSize = newText.m_pageSize;
     m_filename = nullptr;
     m_textLines = nullptr;
     m_noOfLines = 0;
     setFilename(newText.m_filename, true);
     newText.saveAs(m_filename);
     setNoOfLines();
     loadText();
   }

   TextFile::TextFile(unsigned int pageSize) {
     m_pageSize = pageSize;
     m_filename = nullptr;
     m_textLines = nullptr;
     m_noOfLines = 0;
   }

   TextFile::TextFile(const char* filename, unsigned pageSize) {
     m_pageSize = pageSize;
     delete [] m_textLines;
     m_textLines = nullptr;
     delete [] m_filename;
     m_filename = nullptr;
     m_noOfLines = 0;

     if (filename != nullptr) {
       setFilename(filename);
       setNoOfLines();
       loadText();
     }
   }

   TextFile& TextFile::operator=(const TextFile& newFile) {
     if (this == &newFile) return *this;
     if (this->m_textLines != nullptr) {
     this->m_textLines = nullptr;
     }
     newFile.saveAs(this->m_filename);
     setNoOfLines();
     loadText();
     return *this;
   }

   TextFile::~TextFile() {
     if (m_textLines != nullptr) {
       delete[] m_textLines;
       m_textLines = nullptr;
     }
     if (m_filename != nullptr) {
       delete[] m_filename;
       m_filename = nullptr;
     }
     m_noOfLines = 0;
     m_pageSize = 0;
   }

   unsigned TextFile::lines()const {
     return m_noOfLines;
   }

   std::ostream& TextFile::view(std::ostream& ostr)const {
     if (!*this) return ostr;
       ostr<<m_filename<<endl;
       if (m_filename == nullptr) {
          ostr.width(0);
       } else {
          ostr.width(strLen(m_filename));
       }
       ostr.fill('=');
       ostr << "" << endl;

       for (int i = 0; i < (int)m_noOfLines; i++) {
         if(i % m_pageSize == 0 && i > 0) {
                ostr << "Hit ENTER to continue...";
                cin.get();
            }
          ostr << m_textLines[i].m_value << endl;
       }
     return ostr;
   }

   std::istream& TextFile::getFile(std::istream& istr) {
     delete [] m_filename;
     string tmp;
     istr >> tmp;
     while(getchar() != '\n');
     m_filename = new char[strLen(tmp.c_str()) + 1];
     strCpy(m_filename, tmp.c_str());
     setNoOfLines();
     loadText();
     return istr;
   }

   const char* TextFile::operator[](unsigned int index)const {
     if (m_textLines == nullptr) return nullptr;
     return m_textLines[index % m_noOfLines].m_value;
   }

   TextFile::operator bool()const {
     return m_textLines != nullptr && m_filename != nullptr && m_noOfLines != 0;
   }

   const char* TextFile::name()const {
     return m_filename;
   }

   ostream& operator<<(ostream& ostr, const TextFile& text) {
     text.view(ostr);
     return ostr;
   }

   istream& operator>>(istream& istr, TextFile& text) {
     text.getFile(istr);
     return istr;
   }
}
