#include<iostream>
#include<algorithm>
#include<cstring>
#include<ctime>

using namespace std;

const int N = 365 * 10;

string backtest_scope[N]; //存储回测所用的时间段
int total_days = 0; //回测总天数

//实现将日期转换为时间戳
time_t time_stamp(int year,int month,int day)
{
    tm t = {};
    int y = year - 1900;
    t.tm_year = y;
    t.tm_mon = month - 1;
    t.tm_mday = day;
    time_t ans = mktime(&t);
    return ans;
}

//初始化backtest_scope[N],每天以%Y-%m-%d 的字符串格式存储
void backtest_scope_init(int sty,int stm,int std,int edy,int edm,int edd) // 参数:回测开始及结束年月日
{
    //定义回测开始,结束时间的时间戳
    time_t st = time_stamp(sty,stm,std);
    time_t ed = time_stamp(edy,edm,edd);

    //从回测起点开始循环读入日期到backtest_scope[N]中
    for(time_t init = st;init <= ed;init += 24 * 60 * 60)
    {
        tm* local_time = localtime(&init);
        char data[11];
        strftime(data,sizeof(data),"%Y-%m-%d",local_time);
        backtest_scope[total_days++] = data;
    }
}

int main()
{
    //初始化回测时间段
    backtest_scope_init(2015,1,1,2022,12,31);
    for(int i = 0;i < total_days;i++) cout << backtest_scope[i] << endl;
    return 0;
}
