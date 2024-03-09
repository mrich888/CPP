#include <iostream>
#include <string>

void func(int val)
{

}
void func(int *ptr)
{

}


int main()
{
    #if 0
    /*  auto  */
    int a = 100;
    auto num = 666;
    std :: cout << num << std :: endl;

    auto str = "hello world";
    std :: cout << str << std :: endl;//少用。会增加同组开发人员的阅读难度

    auto *pNum = &a;
    std :: cout << *pNum << std :: endl;
    #endif

    int num = 666;
    decltype(num) value = 777;

    std ::string str = "hello";
    decltype(str) ptr = "hello world";

    func(0);
    //func(NULL); candidate  ambiguous
    func(nullptr);


    int array1[5] = {11, 22, 33, 44, 55};
    std :: cout << sizeof(array1) / sizeof(array1[0]) << std :: endl;
    int array2[] = {11, 22, 33, 44, 55};
    std :: cout << sizeof(array2) / sizeof(array2[0]) << std :: endl;
    int array3[] {11, 22, 33, 44, 55};
    std :: cout << sizeof(array3) / sizeof(array3[0]) << std :: endl;

    for (int idx = 0; idx < sizeof(array2) / sizeof(array2[0]);  idx++)
    {
       std :: cout << array2[idx] << std :: endl; /* code */
    }
    
    /* item已经是内部的元素 */
    for (int item : array3)
    {
        std :: cout << item << std :: endl;
    }
    


    return 0;
}