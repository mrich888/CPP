#include <iostream>

class Worker
{
public:
    Worker(int sarary) : m_sarary(sarary)
    {
        std ::cout << "Worker(int sarary)" << std :: endl;
    }
public:
    int m_sarary;
};

class Student
{
public:
    Student(int score) : m_score(score)
    {
        std :: cout << "Student(int score)" << std :: endl;
    }
public:
    int m_score;
};


/* 多继承 */
class Undergraduate : public Student,  public Worker
{
public:
    /*  用初始化列表初始父类的成员变量 */
    Undergraduate(int score, int sarary, int grade) : Student(score), Worker(sarary), m_grade(grade)
    {
        std :: cout << "Undergraduate()" << std :: endl;
    }
    ~Undergraduate()
    {
        std :: cout << "~Undergraduate()" << std :: endl;
    }

    void play()
    {
        std :: cout << "Undergraduate::play" << std :: endl;
    }

    void printInfo()
    {
        std :: cout << "score:" << m_score << "\tsarary:" << m_sarary << "\tgrade:" << m_grade << std :: endl;
    }
public:
    int m_grade;
};


int main()
{
    Undergraduate ug(90, 8000, 10);
    
    int length = sizeof(ug);
    std :: cout << "length:" << length <<  std :: endl;

    ug.printInfo();
    return 0;
}