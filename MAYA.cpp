#include <cstdio>
int main(void){
    int factor[7] = {1, 20, 360};
    char str[1024];
    for(int i = 3; i < 7; ++i) factor[i] = 20 * factor[i - 1];
    for(int n; scanf("%d\n", &n) == 1 && n; ){
    
        int sum = 0;
        while(n--){
        
            fgets(str, 1024, stdin);
            int z = 0;
            for(char *p = str; *p; ++p){
            
                if(*p == '.') ++z;
                else if(*p == '-') z += 5;
                
            }
            sum += z * factor[n];
            
        }
        
        printf("%d\n", sum);
        
    }
    return 0;
}