#include <iostream>
#include <math.h>
using namespace std;

struct parameters
{
    float w,b;
};

struct derivates
{
    float dj_dw,dj_db;
};


float cal_cost(float w, float b, int x[], int y[], int m){
    float cost=0;
    for (int i=0;i<m;i++){
        cost+=pow(((w*x[i]+b)-y[i]),2);
    }
    cost=cost/(2*m);
    return cost;
}

derivates calc_deri(float w, float b, int x[], int y[], int m){
    float dj_dw=0;
    float dj_db=0;

    for (int i=0;i<m;i++){
        dj_dw+=((w*x[i]+b)-y[i])*x[i];
        dj_db+=((w*x[i]+b)-y[i]);
    }

    dj_dw=dj_dw/m;
    dj_db=dj_db/m;

    return {dj_dw,dj_db};
}

parameters gradient_descent(float w,float b, int x[], int y[],int m,int itr){
    float temp_w=w;
    float temp_b=b;

    float alpha=0.03;

    for (int i=0;i<itr;i++){
        auto derivatives=calc_deri(temp_w,temp_b,x,y,m);
        temp_w=temp_w-alpha*derivatives.dj_dw;
        temp_b=temp_b-alpha*derivatives.dj_db;
    }

    return {temp_w,temp_b};
}


int main(){
    int x[]={1,2,3,4,5,6,7,8,9,10};
    int y[]={3,5,7,9,11,13,15,17,19,21};
    int m=sizeof(x)/sizeof(x[0]);
    float w=4,b=10;
    cout<<"The initial cost is:"<<cal_cost(w,b,x,y,m)<<endl;
    parameters res=gradient_descent(w,b,x,y,m,1000000);
    cout<<"w:"<<res.w<<"\n"<<"b:"<<res.b<<"\n";
    cout<<"The final cost is:"<<cal_cost(res.w,res.b,x,y,m)<<endl;
}
