    #include<bits/stdc++.h>
#include<conio.h>
#include<windows.h>
using namespace std;
char foodValues[] = {'A', 'B', 'G', 'L', 'M', 'P', 'S', 'W'};
class Snake {
public:
    int x, y;
    char value;
};
class Food {

public:
    int x, y;
    char value;
    Food() {
        foodGenrator();
    }
    void foodGenrator() {
        srand(time(0));
        x = (rand() % 15) + 1;
        y = (rand() % 75) + 1;
        value = foodValues[rand() % 8];
    }
    bool checkFood(Snake &snakeBody){
       if(snakeBody.x == x && snakeBody.y == y) {
            foodGenrator();
            return true;
       }
       else
        return false;
    }
};
class Board {

public :
    char board[20][80];
    Board(Food food) {
       for(int i = 0;i<20;i++) {
            for(int j = 0;j<80;j++) {
                if(i == 0 || j == 0 || i == 19 || j == 79) {
                    board[i][j] = '*';
                }
                else
                    board[i][j] = ' ';
            }
       }
       updateBoard(food);
    }
    void updateBoard(Food food) {
        board[food.x][food.y] = food.value;
    }
    void updateBoard(vector<Snake> snakeBody) {
        for(int i = 0;i<snakeBody.size();i++) {
            board[snakeBody[i].x][snakeBody[i].y] = snakeBody[i].value;
        }
        printBoard();
    }
    void printBoard() {
        for(int i = 0;i<20;i++) {
            for(int j = 0;j<80;j++) {
                cout<<board[i][j];
            }
            cout<<endl;
        }
    }
};
void snakeBirth(vector<Snake> &snakeBody) {
    srand(time(0));
    snakeBody[0].x = rand() % 10;
    snakeBody[0].y = rand() % 20;
    snakeBody[0].value = 'H';
    snakeBody[1].x = snakeBody[0].x;
    snakeBody[1].y = snakeBody[0].y + 1;
    snakeBody[1].value = '#';
}
void moveSnake(vector<Snake> &snakeBody, Board &boundary, char &dir, Food &food) {

        int size = snakeBody.size() - 1;
        Snake temp = snakeBody[size];
        boundary.board[snakeBody[size].x][snakeBody[size].y] = ' ';
        if(dir == 'a') {
            for(int i=size;i>0;i--) {
                snakeBody[i].x = snakeBody[i-1].x;
                snakeBody[i].y = snakeBody[i-1].y;
            }
            (snakeBody[0].y)--;
            if(snakeBody[0].y == 0)
                snakeBody[0].y = 78;
        }
        else if(dir == 'd') {
            for(int i=size;i>0;i--) {
                snakeBody[i].x = snakeBody[i-1].x;
                snakeBody[i].y = snakeBody[i-1].y;
            }
            (snakeBody[0].y)++;
            if(snakeBody[0].y == 79)
                snakeBody[0].y = 1;
        }
        else if(dir == 'w') {
            for(int i=size;i>0;i--) {
                snakeBody[i].x = snakeBody[i-1].x;
                snakeBody[i].y = snakeBody[i-1].y;
            }
            (snakeBody[0].x)--;
            if(snakeBody[0].x == 0)
                snakeBody[0].x = 18;
        }
        else if(dir == 's') {
            for(int i=size;i>0;i--) {
                snakeBody[i].x = snakeBody[i-1].x;
                snakeBody[i].y = snakeBody[i-1].y;
            }
            (snakeBody[0].x)++;
            if(snakeBody[0].x == 19)
                snakeBody[0].x = 1;
        }

        if(food.checkFood(snakeBody[0])){
            snakeBody.push_back(temp);
            boundary.board[snakeBody[size + 1].x][snakeBody[size + 1].y] = '#';
            boundary.updateBoard(food);
        }
        for(int i=1;i<=size+1;i++)
            if(snakeBody[0].x==snakeBody[i].x&&snakeBody[0].y==snakeBody[i].y)
            dir='x';
        boundary.updateBoard(snakeBody);

}



int main() {

    Food food;
    Board boundary(food);
    vector<Snake> snakeBody(2);
    snakeBirth(snakeBody);
    boundary.updateBoard(snakeBody);
    char dir;
    while(true) {
        if(kbhit()) {
            dir = getch();
        }
        if(dir == 'x' )
            break;
        else if(dir == 'p')
            system("pause");
        moveSnake(snakeBody, boundary, dir, food);
        Sleep(70);
        system("cls");
    }
}
