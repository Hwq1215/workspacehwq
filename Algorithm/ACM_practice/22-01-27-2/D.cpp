#include<bits/stdc++.h>
using namespace std;
char s[1000003];
//zero two four six nine
int main(){
    int n;
    scanf("%d",&n);
    while(n--){
        scanf("%s",s);
        int i = 0;
        int len = strlen(s);
        while( i<len ){
            if(s[i] == 'n'){
                if(s[i+1] == 'i'){
                    if(s[i+2] == 'n'){
                        if(s[i+3] == 'e'){
                            printf("%c",'9');
                            i++;
                        }else{
                            i--;
                        }
                        i++;
                    }
                    i++;
                }
                i++;
            }else if(s[i] == 't'){
                if(s[i+1] == 'w'){
                    if(s[i+2] == 'o'){
                            printf("%c",'2');
                            i++;
                    }
                    i++;
                }
                i++;
            }else if(s[i] == 'f'){
                if(s[i+1] == 'o'){
                    if(s[i+2] == 'u'){
                        if(s[i+3] == 'r'){
                            printf("%c",'4');
                            i++;
                        }
                        i++;
                    }
                    i++;
                }
                i++;
            }else if(s[i] == 's'){
                if(s[i+1] == 'i'){
                    if(s[i+2] == 'x'){
                            printf("%c",'6');
                            i++;
                    }
                    i++;
                }
                i++;
            }else if(s[i] == 'z'){
                if(s[i+1] == 'e'){
                    if(s[i+2] == 'r'){
                        if(s[i+3] == 'o'){
                            printf("%c",'0');
                            i++;
                        }
                        i++;
                    }
                    i++;
                }
                i++;
            }else if(s[i]=='0'||s[i]=='2'||s[i]=='4'||s[i]=='6'||s[i]=='9'){
                printf("%c",s[i]);
                i++;
            }else{
                i++;
            }
    }
    printf("\n");
    }
    
system("pause");
return 0;
}