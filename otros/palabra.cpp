#include "palabra.h"



bool operator > (const palabra& word1,const palabra& word2){
    return word1.m_palabra > word2.m_palabra;
}


bool operator < (const palabra& word1,const palabra& word2){
    return word1.m_palabra < word2.m_palabra;
}

bool operator >= (const palabra& word1,const palabra& word2){
    return word1.m_palabra >= word2.m_palabra;
}

bool operator <= (const palabra& word1,const palabra& word2){
    return word1.m_palabra <= word2.m_palabra;
}

bool operator == (const palabra& word1,const palabra& word2){
    return word1.m_palabra == word2.m_palabra;
}

bool operator != (const palabra& word1,const palabra& word2){
    return word1.m_palabra != word2.m_palabra;
}


void palabra::operator = (palabra word2){

    m_palabra = word2.m_palabra;
    m_traducciones=word2.m_traducciones;
}


