#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE 256
#define MAX_WORD 30

bool isEqual(char first[],char second[],int len){
    for(int i = 0;i<len;i++){
        if(first[i]!=second[i])
        return false;
    } 
    return true;
}

bool IsAlmostEqual(char *maybe, char word[], int wordLen){
    bool b = false;
    int plus = 0;
    for(int i = 0;i<wordLen;i++){
        if(*(maybe+i+plus) != word[i]){
            if(b==true){
                return false;
            }
            else{
                b = true;
                plus = 1;
                i--;
            }
        }
    }
    return true;
}

void optionA(char word[], int wordLen){
    char line[MAX_LINE+1];
    while(fgets(line, sizeof(line),stdin)!= NULL){
        if(strstr(line,word)!=NULL)
            printf("%s",line);
    }
}

void optionB(char word[], int wordLen){
    char line[MAX_LINE+1];
    while(fgets(line, sizeof(line),stdin) != NULL){
        char check[wordLen+1];
        int i = 0;     
        while(line[i]!='\0' && line[i]!= '\n' && line[i] != '\r'){
            int size = 0;
            while(line[i]!= '\n' && line[i]!='\t'&&line[i]!=' ' &&line[i]!='\0' && line[i]!='\r'){
                check[size]=line[i];
                i++;
                size++;
            }
            
            check[size] = '\0';
            
            if(size == wordLen || size ==wordLen+1){
                if(IsAlmostEqual(check,word, wordLen)){
                    puts(check);
                }
            }
            i++;  
        }
    }
}

int main(){
    char firstline[MAX_LINE];
    char safeWord[MAX_WORD];
    memset(safeWord,'\0',MAX_WORD);
    fgets(firstline, sizeof(firstline), stdin);
    
    int i = 0;
    while(firstline[i] != ' '){
        safeWord[i] = firstline[i];
        i++;
    }
    int wordLen = i;
    i++;
    char option = firstline[i];
    
    
    if(option == 'a'){ 
        optionA(safeWord,wordLen);
    }
    else{
        optionB(safeWord,wordLen);
    }

    return 0;
}