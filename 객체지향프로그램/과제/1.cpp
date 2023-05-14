#include <iostream>
#include <vector>
class IntPoint
{
public:
    int x; // x 좌표
    int y; // y 좌표
    IntPoint(int x, int y) : x(x), y(y) {}
};
class Rectangle
{
    IntPoint corner; // 직사각형의 왼쪽-아래 코너점
    int width;       // 직사각형의 폭
    int height;      // 직시각형의 높이
public:
    Rectangle(IntPoint pt, int w, int h) : corner(pt),
        width((w < 0) ? 0 : w), height((h < 0) ? 0 : h) {}
    int perimeter()
    {
        return 2 * width + 2 * height;
    }
    int area()
    {
        return width * height;
    }
    int get_width()
    {
        return width;
    }
    int get_height()
    {
        return height;
    }
    IntPoint get_corner()
    {
        return corner;
    }
    // 현재 인스턴스 사각형과 r이 겹쳐있다면 true, 그렇지 않으며 false
    bool intersect(Rectangle r)
    {
        bool is_left_side_in = (r.corner.x > corner.x) && (r.corner.x < corner.x + width);
        bool is_right_side_in = (r.corner.x + r.width > corner.x) && (r.corner.x + r.width < corner.x + width);
        bool is_top_side_in = (r.corner.y > corner.y) && (r.corner.y < corner.y + height);
        bool is_bottom_side_in = (r.corner.y + r.height > corner.y) && (r.corner.y + r.height < corner.y + height);
        if ((is_left_side_in || is_right_side_in) && (is_top_side_in || is_bottom_side_in))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    // 대각선의 길이(int 형)를 반환
    int diagonal()
    {
        return std::sqrt(std::pow(width, 2) + std::pow(height, 2));
    }
    // 사각형의 중심점의 좌표를 IntPoint 형으로 반환
    IntPoint center()
    {
        IntPoint ip(corner.x + width / 2, corner.y + height / 2);
        return ip;
    }
    // 현재 인스턴스 사각형의 내부(경계포함)에 pt가 있으면 true,
    // 그렇지 않으면 false
    bool is_inside(IntPoint pt)
    {
        bool is_in_x = (pt.x <= corner.x + width) && (pt.x >= corner.x);
        bool is_in_y = (pt.y <= corner.y + height) && (pt.y >= corner.y);
        if (is_in_x && is_in_y)
        {
            return true;
        }
        else
        {
            return false;
        };
    }
};


int main()
{
    IntPoint p1(10, 11);
    // 시작점이 x = 10, y = 11이며 너비,높이가 5와 7인 직사각형 생성
    Rectangle rec1(p1, 5, 7);
    IntPoint p2(15, 15);
    // 시작점이 x = 15, y = 15이며 너비,높이가 5와 7인 직사각형 생성
    Rectangle rec2(p2, 5, 7);
    IntPoint p3(13, 15);
    // 시작점이 x = 13, y = 15이며 너비,높이가 5와 7인 직사각형 생성
    Rectangle rec3(p3, 5, 7);
    std::cout << "rec1는 rec2과 겹치는가?(겹치면 1, 안겹치면 0)" << rec1.intersect(rec2) << std::endl;
    std::cout << "rec1는 rec3과 겹치는가?(겹치면 1, 안겹치면 0)" << rec1.intersect(rec3) << std::endl;
    std::cout << "rec1의 대각선크기는?" << rec1.diagonal() << std::endl;
    std::cout << "rec1의 중심좌표"
        << "x : " << rec1.center().x << "y : " << rec1.center().y << std::endl;
    // 테스트해볼 포인트를 IntPoint형태로 설정
    IntPoint testPoint(12, 13);
    std::cout << rec1.is_inside(testPoint);

};