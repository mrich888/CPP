#include <iostream>
#include <fstream>
#include <iomanip>
#include <fstream>
#include <cstdlib>

#define BUFFER_SIZE 100

class FStream
{
public:
    FStream();

    ~FStream();

private:
    /* data */
};


int main()
{
    const char *name = "./test.txt";
    /* 用构造函数的方式打开文件 */
    //std :: ofstream (name);
    /* 用open成员函数打开文件 
        mode 默认是：ios :: out 以写的方式打开文件
        ios :: app: 以追加的方式写文件
    */
    std :: ofstream ofs;
    ofs.open(name, std :: ios :: out | std :: ios :: app);

    /*判断文件是否打开 */
    if (!ofs.is_open())
    {
        std :: cout << "open error" << std :: endl;
        exit(-1);
    }
    
    /* 读到缓冲区 */
    char buffer[BUFFER_SIZE];
    ofs >> buffer;
    
    ofs.close();




    // int num = 100;
    // printf("num:%d\n", num);
    // printf("num:%12d\n", num);
    // printf("num:%-12d\n", num);
    // std :: cout << setw(12) << 777 << std :: endl;
}