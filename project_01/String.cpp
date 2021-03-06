//
// Created by Soumana Sylla on 1/13/19.
//

#include "String.hpp"




String::String(const char *s) {
    strcpy(buf, s);
}



String::String(const String &s) {
    strcpy(buf, s.buf);
}


char * String::strcpy(char *dest, const char *src) {
    int i = 0;
    while(src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}



void String::print(std::ostream &out) {
    out << buf;
}



void String::read(std::istream &in) {
    in >> buf;
}



String String::operator += (const String s) {
    return strcat(buf, s.buf);
}


char * String::strcat(char *dest, const char *src) {
    int i = 0;
    while(dest[i++] != '\0') {
        if(dest[i] == '\0') {
            for(int j = 0; src[j] != '\0'; j++) {
                dest[i] = src[j];
                i++;
            }
            dest[i] = '\0';
            break;
        }
    }
    return dest;
}



bool String::operator == (const String s) { //
    int result = strcmp(buf, s.buf);
    return result == 0;
}

bool String::operator != (const String s) {
    int result = strcmp(buf, s.buf);
    return result == -1 || result == 1;
}

bool String::operator < (const String s) {
    int result = strcmp(buf, s.buf);
    return result == -1;
}

bool String::operator > (const String s) {
    int result = strcmp(buf, s.buf);
    return result == 1;
}

bool String::operator <= (const String s) {
    int result = strcmp(buf, s.buf);
    return result == -1 || result == 0;
}

bool String::operator >= (const String s) {
    int result = strcmp(buf, s.buf);
    return result == 1 || result == 0;
}


int String::strcmp(const char *left, const char *right) {
    int i = 0;
    while(right[i] != '\0' && left[i] != '\0') {
        if(left[i] < right[i]) {
            return -1;
        }
        else if(left[i] > right[i]) {
            return 1;
        }
        i++;
    }
    if(strlen(left) < strlen(right)) {
        return -1;
    }
    else if(strlen(left) > strlen(right)) {
        return 1;
    }
    return 0;
}


int String::size(String s) {
    return strlen(s.buf);
}



int String::strlen(const char *s) {
    int length = 0;
    while(s[length] != '\0') {
        length++;
    }
    return length;
}


int String::strncmp(const char *left, const char *right, int n) {
    int i = 0;
    while(right[i] != '\0' && left[i] != '\0' && i < n) {
        if(left[i] < right[i]) {
            return -1;
        }
        else if(left[i] > right[i]) {
            return 1;
        }
        i++;
    }

    if(i == n) {
        return 0;
    }
    else if(right[i] == '\0') {
        return 1;
    }
    return -1;
}

String String::reverse() {
    String result;
    int j = 0;
    for(int i = strlen(buf) - 1; i >= 0; i--) {
        result.buf[j++] = buf[i];

    }
    result.buf[j] = '\0';
    return result;
}


int String::indexOf(const char c) {
    for(int i = 0; i < strlen(buf); i++) {
        if(buf[i] == c) {
            return i;
        }
    }
    return -1;
}

char * String::strchr(const char *str, int c) {
    for(const char *ptr = str; *ptr != '\0'; ptr++) {
        if(*ptr == c) {
            return (char*) ptr;
        }
    }
    return nullptr;

}

char * String::strstr(const char *haystack, const char *needle) {
    for(const char *ptr = haystack; *ptr != '\0'; ptr++) {
        if(*ptr == *needle) {
            int result = strncmp(ptr, needle, strlen(needle));
            if(result == 0) {
                return (char*) ptr;
            }
        }
    }
    return nullptr;
}

int String::indexOf(const String pattern) {
    char *ptr = strstr(buf, pattern.buf);
    if(ptr == nullptr) { return -1; }

    for(int i = 0; i < strlen(buf); i++) {
        if(&buf[i] == ptr) {
            return i;
        }
    }

}

char & String::operator [] (int index) {
    if(inBounds(index)) {
        return *strchr(buf, buf[index]);
    }
}


String String::operator + (const String s) {
    return strcat(buf, s.buf);
}



String String::operator = (const String &s) {
    return String(strcpy(buf, s.buf));
}

std::ostream & operator << (std::ostream & out, String str) {
    str.print( out );
    return out;
}

std::istream & operator >> (std::istream & in, String & str) {
    str.read( in );
    return in;
}


String::~String() {}





