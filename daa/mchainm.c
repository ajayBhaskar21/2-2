

#include <stdio.h>

struct nodes {
    int cost ;
    int root;
  
};

int main()
{
    int n = 5;
  
  
    int p = {0, 5, 4, 6, 2, 7};
  
    struct nodes m[n][n];
    
    for(int i = 1; i < n;i++){
        for(int j=1;j<n;j++){
            m[i][j].cost = 0;
        }
    }
    
  
  
    for(int i = 1; i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            if(j>=i){
                
                continue ;
            }
      
            int k = i;
            int t;
            t = m[i][k].cost+
            m[k+1][j].cost+
            p[i]*p[k+1]*p[j+1];

            for(k=i+1;k<j;k++){
                int t1 = m[i][k].cost+
                m[k+1][j].cost+
                p[i]*p[k+1]*p[j+1];
        
                if(t>t1){
                    t = t1;
                }
            }
      
            m[i][j].cost=t;
            for(k=i;k<j;k++) {
                if(m[i][k].cost+
                    m[k+1][j].cost+
                    p[i]*p[k+1]*p[j+1] == t){
                    break;
                }
            }
            m[i][j].root=k;
      
        }

    }

    for(int i = 1; i < n;i++){
        for(int j=1;j<n;j++){
            printf("%d ", m[i][j].cost);
        }
        printf("\n");
    }

}
  
