#include <iostream>
#include <vector>

enum class Color
{
    black,
    white,
};

struct PiecePos
{
    int x;
    int y;
};

class Piece
{
public:
    virtual void draw() = 0;

protected:
    Color c;
};

class BlackPiece : public Piece
{
public:
    void draw()
    {
        std::cout << "下一颗黑色棋子" << std::endl;
    }
};

class WhitePiece : public Piece
{
public:
    void draw()
    {
        std::cout << "下一颗白色棋子" << std::endl;
    }
};

class PieceBoard
{
public:
    PieceBoard(const std::string& white, const std::string& black)
    {
        this->blackName = black;
        this->whiteName = white;
        this->Black = nullptr;
        this->White = nullptr;
    }

    void setPiece(Color c, int x, int y)
    {
        if (c == Color::white)
        {
            if (this->White == nullptr)
            {
                //没有创建
                this->White = new WhitePiece;
            }
            std::cout << whiteName  << "在（" << x << "," << y << ")";
            this->White->draw();
            whitevec.push_back({x,y});//列表初始化
        }
        else
        {
            if (this->White == nullptr)
            {
                //没有创建
                this->White = new WhitePiece;
            }
            std::cout << blackName << "在（" << x << "," << y << ")" ;
            this->White->draw();
            blackvec.push_back({x,y});//列表初始化
        }
    }

private:
    Piece *Black;
    Piece * White;
    std::vector <PiecePos> blackvec;
    std::vector <PiecePos> whitevec;//极大的减少内存
    std::string whiteName;
    std::string blackName;
};

int main()
{
    PieceBoard board("A", "B");
    board.setPiece(Color::white, 0, 0);
    board.setPiece(Color::black, 1, 0);
    board.setPiece(Color::white, 0, 1);
    board.setPiece(Color::black, 0, 2);


    return 0;
}