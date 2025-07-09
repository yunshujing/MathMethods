#include<stdio.h>
#include<math.h>

/*输出矩阵函数*/
/*输出增广矩阵*/
void printMatrix(int n, double a[20][20], double b[20]) 
{ 
    for(int i = 1; i <= n; i++ ) 
    { 
        for(int j = 1; j <= n+1; j++) 
        { 
            if(j == n+1)  
            { 
                if(b[i] >= 0) printf(" %lf\t",b[i]);//正数前面带一个空格 
                else printf("%lf\t",b[i]);  
            } 
            else  
            { 
                if(a[i][j] >= 0) printf(" %lf\t",a[i][j]); 
                else printf("%lf\t",a[i][j]); 
            } 
        }  
        printf("\n"); 
    }  
}

/*输出向量*/ 
void printMatrix3(int n, double a[20]) 
{ 
    for(int i = 1; i <= n; i++ ) 
    { 
        if(a[i] >= 0) printf(" %lf\t",a[i]);
        else printf("%lf\t",a[i]); 
        printf("\n"); 
    }  
}

int main()
{
    int n,k=0; //n 是矩阵维数, k 是迭代次数
    double a[20][20],b[20];
    double xx[20] = {0},x[20] = {0};//xx 记录(k)迭代，x 记录(k+1)迭代，顺便初始化
    double sum = 0; 
    double precision,error;//精度 和 误差  

    /*输入*/ 
    printf("\n 请输入n：\n"); 
    scanf("%d",&n); 
    printf("\n 请输A 和b:\n"); 
    for(int i = 1; i <= n; i++ ) 
    { 
        for(int j = 1; j <= n+1; j++) 
        { 
            if(j == n+1) scanf("%lf",&b[i]); 
            else scanf("%lf",&a[i][j]); 
        }  
    }  
    printf("\n 您输入的矩阵为：\n"); 
    printMatrix(n,a,b);  
    printf("\n 请输入精度：\n"); 
    scanf("%lf",&precision); 

    /*初始化误差大于精度*/ 
    error = precision + 1; 

    /*雅可比迭代*/ 
    while(error > precision) 
    { 
        for(int i = 1; i <= n; i++) 
        { 
            sum = 0; 
            for(int j = 1; j <= n; j++) 
            { 
                if(j != i) 
                    sum += a[i][j] * xx[j];  
            } 
            x[i] =(b[i] - sum) / a[i][i];  
        } 

        //计算误差
        error = 0; 
        for(int i = 1; i <= n; i++) 
            error += fabs(x[i] - xx[i]);  

        //记录本次(k)迭代的x,以便下个循环(k+1)运用  
        for(int i = 1; i <= n; i++) 
            xx[i] = x[i]; 

        //迭代次数增加  
        k++; 

        //输出本次迭代结果 
        printf("\n 第%d 次迭代x = \n",k);  
        printMatrix3(n,x); 
    } 
    printf("\n 一共迭代了%d 次",k); 
    return 0; 
}